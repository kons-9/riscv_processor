module tb_top ();
  // test bench of top module

  reg clk;
  reg rst;

  wire [31:0] x28, x29,x30;
  assign x28 = cpu_top.regfile.regs[28];
  assign x29 = cpu_top.regfile.regs[29];
  assign x30 = cpu_top.regfile.regs[30];

  wire [31:0] mem_data;
  assign mem_data = cpu_top.mem.mem[2];

  cpu_top cpu_top (
      .clk(clk),
      .rst(rst)
  );

  always begin
    #5 clk = !clk;
  end

  initial begin
    $dumpfile("tb_top.vcd");
    $dumpvars(0, tb_top); 
    #1 clk = 0;
    rst = 1;
    #100 rst = 0;

    repeat (10) begin
      $display();
      $display("pc: %d", cpu_top.pc);
      $display("nextpc: %d", cpu_top.pc_next);
      $display("imm: %b", cpu_top.imm);
      $display("inst: %b", cpu_top.inst);
      $display("opcode: %b", cpu_top.opcode);
      $display("rs1_data: %b", cpu_top.rs1_data);
      $display("rs2_data: %b", cpu_top.rs2_data);
      $display("alu_out: %b", cpu_top.alu_out);
      #10;
    end

    repeat (10000) begin
      #10;
    end

    $display();
    // ra register
    $display("ra: %b", cpu_top.regfile.regs[1]);
    // a0 register
    $display("a0: %b", cpu_top.regfile.regs[10]);
    // x28 register
    $display("x28: %b", cpu_top.regfile.regs[28]);
    $finish;

  end
endmodule
