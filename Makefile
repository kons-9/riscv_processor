BASEPATH ="\"/home/kons9/Documents/TA/b3exp/benchmarks/\""
CPPTOP = cpp_cpu_top.v


SIMCPP = tb_coremark.cpp tb_coremarksyn.cpp
SIMOBJ = $(SIMCPP:.cpp=)

# cpp test bench files
TESTCPP = $(filter-out $(SIMCPP), $(wildcard tb_*.cpp))
TESTOBJ =$(TESTCPP:.cpp=)

# verilog test bench files
VTB = $(wildcard tb_*.v)

# all *.v files which are not tb_*.v
SRC = $(filter-out $(VTB), $(wildcard *.v))

# for iverilog
TARGET = cpu
HEX = $(wildcard src/*.hex)

default: test_cpp

coremark: tb_coremark
	@./obj_dir/tb_coremark

coremarksyn: tb_coremarksyn
	@./obj_dir/tb_coremarksyn

sim: $(SIMOBJ)
	@./obj_dir/tb_coremark
	@./obj_dir/tb_coremarksyn

test_cpp: $(TESTOBJ)
	@echo "===== \033[32mstart cpp test\033[0m ====="
	@ok_count=0; \
	fail_count=0; \
	result_list=""; \
	for i in $(TESTOBJ); do \
		tmp=$$(./obj_dir/$$i 2>&1 1>/dev/null); \
		if [ $$? -eq 0 ]; then \
			echo "----- \033[32m$$i passed\033[0m -----"; \
			ok_count=$$((ok_count+1)); \
		else \
			echo "----- \033[31m$$i failed\033[0m -----"; \
			fail_count=$$((fail_count+1)); \
			result_list="$$result_list\033[31m$$i failed: $$tmp\033[0m\n"; \
		fi; \
	done; \
	echo; \
	echo "===== \033[32mresult\033[0m ====="; \
	if [ $$fail_count -ne 0 ]; then \
		echo "$$result_list"; \
	fi; \
	echo "result: \033[32m$$ok_count passed\033[0m, \033[31m$$fail_count failed\033[0m"


# make binary of tb_cpp by verilator
# 1: target name
# 2: top module name
define FUNC_BUILD_CPP
$(1): $(SRC) $(1).cpp 
	verilator -Wno-context -Wno-style -Wno-lint -Wpedantic --trace -cc $(CPPTOP) --exe $(1).cpp -O3 -o $(1) -DBASEPATH=$(BASEPATH) -D$(shell echo $(1) | cut -f 2 -d "_" | tr a-z A-Z)
	make -C obj_dir -f V$(CPPTOP:.v=.mk) 1>/dev/null
endef

$(foreach obj, $(TESTOBJ), $(eval $(call FUNC_BUILD_CPP,$(obj))))

$(foreach obj, $(SIMOBJ),$(eval $(call FUNC_BUILD_CPP,$(obj))))

# custom hex file
hex: $(HEX)
	@cp $(HEX) bin/

# iverilog setting
iverilog_run: $(SRC) $(VTB)
	iverilog -g2012 -o $(TARGET) -s $(VTB) $(SRC)
	./$(TARGET)

clean:
	rm -f *.o *.out *.exe *.so *.a *.dll *.dylib $(TARGET)
	rm -rf obj_dir

.PHONY: clean hex iverilog_run test_cpp coremark coremarksyn sim default
