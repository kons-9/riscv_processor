module tb_top ();
  // test bench of top module

  reg clk;
  reg rst;

  cpu_top cpu_top (
      .clk(clk),
      .rst(rst)
  );

  always_comb begin
    #5 clk = ~clk;
  end

  initial begin
    rst = 1;
    #10 rst = 0;

    repeat (100) begin
      $display("pc: %d", cpu_top.pc);
      $display("inst: %b", cpu_top.inst);
      #10;
    end

  end
endmodule
