module gen_next_pc (
    input rst,
    input is_jump,
    input is_branch_jump,
    input is_jal,
    input is_jalr,
    input is_branch,
    input [31:0] alu_out,
    input [31:0] pc,

    output wire [31:0] pc_next,
    output wire [31:0] pc_plus4
);
  // todo branch prediction

  assign jump_addr = alu_out;
  assign pc_plus4  = pc + 8'h04;
  assign pc_next   = func_next_pc(rst, is_jump, jump_addr, pc);

  function [31:0] func_next_pc;
    input rst;
    input is_jump;
    input [31:0] jump_addr;
    input [31:0] pc;
    begin
      if (rst) begin
        func_next_pc = 8'h00;
      end else if (is_jump && (is_jal | is_jalr | (is_branch & is_branch_jump))) begin
        func_next_pc = jump_addr;
      end else begin
        func_next_pc = pc_plus4;
      end
    end
  endfunction
endmodule
