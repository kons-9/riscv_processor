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

`define COREMARKSYN

module top_module(
    input sysclk,
    input cpu_resetn,
    output wire uart_tx
    );

    cpu_top cpu_top0 (
        .clk(sysclk),
        .rstn(cpu_resetn),
        .uart_tx(uart_tx)
    );
endmodule
