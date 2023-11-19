#pragma once

#include "Vcpp_cpu_top.h"
#include <string>
#include <verilated.h>

#define BASEPATH "/home/kons9/Documents/TA/b3exp/benchmarks"
// load operation
#define LOAD_LB 0b000
#define LOAD_LH 0b001
#define LOAD_LW 0b010
#define LOAD_LBU 0b100
#define LOAD_LHU 0b101
// store operation
#define STORE_SB 0b000
#define STORE_SH 0b001
#define STORE_SW 0b010

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
static std::string to_8digit_HEX(const IData x) {
  char buf[9];
  sprintf(buf, "%08X", x & 0xffffffff);
  return std::string(buf);
}
static std::string to_4digit_HEX(const IData x) {
  char buf[9];
  sprintf(buf, "%04X", x & 0xffff);
  return std::string(buf);
}
static std::string to_2digit_HEX(const IData x) {
  char buf[9];
  sprintf(buf, "%02X", x & 0xff);
  return std::string(buf);
}

static std::string to_8digit_hex(const IData x) {
  char buf[9];
  sprintf(buf, "%08x", x & 0xffffffff);
  return std::string(buf);
}
static std::string to_4digit_hex(const IData x) {
  char buf[9];
  sprintf(buf, "%04x", x & 0xffff);
  return std::string(buf);
}
static std::string to_2digit_hex(const IData x) {
  char buf[9];
  sprintf(buf, "%02x", x & 0xff);
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
    ret += "      <R" + std::to_string(i) + ">0x" + to_8digit_HEX(reg[31 - i]) +
           "</R" + std::to_string(i) + ">\n";
  }
  ret += "      <PC>0x" + to_8digit_HEX(pc) + "</PC>\n";
  ret += "  </RegisterValues>\n";
  ret += "</Config>\n";
  return ret;
}

static std::string mk_addr(const CData addr) {

  char buf[9];
  sprintf(buf, "%02d", addr);
  return std::string(buf);
}

static std::string trace(const IData pc, const IData inst, const CData rd_addr,
                         const IData rd_data, const CData is_store,
                         const CData is_load, const CData load_store_type,
                         const IData mem_addr, const IData mem_data,
                         const CData is_writeback) {
  // example: pc: inst # rd_addr = rd_data
  // 0xcca4: 0x00d785b3 # x11 = 0x0001f7a4
  // 0xcca8: 0x00412783 # x15 = 0x0001efc0;      0x0001efc0 <- mem[0x0001f794]
  // 0xccac: 0x05e10513 # x10 = 0x0001f7ee
  // 0xccb0: 0x7e07a223 # (no destination); mem[0x0001f7a4] <- 0x00000000
  // 0xccb4: 0x98cfe0ef # x01 = 0x0000ccb8
  // 0xae40: 0x00100793 # x15 = 0x00000001
  // 0xae44: 0x00f50023 # (no destination); mem[0x0001f7ee] <- 0x01
  // 0xae48: 0x00008067 # (no destination)
  // 0xcd28: 0x00f707b3 # x15 = 0x0001efc0
  // 0xcd2c: 0x00f12223 # (no destination); mem[0x0001f794] <- 0x0001efc0
  // 0xcd30: 0x7ec7a783 # x15 = 0x00000000;      0x00000000 <- mem[0x0001f7ac]
  // 0xcd34: 0x02a12e23 # (no destination); mem[0x0001f7cc] <- 0x00000007
  // 0xcd38: 0x32079863 # (no destination)
  // 0xcd3c: 0x00412783 # x15 = 0x0001efc0;      0x0001efc0 <- mem[0x0001f794]
  // 0xcd40: 0x7f079783 # x15 = 0x00000066;          0x0066 <- mem[0x0001f7b0]
  // 0xcd44: 0x4e078863 # (no destination)
  // 0xcd48: 0x00001737 # x14 = 0x00001000
  // 0xcd4c: 0x00000013 # (no destination)

  auto header = "0x" + to_4digit_hex(pc) + ": 0x" + to_8digit_hex(inst);

  if (is_store) {
    header += " # (no destination); ";
    switch (load_store_type) {
    case STORE_SB:
      return header + "mem[0x" + to_8digit_hex(mem_addr) + "] <- 0x" +
             to_2digit_hex(mem_data);
    case STORE_SH:
      return header + "mem[0x" + to_8digit_hex(mem_addr) + "] <- 0x" +
             to_4digit_hex(mem_data);
    case STORE_SW:
      return header + "mem[0x" + to_8digit_hex(mem_addr) + "] <- 0x" +
             to_8digit_hex(mem_data);
    }
  } else if (is_load) {
    switch (load_store_type) {
    case LOAD_LB: {
      auto significant_bit = (rd_data >> 7) & 1;
      if (!is_writeback || rd_addr == 0) {
        header += " # (no destination); ";
      } else {
        header += " # x" + mk_addr(rd_addr) + " = 0x" +
                  (significant_bit ? "ffffff" : "000000") +
                  to_2digit_hex(rd_data) + "; ";
      }
      return header + "           0x" + to_2digit_hex(rd_data) + " <- mem[" +
             to_8digit_hex(mem_addr) + "]";
    }
    case LOAD_LH: {
      auto significant_bit = (rd_data >> 15) & 1;
      if (!is_writeback || rd_addr == 0) {
        header += " # (no destination); ";
      } else {
        header += " # x" + mk_addr(rd_addr) + " = 0x" +
                  (significant_bit ? "ffff" : "0000") + to_4digit_hex(rd_data) +
                  "; ";
      }
      return header + "         0x" + to_4digit_hex(rd_data) + " <- mem[0x" +
             to_8digit_hex(mem_addr) + "]";
    }
    case LOAD_LW: {
      if (!is_writeback || rd_addr == 0) {
        header += " # (no destination); ";
      } else {
        header +=
            " # x" + mk_addr(rd_addr) + " = 0x" + to_8digit_hex(rd_data) + "; ";
      }

      return header + "     0x" + to_8digit_hex(rd_data) + " <- mem[0x" +
             to_8digit_hex(mem_addr) + "]";
    }
    case LOAD_LBU: {
      if (!is_writeback || rd_addr == 0) {
        header += " # (no destination); ";
      } else {
        header += " # x" + mk_addr(rd_addr) + " = 0x000000" +
                  to_2digit_hex(rd_data) + "; ";
      }
      return header + "           0x" + to_2digit_hex(rd_data) + " <- mem[0x" +
             to_8digit_hex(mem_addr) + "]";
    }
    case LOAD_LHU: {
      if (!is_writeback || rd_addr == 0) {
        header += " # (no destination); ";
      } else {
        header += " # x" + mk_addr(rd_addr) + " = 0x0000" +
                  to_4digit_hex(rd_data) + "; ";
      }
      return header + "         0x" + to_4digit_hex(rd_data) + " <- mem[0x" +
             to_8digit_hex(mem_addr) + "]";
    }
    }
  } else {
    if (!is_writeback || rd_addr == 0) {
      header += " # (no destination)";
    } else {
      header += " # x" + mk_addr(rd_addr) + " = 0x" + to_8digit_hex(rd_data);
    }
    return header;
  }
  eprintf("error: unknown instruction: \n");
  eprintf("is_store = %d, is_load = %d\n", is_store, is_load);
  eprintf("load_store_type = %d\n", load_store_type);
  exit(1);
};
