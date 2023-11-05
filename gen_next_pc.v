module gen_next_pc (
    input rst,
    input is_jump,
    input is_branch_jump,
    input is_jal,
    input is_jalr,
    input is_branch,
    input [31:0] alu_out,
    input [31:0] pc,
    input enable_pc_update_from_csr,
    input [31:0] csr_pc,

    output wire [31:0] pc_next,
    output wire [31:0] pc_plus4
);
  // todo branch prediction

  assign pc_plus4 = pc + 8'h04;
  assign pc_next = func_next_pc(
      rst, is_jump, is_jal, is_jalr, is_branch, is_branch_jump, alu_out, pc_plus4
  );

  function automatic [31:0] func_next_pc;
    input rst;
    input is_jump;
    input is_jal;
    input is_jalr;
    input is_branch;
    input is_branch_jump;
    input [31:0] jump_addr;
    input [31:0] pc_plus4;
    begin
      if (rst) begin
        func_next_pc = 32'h00008000;
      end else if (enable_pc_update_from_csr) begin
        func_next_pc = csr_pc;
      end else if (is_jump && (is_jal | is_jalr | (is_branch & is_branch_jump))) begin
        func_next_pc = jump_addr;
      end else begin
        func_next_pc = pc_plus4;
      end
    end
  endfunction
endmodule
