module decode (
    input [31:0] inst,

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
    output is_store
);
  assign opcode = inst[6:0];
  assign rd = inst[11:7];
  assign funct3 = inst[14:12];
  assign rs = inst[19:15];
  assign rs2 = inst[24:20];
  assign funct7 = inst[31:25];
  assign opcode_type = get_type(opcode);
  assign imm = decide_imm(opcode_type);
  assign is_r_type = (opcode_type == `TYPE_R);
  assign is_store = (opcode_type == `TYPE_S);

  wire [31:0] imm_i;
  wire [31:0] imm_s;
  wire [31:0] imm_b;
  wire [31:0] imm_u;
  wire [31:0] imm_j;

  assign imm_i = {{20{inst[31]}}, inst[31:20]};
  assign imm_s = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  assign imm_b = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
  assign imm_u = {inst[31:12], 12'b0};
  assign imm_j = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};

  function static [31:0] decide_imm;
    input [2:0] opcode_type;
    begin
      case (opcode_type)
        `TYPE_R: decide_imm = 0;
        `TYPE_I: decide_imm = imm_i;
        `TYPE_S: decide_imm = imm_s;
        `TYPE_B: decide_imm = imm_b;
        `TYPE_U: decide_imm = imm_u;
        `TYPE_J: decide_imm = imm_j;
        default: decide_imm = 0;
      endcase
    end
  endfunction

  function static [2:0] get_type;
    input [6:0] opcode;
    begin
      case (opcode)
        `OPCODE_LUI: get_type = `TYPE_U;
        `OPCODE_AUIPC: get_type = `TYPE_U;
        `OPCODE_OP: get_type = `TYPE_R;
        `OPCODE_OP_IMM: get_type = `TYPE_I;
        `OPCODE_JAL: get_type = `TYPE_J;
        `OPCODE_JALR: get_type = `TYPE_I;
        `OPCODE_BRANCH: get_type = `TYPE_B;
        `OPCODE_LOAD: get_type = `TYPE_I;
        `OPCODE_STORE: get_type = `TYPE_S;
        `OPCODE_MISC_MEM: get_type = `TYPE_I;
        `OPCODE_SYSTEM: get_type = `TYPE_I;
        default: get_type = `TYPE_I;
      endcase
    end
  endfunction

endmodule

