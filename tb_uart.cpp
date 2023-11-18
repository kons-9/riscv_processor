#include "Vcpp_cpu_top.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>
#include <verilated.h>

#define UART

// Set the clock speed of your processor. 10MHz is the default.
static constexpr std::size_t clock_Hz = 10'000'000;
// UART baudrate
static constexpr std::size_t uart_Hz = 115200;
// The number of CoreMark iterations is depend on clock speed.
// Max: 30 seconds
static constexpr std::size_t max_cycle = 1 * clock_Hz;

std::size_t timer_ps = 0;
const std::size_t second = 1'000'000'000'000; // 1 second = 1,000,000,000,000 ps

int uart_rx(unsigned int u) {
  static std::size_t s = 0;
  static std::size_t b = 0;
  static char c = 0;
  if (s == 0 && u == 0) {
    s = timer_ps;
    b = 0;
    c = 0;
  } else if (s != 0 &&
             s + 1'000'000'000'000 / uart_Hz / 2 * (2 * b + 3) < timer_ps) {
    if (b < 8) {
      c += u << b;
      ++b;
    } else {
      std::putchar(c);
      std::fflush(stdout);
      s = 0;
      return c;
    }
  }
  // return MAX_CHAR+1 to indicate no char received
  return std::numeric_limits<char>::max() + 1;
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
  printf("pc = %x\n", top.pc);
  printf("rs1 = %x\n", top.rs1);
  printf("rs2 = %x\n", top.rs2);

  std::vector<char> c = {};

  for (std::size_t cycle = 0; cycle < max_cycle; ++cycle) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
    int tc = uart_rx(top.uart_tx);
    if (tc != std::numeric_limits<char>::max() + 1) {
      c.push_back(static_cast<char>(tc));
    }
    timer_ps += 1'000'000'000'000 / clock_Hz;
  }

  if (c.size() == 1 && c[0] == 'A') {
    std::printf("\n");
    return 0;
  } else {
    std::printf("\n");
    std::printf("Error: got %lu characters, but expected 1 character 'A'.\n",
                c.size());
    return 1;
  }
}
