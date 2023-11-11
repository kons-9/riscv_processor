TOP = tb_top
# all *.v files
OBJ = $(wildcard *.v)
TARGET = cpu
HEX = $(wildcard src/*.hex)

run: $(OBJ)
	iverilog -g2012 -o $(TARGET) -s $(TOP) $(OBJ)
	./$(TARGET)

hex: $(HEX)
	cp $(HEX) bin/

clean:
	rm -f *.o *.out *.exe *.so *.a *.dll *.dylib $(TARGET)

sim: ./obj_dir/Vcpu_top sim_build 
	bash veri.sh

sim_build: $(OBJ) 
	verilator -Wno-context -Wno-style -Wno-lint -Wpedantic --trace -cc cpu_top.v --exe test_bench.cpp

./obj_dir/Vcpu_top: test_bench.cpp sim_build
	make -C obj_dir -f Vcpu_top.mk
