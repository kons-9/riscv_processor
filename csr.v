`include "define.v"

module csr (
    input clk,
    input rst,
    input [11:0] csr_addr,
    input [4:0] r1_addr,
    input [31:0] csr_wdata,
    input [2:0] csr_op,
    input is_system,
    input [11:0] funct12,
    input [5:0] csr_destreg_addr,
    input [4:0] uimm,

    output [31:0] csr_out,
    output is_illegal,
    output write_back,
    output reg is_interrupt,
    output reg is_exception,
    output reg is_stop_clock,
    output wire [31:0] next_exception_pc,
    output wire [31:0] next_interrupt_pc
);
  reg [31:0] csr[0:4095];
  reg [2:0] cpu_mode;

  wire [31:0] mtvec = csr[`MTVEC];
  assign next_exception_pc = mtvec >> 2;
  // vector mode or direct mode
  assign next_interrupt_pc = mtvec[1:0] == 0 ? mtvec >> 2 : mtvec[31:2] + ; 

  wire csr_we = (csr_op == `CSR_RW) && is_system;

  wire [1:0] addr_restriction;
  wire [1:0] addr_mode;
  wire addr_is_custom;

  assign addr_restriction = csr_addr[11:10];
  assign addr_mode = csr_addr[9:8];
  assign addr_custom = (csr_addr[7:6] == `CSR_IS_CUSTOM);

  wire is_mode_illegal;
  wire is_addr_illegal;

  assign is_illegal = (is_mode_illegal || is_addr_illegal);
  assign is_mode_illegal = (is_system && cpu_mode > addr_mode);
  assign is_write_illegal = (csr_we && addr_restriction == `CSR_READ_ONLY);

  wire [31:0] csr_old_wdata;
  assign csr_old_wdata = csr[csr_addr];
  assign csr_out = csr_old_wdata;
  always @(posedge clk) begin
    if (rst) begin
      init();
    end else begin
      execute_csr_operation();
    end
  end

  task init;
    begin
      integer i;
      for (i = 0; i < 4096; i = i + 1) begin
        csr[i] <= 0;
      end
      cpu_mode <= `CSR_PREV_MACHINE;
    end
  endtask

  task start_exception;
    begin
      is_exception <= 1;
    end
  endtask
  task start_interrupt;
    begin
      is_interrupt <= 1;
    end
  endtask

  wire [31:0] bitmask;
  wire [31:0] csr_bitmask_wdata;
  wire [31:0] ext_uimm;
  wire [31:0] csr_cleared_wdata;
  assign bitmask = r1_addr == 0 ? csr_wdata : 32'hFFFFFFFF;
  assign csr_bitmask_wdata = csr_old_wdata & ~bitmask | csr_wdata & bitmask;
  assign csr_cleared_wdata = csr_old_wdata & ~bitmask;
  assign ext_uimm = {27'b0, uimm};

  task execute_csr_operation;
    begin
      case (csr_op)
        `CSR_PRIV: begin
          execute_privileged_operation();
        end
        `CSR_RW: begin
          // swap the value of csr_wdata and csr_rdata
          write_csr(csr_wdata);
        end
        `CSR_RS: begin
          // read csr and write it to destination register
          write_csr(csr_bitmask_wdata);
        end
        `CSR_RC: begin
          // read csr and clear it
          write_csr(csr_cleared_wdata);
        end
        `CSR_RSI: begin
          // read csr and set it
          write_csr(ext_uimm);
        end
        `CSR_RCI: begin
          // read csr and clear it
          write_csr(csr_bitmask_wdata);
        end
        default: begin
          $display("illegal csr operation");
        end
      endcase
    end
  endtask
  wire [31:0] mstatus;
  wire [31:0] mip;
  wire [31:0] mie;
  assign mstatus = csr[`MSTATUS];
  assign mip = csr[`MIP];
  assign mie = csr[`MIE];
  task execute_privileged_operation;
    begin
      case (funct12)
        `CSR_MRET: begin
          $display("unimplemented");
        end
        `CSR_WFI: begin
          // wait for interrupt
          // stop cpu clock until mstatus.mie == 1 && mie != 0
          is_stop_clock <= (mip & mie) == 0;
        end
        `CSR_ECALL: begin
          // go to trap vector
          $display("unimplemented");
        end
        `CSR_EBREAK: begin
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
          $display("illegal privileged operation");
        end
      endcase
    end
  endtask
  task write_csr;
    input [31:0] wdata;
    begin
      if (csr_we && !is_illegal) begin
        csr[csr_addr] <= wdata;
      end
    end
  endtask
endmodule
