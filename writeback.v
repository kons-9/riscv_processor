module writeback (
    input we,
    input [4:0] rd,
    input [31:0] alu_out,
    input [31:0] loaddata,

    output [31:0] rd_data
);
endmodule
