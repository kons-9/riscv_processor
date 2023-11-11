module regfile (
    input clk,
    input rstn,
    input we,
    input [4:0] rs1,
    input [4:0] rs2,
    input [4:0] rd,
    input [31:0] rd_data,
    input alu_in1_use_pc,
    input alu_in2_use_imm,
    input [31:0] pc,
    input [31:0] imm,
    input is_r_type,
    input [4:0] shamt,

    output [31:0] rs1_data,
    output [31:0] rs2_data,
    output [31:0] alu_in1,
    output [31:0] alu_in2,
    output [4:0] shift
);

  reg [31:0] regs[31:0];

  assign rs1_data = regs[rs1];
  assign rs2_data = regs[rs2];
  assign alu_in1 = alu_in1_use_pc ? pc : rs1_data;
  assign alu_in2 = alu_in2_use_imm ? imm : rs2_data;
  assign shift = is_r_type ? rs2_data[4:0] : shamt;

  // write is synchronous
  always @(posedge clk) begin
    if (!rstn) begin
      regs[0]  <= 0;
      regs[1]  <= 0;
      regs[2]  <= 0;
      regs[3]  <= 0;
      regs[4]  <= 0;
      regs[5]  <= 0;
      regs[6]  <= 0;
      regs[7]  <= 0;
      regs[8]  <= 0;
      regs[9]  <= 0;
      regs[10] <= 0;
      regs[11] <= 0;
      regs[12] <= 0;
      regs[13] <= 0;
      regs[14] <= 0;
      regs[15] <= 0;
      regs[16] <= 0;
      regs[17] <= 0;
      regs[18] <= 0;
      regs[19] <= 0;
      regs[20] <= 0;
      regs[21] <= 0;
      regs[22] <= 0;
      regs[23] <= 0;
      regs[24] <= 0;
      regs[25] <= 0;
      regs[26] <= 0;
      regs[27] <= 0;
      regs[28] <= 0;
      regs[29] <= 0;
      regs[30] <= 0;
      regs[31] <= 0;
    end else if (we && rd != 0) begin
      regs[rd] <= rd_data;
    end else begin
      // do nothing
    end
  end
endmodule
