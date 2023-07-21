// `include "define.v"

module alu (
    input [2:0] alu_op,
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] out
);

  always @* begin
    case (alu_op)
      `ALU_ADD:  out = a + b;
      `ALU_SLL:  out = a << b;
      `ALU_SLT:  out = (a < b) ? 1 : 0;
      `ALU_SLTU: out = (a < b) ? 1 : 0;
      `ALU_XOR:  out = a ^ b;
      `ALU_SRL:  out = a >> b;
      `ALU_OR:   out = a | b;
      `ALU_AND:  out = a & b;
      default:   out = 0;
    endcase
  end

endmodule

