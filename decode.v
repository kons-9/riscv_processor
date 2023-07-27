module decode (
    input [31:0] inst,
    input is_jump,

    output [6:0] opcode,
    output [4:0] rs,
    output [4:0] rs2,
    output [4:0] rd,
    output [2:0] funct3,
    output [6:0] funct7,
    output [31:0] imm,
    output [4:0] shamt,
    output [2:0] opcode_type,
    output is_r_type,
    output is_store,
    output is_load,
    output is_writeback,
    output use_adder,
    output use_pc
);
  assign opcode = inst[6:0];
  assign rd = inst[11:7];
  assign funct3 = inst[14:12];
  assign rs = inst[19:15];
  assign rs2 = inst[24:20];
  assign funct7 = inst[31:25];
  assign {is_load, is_store, is_writeback, use_adder, opcode_type} = get_opcode_info(opcode);
  assign imm = decide_imm(opcode_type, inst);
  assign is_r_type = (opcode_type == `TYPE_R);
  assign shamt = inst[24:20];

  wire [31:0] imm_i;
  wire [31:0] imm_s;
  wire [31:0] imm_b;
  wire [31:0] imm_u;
  wire [31:0] imm_j;

  function [31:0] decide_imm;
    input [2:0] opcode_type;
    input [31:0] inst;
    begin
      case (opcode_type)
        `TYPE_R: decide_imm = 0;
        `TYPE_I: decide_imm = {{20{inst[31]}}, inst[31:20]};
        `TYPE_S: decide_imm = {{20{inst[31]}}, inst[31:25], inst[11:7]};
        `TYPE_B: decide_imm = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
        `TYPE_U: decide_imm = {inst[31:12], 12'b0};
        `TYPE_J: decide_imm = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
        default: decide_imm = 0;
      endcase
    end
  endfunction

  // [ is_load , is_store, is_writeback, use_adder, type] ]
  function [6:0] get_opcode_info;
    input [6:0] opcode;
    begin
      case (opcode)
        `OPCODE_LUI: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b0, `TYPE_U};
        `OPCODE_AUIPC: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b0, `TYPE_U};
        `OPCODE_OP: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b0, `TYPE_R};
        `OPCODE_OP_IMM: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b0, `TYPE_I};
        `OPCODE_JAL: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b1, `TYPE_J};
        `OPCODE_JALR: get_opcode_info = {1'b0, 1'b0, 1'b1, 1'b1, `TYPE_J};
        `OPCODE_BRANCH: get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b1, `TYPE_B};
        `OPCODE_LOAD: get_opcode_info = {1'b1, 1'b0, 1'b1, 1'b1, `TYPE_I};
        `OPCODE_STORE: get_opcode_info = {1'b0, 1'b1, 1'b0, 1'b1, `TYPE_S};
        `OPCODE_MISC_MEM: get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
        `OPCODE_SYSTEM: get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
        default: get_opcode_info = {1'b0, 1'b0, 1'b0, 1'b0, `TYPE_I};
      endcase
    end
  endfunction

endmodule

