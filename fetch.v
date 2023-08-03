`include "filename.v"
module fetch (
    input clk,
    input [31:0] pc,

    output [31:0] inst,
    output wire is_jump,
    output wire is_jal,
    output wire is_jalr,
    output wire is_branch
);

  wire [7:0] addr;
  assign addr = pc[7:0];
  instbram instbram (
      .clk (clk),
      .addr(pc[7:0]),
      .inst(inst)
  );

  // for branch prediction
  // assign is_jump = (inst[6:0] == 7'b110xx11);
  assign is_jump = (inst[1:0] == 2'b11 && inst[6:4] == 3'b110);
  assign is_jal = (inst[3] & 1);
  assign is_jalr = (inst[2] & 1);
  assign is_branch = (~is_jal & ~is_jalr);

endmodule

module instbram (
    input clk,
    input [7:0] addr,
    output reg [31:0] inst
);
  reg [31:0] mem[0:16383];
  // reg [31:0] mem[0:16383];

  integer i;
  initial begin
    // initialize memory to zero
    for (i = 0; i < 16384; i = i + 1) begin
      mem[i] = 0;
    end
    $readmemh(FILENAME, mem);
  end
  always @(*) begin
    // inst <= 32'h074000EF;
    inst <= mem[addr>>2];
  end

endmodule
