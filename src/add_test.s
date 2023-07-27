.globl main
main:
  addi x2, x0, 1
  add a3, x0, x2
.L1:
  j .L1
