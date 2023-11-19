
module fetch (
    input clk,
    input [31:0] pc,

    output [31:0] inst
);

  wire [7:0] addr;
  assign addr = pc[7:0];
  instbram instbram (
      .clk (clk),
      .addr(pc),
      .inst(inst)
  );

endmodule
`ifndef BASEPATH
  // error if
  base path is not defined
`endif

module instbram (
    input clk,
    input [31:0]addr,
    output wire [31:0] inst
);
  reg [31:0] mem[0:31999];

  `ifdef COREMARKSYN
    parameter FILENAME= {`BASEPATH, "Coremark_for_Synthesis/code.hex"};
  `elsif COREMARK
    parameter FILENAME= {`BASEPATH, "Coremark/code.hex"};
  `elsif INTREGIMM
    parameter FILENAME= {`BASEPATH, "tests/IntRegImm/code.hex"};
  `elsif UART
    parameter FILENAME= {`BASEPATH, "tests/Uart/code.hex"};
  `elsif ZEROREGISTER
    parameter FILENAME= {`BASEPATH, "tests/ZeroRegister/code.hex"};
  `elsif CONTROLTRANSFER
    parameter FILENAME= {`BASEPATH, "tests/ControlTransfer/code.hex"};
  `elsif LOADANDSTORE
    parameter FILENAME= {`BASEPATH, "tests/LoadAndStore/code.hex"};
  `elsif INTREGREG
    parameter FILENAME= {`BASEPATH, "tests/IntRegReg/code.hex"};
  `else
      error occurd
    // parameter FILENAME= {`BATHPATH, "Coremark_for_Synthesis/code.hex"};
  `endif
  ;
  integer i;
  initial begin
    $readmemh(FILENAME, mem);
  end
  wire [31:0]mem_addr = addr >> 2;
  assign inst = mem[mem_addr];

endmodule
