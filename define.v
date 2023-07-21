// riscv-previleged

// Previleed level
`define PREV_USER 2'b00
`define PREV_SUPERVISOR 2'b01
`define PREV_MACHINE 2'b11

// decode opcode
`define LUI 7'b0110111
`define AUIPC 7'0010111
`define OP 7'b1101111
`define OP_IMM 7'b0010011
`define JAL 7'b1101111
`define JALR 7'b1100111
`define BRANCH 7'b1100011
`define LOAD 7'b0000011
`define STORE 7'b0100011
// fence
`define MISC_MEM 7'b0001111
// ecall, ebreak and priviledged
`define SYSTEM 7'b1110011

// ALU operation
`define ALU_ADD 3'b000
`define ALU_SLL 3'b001
`define ALU_SLT 3'b010
`define ALU_SLTU 3'b011
`define ALU_XOR 3'b100
`define ALU_SRL 3'b101
`define ALU_OR 3'b110
`define ALU_AND 3'b111

// branch operation
`define BRANCH_BEQ 3'b000
`define BRANCH_BNE 3'b001
`define BRANCH_BLT 3'b100
`define BRANCH_BGE 3'b101
`define BRANCH_BLTU 3'b110
`define BRANCH_BGEU 3'b111

// load operation
`define LOAD_LB 3'b000
`define LOAD_LH 3'b001
`define LOAD_LW 3'b010
`define LOAD_LBU 3'b100
`define LOAD_LHU 3'b101

// store operation
`define STORE_SB 3'b000
`define STORE_SH 3'b001
`define STORE_SW 3'b010

