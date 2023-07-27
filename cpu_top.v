`include "define.v"
module cpu_top (
    input clk,
    input rst
);

  reg is_interrupt = 0;
  reg is_exception = 0;
  reg [31:0] pc;

  //////////////////////////////////////////////////
  // fetch stage
  // //////////////////////////////////////////////
  wire is_jump_operation;
  wire is_branch_jump;
  wire is_jal;
  wire is_jalr;
  wire is_branch;
  wire [7:0] jump_addr;
  wire [31:0] pc_next;
  wire [31:0] pc_plus4;

  wire [31:0] alu_out;

  gen_next_pc gen_next_pc (
      .rst(rst),
      .is_jump(is_jump_operation),
      .is_branch_jump(is_branch_jump),
      .is_jal(is_jal),
      .is_jalr(is_jalr),
      .is_branch(is_branch),
      .alu_out(alu_out),
      .pc(pc),

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
      .use_pc(using_pc)
  );

  wire we;
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
  wire [31:0] alu_in1 = using_pc ? pc : rs1_data;
  wire [31:0] alu_in2 = is_r_type ? rs2_data : imm;

  alu alu (
      .alu_op(alu_op),
      .in1(alu_in1),
      .in2(alu_in2),
      .funct7(funct7),
      .shamt(shamt),
      .is_r_type(is_r_type),

      .out(alu_out)
  );

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
  wire [13:0] mem_addr = alu_out[13:0];

  wire [31:0] loaddata;

  mem mem (
      .clk(clk),
      .is_store(is_store),
      .addr(mem_addr),
      .wdata(rs2_data),
      .store_load_type(funct3),
      .loaddata(loaddata)
  );

  //////////////////////////////////////////////////
  // writeback stage
  // //////////////////////////////////////////////

  // set we, rd_data
  writeback writeback (
      .is_writeback(is_writeback),
      .is_load(is_load),
      .opcode_type(opcode_type),
      .loaddata(loaddata),
      .alu_out(alu_out),
      .pc_plus4(pc_plus4),

      .we(we),
      .rd_data(rd_data)
  );

  ////////////////////////////////////////////////
  // control
  ////////////////////////////////////////////////

  ////////////////////////////////////////////////
  // csr
  ////////////////////////////////////////////////
  csr csr (
      .clk(clk),
      .csr_addr(),
      .csr_we(),
      .csr_wdata(),
      .csr_rdata(),

      .csr_out()
  );

endmodule
