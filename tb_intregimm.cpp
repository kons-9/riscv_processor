#include "Vcpp_cpu_top.h"
#include "util.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <verilated.h>

// max cycle is actually 1000
static constexpr std::size_t max_cycle = 10'000;

int main() {
  Vcpp_cpu_top top;
  top.clk = 0;
  top.eval();

  top.rstn = 0;
  top.eval();

  top.clk = 1;
  top.eval();

  top.clk = 0;
  top.eval();

  top.rstn = 1;
  top.eval();

  for (std::size_t cycle = 0; cycle < max_cycle; ++cycle) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
  }

  auto prepc = top.pc;
  top.clk = 0;
  top.eval();
  top.clk = 1;
  top.eval();
  if (top.pc != prepc) {
    std::printf("Error: simulation is not finished.\n");
    return 1;
  }

  std::string xml = to_xml(top.pc, top.regfile);
  std::string ref_xml;
  auto path = std::string(BASEPATH) + "/tests/IntRegImm/cfg.xml";
  ref_xml =
      std::string(std::istreambuf_iterator<char>(std::ifstream(path).rdbuf()),
                  std::istreambuf_iterator<char>());

  if (xml != ref_xml) {
    auto diffstr =
        "zsh -c \"diff <(echo '" + xml + "') <(echo '" + ref_xml + "')\"";

    // std::printf("%s\n", diffstr.c_str());
    // std command diff
    auto err = std::system(diffstr.c_str());
    if (err != 0) {
      std::printf("Error: result is not matched with cfg.xml.\n");
      return 1;
    }

    return 1;
  } else {
    return 0;
  }
}
