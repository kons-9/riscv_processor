.globl main
main:
  addi x2, x0, 1
  sub x1, x0, x2
.L1:
  j .L1
