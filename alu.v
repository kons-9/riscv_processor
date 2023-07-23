// `include "define.v"

module alu (
    input [2:0] alu_op,
    input [31:0] in1,
    input [31:0] in2,
    input [6:0] funct7,
    input [4:0] shamt,
    input is_r_type,

    output [31:0] out
);
  wire is_sub_or_sra = funct7[6];
  assign out = alu_out(alu_op, in1, in2, is_sub_or_sra, is_r_type);

  function static [31:0] alu_out;
    input [2:0] alu_op;
    input [31:0] in1;
    input [31:0] in2;
    input is_sub_or_sra;
    input is_r_type;

    begin
      case (alu_op)
        `ALU_ADD: begin
          if (is_r_type && is_sub_or_sra) begin
            alu_out = in1 - in2;
          end else begin
            alu_out = in1 + in2;
          end
        end
        `ALU_SLL: begin
          // todo: use one operator
          if (is_r_type) alu_out = in1 << shamt;
          else alu_out = in1 << in2;
        end
        `ALU_SLT:  alu_out = (in1 < in2) ? 1 : 0;
        `ALU_SLTU: alu_out = (in1 < in2) ? 1 : 0;
        `ALU_XOR:  alu_out = in1 ^ in2;
        `ALU_SRL: begin
          if (is_sub_or_sra) begin
            // arithmetic shift
            if (is_r_type) alu_out = (in1) >>> shamt;
            else alu_out = (in1) >>> in2;
          end else begin
            // logical shift
            if (is_r_type) alu_out = (in1) >> shamt;
            else alu_out = (in1) >> in2;
          end
        end
        `ALU_OR:   alu_out = in1 | in2;
        `ALU_AND:  alu_out = in1 & in2;
        default:   alu_out = 0;
      endcase
    end
  endfunction

endmodule

