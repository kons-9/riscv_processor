CC = riscv32-unknown-linux-gnu-gcc
LD = riscv32-unknown-linux-gnu-ld
OBJCOPY = riscv32-unknown-linux-gnu-objcopy
OBJDUMP = riscv32-unknown-linux-gnu-objdump
CFLAGS = -march=rv32i -ffreestanding -Wall -Wextra -O0
LDFLAGS = -T link.ld -nostdlib -static 

CFILES = $(wildcard *.c)
SFILES = $(filter-out start.s,$(wildcard *.s))

# all hex files
all: $(CFILES:.c=.binary) $(SFILES:.s=.binary) $(CFILES:.c=.hex) $(SFILES:.s=.hex)

%.binary: %.hex
	python3 hex2bin.py $< $@

start.o: start.s
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@
%.bin: %.elf
	$(OBJCOPY) -O binary $< $@
%.elf: %.o start.o
	$(LD) $(LDFLAGS) start.o $< -o $@
%.hex: %.bin
	hexdump -v -e '1/4 "%08x" "\n"' $< > $@
%.s: %.c Makefile
	$(CC) $(CFLAGS) -S $< -o $@

define make_s_bin_hex_from_c
# 1: c
# 2: o
# 3: bin
# 4: elf
# 5: hex
# 6: s
# make .o file from .s file
$(2): $(6)
	$(CC) $(CFLAGS) -c $$< -o $$@

# make .bin file from .elf file
$(3): $(4)
	$(OBJCOPY) -O binary $$< $$@

# make .elf file from .o file + start.o
$(4): $(2) start.o
	$(LD) $(LDFLAGS) start.o $$< -o $$@

# make .hex file from .bin file
$(5): $(3)
	hexdump -v -e '1/4 "%08x" "\n"' $$< > $$@

# make .s file from .c file
$(6): $(1) Makefile
	$(CC) $(CFLAGS) -S $$< -o $$@
endef
#
# $(foreach cfile,$(CFILES),$(eval $(call make_s_bin_hex_from_c,$(cfile),$(cfile:.c=.o),$(cfile:.c=.bin),$(cfile:.c=.elf),$(cfile:.c=.hex),$(cfile:.c=.s))))

clean:
	rm -f *.bin *.hex *.elf *.o $(CFILES:.c=.s) *.binary

.PHONY: all clean
