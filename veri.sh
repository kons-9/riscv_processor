#!/bin/bash
verilator --cc cpu_top.v -exe test_bench.cpp
make -C obj_dir -f Vcpu_top.mk
echo
echo "------------------start------------------"
./obj_dir/Vcpu_top
echo
echo "------------------end--------------------"
