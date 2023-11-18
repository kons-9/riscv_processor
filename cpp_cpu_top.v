module cpp_cpu_top (
    input clk,
    input rstn,
    output wire uart_tx,
    output wire [31:0] pc,
    output wire [31:0] regfile [0:31],
    output wire [31:0] rs1_data,
    output wire [31:0] rs2_data,
    output wire [31:0] imm,
    output wire [31:0] alu_out,
    output wire [ 4:0] rs1,
    output wire [ 4:0] rs2,
    output wire [ 4:0] rd
    );

    
    assign pc       = cpu_top0.pc;
    assign regfile  = cpu_top0.regfile.regs;
    assign rs1_data = cpu_top0.rs1_data;
    assign rs2_data = cpu_top0.rs2_data;
    assign imm      = cpu_top0.imm;
    assign alu_out  = cpu_top0.alu_out;
    assign rs1      = cpu_top0.rs1;
    assign rs2      = cpu_top0.rs2;
    assign rd       = cpu_top0.rd;

    cpu_top cpu_top0 (
        .clk(clk),
        .rstn(rstn),
        .uart_tx(uart_tx)
    );
endmodule
