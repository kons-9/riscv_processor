// riscv-previleged

// decode opcode
`define OPCODE_LUI 7'b0110111
`define OPCODE_AUIPC 7'b0010111
`define OPCODE_OP 7'b0110011
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

//////////////////////////////////////////////
// for csr
//////////////////////////////////////////////

// csr operation (funct3)
`define CSR_PRIV 3'b000
`define CSR_RW 3'b001
`define CSR_RS 3'b010
`define CSR_RC 3'b011
`define CSR_RWI 3'b101
`define CSR_RSI 3'b110
`define CSR_RCI 3'b111
// funct12
`define CSR_SRET 12'b000100000010
`define CSR_MRET 12'b001100000010
`define CSR_WFI 12'b000100000101
`define CSR_ECALL 12'b000000000000
`define CSR_EBREAK 12'b000000000001
`define CSR_SFENCE_VMA 12'b0001001xxxxx
`define CSR_SINVAL_VMA 12'b0001011xxxxx
`define CSR_SFENCE_W_INVAL 12'b000110100000
`define CSR_SFENCE_INVAL_IR 12'b000110100001

// csr restrict
`define CSR_READ_ONLY 2'b11 // csr[11:10]
`define CSR_IS_CUSTOM 2'b11 // csr[7:6]

// Previleed level csr[9:8]
`define CSR_PREV_USER 2'b00
`define CSR_PREV_SUPERVISOR 2'b01
`define CSR_PREV_MACHINE 2'b11

// csr register
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

// status
`define STATUS_MIE 3
`define STATUS_MPIE 7
`define STATUS_MPP 12:11

// exception
`define EXCEPTION_INSTRUCTION_ADDRESS_MISALIGNED 31'h0
`define EXCEPTION_INSTRUCTION_ACCESS_FAULT 31'h1
`define EXCEPTION_ILLEGAL_INSTRUCTION 31'h2
`define EXCEPTION_EBREAK 31'h3
`define EXCEPTION_LOAD_ADDRESS_MISALIGNED 31'h4
`define EXCEPTION_LOAD_ACCESS_FAULT 31'h5
`define EXCEPTION_STORE_ADDRESS_MISALIGNED 31'h6
`define EXCEPTION_STORE_ACCESS_FAULT 31'h7
`define EXCEPTION_ECALL_U 31'h8
`define EXCEPTION_ECALL_S 31'h9
`define EXCEPTION_ECALL_M 31'ha
`define EXCEPTION_INSTRUCTION_PAGE_FAULT 31'h12
`define EXCEPTION_LOAD_PAGE_FAULT 31'h13
`define EXCEPTION_STORE_PAGE_FAULT 31'h15


