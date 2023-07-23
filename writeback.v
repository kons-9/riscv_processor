module writeback (
    input is_writeback,
    input is_load,
    input [31:0] alu_out,
    input [31:0] loaddata,

    output we,
    output [31:0] rd_data
);
  assign we = is_writeback;
  assign rd_data = is_load ? loaddata : alu_out;

endmodule
