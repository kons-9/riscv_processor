// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu_top.h for the primary calling header

#include "Vcpu_top.h"
#include "Vcpu_top__Syms.h"

//==========

VL_CTOR_IMP(Vcpu_top) {
    Vcpu_top__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu_top__Syms(this, name());
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu_top::__Vconfigure(Vcpu_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vcpu_top::~Vcpu_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vcpu_top::_initial__TOP__1(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_initial__TOP__1\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*511:0*/ __Vtemp1[16];
    WData/*511:0*/ __Vtemp2[16];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x64617461U;
    __Vtemp1[2U] = 0x61726b2fU;
    __Vtemp1[3U] = 0x6f72656dU;
    __Vtemp1[4U] = 0x6b732f43U;
    __Vtemp1[5U] = 0x686d6172U;
    __Vtemp1[6U] = 0x62656e63U;
    __Vtemp1[7U] = 0x6578702fU;
    __Vtemp1[8U] = 0x732f6233U;
    __Vtemp1[9U] = 0x6d656e74U;
    __Vtemp1[0xaU] = 0x446f6375U;
    __Vtemp1[0xbU] = 0x746f732fU;
    __Vtemp1[0xcU] = 0x732f676fU;
    __Vtemp1[0xdU] = 0x55736572U;
    __Vtemp1[0xeU] = 0x742f632fU;
    __Vtemp1[0xfU] = 0x2f6d6eU;
    VL_READMEM_N(true, 32, 65537, 0, VL_CVT_PACK_STR_NW(16, __Vtemp1)
                 , vlTOPp->cpu_top__DOT__mem__DOT__mem
                 , 0, ~0ULL);
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x636f6465U;
    __Vtemp2[2U] = 0x61726b2fU;
    __Vtemp2[3U] = 0x6f72656dU;
    __Vtemp2[4U] = 0x6b732f43U;
    __Vtemp2[5U] = 0x686d6172U;
    __Vtemp2[6U] = 0x62656e63U;
    __Vtemp2[7U] = 0x6578702fU;
    __Vtemp2[8U] = 0x732f6233U;
    __Vtemp2[9U] = 0x6d656e74U;
    __Vtemp2[0xaU] = 0x446f6375U;
    __Vtemp2[0xbU] = 0x746f732fU;
    __Vtemp2[0xcU] = 0x732f676fU;
    __Vtemp2[0xdU] = 0x55736572U;
    __Vtemp2[0xeU] = 0x742f632fU;
    __Vtemp2[0xfU] = 0x2f6d6eU;
    VL_READMEM_N(true, 32, 32000, 0, VL_CVT_PACK_STR_NW(16, __Vtemp2)
                 , vlTOPp->cpu_top__DOT__fetch__DOT__instbram__DOT__mem
                 , 0, ~0ULL);
}

void Vcpu_top::_settle__TOP__5(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_settle__TOP__5\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpp = (3U 
                                                   & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
                                                      >> 0xbU));
    vlTOPp->cpu_top__DOT__csr__DOT__mstatus_mpie = 
        (1U & (vlTOPp->cpu_top__DOT__csr__DOT__mstatus 
               >> 7U));
    vlTOPp->cpu_top__DOT__uart0__DOT__uart_busy = (0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount) 
                                                       >> 1U)));
    vlTOPp->cpu_top__DOT__uart0__DOT__sending = (0U 
                                                 != (IData)(vlTOPp->cpu_top__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu_top__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                              & (vlTOPp->cpu_top__DOT__uart0__DOT__d 
                                                 + 
                                                 ((0x10000000U 
                                                   & vlTOPp->cpu_top__DOT__uart0__DOT__d)
                                                   ? 0x1c200U
                                                   : 0xff692b80U)));
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

void Vcpu_top::_eval_initial(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_eval_initial\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rstn = vlTOPp->rstn;
}

void Vcpu_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::final\n"); );
    // Variables
    Vcpu_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu_top::_eval_settle(Vcpu_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_eval_settle\n"); );
    Vcpu_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vcpu_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu_top::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rstn = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    cpu_top__DOT__pc = VL_RAND_RESET_I(32);
    cpu_top__DOT__pc_next = VL_RAND_RESET_I(32);
    cpu_top__DOT__is_branch_jump = VL_RAND_RESET_I(1);
    cpu_top__DOT__alu_out = VL_RAND_RESET_I(32);
    cpu_top__DOT__inst = VL_RAND_RESET_I(32);
    cpu_top__DOT__imm = VL_RAND_RESET_I(32);
    cpu_top__DOT__is_store = VL_RAND_RESET_I(1);
    cpu_top__DOT__is_load = VL_RAND_RESET_I(1);
    cpu_top__DOT__is_writeback = VL_RAND_RESET_I(1);
    cpu_top__DOT__alu_in1_use_pc = VL_RAND_RESET_I(1);
    cpu_top__DOT__alu_in2_use_imm = VL_RAND_RESET_I(1);
    cpu_top__DOT__is_r_type = VL_RAND_RESET_I(1);
    cpu_top__DOT__is_branch = VL_RAND_RESET_I(1);
    cpu_top__DOT__store_pc4 = VL_RAND_RESET_I(1);
    cpu_top__DOT__is_system = VL_RAND_RESET_I(1);
    cpu_top__DOT__rs1_data = VL_RAND_RESET_I(32);
    cpu_top__DOT__rs2_data = VL_RAND_RESET_I(32);
    cpu_top__DOT__rd_data = VL_RAND_RESET_I(32);
    cpu_top__DOT__alu_in2 = VL_RAND_RESET_I(32);
    cpu_top__DOT__is_illegal = VL_RAND_RESET_I(1);
    cpu_top__DOT__uart_we = VL_RAND_RESET_I(1);
    cpu_top__DOT__loaddata = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr_data = VL_RAND_RESET_I(32);
    cpu_top__DOT__is_write_back_from_csr = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32000; ++__Vi0) {
            cpu_top__DOT__fetch__DOT__instbram__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu_top__DOT__decode__DOT__opcode_type = VL_RAND_RESET_I(3);
    cpu_top__DOT__decode__DOT__is_jal = VL_RAND_RESET_I(1);
    cpu_top__DOT__decode__DOT__is_jalr = VL_RAND_RESET_I(1);
    cpu_top__DOT__decode__DOT__use_adder = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu_top__DOT__regfile__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<65537; ++__Vi0) {
            cpu_top__DOT__mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu_top__DOT__mem__DOT__data = VL_RAND_RESET_I(32);
    cpu_top__DOT__mem__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    cpu_top__DOT__mem__DOT____Vlvbound2 = VL_RAND_RESET_I(8);
    cpu_top__DOT__mem__DOT____Vlvbound3 = VL_RAND_RESET_I(8);
    cpu_top__DOT__mem__DOT____Vlvbound4 = VL_RAND_RESET_I(8);
    cpu_top__DOT__mem__DOT____Vlvbound5 = VL_RAND_RESET_I(16);
    cpu_top__DOT__mem__DOT____Vlvbound6 = VL_RAND_RESET_I(16);
    cpu_top__DOT__mem__DOT____Vlvbound7 = VL_RAND_RESET_I(16);
    cpu_top__DOT__mem__DOT____Vlvbound8 = VL_RAND_RESET_I(32);
    cpu_top__DOT__mem__DOT____Vlvbound9 = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__cpu_mode = VL_RAND_RESET_I(3);
    cpu_top__DOT__csr__DOT__mstatus = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__misa = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mie = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mtvec = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mscratch = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mepc = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mcause = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mtval = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mip = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__mstatus_mpp = VL_RAND_RESET_I(2);
    cpu_top__DOT__csr__DOT__mstatus_mpie = VL_RAND_RESET_I(1);
    cpu_top__DOT__csr__DOT__exception_code = VL_RAND_RESET_I(31);
    cpu_top__DOT__csr__DOT__update_pc = VL_RAND_RESET_I(1);
    cpu_top__DOT__csr__DOT__is_interrupt = VL_RAND_RESET_I(1);
    cpu_top__DOT__csr__DOT__tval = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__bitmask = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__csr_bitmask_wdata = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__csr_bitmask_uimm = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__csr_cleared_uimm = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__csr_data = VL_RAND_RESET_I(32);
    cpu_top__DOT__csr__DOT__is_write = VL_RAND_RESET_I(1);
    cpu_top__DOT__csr__DOT__is_priv = VL_RAND_RESET_I(1);
    cpu_top__DOT__csr__DOT__tmp_write_back = VL_RAND_RESET_I(1);
    cpu_top__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    cpu_top__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    cpu_top__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    cpu_top__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    cpu_top__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    cpu_top__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    cpu_top__DOT__hardware_counter_0__DOT__cycles = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__rstn = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__is_jump = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__jump_addr = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__pc_plus4 = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__enable_pc_update_from_csr = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__gen_next_pc__DOT__func_next_pc__0__csr_pc = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__1__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__2__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__3__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__4__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__5__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__6__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__7__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__8__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__9__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__10__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__11__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__Vfuncout = VL_RAND_RESET_I(14);
    __Vfunc_cpu_top__DOT__decode__DOT__get_opcode_info__12__opcode = VL_RAND_RESET_I(7);
    __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__opcode_type = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__decode__DOT__get_imm__13__inst = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__alu_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in1 = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__in2 = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sub = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__is_sra = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__alu__DOT__alu_out__14__shift = VL_RAND_RESET_I(5);
    __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__branch_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs1_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__branch_conditional__DOT__func_branch_conditional__15__rs2_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__raw_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__mem__DOT__get_data__16__addr_rem = VL_RAND_RESET_I(2);
    __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__data = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__mem__DOT__get_loaddata__17__store_load_type = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_writeback = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__csr_data = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__is_load = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__loaddata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__alu_out = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__writeback__DOT__get_rd_data__18__store_pc4 = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__Vfuncout = VL_RAND_RESET_Q(33);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__funct12 = VL_RAND_RESET_I(12);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__global_mie = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mie = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__mip = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__19__is_illegal = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__Vfuncout = VL_RAND_RESET_Q(33);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__funct12 = VL_RAND_RESET_I(12);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__global_mie = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mie = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__mip = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__20__is_illegal = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__Vfuncout = VL_RAND_RESET_Q(33);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__funct12 = VL_RAND_RESET_I(12);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__global_mie = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mie = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__mip = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__get_mcause__21__is_illegal = VL_RAND_RESET_I(1);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__csr_addr = VL_RAND_RESET_I(12);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mstatus = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__misa = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mie = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtvec = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mscratch = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mepc = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mcause = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mtval = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__read_csr__22__mip = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__Vfuncout = VL_RAND_RESET_Q(35);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__ext_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_bitmask_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__23__csr_cleared_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__Vfuncout = VL_RAND_RESET_Q(35);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__ext_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_bitmask_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__24__csr_cleared_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__Vfuncout = VL_RAND_RESET_Q(35);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__ext_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_bitmask_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__25__csr_cleared_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__Vfuncout = VL_RAND_RESET_Q(35);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_op = VL_RAND_RESET_I(3);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_wdata = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__ext_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_bitmask_uimm = VL_RAND_RESET_I(32);
    __Vfunc_cpu_top__DOT__csr__DOT__decode_csr_operation__26__csr_cleared_uimm = VL_RAND_RESET_I(32);
}
