module regfile (
    input clk,
    input rst,
    input we,
    input [4:0] rs1,
    input [4:0] rs2,
    input [4:0] rd,
    input [31:0] rd_data,
    output [31:0] rs1_data,
    output [31:0] rs2_data
);

  reg [31:0] regs[32];

  assign rs1_data = regs[rs1];
  assign rs2_data = regs[rs2];

  // write is synchronous
  always @(posedge clk) begin
    if (rst) begin
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
