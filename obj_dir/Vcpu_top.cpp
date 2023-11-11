// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_top.h for the primary calling header

#include "Vcpu_top.h"
#include "Vcpu_top__Syms.h"

//==========

void Vcpu_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu_top::eval\n"); );
    Vcpu_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu_top.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu_top::_eval_initial_loop(Vcpu_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu_top.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcpu_top::_sequent__TOP__2(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_sequent__TOP__2\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__cpu_top__DOT__uart0__DOT__bitcount;
    SData/*8:0*/ __Vdly__cpu_top__DOT__uart0__DOT__shifter;
    // Body
    __Vdly__cpu_top__DOT__uart0__DOT__bitcount = vlTOPp->cpu_top__DOT__uart0__DOT__bitcount;
    __Vdly__cpu_top__DOT__uart0__DOT__shifter = vlTOPp->cpu_top__DOT__uart0__DOT__shifter;
    if (vlTOPp->rstn) {
        if (((IData)(vlTOPp->cpu_top__DOT__uart_we) 
             & (~ (IData)(vlTOPp->cpu_top__DOT__uart0__DOT__uart_busy)))) {
            __Vdly__cpu_top__DOT__uart0__DOT__bitcount = 0xbU;
        }
        if (((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__sending) 
             & (~ (vlTOPp->cpu_top__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu_top__DOT__uart0__DOT__bitcount 
                = (0xfU & ((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__cpu_top__DOT__uart0__DOT__bitcount = 0U;
    }
    vlTOPp->cpu_top__DOT__hardware_counter_0__DOT__cycles 
        = ((IData)(vlTOPp->rstn) ? ((IData)(1U) + vlTOPp->cpu_top__DOT__hardware_counter_0__DOT__cycles)
            : 0U);
    if (vlTOPp->rstn) {
        if (((IData)(vlTOPp->cpu_top__DOT__uart_we) 
             & (~ (IData)((0U != (7U & ((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount) 
                                        >> 1U))))))) {
            __Vdly__cpu_top__DOT__uart0__DOT__shifter 
                = (0x1feU & (vlTOPp->cpu_top__DOT__rs2_data 
                             << 1U));
        }
        if (((0U != (IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount)) 
             & (~ (vlTOPp->cpu_top__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu_top__DOT__uart0__DOT__shifter 
                = (0x100U | (0xffU & ((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__shifter) 
                                      >> 1U)));
            vlTOPp->uart_tx = (1U & (IData)(vlTOPp->cpu_top__DOT__uart0__DOT__shifter));
        }
    } else {
        __Vdly__cpu_top__DOT__uart0__DOT__shifter = 0U;
        vlTOPp->uart_tx = 1U;
    }
    vlTOPp->cpu_top__DOT__uart0__DOT__shifter = __Vdly__cpu_top__DOT__uart0__DOT__shifter;
    vlTOPp->cpu_top__DOT__uart0__DOT__bitcount = __Vdly__cpu_top__DOT__uart0__DOT__bitcount;
    vlTOPp->cpu_top__DOT__uart0__DOT__uart_busy = (0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount) 
                                                       >> 1U)));
    vlTOPp->cpu_top__DOT__uart0__DOT__sending = (0U 
                                                 != (IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu_top__DOT__uart0__DOT__d = ((IData)(vlTOPp->rstn)
                                            ? vlTOPp->cpu_top__DOT__uart0__DOT__dNxt
                                            : 0U);
    vlTOPp->cpu_top__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                              & (vlTOPp->cpu_top__DOT__uart0__DOT__d 
                                                 + 
                                                 ((0x10000000U 
                                                   & vlTOPp->cpu_top__DOT__uart0__DOT__d)
                                                   ? 0x1c200U
                                                   : 0xff692b80U)));
}

VL_INLINE_OPT void Vcpu_top::_sequent__TOP__3(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_sequent__TOP__3\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v4;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v5;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v6;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v6;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v7;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v7;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v8;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v8;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v9;
    CData/*7:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v9;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v9;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v10;
    CData/*7:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v10;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v10;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v11;
    CData/*7:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v11;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v11;
    CData/*4:0*/ __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v12;
    CData/*7:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v12;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v12;
    SData/*15:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v6;
    SData/*15:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v7;
    SData/*15:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v8;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v0;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v0;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v1;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v1;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v2;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v2;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v3;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v3;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v4;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v4;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v5;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v5;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v6;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v7;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v8;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v9;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v10;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v11;
    IData/*16:0*/ __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v12;
    // Body
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v0 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v1 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v2 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v3 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v4 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v5 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v6 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v7 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v8 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v9 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v10 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v11 = 0U;
    __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v12 = 0U;
    if ((((~ (IData)(vlTOPp->cpu_top__DOT__is_illegal)) 
          & (IData)(vlTOPp->cpu_top__DOT__is_store)) 
         & (~ (IData)(vlTOPp->cpu_top__DOT__uart_we)))) {
        if ((0x4000U & vlTOPp->cpu_top__DOT__inst)) {
            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9 
                = vlTOPp->cpu_top__DOT__rs2_data;
            if ((0x10000U >= (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                          >> 2U)))) {
                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v0 
                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9;
                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v0 = 1U;
                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v0 
                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                   >> 2U));
            }
        } else {
            if ((0x2000U & vlTOPp->cpu_top__DOT__inst)) {
                if ((0x1000U & vlTOPp->cpu_top__DOT__inst)) {
                    vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9 
                        = vlTOPp->cpu_top__DOT__rs2_data;
                    if ((0x10000U >= (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                  >> 2U)))) {
                        __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v1 
                            = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9;
                        __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v1 = 1U;
                        __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v1 
                            = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                           >> 2U));
                    }
                } else {
                    if ((2U & vlTOPp->cpu_top__DOT__alu_out)) {
                        vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9 
                            = vlTOPp->cpu_top__DOT__rs2_data;
                        if ((0x10000U >= (0x1ffffU 
                                          & (vlTOPp->cpu_top__DOT__alu_out 
                                             >> 2U)))) {
                            __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v2 
                                = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9;
                            __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v2 = 1U;
                            __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v2 
                                = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                               >> 2U));
                        }
                    } else {
                        if ((1U & vlTOPp->cpu_top__DOT__alu_out)) {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9 
                                = vlTOPp->cpu_top__DOT__rs2_data;
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v3 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v3 = 1U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v3 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        } else {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound8 
                                = vlTOPp->cpu_top__DOT__rs2_data;
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v4 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound8;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v4 = 1U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v4 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        }
                    }
                }
            } else {
                if ((0x1000U & vlTOPp->cpu_top__DOT__inst)) {
                    if ((2U & vlTOPp->cpu_top__DOT__alu_out)) {
                        if ((1U & vlTOPp->cpu_top__DOT__alu_out)) {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9 
                                = vlTOPp->cpu_top__DOT__rs2_data;
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v5 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound9;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v5 = 1U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v5 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        } else {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound7 
                                = (0xffffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v6 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound7;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v6 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v6 = 0x10U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v6 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        }
                    } else {
                        if ((1U & vlTOPp->cpu_top__DOT__alu_out)) {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound6 
                                = (0xffffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v7 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound6;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v7 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v7 = 8U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v7 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        } else {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound5 
                                = (0xffffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v8 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound5;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v8 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v8 = 0U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v8 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        }
                    }
                } else {
                    if ((2U & vlTOPp->cpu_top__DOT__alu_out)) {
                        if ((1U & vlTOPp->cpu_top__DOT__alu_out)) {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound4 
                                = (0xffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v9 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound4;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v9 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v9 = 0x18U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v9 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        } else {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound3 
                                = (0xffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v10 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound3;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v10 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v10 = 0x10U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v10 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        }
                    } else {
                        if ((1U & vlTOPp->cpu_top__DOT__alu_out)) {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound2 
                                = (0xffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v11 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound2;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v11 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v11 = 8U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v11 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        } else {
                            vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound1 
                                = (0xffU & vlTOPp->cpu_top__DOT__rs2_data);
                            if ((0x10000U >= (0x1ffffU 
                                              & (vlTOPp->cpu_top__DOT__alu_out 
                                                 >> 2U)))) {
                                __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v12 
                                    = vlTOPp->cpu_top__DOT__mem__DOT____Vlvbound1;
                                __Vdlyvset__cpu_top__DOT__mem__DOT__mem__v12 = 1U;
                                __Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v12 = 0U;
                                __Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v12 
                                    = (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                                   >> 2U));
                            }
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v0) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v0] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v0;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v1) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v1] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v1;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v2) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v2] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v2;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v3) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v3] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v3;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v4) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v4] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v4;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v5) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v5] 
            = __Vdlyvval__cpu_top__DOT__mem__DOT__mem__v5;
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v6) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v6] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v6))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v6]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v6) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v6)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v7) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v7] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v7))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v7]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v7) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v7)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v8) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v8] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v8))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v8]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v8) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v8)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v9) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v9] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v9))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v9]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v9) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v9)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v10) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v10] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v10))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v10]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v10) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v10)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v11) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v11] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v11))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v11]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v11) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v11)));
    }
    if (__Vdlyvset__cpu_top__DOT__mem__DOT__mem__v12) {
        vlTOPp->cpu_top__DOT__mem__DOT__mem[__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v12] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v12))) 
                & vlTOPp->cpu_top__DOT__mem__DOT__mem
                [__Vdlyvdim0__cpu_top__DOT__mem__DOT__mem__v12]) 
               | ((IData)(__Vdlyvval__cpu_top__DOT__mem__DOT__mem__v12) 
                  << (IData)(__Vdlyvlsb__cpu_top__DOT__mem__DOT__mem__v12)));
    }
}

