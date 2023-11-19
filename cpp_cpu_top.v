module cpp_cpu_top (
    input clk,
    input rstn,
    output wire uart_tx,
    output wire [31:0] pc,
    output wire [31:0] inst,
    output wire [31:0] regfile[0:31],
    output wire [31:0] rs1_data,
    output wire [31:0] rs2_data,
    output wire [31:0] rd_data,
    output wire [4:0] rd_addr,
    output wire [31:0] imm,
    output wire [31:0] mem_addr,
    output wire [31:0] mem_data,
    output wire [31:0] alu_out,
    output wire [4:0] rs1,
    output wire [4:0] rs2,
    output wire [4:0] rd,
    output wire [2:0] load_store_type,
    output wire is_load,
    output wire is_store,
    output wire is_stall,
    output wire is_writeback
);

  assign pc              = cpu_top0.pc;
  assign regfile         = cpu_top0.regfile.regs;
  assign rs1_data        = cpu_top0.rs1_data;
  assign rs2_data        = cpu_top0.rs2_data;
  assign rd_data         = cpu_top0.rd_data;
  assign rd_addr         = cpu_top0.rd;
  assign imm             = cpu_top0.imm;
  assign alu_out         = cpu_top0.alu_out;
  assign rs1             = cpu_top0.rs1;
  assign rs2             = cpu_top0.rs2;
  assign rd              = cpu_top0.rd;
  assign load_store_type = cpu_top0.ls_op;
  assign mem_addr        = cpu_top0.mem.mem_addr;
  assign mem_data        = cpu_top0.mem.wdata;
  assign inst            = cpu_top0.inst;
  assign is_load         = cpu_top0.is_load;
  assign is_store        = cpu_top0.is_store;
  assign is_stall        = cpu_top0.gen_next_pc.is_stall;
  assign is_writeback    = cpu_top0.is_writeback;

  cpu_top cpu_top0 (
      .clk(clk),
      .rstn(rstn),
      .uart_tx(uart_tx)
  );
endmodule
