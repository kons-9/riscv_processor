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
  integer fd;

  always @(posedge clk) begin
    // expected output like this:
    // 0xcc24: 0x81010113 # x02 = 0x0001f810
    // 0xcc28: 0x00001737 # x14 = 0x00001000
    // 0xcc2c: 0x7e112623 # (no destination); mem[0x0001fffc] <- 0x0000808c
    // 0xcc30: 0x7e812423 # (no destination); mem[0x0001fff8] <- 0x00000000
    // 0xa2d8: 0x7707a503 # x10 = 0x00000000;      0x00000000 <- mem[0x00010770]
    
    if (cpu_top.is_store) begin
        $fwrite(fd, "0x%04x: 0x%08x # (no destination); mem[0x%08x] <- 0x%08x\n", cpu_top.pc, cpu_top.inst, cpu_top.alu_out, cpu_top.rs2_data);
    end else if (cpu_top.is_load) begin
        $fwrite(fd, "0x%04x: 0x%08x # x%02d = 0x%08x;      0x%08x <- mem[0x%08x]\n", cpu_top.pc, cpu_top.inst, cpu_top.rd, cpu_top.rd_data, cpu_top.rd_data, cpu_top.alu_out);
    end else if (cpu_top.is_writeback) begin
        $fwrite(fd, "0x%04x: 0x%08x # x%02d = 0x%08x\n", cpu_top.pc, cpu_top.inst, cpu_top.rd, cpu_top.rd_data);
    end else begin
        $fwrite(fd, "0x%04x: 0x%08x # (no destination)\n", cpu_top.pc, cpu_top.inst);
    end
  end

  initial begin
    $dumpfile("tb_top.vcd");
    $dumpvars(0, tb_top); 
    fd = $fopen("output.trace", "w");

    #1 clk = 0;
    rstn = 0;
    #20 rstn = 1;

    repeat (100000) begin
      #10;
    end
    $finish;

  end
endmodule