VL_INLINE_OPT void Vcpu_top::_sequent__TOP__4(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_sequent__TOP__4\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__cpu_top__DOT__regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v1;
    CData/*2:0*/ __Vdly__cpu_top__DOT__csr__DOT__cpu_mode;
    IData/*31:0*/ __Vdlyvval__cpu_top__DOT__regfile__DOT__regs__v0;
    // Body
    __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v0 = 0U;
    __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v1 = 0U;
    __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode;
    if (vlTOPp->rstn) {
        if ((((~ (IData)(vlTOPp->cpu_top__DOT__is_illegal)) 
              & ((IData)(vlTOPp->cpu_top__DOT__is_write_back_from_csr) 
                 | (IData)(vlTOPp->cpu_top__DOT__is_writeback))) 
             & (0U != (0x1fU & (vlTOPp->cpu_top__DOT__inst 
                                >> 7U))))) {
            __Vdlyvval__cpu_top__DOT__regfile__DOT__regs__v0 
                = vlTOPp->cpu_top__DOT__rd_data;
            __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v0 = 1U;
            __Vdlyvdim0__cpu_top__DOT__regfile__DOT__regs__v0 
                = (0x1fU & (vlTOPp->cpu_top__DOT__inst 
                            >> 7U));
        }
    } else {
        __Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v1 = 1U;
    }
    if (vlTOPp->rstn) {
        if (((IData)(vlTOPp->cpu_top__DOT__is_system) 
             & (~ (IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_priv)))) {
            if (vlTOPp->cpu_top__DOT__csr__DOT__is_write) {
                if (((((((((0x300U == (0xfffU & vlTOPp->cpu_top__DOT__imm)) 
                           | (0x301U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                          | (0x304U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                         | (0x305U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                        | (0x340U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                       | (0x341U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                      | (0x342U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                     | (0x343U == (0xfffU & vlTOPp->cpu_top__DOT__imm)))) {
                    if ((0x300U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                    } else {
                        if ((0x301U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                            vlTOPp->cpu_top__DOT__csr__DOT__misa 
                                = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                        } else {
                            if ((0x304U == (0xfffU 
                                            & vlTOPp->cpu_top__DOT__imm))) {
                                vlTOPp->cpu_top__DOT__csr__DOT__mie 
                                    = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                            } else {
                                if ((0x305U == (0xfffU 
                                                & vlTOPp->cpu_top__DOT__imm))) {
                                    vlTOPp->cpu_top__DOT__csr__DOT__mtvec 
                                        = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                                } else {
                                    if ((0x340U == 
                                         (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                                        vlTOPp->cpu_top__DOT__csr__DOT__mscratch 
                                            = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                                    } else {
                                        if ((0x341U 
                                             == (0xfffU 
                                                 & vlTOPp->cpu_top__DOT__imm))) {
                                            vlTOPp->cpu_top__DOT__csr__DOT__mepc 
                                                = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                                        } else {
                                            if ((0x342U 
                                                 == 
                                                 (0xfffU 
                                                  & vlTOPp->cpu_top__DOT__imm))) {
                                                vlTOPp->cpu_top__DOT__csr__DOT__mcause 
                                                    = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                                            } else {
                                                vlTOPp->cpu_top__DOT__csr__DOT__mtval 
                                                    = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0x344U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                        vlTOPp->cpu_top__DOT__csr__DOT__mip 
                            = vlTOPp->cpu_top__DOT__csr__DOT__csr_data;
                    }
                }
            }
        } else {
            if (((IData)(vlTOPp->cpu_top__DOT__is_system) 
                 & (IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_priv))) {
                if (((((((0x302U == (0xfffU & vlTOPp->cpu_top__DOT__imm)) 
                         | (0x105U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                        | (0U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                       | (1U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                      | (0x102U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) 
                     | (0x1a0U == (0xfffU & vlTOPp->cpu_top__DOT__imm)))) {
                    if ((0x302U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = ((0xfffffff7U & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                               | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie) 
                                  << 3U));
                        __Vdly__cpu_top__DOT__csr__DOT__cpu_mode 
                            = vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpp;
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = (0x80U | vlTOPp->cpu_top__DOT__csr__DOT__mstatus);
                    } else {
                        if ((0x105U != (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                            if ((0U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                                vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                    = ((0xfffffff7U 
                                        & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                                       | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie) 
                                          << 3U));
                                vlTOPp->cpu_top__DOT__csr__DOT__mepc 
                                    = vlTOPp->cpu_top__DOT__pc;
                                vlTOPp->cpu_top__DOT__csr__DOT__mcause 
                                    = (((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt) 
                                        << 0x1fU) | vlTOPp->cpu_top__DOT__csr__DOT__exception_code);
                                vlTOPp->cpu_top__DOT__csr__DOT__mtval 
                                    = vlTOPp->cpu_top__DOT__csr__DOT__tval;
                                vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                    = (0x80U | vlTOPp->cpu_top__DOT__csr__DOT__mstatus);
                                vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                    = ((0xffffe7ffU 
                                        & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                                       | (0x1800U & 
                                          ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode) 
                                           << 0xbU)));
                                __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = 3U;
                            } else {
                                if ((1U == (0xfffU 
                                            & vlTOPp->cpu_top__DOT__imm))) {
                                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                        = ((0xfffffff7U 
                                            & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                                           | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie) 
                                              << 3U));
                                    vlTOPp->cpu_top__DOT__csr__DOT__mepc 
                                        = vlTOPp->cpu_top__DOT__pc;
                                    vlTOPp->cpu_top__DOT__csr__DOT__mcause 
                                        = (((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt) 
                                            << 0x1fU) 
                                           | vlTOPp->cpu_top__DOT__csr__DOT__exception_code);
                                    vlTOPp->cpu_top__DOT__csr__DOT__mtval 
                                        = vlTOPp->cpu_top__DOT__csr__DOT__tval;
                                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                        = (0x80U | vlTOPp->cpu_top__DOT__csr__DOT__mstatus);
                                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                        = ((0xffffe7ffU 
                                            & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                                           | (0x1800U 
                                              & ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode) 
                                                 << 0xbU)));
                                    __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = 3U;
                                } else {
                                    if ((0x102U == 
                                         (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                                        VL_WRITEF("unimplemented\n");
                                    } else {
                                        VL_WRITEF("unimplemented\n");
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if ((0x1a1U == (0xfffU & vlTOPp->cpu_top__DOT__imm))) {
                        VL_WRITEF("unimplemented\n");
                    } else {
                        VL_WRITEF("illegal privileged operation\n");
                    }
                }
            } else {
                if (vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt) {
                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                        = ((0xfffffff7U & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                           | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie) 
                              << 3U));
                    vlTOPp->cpu_top__DOT__csr__DOT__mepc 
                        = vlTOPp->cpu_top__DOT__pc;
                    vlTOPp->cpu_top__DOT__csr__DOT__mcause 
                        = (((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt) 
                            << 0x1fU) | vlTOPp->cpu_top__DOT__csr__DOT__exception_code);
                    vlTOPp->cpu_top__DOT__csr__DOT__mtval 
                        = vlTOPp->cpu_top__DOT__csr__DOT__tval;
                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                        = (0x80U | vlTOPp->cpu_top__DOT__csr__DOT__mstatus);
                    vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                        = ((0xffffe7ffU & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                           | (0x1800U & ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode) 
                                         << 0xbU)));
                    __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = 3U;
                } else {
                    if (vlTOPp->cpu_top__DOT__is_illegal) {
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = ((0xfffffff7U & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                               | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie) 
                                  << 3U));
                        vlTOPp->cpu_top__DOT__csr__DOT__mepc 
                            = vlTOPp->cpu_top__DOT__pc;
                        vlTOPp->cpu_top__DOT__csr__DOT__mcause 
                            = (((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt) 
                                << 0x1fU) | vlTOPp->cpu_top__DOT__csr__DOT__exception_code);
                        vlTOPp->cpu_top__DOT__csr__DOT__mtval 
                            = vlTOPp->cpu_top__DOT__csr__DOT__tval;
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = (0x80U | vlTOPp->cpu_top__DOT__csr__DOT__mstatus);
                        vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                            = ((0xffffe7ffU & vlTOPp->cpu_top__DOT__csr__DOT__mstatus) 
                               | (0x1800U & ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode) 
                                             << 0xbU)));
                        __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = 3U;
                    }
                }
            }
        }
    } else {
        __Vdly__cpu_top__DOT__csr__DOT__cpu_mode = 3U;
    }
    if (__Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v0) {
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[__Vdlyvdim0__cpu_top__DOT__regfile__DOT__regs__v0] 
            = __Vdlyvval__cpu_top__DOT__regfile__DOT__regs__v0;
    }
    if (__Vdlyvset__cpu_top__DOT__regfile__DOT__regs__v1) {
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[1U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[2U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[3U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[4U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[5U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[6U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[7U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[8U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[9U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xaU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xbU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xcU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xdU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xeU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0xfU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x10U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x11U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x12U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x13U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x14U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x15U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x16U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x17U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x18U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x19U] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1aU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1bU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1cU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1dU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1eU] = 0U;
        vlTOPp->cpu_top__DOT__regfile__DOT__regs[0x1fU] = 0U;
    }
    vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode = __Vdly__cpu_top__DOT__csr__DOT__cpu_mode;
    vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpp = (3U 
                                                   & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                                      >> 0xbU));
    vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie = 
        (1U & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
               >> 7U));
    vlTOPp->cpu_top__DOT__pc = vlTOPp->cpu_top__DOT__pc_next;
    vlTOPp->cpu_top__DOT__inst = ((0x7cffU >= (0x7fffU 
                                               & (vlTOPp->cpu_top__DOT__pc 
                                                  >> 2U)))
                                   ? vlTOPp->cpu_top__DOT__fetch__DOT__instbram__DOT__mem
                                  [(0x7fffU & (vlTOPp->cpu_top__DOT__pc 
                                               >> 2U))]
                                   : 0U);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_writeback = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__Vfuncout) 
                                                >> 6U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_store = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__Vfuncout) 
                                            >> 7U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_load = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__Vfuncout) 
                                           >> 8U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_branch = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__Vfuncout) 
                                             >> 0xbU));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__decode__DOT__is_jal = (1U 
                                                 & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__Vfuncout) 
                                                    >> 0xdU));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__decode__DOT__is_jalr = (1U 
                                                  & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__Vfuncout) 
                                                     >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_r_type = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__Vfuncout) 
                                             >> 0xaU));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__decode__DOT__use_adder = 
        (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__Vfuncout) 
               >> 5U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__alu_in1_use_pc = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__Vfuncout) 
                                                  >> 4U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__is_system = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__Vfuncout) 
                                             >> 9U));
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__alu_in2_use_imm = (1U & ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__Vfuncout) 
                                                   >> 3U));
    vlTOPp->cpu_top__DOT__rs2_data = vlTOPp->cpu_top__DOT__regfile__DOT__regs
        [(0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0x14U))];
    vlTOPp->cpu_top__DOT__rs1_data = vlTOPp->cpu_top__DOT__regfile__DOT__regs
        [(0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0xfU))];
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode 
        = (0x7fU & vlTOPp->cpu_top__DOT__inst);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__Vfuncout 
        = ((0x40U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
            ? ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                    ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                        ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                 ? 1U : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                              ? 0x201U
                                              : 1U)
                                          : 1U))) : 
                   ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                     ? ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                         ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                             ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                 ? 0x207dU : 1U) : 1U)
                         : 1U) : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                   ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? 0x1069U
                                           : 1U) : 1U)
                                   : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                       ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? 0x83bU
                                           : 1U) : 1U))))
                : 1U) : ((0x20U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                          ? ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                   ? 0x6cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                   ? 0x440U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                     ? 0xaaU
                                                     : 1U)
                                                    : 1U))))
                          : ((0x10U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                              ? ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                   ? 0x7cU
                                                   : 1U)
                                               : 1U)
                                           : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                   ? 0x49U
                                                   : 1U)
                                               : 1U)))
                              : ((8U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                  ? 1U : ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                           ? 1U : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode))
                                                     ? 0x169U
                                                     : 1U)
                                                    : 1U))))));
    vlTOPp->cpu_top__DOT__decode__DOT__opcode_type 
        = (7U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__Vfuncout));
    vlTOPp->cpu_top__DOT__store_pc4 = ((IData)(vlTOPp->cpu_top__DOT__decode__DOT__is_jal) 
                                       | (IData)(vlTOPp->cpu_top__DOT__decode__DOT__is_jalr));
    vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data 
        = vlTOPp->cpu_top__DOT__rs2_data;
    vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data 
        = vlTOPp->cpu_top__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op))
                    ? (vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data 
                       >= vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data)
                    : (vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data 
                       < vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op))
                    ? VL_GTES_III(1,32,32, vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data, vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data)
                    : VL_LTS_III(1,32,32, vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data, vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data)))
            : ((~ ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op) 
                   >> 1U)) & ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op))
                               ? (vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data 
                                  != vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data)
                               : (vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data 
                                  == vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data))));
    vlTOPp->cpu_top__DOT__is_branch_jump = ((IData)(vlTOPp->cpu_top__DOT__is_branch) 
                                            & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__Vfuncout));
    vlTOPp->cpu_top__DOT__csr__DOT__bitmask = ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->cpu_top__DOT__inst 
                                                    >> 0xfU)))
                                                ? vlTOPp->cpu_top__DOT__rs1_data
                                                : 0xffffffffU);
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
        = vlTOPp->cpu_top__DOT__inst;
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type 
        = vlTOPp->cpu_top__DOT__decode__DOT__opcode_type;
    vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
                ? 0U : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
                         ? ((0xffe00000U & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                           >> 0x1fU)))) 
                                            << 0x15U)) 
                            | ((0x100000U & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                             >> 0xbU)) 
                               | ((0xff000U & vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst) 
                                  | ((0x800U & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                >> 9U)) 
                                     | (0x7feU & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                  >> 0x14U))))))
                         : (0xfffff000U & vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst)))
            : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
                    ? ((0xffffe000U & ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                      >> 0x1fU)))) 
                                       << 0xdU)) | 
                       ((0x1000U & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                    >> 0x13U)) | ((0x800U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                      << 4U)) 
                                                  | ((0x7e0U 
                                                      & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                           >> 7U))))))
                    : ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                    >> 7U)))))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       (0xfffU & (vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst 
                                  >> 0x14U))) : 0U)));
    vlTOPp->cpu_top__DOT__imm = vlTOPp->__Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__Vfuncout;
    vlTOPp->cpu_top__DOT__alu_in2 = ((IData)(vlTOPp->cpu_top__DOT__alu_in2_use_imm)
                                      ? vlTOPp->cpu_top__DOT__imm
                                      : vlTOPp->cpu_top__DOT__rs2_data);
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mip 
        = vlTOPp->cpu_top__DOT__csr__DOT__mip;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtval 
        = vlTOPp->cpu_top__DOT__csr__DOT__mtval;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mcause 
        = vlTOPp->cpu_top__DOT__csr__DOT__mcause;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mepc 
        = vlTOPp->cpu_top__DOT__csr__DOT__mepc;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mscratch 
        = vlTOPp->cpu_top__DOT__csr__DOT__mscratch;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtvec 
        = vlTOPp->cpu_top__DOT__csr__DOT__mtvec;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mie 
        = vlTOPp->cpu_top__DOT__csr__DOT__mie;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__misa 
        = vlTOPp->cpu_top__DOT__csr__DOT__misa;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mstatus 
        = vlTOPp->cpu_top__DOT__csr__DOT__mstatus;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr 
        = (0xfffU & vlTOPp->cpu_top__DOT__imm);
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__Vfuncout 
        = (((((((((0x300U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr)) 
                  | (0x301U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
                 | (0x304U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
                | (0x305U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
               | (0x340U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
              | (0x341U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
             | (0x342U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))) 
            | (0x343U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr)))
            ? ((0x300U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mstatus
                : ((0x301U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                    ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__misa
                    : ((0x304U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                        ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mie
                        : ((0x305U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                            ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtvec
                            : ((0x340U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                                ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mscratch
                                : ((0x341U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                                    ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mepc
                                    : ((0x342U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                                        ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mcause
                                        : vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtval)))))))
            : ((0x344U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr))
                ? vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mip
                : 0U));
    vlTOPp->cpu_top__DOT__csr_data = vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__Vfuncout;
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift 
        = (0x1fU & ((IData)(vlTOPp->cpu_top__DOT__is_r_type)
                     ? vlTOPp->cpu_top__DOT__rs2_data
                     : (vlTOPp->cpu_top__DOT__inst 
                        >> 0x14U)));
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sra 
        = (1U & (vlTOPp->cpu_top__DOT__inst >> 0x1eU));
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sub 
        = ((IData)(vlTOPp->cpu_top__DOT__is_r_type) 
           & (vlTOPp->cpu_top__DOT__inst >> 0x1eU));
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2 
        = vlTOPp->cpu_top__DOT__alu_in2;
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
        = ((IData)(vlTOPp->cpu_top__DOT__alu_in1_use_pc)
            ? vlTOPp->cpu_top__DOT__pc : vlTOPp->cpu_top__DOT__rs1_data);
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op 
        = ((IData)(vlTOPp->cpu_top__DOT__decode__DOT__use_adder)
            ? 0U : (7U & (vlTOPp->cpu_top__DOT__inst 
                          >> 0xcU)));
    vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                    ? (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                       & vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)
                    : (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                       | vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                    ? ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sra)
                        ? VL_SHIFTRS_III(32,32,5, vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1, (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift))
                        : (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                           >> (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift)))
                    : (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                       ^ vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)))
            : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                    ? ((vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                        < vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)
                        ? 1U : 0U) : (VL_LTS_III(1,32,32, vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1, vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)
                                       ? 1U : 0U)) : 
               ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op))
                 ? (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                    << (IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift))
                 : ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sub)
                     ? (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                        - vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)
                     : (vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 
                        + vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2)))));
    vlTOPp->cpu_top__DOT__alu_out = ((0x37U == (0x7fU 
                                                & vlTOPp->cpu_top__DOT__inst))
                                      ? vlTOPp->cpu_top__DOT__alu_in2
                                      : vlTOPp->__Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__Vfuncout);
    vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm 
        = (vlTOPp->cpu_top__DOT__csr_data & (~ vlTOPp->cpu_top__DOT__csr__DOT__bitmask));
    vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_wdata 
        = ((vlTOPp->cpu_top__DOT__csr_data & (~ vlTOPp->cpu_top__DOT__csr__DOT__bitmask)) 
           | (vlTOPp->cpu_top__DOT__rs1_data & vlTOPp->cpu_top__DOT__csr__DOT__bitmask));
    vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_uimm 
        = ((vlTOPp->cpu_top__DOT__csr_data & (~ vlTOPp->cpu_top__DOT__csr__DOT__bitmask)) 
           | (0x1fU & ((vlTOPp->cpu_top__DOT__inst 
                        >> 0xfU) & vlTOPp->cpu_top__DOT__csr__DOT__bitmask)));
    vlTOPp->cpu_top__DOT__uart_we = ((0xf6fff070U == vlTOPp->cpu_top__DOT__alu_out) 
                                     & (IData)(vlTOPp->cpu_top__DOT__is_store));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__ext_uimm 
        = (0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0xfU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_wdata;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_wdata 
        = vlTOPp->cpu_top__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_uimm)) 
                               << 3U)) : (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_uimm)) 
                                                  << 3U)))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__ext_uimm)) 
                               << 3U)) : 0ULL)) : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_wdata)) 
                                                        << 3U))
                                                     : 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_wdata)) 
                                                        << 3U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_wdata)) 
                                                        << 3U))
                                                     : 2ULL)));
    vlTOPp->cpu_top__DOT__csr__DOT__csr_data = (IData)(
                                                       (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__Vfuncout 
                                                        >> 3U));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__ext_uimm 
        = (0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0xfU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_wdata;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_wdata 
        = vlTOPp->cpu_top__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_uimm)) 
                               << 3U)) : (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_uimm)) 
                                                  << 3U)))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__ext_uimm)) 
                               << 3U)) : 0ULL)) : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_wdata)) 
                                                        << 3U))
                                                     : 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_wdata)) 
                                                        << 3U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_wdata)) 
                                                        << 3U))
                                                     : 2ULL)));
    vlTOPp->cpu_top__DOT__csr__DOT__is_priv = (1U & (IData)(
                                                            (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__Vfuncout 
                                                             >> 1U)));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__ext_uimm 
        = (0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0xfU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_wdata;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_wdata 
        = vlTOPp->cpu_top__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_uimm)) 
                               << 3U)) : (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_uimm)) 
                                                  << 3U)))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__ext_uimm)) 
                               << 3U)) : 0ULL)) : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_wdata)) 
                                                        << 3U))
                                                     : 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_wdata)) 
                                                        << 3U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_wdata)) 
                                                        << 3U))
                                                     : 2ULL)));
    vlTOPp->cpu_top__DOT__csr__DOT__tmp_write_back 
        = (1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__Vfuncout));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_uimm 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__ext_uimm 
        = (0x1fU & (vlTOPp->cpu_top__DOT__inst >> 0xfU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_cleared_uimm;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_wdata 
        = vlTOPp->cpu_top__DOT__csr__DOT__csr_bitmask_wdata;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_wdata 
        = vlTOPp->cpu_top__DOT__rs1_data;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_uimm)) 
                               << 3U)) : (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_uimm)) 
                                                  << 3U)))
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                    ? (5ULL | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__ext_uimm)) 
                               << 3U)) : 0ULL)) : (
                                                   (2U 
                                                    & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_wdata)) 
                                                        << 3U))
                                                     : 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_wdata)) 
                                                        << 3U)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op))
                                                     ? 
                                                    (5ULL 
                                                     | ((QData)((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_wdata)) 
                                                        << 3U))
                                                     : 2ULL)));
    vlTOPp->cpu_top__DOT__csr__DOT__is_write = (1U 
                                                & (IData)(
                                                          (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__Vfuncout 
                                                           >> 2U)));
    vlTOPp->cpu_top__DOT__is_illegal = ((IData)(vlTOPp->cpu_top__DOT__is_system) 
                                        & (((IData)(vlTOPp->cpu_top__DOT__is_system) 
                                            & ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode) 
                                               > (3U 
                                                  & (vlTOPp->cpu_top__DOT__imm 
                                                     >> 8U)))) 
                                           | ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_write) 
                                              & (3U 
                                                 == 
                                                 (3U 
                                                  & (vlTOPp->cpu_top__DOT__imm 
                                                     >> 0xaU))))));
    if (vlTOPp->cpu_top__DOT__is_illegal) {
        vlTOPp->cpu_top__DOT__csr__DOT__tval = (0xfffU 
                                                & vlTOPp->cpu_top__DOT__imm);
        vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__is_illegal = 1U;
    } else {
        vlTOPp->cpu_top__DOT__csr__DOT__tval = vlTOPp->cpu_top__DOT__pc;
        vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__is_illegal = 0U;
    }
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mip 
        = vlTOPp->cpu_top__DOT__csr__DOT__mip;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mie 
        = vlTOPp->cpu_top__DOT__csr__DOT__mie;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__global_mie 
        = (1U & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                 >> 3U));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12 
        = (0xfffU & vlTOPp->cpu_top__DOT__imm);
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__is_illegal)
            ? 0x80000002ULL : (((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__global_mie) 
                                & (0U != (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mie 
                                          & (0U != vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mip))))
                                ? (0x180000000ULL | (QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mie 
                                                                        & vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mip)))))
                                : ((0x302U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12))
                                    ? 0x100000000ULL
                                    : ((0x105U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12))
                                        ? 0x100000000ULL
                                        : ((0U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12))
                                            ? ((0U 
                                                == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                ? 0x80000008ULL
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                    ? 0x80000009ULL
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                     ? 0x8000000aULL
                                                     : 0x80000002ULL)))
                                            : ((1U 
                                                == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12))
                                                ? 0x80000003ULL
                                                : 0ULL))))));
    vlTOPp->cpu_top__DOT__csr__DOT__exception_code 
        = (0x7fffffffU & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__Vfuncout));
    vlTOPp->cpu_top__DOT__is_write_back_from_csr = 
        ((((IData)(vlTOPp->cpu_top__DOT__is_system) 
           & (IData)(vlTOPp->cpu_top__DOT__csr__DOT__tmp_write_back)) 
          & (~ (IData)(vlTOPp->cpu_top__DOT__is_illegal))) 
         & (0U != (0x1fU & (vlTOPp->cpu_top__DOT__inst 
                            >> 7U))));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__is_illegal 
        = vlTOPp->cpu_top__DOT__is_illegal;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mip 
        = vlTOPp->cpu_top__DOT__csr__DOT__mip;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mie 
        = vlTOPp->cpu_top__DOT__csr__DOT__mie;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__global_mie 
        = (1U & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                 >> 3U));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12 
        = (0xfffU & vlTOPp->cpu_top__DOT__imm);
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__is_illegal)
            ? 0x80000002ULL : (((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__global_mie) 
                                & (0U != (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mie 
                                          & (0U != vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mip))))
                                ? (0x180000000ULL | (QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mie 
                                                                        & vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mip)))))
                                : ((0x302U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12))
                                    ? 0x100000000ULL
                                    : ((0x105U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12))
                                        ? 0x100000000ULL
                                        : ((0U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12))
                                            ? ((0U 
                                                == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                ? 0x80000008ULL
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                    ? 0x80000009ULL
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                     ? 0x8000000aULL
                                                     : 0x80000002ULL)))
                                            : ((1U 
                                                == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12))
                                                ? 0x80000003ULL
                                                : 0ULL))))));
    vlTOPp->cpu_top__DOT__csr__DOT__update_pc = (1U 
                                                 & (IData)(
                                                           (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__Vfuncout 
                                                            >> 0x20U)));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__is_illegal 
        = vlTOPp->cpu_top__DOT__is_illegal;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mip 
        = vlTOPp->cpu_top__DOT__csr__DOT__mip;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mie 
        = vlTOPp->cpu_top__DOT__csr__DOT__mie;
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__global_mie 
        = (1U & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                 >> 3U));
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12 
        = (0xfffU & vlTOPp->cpu_top__DOT__imm);
    vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__is_illegal)
            ? 0x80000002ULL : (((IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__global_mie) 
                                & (0U != (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mie 
                                          & (0U != vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mip))))
                                ? (0x180000000ULL | (QData)((IData)(
                                                                    (0x7fffffffU 
                                                                     & (vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mie 
                                                                        & vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mip)))))
                                : ((0x302U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12))
                                    ? 0x100000000ULL
                                    : ((0x105U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12))
                                        ? 0x100000000ULL
                                        : ((0U == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12))
                                            ? ((0U 
                                                == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                ? 0x80000008ULL
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                    ? 0x80000009ULL
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->cpu_top__DOT__csr__DOT__cpu_mode))
                                                     ? 0x8000000aULL
                                                     : 0x80000002ULL)))
                                            : ((1U 
                                                == (IData)(vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12))
                                                ? 0x80000003ULL
                                                : 0ULL))))));
    vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt = 
        (1U & (IData)((vlTOPp->__Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__Vfuncout 
                       >> 0x1fU)));
}

