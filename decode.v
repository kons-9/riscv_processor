`include "define.v"

module decode (
    input [31:0] inst,

    output [4:0] rs1,
    output [4:0] rs2,
    output [4:0] rd,
    output [31:0] imm,
    output is_store,
    output is_load,
    output is_writeback,
    output [2:0] alu_op,
    output [2:0] csr_op,
    output [2:0] ls_op,
    output alu_in1_use_pc,
    output alu_in2_use_imm,
    output use_raw_imm,
    output is_sub,
    output is_sra,
    output is_r_type,
    output [4:0] shamt,
    output [2:0] branch_op,
    output is_branch,
    output store_pc4,
    output is_ja,

    // for system call
    output is_system
);

  wire [6:0]opcode = inst[6:0];
  assign rd = inst[11:7];
  wire [2:0] funct3 = inst[14:12];
  assign rs1 = inst[19:15];
  assign rs2 = inst[24:20];
  wire [6:0] funct7 = inst[31:25];
  assign shamt = inst[24:20];

  wire [2:0] opcode_type;
  wire is_jal;
  wire is_jalr;
  wire use_adder;

  assign {is_jal, is_jalr, is_branch, is_r_type, is_system, is_load, is_store, is_writeback, use_adder, alu_in1_use_pc, alu_in2_use_imm, opcode_type} = get_opcode_info(opcode);
  assign imm = get_imm(opcode_type, inst);


  assign alu_op = use_adder ? `ALU_ADD : funct3;
  assign csr_op = funct3;
  assign ls_op = funct3;

  assign use_raw_imm = (opcode == `OPCODE_LUI); 
  assign is_sub = is_r_type && funct7[5];
  assign is_sra = funct7[5];
  wire using_pc = (is_jal | is_branch);
  assign branch_op = funct3;

  assign store_pc4 = (is_jal | is_jalr);
  assign is_ja = store_pc4;

  // imm
  function [31:0] get_imm;
    input [2:0] opcode_type;
    input [31:0] inst;
    begin
      case (opcode_type)
        `TYPE_R: get_imm = {32{1'b0}};
        `TYPE_I: get_imm = {{20{inst[31]}}, inst[31:20]};
        `TYPE_S: get_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
        `TYPE_B: get_imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
        `TYPE_U: get_imm = {inst[31:12], 12'b0};
        `TYPE_J: get_imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
        default: get_imm = {32{1'b0}};
      endcase
    end
  endfunction

  // [ jal, jalr, bran, is_r_type, is_system, is_load , is_store, is_writeback, use_adder, alu_in1_use_pc, alu_in2_use_imm, opcode_type ]
  function [13:0] get_opcode_info;
    input [6:0] opcode;
    begin
      case (opcode)
        //                  get_opcode_info = {jal   jalr  bran  rtyp  sys   load  store wb    adder in1_  in2_  type   }};
        `OPCODE_LUI:        get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b1, 1'b0, 1'b1, `TYPE_U};
        `OPCODE_AUIPC:      get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b1, 1'b1, 1'b1, `TYPE_U};
        `OPCODE_OP:         get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, `TYPE_R};
        `OPCODE_OP_IMM:     get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b1, `TYPE_I};
        `OPCODE_JAL:        get_opcode_info = {1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b1, 1'b1, 1'b1, `TYPE_J};
        `OPCODE_JALR:       get_opcode_info = {1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b1, 1'b0, 1'b1, `TYPE_I};
        `OPCODE_BRANCH:     get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b1, 1'b1, `TYPE_B};
        `OPCODE_LOAD:       get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b1, 1'b1, 1'b0, 1'b1, `TYPE_I};
        `OPCODE_STORE:      get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b1, 1'b0, 1'b1, `TYPE_S};
        `OPCODE_MISC_MEM:   get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
        `OPCODE_SYSTEM:     get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
        default:            get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
      endcase
    end
  endfunction

endmodule

