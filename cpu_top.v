// top module
//
module cpu_top (
    input clk,
    input rst
);

  reg is_interrupt = 0;
  reg is_exception = 0;
  reg [7:0] pc;

  //////////////////////////////////////////////////
  // fetch stage
  // //////////////////////////////////////////////
  wire is_jump;
  wire [7:0] jump_addr;
  wire [7:0] pc_next;

  gen_next_pc gen_next_pc (
      .rst(rst),
      .is_jump(is_jump),
      .jump_addr(jump_addr),
      .pc(pc),

      .pc_next(pc_next)
  );

  always @(posedge clk) begin
    if (rst) begin
      pc <= 0;
    end else begin
      pc <= pc_next;
    end
  end


  wire [31:0] inst;
  fetch fetch (
      .clk(clk),
      .pc (pc),

      .inst(inst),
      .is_jump(is_jump)
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

  decode decode (
      .inst(inst),

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
      .is_store(is_store)
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

  wire [ 2:0] alu_op = funct3;
  wire [31:0] alu_in1 = rs1_data;
  wire [31:0] alu_in2 = is_r_type ? rs2_data : imm;
  wire [31:0] alu_out;

  alu alu (
      .alu_op(alu_op),
      .in1(alu_in1),
      .in2(alu_in2),
      .funct7(funct7),
      .shamt(shamt),
      .is_r_type(is_r_type),

      .out(alu_out)
  );

  ////////////////////////////////////////////////
  // memory stage
  // ////////////////////////////////////////////

  // mem[rs1 + offset(imm)] -> rd
  wire [31:0] mem_addr = alu_out;

  wire [31:0] loaddata;

  mem mem (
      .clk(clk),
      .is_store(is_store),
      .addr(mem_addr),
      .wdata(mem_data),
      .store_load_type(funct3),
      .loaddata(loaddata)
  );

  //////////////////////////////////////////////////
  // writeback stage
  // //////////////////////////////////////////////

  // set we, rd_data
  writeback writeback (
      .we(we),
      .rd(rd),
      .loaddata(loaddata),
      .alu_out(alu_out),

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
