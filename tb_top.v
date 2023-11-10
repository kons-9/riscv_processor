module tb_top ();
  // test bench of top module

  reg clk;
  reg rstn;
  
  wire uart_tx;

  wire [31:0] pc = cpu_top.pc;
  wire [31:0] inst = cpu_top.inst;
  wire [31:0] regs [31:0] = cpu_top.regfile.regs; 

  cpu_top cpu_top (
      .clk(clk),
      .rstn(rstn),
      .uart_tx(uart_tx)
  );

  always begin
    #5 clk = !clk;
  end

  initial begin
    $dumpfile("tb_top.vcd");
    $dumpvars(0, tb_top); 
    #1 clk = 0;
    rstn = 0;
    #100 rstn = 1;

    repeat (10) begin
      $display("pc: %d", cpu_top.pc);
      $display("alu_out: %b", cpu_top.alu_out);
      #10;
    end

    repeat (10000) begin
      #10;
    end

    $display();
    // ra register
    $display("ra: %b", cpu_top.regfile.regs[1]);
    // a5 register
    $display("a5: %b", cpu_top.regfile.regs[15]);
    // x28 register
    $display("x28: %b", cpu_top.regfile.regs[28]);
    $finish;

  end
endmodule
