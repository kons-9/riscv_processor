// riscv-previleged

// Previleed level
`define PREV_USER 2'b00
`define PREV_SUPERVISOR 2'b01
`define PREV_MACHINE 2'b11

// decode opcode
`define OPCODE_LUI 7'b0110111
`define OPCODE_AUIPC 7'b0010111
`define OPCODE_OP 7'b1101111
`define OPCODE_OP_IMM 7'b0010011
`define OPCODE_JAL 7'b1101111
`define OPCODE_JALR 7'b1100111
`define OPCODE_BRANCH 7'b1100011
`define OPCODE_LOAD 7'b0000011
`define OPCODE_STORE 7'b0100011
// fence
`define OPCODE_MISC_MEM 7'b0001111
// ecall, ebreak and priviledged
`define OPCODE_SYSTEM 7'b1110011

// decode type
`define TYPE_R 3'b000
`define TYPE_I 3'b001
`define TYPE_S 3'b010
`define TYPE_B 3'b011
`define TYPE_U 3'b100
`define TYPE_J 3'b101

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

// csr
`define MSTATUS 12'h300
`define MISA 12'h301
`define MEDELEG 12'h302
`define MIDELEG 12'h303
`define MIE 12'h304
`define MTVEC 12'h305
`define MSCRATCH 12'h340
`define MEPC 12'h341
`define MCAUSE 12'h342
`define MTVAL 12'h343
`define MIP 12'h344

// mstatus
`define MSTATUS_MIE 3
`define MSTATUS_MPIE 7

