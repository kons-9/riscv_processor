#include <cstdio>
#include <verilated.h>
#include "Vcpu_top.h"
#include <fstream>

// Set the clock speed of your processor. 10MHz is the default.
static constexpr std::size_t clock_Hz = 350'000;
// UART baudrate
static constexpr std::size_t uart_Hz = 115200;
// The number of CoreMark iterations is depend on clock speed.
// Max: 30 seconds
static constexpr std::size_t max_cycle = 10000000 * clock_Hz;

std::size_t timer_ps = 0;
const std::size_t second = 1'000'000'000'000;  // 1 second = 1,000,000,000,000 ps

void uart_rx(unsigned int u) {
    static std::size_t s = 0;
    static std::size_t b = 0;
    static char c = 0;
    if (s == 0 && u == 0) {
        s = timer_ps;
        b = 0;
        c = 0;
    } else if (s != 0 && s + 1'000'000'000'000 / uart_Hz / 2 * (2 * b + 3) < timer_ps) {
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
#ifdef DEBUG
        if (top.cpu_top__DOT__is_store) {
            std::fprintf(fd,
                         "0x%04x: 0x%08x # (no destination); mem[0x%08x] <- 0x%08x\n",
                         top.cpu_top__DOT__pc,
                         top.cpu_top__DOT__inst,
                         top.cpu_top__DOT__alu_out,
                         top.cpu_top__DOT__rs2_data);
        } else if (top.cpu_top__DOT__is_load) {
            std::fprintf(fd,
                         "0x%04x: 0x%08x # x%02d = 0x%08x;      0x%08x <- mem[0x%08x]\n",
                         top.cpu_top__DOT__pc,
                         top.cpu_top__DOT__inst,
                         top.cpu_top__DOT__rd,
                         top.cpu_top__DOT__rd_data,
                         top.cpu_top__DOT__rd_data,
                         top.cpu_top__DOT__alu_out);

        } else if (top.cpu_top__DOT__is_writeback) {
            std::fprintf(fd,
                         "0x%04x: 0x%08x # x%02d = 0x%08x\n",
                         top.cpu_top__DOT__pc,
                         top.cpu_top__DOT__inst,
                         top.cpu_top__DOT__rd,
                         top.cpu_top__DOT__rd_data);
        } else {
            std::fprintf(fd, "0x%04x: 0x%08x # (no destination)\n", top.cpu_top__DOT__pc, top.cpu_top__DOT__inst);
        }
#endif
        timer_ps += 1'000'000'000'000 / clock_Hz;
    }
}
