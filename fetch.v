module fetch (
    input clk,
    input [31:0] pc,

    output [31:0] inst,
    output wire is_jump,
    output wire is_jal,
    output wire is_jalr,
    output wire is_branch
);
  instbram instbram (
      .clk (clk),
      .addr(pc),
      .inst(inst)
  );

  // for branch prediction
  assign is_jump = (inst[6:0] == 7'b110xx11);
  assign is_jal = (inst[3] == 1);
  assign is_jalr = (inst[2] == 1);
  assign is_branch = (~is_jal & ~is_jalr);

endmodule

module instbram (
    input clk,
    input [7:0] addr,
    output reg [31:0] inst
);
  reg [31:0] mem[0:16383];

  initial begin
    parameter FILENAME = "/home/wslmtl/Documents/riscv/bin/code.hex";
    $readmemh(FILENAME, mem);
  end
  always @(posedge clk) begin
    inst <= mem[addr>>2];
  end

endmodule
