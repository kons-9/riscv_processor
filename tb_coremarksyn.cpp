#include "Vcpu_top.h"
#include <cstdio>
#include <fstream>
#include <verilated.h>

#define COREMARKSYN

// Set the clock speed of your processor. 10MHz is the default.
static constexpr std::size_t clock_Hz = 10'000'000;
// UART baudrate
static constexpr std::size_t uart_Hz = 115200;
// The number of CoreMark iterations is depend on clock speed.
// Max: 30 seconds
static constexpr std::size_t max_cycle = 10'000 * clock_Hz;

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
  } else if (s != 0 &&
             s + 1'000'000'000'000 / uart_Hz / 2 * (2 * b + 3) < timer_ps) {
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

  // fd = $fopen("output.trace", "w");
#ifdef DEBUG
  FILE *fd = std::fopen("output.trace", "w");
#endif

  Vcpu_top top;
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
    uart_rx(top.uart_tx);
    timer_ps += 1'000'000'000'000 / clock_Hz;
  }
}
