module fetch (
    input clk,
    input [7:0] pc,

    output [31:0] inst,
    output wire is_jump
);
  instbram instbram (
      .clk (clk),
      .addr(pc),
      .inst(inst)
  );

  assign is_jump = (inst[6:0] == 7'b110xx11);

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
