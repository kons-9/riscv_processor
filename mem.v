module mem (
    input clk,
    input is_store,
    input is_illegal,
    input [16:0] addr,
    input [31:0] wdata,
    input [2:0] store_load_type,
    output [31:0] loaddata
);
  reg [31:0] mem[0:65536];

  parameter FILENAME = "/Users/gotos/Documents/b3exp/benchmarks/Coremark/data.hex";
  initial begin
    $readmemh(FILENAME, mem);
  end
  wire [31:0] data;
  assign data = mem[addr];

  assign loaddata = get_loaddata(data, store_load_type);

  function [31:0] get_loaddata;
    input [31:0] data;
    input [2:0] store_load_type;
    begin
      case (store_load_type)
        `LOAD_LB:  get_loaddata = {{24{data[7]}}, data[7:0]};
        `LOAD_LH:  get_loaddata = {{16{data[15]}}, data[15:0]};
        `LOAD_LW:  get_loaddata = data;
        `LOAD_LBU: get_loaddata = {{24{1'b0}}, data[7:0]};
        `LOAD_LHU: get_loaddata = {{16{1'b0}}, data[15:0]};
        default:   get_loaddata = data;
      endcase
    end
  endfunction

  always @(negedge clk) begin
    if (!is_illegal && is_store) begin
      case (store_load_type)
        `STORE_SB: mem[addr][7:0] <= wdata[7:0];
        `STORE_SH: mem[addr][15:0] <= wdata[15:0];
        `STORE_SW: mem[addr] <= wdata;
        default:   mem[addr] <= wdata;
      endcase
    end
  end
endmodule
