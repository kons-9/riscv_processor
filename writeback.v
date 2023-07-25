module writeback (
    input is_writeback,
    input is_load,
    input [31:0] alu_out,
    input [31:0] loaddata,
    input [2:0] opcode_type,
    input [31:0] pc_plus4,

    output we,
    output [31:0] rd_data
);
  assign we = is_writeback;
  assign rd_data = opcode_type == `TYPE_J ? pc_plus4 : is_load ? loaddata : alu_out;

endmodule
