`include "define.v"
module cpu_top (
    input clk,
    input rst,
    output wire uart_tx
);

  reg is_interrupt = 0;
  reg is_exception = 0;
  reg [31:0] pc;
  initial begin
    pc = 'h8000;
  end

  //////////////////////////////////////////////////
  // fetch stage
  // //////////////////////////////////////////////
  wire is_jump_operation;
  wire is_branch_jump;
  wire is_jal;
  wire is_jalr;
  wire is_branch;
//  wire [7:0] jump_addr;
  wire [31:0] pc_next;
  wire [31:0] pc_plus4;

  wire [31:0] alu_out;
  wire [31:0] next_csr_pc;
  wire enable_pc_update_from_csr;

  gen_next_pc gen_next_pc (
      .rst(rst),
      .is_jump(is_jump_operation),
      .is_branch_jump(is_branch_jump),
      .is_jal(is_jal),
      .is_jalr(is_jalr),
      .is_branch(is_branch),
      .alu_out(alu_out),
      .pc(pc),
      .enable_pc_update_from_csr(enable_pc_update_from_csr),
      .csr_pc(next_csr_pc),

      .pc_next (pc_next),
      .pc_plus4(pc_plus4)
  );

  always @(posedge clk) begin
    pc <= pc_next;
  end


  wire [31:0] inst;
  fetch fetch (
      .clk(clk),
      .pc (pc),

      .inst(inst),
      .is_jump(is_jump_operation),
      .is_jal(is_jal),
      .is_jalr(is_jalr),
      .is_branch(is_branch)
  );

  ////////////////////////////////////////////////
  // decode stage
  ////////////////////////////////////////////////

  wire [6:0] opcode;
  wire [4:0] rs;
  wire [4:0] rs2;
  wire [4:0] rd;
  wire [2:0] funct3;
  wire [6:0] funct7;
  wire [31:0] imm;
  wire [4:0] shamt;
  wire [2:0] opcode_type;
  wire is_r_type;
  wire is_store;
  wire is_load;
  wire is_writeback;
  wire using_pc;
  wire is_system;
  assign using_pc = is_jump_operation && (is_jal || is_branch);

  decode decode (
      .inst(inst),
      .is_jump(is_jump_operation),

      .opcode(opcode),
      .rs(rs),
      .rs2(rs2),
      .rd(rd),
      .funct3(funct3),
      .funct7(funct7),
      .opcode_type(opcode_type),
      .imm(imm),
      .shamt(shamt),
      .is_r_type(is_r_type),
      .is_store(is_store),
      .is_load(is_load),
      .is_writeback(is_writeback),
      .use_adder(use_adder),
      .use_pc(use_pc),
      .is_lui(is_lui),
      .is_system(is_system)
  );

  // wire reg_we = is_system ? is_system_writeback : is_writeback;
  wire [31:0] rs1_data;
  wire [31:0] rs2_data;
  wire [31:0] rd_data;

  regfile regfile (
      .clk(clk),
      .rst(rst),
      .we(we),
      .rs1(rs),
      .rs2(rs2),
      .rd(rd),
      .rd_data(rd_data),

      .rs1_data(rs1_data),
      .rs2_data(rs2_data)
  );

  //////////////////////////////////////////////////
  // execute stage
  // //////////////////////////////////////////////

  wire [ 2:0] alu_op = use_adder ? `ALU_ADD : funct3;
  wire [31:0] alu_in1 = (using_pc | use_pc) ? pc : rs1_data;
  wire [31:0] alu_in2 = is_r_type ? rs2_data : imm;
  wire [31:0] tmp_alu_out;
  alu alu (
      .alu_op(alu_op),
      .in1(alu_in1),
      .in2(alu_in2),
      .funct7(funct7),
      .shamt(shamt),
      .is_r_type(is_r_type),

      .out(tmp_alu_out)
  );
  assign alu_out = is_lui ? imm : tmp_alu_out;

  branch_conditional branch_conditional (
      .branch_op(funct3),
      .rs1_data(rs1_data),
      .rs2_data(rs2_data),
      .is_branch_jump(is_branch_jump)
  );

  ////////////////////////////////////////////////
  // memory stage
  // ////////////////////////////////////////////

  // mem[rs1 + offset(imm)] -> rd
  wire [31:0] mem_addr = alu_out[16:0]>>2;

  wire [31:0] t_loaddata;
  wire is_illegal;

  wire uart_we = is_store && (mem_addr == `UART_TX_ADDR);
  wire [7:0] uart_data = rs2_data[7:0];

  wire [31:0] hardware_counter;
  wire [31:0] loaddata = ((mem_addr == `HARDWARE_COUNTER_ADDR) && (funct3 == `LOAD_LW)) ? hardware_counter : t_loaddata;

  mem mem (
      .clk(clk),
      .is_store(is_store & !uart_we),
      .is_illegal(is_illegal),
      .addr(mem_addr),
      .wdata(rs2_data),
      .store_load_type(funct3),
      .loaddata(t_loaddata)
  );

  //////////////////////////////////////////////////
  // writeback stage
  // //////////////////////////////////////////////

  wire [31:0] csr_data;
  wire is_write_back_from_csr;
  // set we, rd_data
  writeback writeback (
      .is_writeback(is_writeback),
      .is_load(is_load),
      .opcode_type(opcode_type),
      .loaddata(loaddata),
      .alu_out(alu_out),
      .pc_plus4(pc_plus4),
      .csr_data(csr_data),
      .csr_writeback(is_write_back_from_csr),
      .is_illegal(is_illegal),

      .we(we),
      .rd_data(rd_data)
  );

  ////////////////////////////////////////////////
  // csr
  ////////////////////////////////////////////////

  csr csr (
      .clk(clk),
      .rst(rst),
      .csr_addr(imm[11:0]),
      .rs_addr(rs),
      .csr_wdata(rs1_data),
      .csr_op(funct3),
      .is_system(is_system),
      .funct12(imm[11:0]),
      .csr_destreg_addr(rd),
      .uimm(rs),
      .illegal_instruction(1'b0),  // future work
      .access_fault(31'b0),  // future work
      .pc(pc),
      // output
      .csr_out(csr_data),
      .is_illegal(is_illegal),
      .write_back(is_write_back_from_csr),
      .next_csr_pc(next_csr_pc),
      .enable_pc_update_from_csr(enable_pc_update_from_csr)
  );

  ////////////////////////////////////////////////
  // uart
  // ////////////////////////////////////////////
 
  uart uart0(
     .uart_tx(uart_tx),     // UART transmit wire
     // Inputs
     .uart_wr_i(uart_we),   // Raise to transmit byte
     .uart_dat_i(uart_data),  // 8-bit data
     .sys_clk_i(clk),   // System clock, 100 MHz
     .sys_rstn_i(rst)    // System reset
  );

  ////////////////////////////////////////////////
  // hardware counter
  // ////////////////////////////////////////////
  //

  hardware_counter hardware_counter_0 (
      .clk_ip(clk),
      .rstn_ip(rst),
      .counter_op(hardware_counter)
  );



endmodule