VL_INLINE_OPT void Vcpu_top::_multiclk__TOP__6(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_multiclk__TOP__6\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem 
        = (3U & vlTOPp->cpu_top__DOT__alu_out);
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
        = ((0x10000U >= (0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                                     >> 2U))) ? vlTOPp->cpu_top__DOT__mem__DOT__mem
           [(0x1ffffU & (vlTOPp->cpu_top__DOT__alu_out 
                         >> 2U))] : 0U);
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__Vfuncout 
        = ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem))
            ? ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem))
                ? ((0xffffff00U & ((- (IData)((1U & 
                                               (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                >> 0x1fU)))) 
                                   << 8U)) | (0xffU 
                                              & (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                 >> 0x18U)))
                : ((0xffff0000U & ((- (IData)((1U & 
                                               (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                >> 0x1fU)))) 
                                   << 0x10U)) | (0xffffU 
                                                 & (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                    >> 0x10U))))
            : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem))
                ? ((0xff000000U & ((- (IData)((1U & 
                                               (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                >> 0x1fU)))) 
                                   << 0x18U)) | (0xffffffU 
                                                 & (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data 
                                                    >> 8U)))
                : vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data));
    vlTOPp->cpu_top__DOT__mem__DOT__data = vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_data__16__Vfuncout;
}

