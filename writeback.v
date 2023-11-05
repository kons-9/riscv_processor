module writeback (
    input is_writeback,
    input is_load,
    input [31:0] alu_out,
    input [31:0] loaddata,
    input [2:0] opcode_type,
    input [31:0] pc_plus4,
    input [31:0] csr_data,
    input csr_writeback,
    input is_illegal,

    output we,
    output [31:0] rd_data
);
  assign we = !is_illegal && (csr_writeback | is_writeback);
  assign rd_data = get_rd_data(csr_writeback, csr_data, opcode_type, is_load, loaddata, alu_out);

  function automatic [31:0] get_rd_data;
    input csr_writeback;
    input [31:0] csr_data;
    input [2:0] opcode_type;
    input is_load;
    input [31:0] loaddata;
    input [31:0] alu_out;
    begin
      if (csr_writeback) begin
        get_rd_data = csr_data;
      end else if (opcode_type == `TYPE_J || opcode_type == `TYPE_JR) begin
        get_rd_data = pc_plus4;
      end else if (is_load) begin
        get_rd_data = loaddata;
      end else begin
        get_rd_data = alu_out;
      end
    end
  endfunction

endmodule
