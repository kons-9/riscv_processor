TOP = tb_top
# all *.v files
OBJ = $(wildcard *.v)
TARGET = cpu

run: $(OBJ)
	iverilog -o $(TARGET) -s $(TOP) $(OBJ)

clean:
	rm -f *.o *.out *.exe *.so *.a *.dll *.dylib $(TARGET)
