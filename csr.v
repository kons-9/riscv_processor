`include "define.v"

module csr (
    input clk,
    input [11:0] csr_addr,
    input csr_we,
    input [31:0] csr_wdata,
    input [31:0] csr_rdata,

    output [31:0] csr_out
);
  reg [31:0] csr[0:4095];

  initial begin
    $readmemh("csr.mem", csr);
  end

  always @(negedge clk) begin
    if (csr_we) begin
      csr[csr_addr] <= csr_wdata;
    end
  end

  assign csr_out = csr[csr_addr];

  wire [31:0] mstatus;
  wire [31:0] mie;
  wire [31:0] mtvec;
  wire [31:0] mscratch;
  wire [31:0] mepc;
  wire [31:0] mcause;
  wire [31:0] mtval;
  wire [31:0] mip;

  assign mstatus = csr[`MSTATUS];
  assign mie = csr[`MIE];
  assign mtvec = csr[`MTVEC];
  assign mscratch = csr[`MSCRATCH];
  assign mepc = csr[`MEPC];
  assign mcause = csr[`MCAUSE];
  assign mtval = csr[`MTVAL];
  assign mip = csr[`MIP];

  wire global_mie = mstatus[`MSTATUS_MIE];
  // this value has old mie value
  wire mpie = mstatus[`MSTATUS_MPIE];

endmodule