VL_INLINE_OPT void Vcpu_top::_combo__TOP__7(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_combo__TOP__7\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__csr_pc 
        = (((0x105U == (0xfffU & vlTOPp->cpu_top__DOT__imm)) 
            & (~ (IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt)))
            ? vlTOPp->cpu_top__DOT__pc : ((IData)(vlTOPp->cpu_top__DOT__csr__DOT__is_interrupt)
                                           ? (1U & 
                                              ((0U 
                                                == 
                                                (3U 
                                                 & vlTOPp->cpu_top__DOT__csr__DOT__mtvec))
                                                ? vlTOPp->cpu_top__DOT__csr__DOT__mtvec
                                                : (
                                                   (vlTOPp->cpu_top__DOT__csr__DOT__mtvec 
                                                    + 
                                                    (0x7fffffffU 
                                                     & vlTOPp->cpu_top__DOT__csr__DOT__mcause)) 
                                                   << 2U)))
                                           : (1U & 
                                              (vlTOPp->cpu_top__DOT__csr__DOT__mtvec 
                                               >> 2U))));
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__enable_pc_update_from_csr 
        = ((IData)(vlTOPp->cpu_top__DOT__is_system) 
           & (IData)(vlTOPp->cpu_top__DOT__csr__DOT__update_pc));
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__pc_plus4 
        = ((IData)(4U) + vlTOPp->cpu_top__DOT__pc);
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__jump_addr 
        = vlTOPp->cpu_top__DOT__alu_out;
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__is_jump 
        = ((IData)(vlTOPp->cpu_top__DOT__is_branch_jump) 
           | (IData)(vlTOPp->cpu_top__DOT__store_pc4));
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__rstn 
        = vlTOPp->rstn;
    vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__rstn)
            ? ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__enable_pc_update_from_csr)
                ? vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__csr_pc
                : ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__is_jump)
                    ? vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__jump_addr
                    : vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__pc_plus4))
            : 0x8000U);
    vlTOPp->cpu_top__DOT__pc_next = vlTOPp->__Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__Vfuncout;
}

