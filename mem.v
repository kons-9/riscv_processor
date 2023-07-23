module mem (
    input clk,
    input is_store,
    input [13:0] addr,
    input [31:0] wdata,
    input [2:0] store_load_type,
    output [31:0] loaddata
);
  reg [31:0] mem[0:32767];

  initial begin
    parameter FILENAME = "/home/wslmtl/Documents/riscv/bin/mem.hex";
    $readmemh(FILENAME, mem);
  end
  assign loaddata = get_loaddata(addr, store_load_type);

  function [31:0] get_loaddata;
    input [13:0] addr;
    input [2:0] store_load_type;
    begin
      case (store_load_type)
        `LOAD_LB: get_loaddata = {mem[addr][7:0], {24{mem[addr][7]}}};
        `LOAD_LH: get_loaddata = {mem[addr][15:0], {16{mem[addr][15]}}};
        `LOAD_LW: get_loaddata = mem[addr];
        default:  get_loaddata = mem[addr];
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
