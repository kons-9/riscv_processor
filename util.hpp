#pragma once

#include "Vcpp_cpu_top.h"
#include <string>
#include <verilated.h>

#define BASEPATH "/home/kons9/Documents/TA/b3exp/benchmarks"

#include <verilated_heavy.h>
// <?xml version='1.0' encoding='utf-8'?>
// <Config>
//   <MaxTestCycles>1000</MaxTestCycles>
//   <RegisterValues>
//       <R0>0x00000000</R0>
//       ...
//       <R31>0x00000000</R31>
//       <PC>0x00008130</PC>
//   </RegisterValues>
// </Config>
//
static std::string to_8digit_hex(const IData x) {
  char buf[9];
  sprintf(buf, "%08X", x);
  return std::string(buf);
}

static void eprintf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

static std::string to_xml(const IData pc, const IData reg[32]) {
  std::string ret = "";
  ret += "<?xml version='1.0' encoding='utf-8'?>\n";
  ret += "<Config>\n";
  ret += "  <MaxTestCycles>1000</MaxTestCycles>\n";
  ret += "  <RegisterValues>\n";
  for (int i = 0; i < 32; i++) {
    // 8桁の16進数で出力
    ret += "      <R" + std::to_string(i) + ">0x" + to_8digit_hex(reg[31 - i]) +
           "</R" + std::to_string(i) + ">\n";
  }
  ret += "      <PC>0x" + to_8digit_hex(pc) + "</PC>\n";
  ret += "  </RegisterValues>\n";
  ret += "</Config>\n";
  return ret;
}

static std::string trace(const IData pc, const CData rs1_addr,
                         const IData rs1_data, const CData rs2_addr,
                         const IData rs2_data, const CData rd_addr,
                         const IData rd_data, const IData imm,
                         const CData opcode, const CData funct3,
                         const CData funct7) {
  // todo
  return "";
};
