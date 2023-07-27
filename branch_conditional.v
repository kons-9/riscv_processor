`include "define.v"
module branch_conditional (
    input [2:0] branch_op,
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    output wire is_branch_jump
);
  assign is_branch_jump = func_branch_conditional(branch_op, rs1_data, rs2_data);

  function func_branch_conditional;
    input [2:0] branch_op;
    input [31:0] rs1_data;
    input [31:0] rs2_data;
    begin
      case (branch_op)
        `BRANCH_BEQ: func_branch_conditional = (rs1_data == rs2_data);
        `BRANCH_BNE: func_branch_conditional = (rs1_data != rs2_data);
        `BRANCH_BLT: func_branch_conditional = ($signed(rs1_data) < $signed(rs2_data));
        `BRANCH_BGE: func_branch_conditional = ($signed(rs1_data) >= $signed(rs2_data));
        `BRANCH_BLTU: func_branch_conditional = ($unsigned(rs1_data) < $unsigned(rs2_data));
        `BRANCH_BGEU: func_branch_conditional = (rs1_data >= rs2_data);
        default: func_branch_conditional = 1'b0;
      endcase
    end
  endfunction
endmodule
