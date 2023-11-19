OUTPUT_ARCH( "riscv" )
ENTRY(_start)

SECTIONS {
  . = 0x00008000;
  .text.startup : { *(.text.startup) }
}
