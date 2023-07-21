// top module
//
module cpu_top (
    input clk,
    input rst
);
  wire [7:0] pc;
  pc_counter pc_counter (
      .clk(clk),
      .rst(rst),
      .pc (pc)
  );

  wire [31:0] inst;
  instruction_memory instruction_memory (
      .clk (clk),
      .rst (rst),
      .pc  (pc),
      .inst(inst)
  );



endmodule
