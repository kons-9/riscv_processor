`include "define.v"
module mem (
    input clk,
    input is_store,
    input is_illegal,
    input [31:0] mem_addr,
    input [31:0] wdata,
    input [2:0] store_load_type,
    input [31:0] hardware_counter,

    output [31:0] loaddata,
    output uart_we
);
  reg [31:0] mem[0:65536];

  parameter FILENAME = "/Users/gotos/Documents/b3exp/benchmarks/Coremark/data.hex";
  initial begin
    $readmemh(FILENAME, mem);
  end

  wire [31:0] data;
  wire [16:0] addr = mem_addr >> 2;
  wire [1:0] addr_rem = mem_addr[1:0];

  wire is_hardware_counter = (mem_addr == `HARDWARE_COUNTER_ADDR) && (store_load_type == `LOAD_LW);

  assign data = get_data(mem[addr], addr_rem);
  assign loaddata = is_hardware_counter ? hardware_counter : get_loaddata(data, store_load_type);
  assign uart_we = (mem_addr == `UART_TX_ADDR) && is_store;

  function [31:0] get_data;
      input [31:0] raw_data;
      input [1:0] addr_rem;
      begin
        case (addr_rem)
          2'b00: get_data = raw_data[31:0];
          2'b01: get_data = {{8{raw_data[31]}}, raw_data[31:8]};
          2'b10: get_data = {{16{raw_data[31]}}, raw_data[31:16]};
          2'b11: get_data = {{24{raw_data[31]}}, raw_data[31:24]};
          default: get_data = raw_data;
        endcase
      end
  endfunction

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
    if (!is_illegal && is_store && !uart_we ) begin
      case ({store_load_type, addr_rem})
        {`STORE_SB, 2'b00}: mem[addr][7:0] <= wdata[7:0];
        {`STORE_SB, 2'b01}: mem[addr][15:8] <= wdata[7:0];
        {`STORE_SB, 2'b10}: mem[addr][23:16] <= wdata[7:0];
        {`STORE_SB, 2'b11}: mem[addr][31:24] <= wdata[7:0];

        {`STORE_SH, 2'b00}: mem[addr][15:0] <= wdata[15:0];
        {`STORE_SH, 2'b01}: mem[addr][23:8] <= wdata[15:0];
        {`STORE_SH, 2'b10}: mem[addr][31:16] <= wdata[15:0];

        {`STORE_SW, 2'b00}: mem[addr] <= wdata;
        default:   mem[addr] <= wdata;
      endcase
    end
  end
endmodule
