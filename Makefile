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
