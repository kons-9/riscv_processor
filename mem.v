module mem (
    input clk,
    input is_store,
    input [13:0] addr,
    input [31:0] wdata,
    input [2:0] store_load_type,
    output [31:0] loaddata
);
  reg [31:0] mem[0:32767];

  parameter FILENAME = "/home/wslmtl/Documents/riscv/bin/mem.hex";
  initial begin
    $readmemh(FILENAME, mem);
  end
  wire [31:0] data;
  assign data= mem[addr];

  assign loaddata = get_loaddata(data, store_load_type);

  function [31:0] get_loaddata;
    input [31:0] data;
    input [2:0] store_load_type;
    begin
      case (store_load_type)
        `LOAD_LB: get_loaddata = {data[7:0], {24{data[7]}}};
        `LOAD_LH: get_loaddata = {data[15:0], {16{data[15]}}};
        `LOAD_LW: get_loaddata = data;
        default:  get_loaddata = data;
      endcase
    end
  endfunction

  always @(negedge clk) begin
    if (is_store) begin
      case (store_load_type)
        `STORE_SB: mem[addr] <= wdata[7:0];
        `STORE_SH: mem[addr] <= wdata[15:0];
        `STORE_SW: mem[addr] <= wdata[31:0];
        default:   mem[addr] <= wdata;
      endcase
    end
  end
endmodule
