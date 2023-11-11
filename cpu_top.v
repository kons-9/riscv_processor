`include "define.v"
module cpu_top (
    input clk,
    input rstn,
    output wire uart_tx
);

  //////////////////////////////////////////////////
  // fetch stage
  // //////////////////////////////////////////////
  reg [31:0] pc;
  wire [31:0] pc_next;

  always @(posedge clk) begin
    pc <= pc_next;
  end

  wire is_branch_jump;
  wire is_ja;
  wire [31:0] alu_out;
  wire enable_pc_update_from_csr;
  wire [31:0] next_csr_pc;

  wire [31:0] pc_plus4;

  gen_next_pc gen_next_pc (
      .rstn(rstn),
      .is_jump_operation(is_branch_jump | is_ja),
      .jump_addr(alu_out),
      .pc(pc),
      .enable_pc_update_from_csr(enable_pc_update_from_csr),
      .csr_pc(next_csr_pc),

      .pc_next (pc_next),
      .pc_plus4(pc_plus4)
  );

  wire [31:0] inst;
  fetch fetch (
      .clk(clk),
      .pc (pc),

      .inst(inst)
  );

  ////////////////////////////////////////////////
  // decode stage && register read
  ////////////////////////////////////////////////

  wire [4:0] rs1;
  wire [4:0] rs2;
  wire [4:0] rd;
  wire [31:0] imm;
  wire is_store;
  wire is_load;
  wire is_writeback;
  wire [2:0] alu_op;
  wire [2:0] csr_op;
  wire [2:0] ls_op;
  wire alu_in1_use_pc;
  wire alu_in2_use_imm;
  wire use_raw_imm;
  wire is_sub;
  wire is_sra;
  wire is_r_type;
  wire [4:0] shamt;
  wire [2:0] branch_op;
  wire is_branch;
  wire store_pc4;

  wire is_system;

  decode decode (
      .inst(inst),

      .rs1(rs1),
      .rs2(rs2),
      .rd(rd),
      .imm(imm),
      .is_store(is_store),
      .is_load(is_load),
      .is_writeback(is_writeback),
      .alu_op(alu_op),
      .csr_op(csr_op),
      .ls_op(ls_op),
      .alu_in1_use_pc(alu_in1_use_pc),
      .alu_in2_use_imm(alu_in2_use_imm),
      .use_raw_imm(use_raw_imm),
      .is_sub(is_sub),
      .is_sra(is_sra),
      .is_r_type(is_r_type),
      .shamt(shamt),
      .branch_op(branch_op),
      .is_branch(is_branch),
      .store_pc4(store_pc4),
      .is_ja(is_ja),
      .is_system(is_system)
  );

  wire [31:0] rs1_data;
  wire [31:0] rs2_data;
  wire [31:0] rd_data;
  wire [31:0] alu_in1;
  wire [31:0] alu_in2;
  wire [4:0] shift;
  wire we;

  regfile regfile (
      .clk(clk),
      .rstn(rstn),
      .we(we),
      .rs1(rs1),
      .rs2(rs2),
      .rd(rd),
      .rd_data(rd_data),
      .alu_in1_use_pc(alu_in1_use_pc),
      .alu_in2_use_imm(alu_in2_use_imm),
      .pc(pc),
      .imm(imm),
      .is_r_type(is_r_type),
      .shamt(shamt),

      .rs1_data(rs1_data),
      .rs2_data(rs2_data),
      .alu_in1(alu_in1),
      .alu_in2(alu_in2),
      .shift(shift)
  );


  //////////////////////////////////////////////////
  // execute stage
  // //////////////////////////////////////////////

  alu alu (
      .alu_op(alu_op),
      .in1(alu_in1),
      .in2(alu_in2),
      .shift(shift),
      .is_sub(is_sub),
      .is_sra(is_sra),
      .use_raw_imm(use_raw_imm),

      .out(alu_out)
  );

  branch_conditional branch_conditional (
      .is_branch(is_branch),
      .branch_op(branch_op),
      .rs1_data(rs1_data),
      .rs2_data(rs2_data),

      .is_branch_jump(is_branch_jump)
  );

  ////////////////////////////////////////////////
  // memory stage
  // ////////////////////////////////////////////

  // mem[rs1 + offset(imm)] -> rd
  wire is_illegal;
  wire [31:0] hardware_counter;

  wire uart_we;
  wire [31:0] loaddata;

  mem mem (
      .clk(clk),
      .is_store(is_store),
      .is_illegal(is_illegal),
      .mem_addr(alu_out),
      .wdata(rs2_data),
      .store_load_type(ls_op),
      .hardware_counter(hardware_counter),

      .loaddata(loaddata),
      .uart_we(uart_we)
  );

  //////////////////////////////////////////////////
  // writeback stage
  // //////////////////////////////////////////////

  wire [31:0] csr_data;
  wire is_write_back_from_csr;
  // set we, rd_data
  writeback writeback (
      .is_writeback(is_writeback),
      .is_load(is_load),
      .loaddata(loaddata),
      .alu_out(alu_out),
      .pc_plus4(pc_plus4),
      .csr_data(csr_data),
      .csr_writeback(is_write_back_from_csr),
      .is_illegal(is_illegal),
      .store_pc4(store_pc4),

      .we(we),
      .rd_data(rd_data)
  );

  ////////////////////////////////////////////////
  // csr
  ////////////////////////////////////////////////

  csr csr (
      .clk(clk),
      .rstn(rstn),
      .csr_addr(imm[11:0]),
      .rs_addr(rs1),
      .csr_wdata(rs1_data),
      .csr_op(csr_op),
      .is_system(is_system),
      .funct12(imm[11:0]),
      .csr_destreg_addr(rd),
      .uimm(rs1),
      .illegal_instruction(1'b0),  // future work
      .access_fault(31'b0),  // future work
      .pc(pc),
      // output
      .csr_out(csr_data),
      .is_illegal(is_illegal),
      .write_back(is_write_back_from_csr),
      .next_csr_pc(next_csr_pc),
      .enable_pc_update_from_csr(enable_pc_update_from_csr)
  );

  ////////////////////////////////////////////////
  // uart
  // ////////////////////////////////////////////
  //
  wire [7:0] uart_data = rs2_data[7:0];
 
  uart uart0(
     .uart_tx(uart_tx),     // UART transmit wire
     // Inputs
     .uart_wr_i(uart_we),   // Raise to transmit byte
     .uart_dat_i(uart_data),  // 8-bit data
     .sys_clk_i(clk),   // System clock, 100 MHz
     .sys_rstn_i(rstn)    // System reset
  );

  ////////////////////////////////////////////////
  // hardware counter
  // ////////////////////////////////////////////
  //

  hardware_counter hardware_counter_0 (
      .clk_ip(clk),
      .rstn_ip(rstn),
      .counter_op(hardware_counter)
  );



endmodule
