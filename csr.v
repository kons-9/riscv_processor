`include "define.v"

module csr (
    input clk,
    input rst,
    input [11:0] csr_addr,
    input [4:0] rs_addr,
    input [31:0] csr_wdata,
    input [2:0] csr_op,
    input is_system,
    input [11:0] funct12,
    input [4:0] csr_destreg_addr,
    input [4:0] uimm,
    input illegal_instruction,
    input [30:0] access_fault,
    input [31:0] pc,

    output [31:0] csr_out,
    output is_illegal,
    output write_back,
    output [31:0] next_csr_pc,
    output enable_pc_update_from_csr
);

  reg [2:0] cpu_mode;
  reg [31:0] mstatus;
  reg [31:0] misa;
  reg [31:0] mie;
  reg [31:0] mtvec;
  reg [31:0] mscratch;
  reg [31:0] mepc;
  reg [31:0] mcause;
  reg [31:0] mtval;
  reg [31:0] mip;
  wire global_mie = mstatus[`STATUS_MIE];
  wire [1:0] mstatus_mpp = mstatus[`STATUS_MPP];
  wire mstatus_mpie = mstatus[`STATUS_MPIE];

  wire [30:0] exception_code;
  wire update_pc, is_interrupt;

  function [32:0] get_mcause;
    input [11:0] funct12;
    input [31:0] pc;
    input [31:0] mie;
    input [31:0] mip;
    input [30:0] access_fault;
    input illegal_instruction;
    input is_illegal;
    // output = {update_pc, is_interrupt, exception_code}
    begin
      if (illegal_instruction | is_illegal) begin
        get_mcause = {1'b1, `EXCEPTION_ILLEGAL_INSTRUCTION};
      end else if (access_fault != 31'b0) begin
        get_mcause = {1'b1, 1'b0, access_fault};
      end else if (global_mie && (mie & mip != 32'b0)) begin
        // interrupt
        get_mcause = {1'b1, 1'b1, (mie[30:0] & mip[30:0])};
      end else begin
        case (funct12)
          `CSR_MRET: get_mcause = {1'b1, 1'b0, 31'b0};
          `CSR_WFI: get_mcause = {1'b1, 1'b0, 31'b0};
          `CSR_ECALL: begin
            case (cpu_mode)
              `CSR_PREV_USER: get_mcause = {1'b1, `EXCEPTION_ECALL_U};
              `CSR_PREV_SUPERVISOR: get_mcause = {1'b1, `EXCEPTION_ECALL_S};
              `CSR_PREV_MACHINE: get_mcause = {1'b1, `EXCEPTION_ECALL_M};
              default: get_mcause = {1'b1, `EXCEPTION_ILLEGAL_INSTRUCTION};
            endcase
          end
          `CSR_EBREAK: get_mcause = {1'b1, `EXCEPTION_EBREAK};
          // `CSR_SRET: get_mcause = {1'b1, 1'b0, 31'b0};
          default: get_mcause = 33'b0;
        endcase
      end
    end
  endfunction
  assign {update_pc, is_interrupt, exception_code} = get_mcause(
      funct12, pc, mie, mip, access_fault, illegal_instruction, is_illegal
  );
  // assign {update_pc, is_interrupt, exception_code} = 33'b0;

  wire [31:0] tval;
  assign tval = is_illegal ? csr_addr : pc;

  assign csr_out = read_csr(
      csr_addr, mstatus, misa, mie, mtvec, mscratch, mepc, mcause, mtval, mip
  );
  function automatic [31:0] read_csr;
    input [11:0] csr_addr;
    input [31:0] mstatus;
    input [31:0] misa;
    input [31:0] mie;
    input [31:0] mtvec;
    input [31:0] mscratch;
    input [31:0] mepc;
    input [31:0] mcause;
    input [31:0] mtval;
    input [31:0] mip;
    begin
      case (csr_addr)
        `MSTATUS: read_csr = mstatus;
        `MISA: read_csr = misa;
        `MIE: read_csr = mie;
        `MTVEC: read_csr = mtvec;
        `MSCRATCH: read_csr = mscratch;
        `MEPC: read_csr = mepc;
        `MCAUSE: read_csr = mcause;
        `MTVAL: read_csr = mtval;
        `MIP: read_csr = mip;
        default: read_csr = 0;
      endcase
    end
  endfunction

  assign next_exception_pc = mtvec >> 2;
  // vector mode or direct mode
  assign next_interrupt_pc = mtvec[1:0] == 0 ? mtvec : mtvec[31:0] + mcause[30:0] << 2;
  wire is_wfi = funct12 == `CSR_WFI && !is_interrupt;
  assign next_csr_pc = is_wfi ? pc : is_interrupt ? next_interrupt_pc : next_exception_pc;
  assign enable_pc_update_from_csr = is_system && update_pc;

  wire [1:0] addr_restriction;
  wire [1:0] addr_mode;
  wire addr_is_custom;
  assign addr_restriction = csr_addr[11:10];
  assign addr_mode = csr_addr[9:8];
  assign addr_custom = (csr_addr[7:6] == `CSR_IS_CUSTOM);

  wire is_mode_illegal;
  wire is_write_illegal;
  assign is_mode_illegal = (is_system && cpu_mode > addr_mode);
  assign is_write_illegal = (is_write && addr_restriction == `CSR_READ_ONLY);
  assign is_illegal = (is_mode_illegal || is_write_illegal);


  wire [31:0] bitmask;
  wire [31:0] csr_bitmask_wdata;
  wire [31:0] ext_uimm;
  wire [31:0] csr_cleared_wdata;
  wire [31:0] csr_bitmask_uimm;
  wire [31:0] csr_cleared_uimm;
  assign bitmask = rs_addr == 0 ? csr_wdata : 32'hFFFFFFFF;
  assign csr_bitmask_wdata = csr_out & ~bitmask | csr_wdata & bitmask;
  assign csr_cleared_wdata = csr_out & ~bitmask;
  assign ext_uimm = {27'b0, uimm};
  assign csr_bitmask_uimm = csr_out & ~bitmask | ext_uimm & bitmask;
  assign csr_cleared_uimm = csr_out & ~bitmask;

  wire [31:0] csr_data;
  wire is_write, is_priv;
  wire tmp_write_back;
  assign {csr_data, is_write, is_priv, tmp_write_back} = decode_csr_operation(
      csr_op,
      csr_wdata,
      csr_bitmask_wdata,
      csr_cleared_wdata,
      ext_uimm,
      csr_bitmask_uimm,
      csr_cleared_uimm
  );
  assign write_back = tmp_write_back && !is_illegal && csr_destreg_addr != 0;

  function automatic [34:0] decode_csr_operation;
    input [2:0] csr_op;
    input [31:0] csr_wdata;
    input [31:0] csr_bitmask_wdata;
    input [31:0] csr_cleared_wdata;
    input [31:0] ext_uimm;
    input [31:0] csr_bitmask_uimm;
    input [31:0] csr_cleared_uimm;
    // output = {[31:0] csr_data, is_write, is_priv, write_back}
    begin
      case (csr_op)
        `CSR_PRIV: begin
          decode_csr_operation = {32'b0, 1'b0, 1'b1, 1'b0};
        end
        `CSR_RW: begin
          // swap the value of csr_wdata and csr_rdata
          decode_csr_operation = {csr_wdata, 1'b1, 1'b0, 1'b1};
        end
        `CSR_RS: begin
          // read csr and write it to destination register
          decode_csr_operation = {csr_bitmask_wdata, 1'b1, 1'b0, 1'b1};
        end
        `CSR_RC: begin
          // read csr and clear it
          decode_csr_operation = {csr_cleared_wdata, 1'b1, 1'b0, 1'b1};
        end
        `CSR_RWI: begin
          // read csr and write immediate value to destination register
          decode_csr_operation = {ext_uimm, 1'b1, 1'b0, 1'b1};
        end
        `CSR_RSI: begin
          // read csr and set it
          decode_csr_operation = {csr_bitmask_uimm, 1'b1, 1'b0, 1'b1};
        end
        `CSR_RCI: begin
          // read csr and clear it
          decode_csr_operation = {csr_cleared_uimm, 1'b1, 1'b0, 1'b1};
        end
        default: begin
          decode_csr_operation = {32'b0, 1'b0, 1'b0, 1'b0};
          // $display("illegal csr operation");
        end
      endcase
    end
  endfunction

  ///////////////////////
  // synchronous process
  // write register file
  ///////////////////////

  always @(posedge clk) begin
    if (rst) begin
      // initialize
      init();
    end else if (is_system && !is_priv) begin
      if (is_write) begin
        case (csr_addr)
          `MSTATUS: mstatus <= csr_data;
          `MISA: misa <= csr_data;
          `MIE: mie <= csr_data;
          `MTVEC: mtvec <= csr_data;
          `MSCRATCH: mscratch <= csr_data;
          `MEPC: mepc <= csr_data;
          `MCAUSE: mcause <= csr_data;
          `MTVAL: mtval <= csr_data;
          `MIP: mip <= csr_data;
          default: ;
        endcase
      end

    end else if (is_system && is_priv) begin
      execute_priv_operation();
    end else if (is_interrupt) begin
      // interrupt
      // go to trap vector
      start_exception();
    end else if (is_system && is_illegal || illegal_instruction) begin
      // illegal instruction
      // go to trap vector
      start_exception();
    end else begin
    end
  end
  task automatic init;
    begin
      cpu_mode <= `CSR_PREV_MACHINE;
    end
  endtask

  task automatic execute_priv_operation;
    begin
      case (funct12)
        `CSR_MRET: begin
          mstatus[`STATUS_MIE] <= mstatus_mpie;
          mstatus[`STATUS_MPIE] <= 1;
          cpu_mode <= mstatus_mpp;
        end
        `CSR_WFI: begin
          // wait for interrupt
          // stop cpu clock until mstatus.mie == 1 && mie != 0
          // nothing to do
        end
        `CSR_ECALL: begin
          // go to trap vector
          start_exception();
        end
        `CSR_EBREAK: begin
          start_exception();
          $display("unimplemented");
        end
        /////////////////////////////////////////////
        // future work
        /////////////////////////////////////////////
        `CSR_SRET: begin
          $display("unimplemented");
        end
        `CSR_SFENCE_VMA: begin
          $display("unimplemented");
        end
        `CSR_SINVAL_VMA: begin
          $display("unimplemented");
        end
        `CSR_SFENCE_W_INVAL: begin
          $display("unimplemented");
        end
        `CSR_SFENCE_INVAL_IR: begin
          $display("unimplemented");
        end
        default: begin
          // illegal instruction
          $display("illegal privileged operation");
        end
      endcase
    end
  endtask

  task automatic start_exception;
    begin
      mstatus[`STATUS_MIE] <= mstatus_mpie;
      mstatus[`STATUS_MPIE] <= 1;
      mstatus[`STATUS_MPP] <= cpu_mode;
      // set mepc = pc
      mepc <= pc;
      // set mcause = cause
      mcause <= {is_interrupt, exception_code};
      // set mtval = tval
      mtval <= tval;
      cpu_mode <= `CSR_PREV_MACHINE;
    end
  endtask

endmodule
