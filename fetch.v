
module fetch (
    input clk,
    input [31:0] pc,

    output [31:0] inst
);

  wire [7:0] addr;
  assign addr = pc[7:0];
  instbram instbram (
      .clk (clk),
      .addr(pc),
      .inst(inst)
  );

endmodule

module instbram (
    input clk,
    input [31:0]addr,
    output reg [31:0] inst
);
  reg [31:0] mem[0:31999];
  // reg [31:0] mem[0:16383];
//  parameter FILENAME= "C:\Users\gotos\Documents\riscv_processor\src\fib.hex";
  parameter FILENAME= "/Users/gotos/Documents/b3exp/benchmarks/tests/Coremark/code.hex";
  integer i;
  initial begin
    // initialize memory to zero
//    for (i = 0; i < 16384; i = i + 1) begin
//      mem[i] = 0;
//    end
    $readmemh(FILENAME, mem);
  end
  wire [31:0]mem_addr = addr >> 2;
  always @(*) begin
    // inst <= 32'h074000EF;
    inst <= mem[mem_addr];
  end

endmodule
