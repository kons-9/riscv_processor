`include "define.v"

module alu (
    input [2:0] alu_op,
    input [31:0] in1,
    input [31:0] in2,
    input [4:0] shift,
    input is_sub,
    input is_sra,
    input use_raw_imm,

    output [31:0] out
);

  assign out = use_raw_imm ? in2 : alu_out(alu_op, in1, in2, is_sub, is_sra, shift);

  function [31:0] alu_out;
    input [2:0] alu_op;
    input [31:0] in1;
    input [31:0] in2;
    input is_sub;
    input is_sra;
    input [4:0] shift;

    begin
      case (alu_op)
        `ALU_ADD: begin
          if (is_sub) begin
            alu_out = in1 - in2;
          end else begin
            alu_out = in1 + in2;
          end
        end
        `ALU_SLL: begin
          alu_out = in1 << shift;
        end
        `ALU_SLT:  alu_out = ($signed(in1) < $signed(in2)) ? 1 : 0;
        `ALU_SLTU: alu_out = ($unsigned(in1) < $unsigned(in2)) ? 1 : 0;
        `ALU_XOR:  alu_out = in1 ^ in2;
        `ALU_SRL: begin
          if (is_sra) begin
            // arithmetic shift
            alu_out = $signed(in1) >>> shift;
          end else begin
            // logical shift
            alu_out = (in1) >> shift;
          end
        end
        `ALU_OR:   alu_out = in1 | in2;
        `ALU_AND:  alu_out = in1 & in2;
        default:   alu_out = 0;
      endcase
    end
  endfunction

endmodule

