#include "Vcpp_cpu_top.h"
#include "util.hpp"
#include <cstdio>
#include <fstream>
#include <verilated.h>

#define COREMARK

// Set the clock speed of your processor. 10MHz is the default.
static constexpr std::size_t clock_Hz = 10'000'000;
// UART baudrate
static constexpr std::size_t uart_Hz = 115200;
// The number of CoreMark iterations is depend on clock speed.
// Max: 30 seconds
static constexpr std::size_t max_cycle = 100 * clock_Hz;

std::size_t timer_ps = 0;
const std::size_t second = 1'000'000'000'000; // 1 second = 1,000,000,000,000 ps

void uart_rx(unsigned int u) {
  static std::size_t s = 0;
  static std::size_t b = 0;
  static char c = 0;
  if (s == 0 && u == 0) {
    s = timer_ps;
    b = 0;
    c = 0;
  } else if (s != 0 && s + second / uart_Hz / 2 * (2 * b + 3) < timer_ps) {
    if (b < 8) {
      c += u << b;
      ++b;
    } else {
      std::putchar(c);
      std::fflush(stdout);
      s = 0;
    }
  }
}

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

  auto preinst = top.inst;

  std::ofstream ofs("coremark.trace");
  auto trace_str = trace(top.pc, top.inst, top.rd_addr, top.rd_data,
                         top.is_store, top.is_load, top.load_store_type,
                         top.mem_addr, top.mem_data, top.is_writeback);
  ofs << trace_str << "\n";

  for (std::size_t cycle = 0; cycle < max_cycle; ++cycle) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
    uart_rx(top.uart_tx);
    timer_ps += second / clock_Hz;

    if (top.is_stall) {
      continue;
    }
    if (top.inst == preinst) {
      break;
    }
    preinst = top.inst;

    auto trace_str = trace(top.pc, top.inst, top.rd_addr, top.rd_data,
                           top.is_store, top.is_load, top.load_store_type,
                           top.mem_addr, top.mem_data, top.is_writeback);
    ofs << trace_str << "\n";
  }

  ofs.close();

  // wait 1 second for uart
  for (std::size_t cycle = 0; cycle < clock_Hz; ++cycle) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
    uart_rx(top.uart_tx);
    timer_ps += second / clock_Hz;
  }
}
