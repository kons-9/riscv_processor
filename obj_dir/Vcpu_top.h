// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_TOP_H_
#define _VCPU_TOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vcpu_top__Syms;

//----------

VL_MODULE(Vcpu_top) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rstn,0,0);
    VL_OUT8(uart_tx,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ cpu_top__DOT__is_branch_jump;
    CData/*0:0*/ cpu_top__DOT__is_store;
    CData/*0:0*/ cpu_top__DOT__is_load;
    CData/*0:0*/ cpu_top__DOT__is_writeback;
    CData/*0:0*/ cpu_top__DOT__alu_in1_use_pc;
    CData/*0:0*/ cpu_top__DOT__alu_in2_use_imm;
    CData/*0:0*/ cpu_top__DOT__is_r_type;
    CData/*0:0*/ cpu_top__DOT__is_branch;
    CData/*0:0*/ cpu_top__DOT__store_pc4;
    CData/*0:0*/ cpu_top__DOT__is_system;
    CData/*0:0*/ cpu_top__DOT__is_illegal;
    CData/*0:0*/ cpu_top__DOT__uart_we;
    CData/*0:0*/ cpu_top__DOT__is_write_back_from_csr;
    CData/*2:0*/ cpu_top__DOT__decode__DOT__opcode_type;
    CData/*0:0*/ cpu_top__DOT__decode__DOT__is_jal;
    CData/*0:0*/ cpu_top__DOT__decode__DOT__is_jalr;
    CData/*0:0*/ cpu_top__DOT__decode__DOT__use_adder;
    CData/*2:0*/ cpu_top__DOT__csr__DOT__cpu_mode;
    CData/*1:0*/ cpu_top__DOT__csr__DOT__mstatus_mpp;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__mstatus_mpie;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__update_pc;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__is_interrupt;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__is_write;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__is_priv;
    CData/*0:0*/ cpu_top__DOT__csr__DOT__tmp_write_back;
    CData/*3:0*/ cpu_top__DOT__uart0__DOT__bitcount;
    CData/*0:0*/ cpu_top__DOT__uart0__DOT__uart_busy;
    CData/*0:0*/ cpu_top__DOT__uart0__DOT__sending;
    SData/*8:0*/ cpu_top__DOT__uart0__DOT__shifter;
    IData/*31:0*/ cpu_top__DOT__pc;
    IData/*31:0*/ cpu_top__DOT__pc_next;
    IData/*31:0*/ cpu_top__DOT__alu_out;
    IData/*31:0*/ cpu_top__DOT__inst;
    IData/*31:0*/ cpu_top__DOT__imm;
    IData/*31:0*/ cpu_top__DOT__rs1_data;
    IData/*31:0*/ cpu_top__DOT__rs2_data;
    IData/*31:0*/ cpu_top__DOT__rd_data;
    IData/*31:0*/ cpu_top__DOT__alu_in2;
    IData/*31:0*/ cpu_top__DOT__loaddata;
    IData/*31:0*/ cpu_top__DOT__csr_data;
    IData/*31:0*/ cpu_top__DOT__mem__DOT__data;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mstatus;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__misa;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mie;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mtvec;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mscratch;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mepc;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mcause;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mtval;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__mip;
    IData/*30:0*/ cpu_top__DOT__csr__DOT__exception_code;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__tval;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__bitmask;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__csr_bitmask_wdata;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__csr_bitmask_uimm;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    IData/*31:0*/ cpu_top__DOT__csr__DOT__csr_data;
    IData/*28:0*/ cpu_top__DOT__uart0__DOT__d;
    IData/*28:0*/ cpu_top__DOT__uart0__DOT__dNxt;
    IData/*31:0*/ cpu_top__DOT__hardware_counter_0__DOT__cycles;
    IData/*31:0*/ cpu_top__DOT__fetch__DOT__instbram__DOT__mem[32000];
    IData/*31:0*/ cpu_top__DOT__regfile__DOT__regs[32];
    IData/*31:0*/ cpu_top__DOT__mem__DOT__mem[65537];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*7:0*/ cpu_top__DOT__mem__DOT____Vlvbound1;
        CData/*7:0*/ cpu_top__DOT__mem__DOT____Vlvbound2;
        CData/*7:0*/ cpu_top__DOT__mem__DOT____Vlvbound3;
        CData/*7:0*/ cpu_top__DOT__mem__DOT____Vlvbound4;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__rstn;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__is_jump;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__enable_pc_update_from_csr;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode;
        CData/*6:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sub;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sra;
        CData/*4:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__Vfuncout;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op;
        CData/*1:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_writeback;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__is_load;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__store_pc4;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__global_mie;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__is_illegal;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__global_mie;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__is_illegal;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__global_mie;
        CData/*0:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__is_illegal;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op;
        CData/*2:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op;
        CData/*0:0*/ __Vclklast__TOP__clk;
        CData/*0:0*/ __Vclklast__TOP__rstn;
        SData/*15:0*/ cpu_top__DOT__mem__DOT____Vlvbound5;
        SData/*15:0*/ cpu_top__DOT__mem__DOT____Vlvbound6;
        SData/*15:0*/ cpu_top__DOT__mem__DOT____Vlvbound7;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__Vfuncout;
        SData/*13:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__Vfuncout;
        SData/*11:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12;
        SData/*11:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12;
        SData/*11:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12;
        SData/*11:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr;
        IData/*31:0*/ cpu_top__DOT__mem__DOT____Vlvbound8;
        IData/*31:0*/ cpu_top__DOT__mem__DOT____Vlvbound9;
    };
    struct {
        IData/*31:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__jump_addr;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__pc_plus4;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__csr_pc;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_data;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__loaddata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__alu_out;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mie;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mip;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mie;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mip;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mie;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mip;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__Vfuncout;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mstatus;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__misa;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mie;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtvec;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mscratch;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mepc;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mcause;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtval;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mip;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__ext_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__ext_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__ext_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_wdata;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__ext_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_uimm;
        IData/*31:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_uimm;
        QData/*32:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__Vfuncout;
        QData/*32:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__Vfuncout;
        QData/*32:0*/ __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__Vfuncout;
        QData/*34:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__Vfuncout;
        QData/*34:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__Vfuncout;
    };
    struct {
        QData/*34:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__Vfuncout;
        QData/*34:0*/ __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__Vfuncout;
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu_top__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu_top);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu_top(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu_top();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu_top__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu_top__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu_top__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vcpu_top__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(Vcpu_top__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu_top__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vcpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__6(Vcpu_top__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__8(Vcpu_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vcpu_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vcpu_top__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vcpu_top__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vcpu_top__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
