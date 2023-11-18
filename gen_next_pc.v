module gen_next_pc (
    input rstn,
    input is_jump_operation,
    input [31:0] jump_addr,
    input [31:0] pc,
    input enable_pc_update_from_csr,
    input [31:0] csr_pc,
    input is_stall,

    output wire [31:0] pc_next,
    output wire [31:0] pc_plus4
);
  // todo branch prediction
  //
  assign pc_plus4 = pc + 'h04;
  assign pc_next = func_next_pc(
      rstn, 
      is_stall,
      pc,
      is_jump_operation,
      jump_addr,
      pc_plus4,
      enable_pc_update_from_csr,
      csr_pc
  );

  function automatic [31:0] func_next_pc;
    input rstn;
    input is_stall;
    input [31:0] pc;
    input is_jump;
    input [31:0] jump_addr;
    input [31:0] pc_plus4;
    input enable_pc_update_from_csr;
    input [31:0] csr_pc;

    begin
      if (!rstn) begin
        func_next_pc = 32'h00008000;
      end else if (is_stall) begin
        func_next_pc = pc;
      end else if (enable_pc_update_from_csr) begin
        func_next_pc = csr_pc;
      end else if (is_jump) begin
        func_next_pc = jump_addr;
      end else begin
        func_next_pc = pc_plus4;
      end
    end
  endfunction
endmodule