VL_INLINE_OPT void Vcpu_top::_multiclk__TOP__8(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_multiclk__TOP__8\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type 
        = (7U & (vlTOPp->cpu_top__DOT__inst >> 0xcU));
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data 
        = vlTOPp->cpu_top__DOT__mem__DOT__data;
    vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__Vfuncout 
        = ((4U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type))
            ? ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type))
                ? vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type))
                    ? (0xffffU & vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data)
                    : (0xffU & vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data)))
            : ((2U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type))
                ? vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data
                : ((1U & (IData)(vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type))
                    ? ((0xffff0000U & ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data 
                                                      >> 0xfU)))) 
                                       << 0x10U)) | 
                       (0xffffU & vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data))
                    : ((0xffffff00U & ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data 
                                                      >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data)))));
    vlTOPp->cpu_top__DOT__loaddata = (((0xffffff00U 
                                        == vlTOPp->cpu_top__DOT__alu_out) 
                                       & (2U == (7U 
                                                 & (vlTOPp->cpu_top__DOT__inst 
                                                    >> 0xcU))))
                                       ? vlTOPp->cpu_top__DOT__hardware_counter_0__DOT__cycles
                                       : vlTOPp->__Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__Vfuncout);
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__store_pc4 
        = vlTOPp->cpu_top__DOT__store_pc4;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__alu_out 
        = vlTOPp->cpu_top__DOT__alu_out;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__loaddata 
        = vlTOPp->cpu_top__DOT__loaddata;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__is_load 
        = vlTOPp->cpu_top__DOT__is_load;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_data 
        = vlTOPp->cpu_top__DOT__csr_data;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_writeback 
        = vlTOPp->cpu_top__DOT__is_write_back_from_csr;
    vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__Vfuncout 
        = ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_writeback)
            ? vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_data
            : ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__store_pc4)
                ? ((IData)(4U) + vlTOPp->cpu_top__DOT__pc)
                : ((IData)(vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__is_load)
                    ? vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__loaddata
                    : vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__alu_out)));
    vlTOPp->cpu_top__DOT__rd_data = vlTOPp->__Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__Vfuncout;
}

void Vcpu_top::_eval(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_eval\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rstn)) & (IData)(vlTOPp->__Vclklast__TOP__rstn)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_multiclk__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    if ((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((~ (IData)(vlTOPp->rstn)) & (IData)(vlTOPp->__Vclklast__TOP__rstn)))) {
        vlTOPp->_multiclk__TOP__8(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

VL_INLINE_OPT QData Vcpu_top::_change_request(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_change_request\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vcpu_top::_change_request_1(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_change_request_1\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rstn & 0xfeU))) {
        Verilated::overWidthError("rstn");}
}
#endif  // VL_DEBUG
