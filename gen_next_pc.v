module gen_next_pc (
    input rst,
    input is_jump,
    input [7:0] jump_addr,
    input [7:0] pc,

    output wire [7:0] pc_next,
    output wire [7:0] pc_plus4
);
  // todo branch prediction

  assign pc_plus4 = pc + 8'h04;
  assign pc_next  = func_next_pc(rst, is_jump, jump_addr, pc);

  function [7:0] func_next_pc;
    input rst;
    input is_jump;
    input [7:0] jump_addr;
    input [7:0] pc;
    begin
      if (rst) begin
        func_next_pc = 8'h00;
      end else if (is_jump) begin
        func_next_pc = jump_addr;
      end else begin
        func_next_pc = pc_plus4;
      end
    end
  endfunction
endmodule
