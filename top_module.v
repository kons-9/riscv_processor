`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/09/13 16:33:03
// Design Name:
// Module Name: top_module
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////


module top_module(
    input sysclk,
    input [7:0] sw,
    input [7:0] cpu_resetn,
    output [7:0] led,
    output wire uart_tx
    );

    cpu_top cpu_top0 (
        .clk(sysclk),
        .rstn(cpu_resetn),
        .uart_tx(uart_tx)
    );


endmodule
