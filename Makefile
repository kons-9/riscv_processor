BASEPATH ="\"/home/kons9/Documents/TA/b3exp/benchmarks\""

# cpp test bench files
TESTCPP =tb_uart.cpp
TESTOBJ =$(TESTCPP:.cpp=)
TESTTOP =cpp_cpu_top.v

SIMCPP = tb_coremark.cpp tb_coremarksyn.cpp
SIMOBJ = $(SIMCPP:.cpp=)
SIMTOP = cpu_top.v

# verilog test bench files
VTB = $(wildcard tb_*.v)

# all *.v files which are not tb_*.v
SRC = $(filter-out $(VTB), $(wildcard *.v))
TARGET = cpu
HEX = $(wildcard src/*.hex)

test_cpp: $(TESTCPP:.cpp=)
	@echo "===== \033[32mstart cpp test\033[0m ====="
	@ok_count=0; \
	fail_count=0; \
	for i in $<; do \
		echo "===== \033[32mstart $$i\033[0m ====="; \
		./obj_dir/$$i; \
		if [ $$? -eq 0 ]; then \
			echo "===== \033[32m$$i passed\033[0m ====="; \
			ok_count=$$((ok_count+1)); \
		else \
			echo "===== \033[31m$$i failed\033[0m ====="; \
			fail_count=$$((fail_count+1)); \
		fi; \
	done; \
	echo; \
	echo "===== result: \033[32m $$ok_count passed\033[0m \033[31m$$fail_count failed\033[0m ====="

# make binary of tb_cpp by verilator
# 1: target name
# 2: top module name
define FUNC_BUILD_CPP
$(1): $(SRC) $(1).cpp 
	verilator -Wno-context -Wno-style -Wno-lint -Wpedantic --trace -cc $(2) --exe $(1).cpp -O3 -o $(1) -DBASEPATH=$(BASEPATH) -D$(shell echo $(1) | cut -f 2 -d "_" | tr a-z A-Z)
	@make -C obj_dir -f V$(2:.v=.mk) 1>/dev/null
endef

$(foreach obj,$(TESTOBJ),$(eval $(call FUNC_BUILD_CPP,$(obj),$(TESTTOP))))

$(foreach obj, $(SIMOBJ), $(eval $(call FUNC_BUILD_CPP,$(obj),$(SIMTOP))))

hex: $(HEX)
	cp $(HEX) bin/

# iverilog setting

iverilog_run: $(SRC) $(VTB)
	iverilog -g2012 -o $(TARGET) -s $(VTB) $(SRC)
	./$(TARGET)

clean:
	rm -f *.o *.out *.exe *.so *.a *.dll *.dylib $(TARGET)
	rm -rf obj_dir

