.globl main
main:
  addi x29, x0, -0x1 /* initialize x29 to -1 */
  addi x28, x0, 0x2 /* initialize x28 to 2 */

  add x30, x29, x28 /* rtype */
  sub x30, x29, x28
  sll x30, x29, x28
  slt x30, x29, x28
  sltu x30, x29, x28
  xor x30, x29, x28
  srl x30, x29, x28
  sra x30, x29, x28
  or x30, x29, x28
  and x30, x29, x28

  sb x29, 0x0(x28) /* store */
  sh x29, 0x0(x28)
  sw x29, 0x0(x28)

  addi x30, x29, 0x8 /* itype */
  slti x30, x29, 0x8
  sltiu x30, x29, 0x8
  xori x30, x29, 0x8
  ori x30, x29, 0x11
  andi x30, x29, 0x11
  slli x30, x29, 0x3
  srli x30, x29, 0x3
  srai x30, x29, 0x3
  lb x30, 0x0(x28) /* load */
  lh x30, 0x0(x28)
  lw x30, 0x0(x28)
  lbu x30, 0x0(x28)
  lhu x30, 0x0(x28)

  /* x29 = -1, x28 = 2 */
  beq x29, x28, .L3 /* btype */
  beq x29, x29, .L3 
.beq:
  bne x29, x29, .L4
  bne x29, x28, .L4
.bne:
  blt x29, x28, .L5
  blt x28, x29, .L5
.blt:
  bge x28, x29, .L6
  bge x29, x28, .L6
.bge:
  bltu x29, x28, .L7
  bltu x28, x29, .L7
.bltu:
  bgeu x28, x29, .L8
  bgeu x29, x28, .L8
.bgeu:
  j .bgeu

.L3:
  j .beq
.L4:
  j .bne
.L5:
  j .blt
.L6:
  j .bge
.L7:
  j .bltu
.L8:
  j .bgeu
