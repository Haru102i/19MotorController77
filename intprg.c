/************************************************************************
*
* Device     : RX/RX600/RX66T
*
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 0.5  (2018-01-12)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2018 Renesas Electronics Corporation.
*
************************************************************************/

#include <machine.h>
#include "vect.h"
#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(){  } */}

// Exception(Access Instruction)
void Excep_AccessInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(){  } */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(){  } */}

// NMI
void NonMaskableInterrupt(void){/* brk(){  } */}

// Dummy
void Dummy(void){/* brk(){  } */}

// BRK
void Excep_BRK(void){ wait(); }

// BSC_BUSERR
void Excep_BSC_BUSERR(void){ }

// RAM_RAMERR
void Excep_RAM_RAMERR(void){ }

// FCU_FIFERR
void Excep_FCU_FIFERR(void){ }

// FCU_FRDYI
void Excep_FCU_FRDYI(void){ }

// ICU_SWINT2
void Excep_ICU_SWINT2(void){ }

// ICU_SWINT
void Excep_ICU_SWINT(void){ }

// CMT0_CMI0
void Excep_CMT0_CMI0(void){ }

// CMT1_CMI1
void Excep_CMT1_CMI1(void){ }

// CMT2_CMI2
void Excep_CMT2_CMI2(void){ }

// CMT3_CMI3
void Excep_CMT3_CMI3(void){ }

// USB0_D0FIFO0
void Excep_USB0_D0FIFO0(void){ }

// USB0_D1FIFO0
void Excep_USB0_D1FIFO0(void){ }

// RSPI0_SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0_SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RIIC0_RXI0
void Excep_RIIC0_RXI0(void){ }

// RIIC0_TXI0
void Excep_RIIC0_TXI0(void){ }

// SCI1_RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1_TXI1
void Excep_SCI1_TXI1(void){ }

// ICU_IRQ0
void Excep_ICU_IRQ0(void){ }

// ICU_IRQ1
void Excep_ICU_IRQ1(void){ }

// ICU_IRQ2
void Excep_ICU_IRQ2(void){ }

// ICU_IRQ3
void Excep_ICU_IRQ3(void){ }

// ICU_IRQ4
void Excep_ICU_IRQ4(void){ }

// ICU_IRQ5
void Excep_ICU_IRQ5(void){ }

// ICU_IRQ6
void Excep_ICU_IRQ6(void){ }

// ICU_IRQ7
void Excep_ICU_IRQ7(void){ }

// ICU_IRQ8
void Excep_ICU_IRQ8(void){ }

// ICU_IRQ9
void Excep_ICU_IRQ9(void){ }

// ICU_IRQ10
void Excep_ICU_IRQ10(void){ }

// ICU_IRQ11
void Excep_ICU_IRQ11(void){ }

// ICU_IRQ12
void Excep_ICU_IRQ12(void){ }

// ICU_IRQ13
void Excep_ICU_IRQ13(void){ }

// ICU_IRQ14
void Excep_ICU_IRQ14(void){ }

// ICU_IRQ15
void Excep_ICU_IRQ15(void){ }

// SCI5_RXI5
void Excep_SCI5_RXI5(void){ }

// SCI5_TXI5
void Excep_SCI5_TXI5(void){ }

// SCI6_RXI6
void Excep_SCI6_RXI6(void){ }

// SCI6_TXI6
void Excep_SCI6_TXI6(void){ }

// LVD1_LVD1
void Excep_LVD1_LVD1(void){ }

// LVD2_LVD2
void Excep_LVD2_LVD2(void){ }

// USB0_USBR0
void Excep_USB0_USBR0(void){ }

// IWDT_IWUNI
void Excep_IWDT_IWUNI(void){ }

// WDT_WUNI
void Excep_WDT_WUNI(void){ }

// SCI8_RXI8
void Excep_SCI8_RXI8(void){ }

// SCI8_TXI8
void Excep_SCI8_TXI8(void){ }

// SCI9_RXI9
void Excep_SCI9_RXI9(void){ }

// SCI9_TXI9
void Excep_SCI9_TXI9(void){ }

// ICU_GROUPBE0
void Excep_ICU_GROUPBE0(void){ }

// ICU_GROUPBL0
void Excep_ICU_GROUPBL0(void){ }

// ICU_GROUPBL1
void Excep_ICU_GROUPBL1(void){ }

// ICU_GROUPAL0
void Excep_ICU_GROUPAL0(void){ }

// SCI11_RXI11
void Excep_SCI11_RXI11(void){ }

// SCI11_TXI11
void Excep_SCI11_TXI11(void){ }

// SCI12_RXI12
void Excep_SCI12_RXI12(void){ }

// SCI12_TXI12
void Excep_SCI12_TXI12(void){ }

// DMAC_DMAC0I
void Excep_DMAC_DMAC0I(void){ }

// DMAC_DMAC1I
void Excep_DMAC_DMAC1I(void){ }

// DMAC_DMAC2I
void Excep_DMAC_DMAC2I(void){ }

// DMAC_DMAC3I
void Excep_DMAC_DMAC3I(void){ }

// DMAC_DMAC74I
void Excep_DMAC_DMAC74I(void){ }

// OST_OSTDI
void Excep_OST_OSTDI(void){ }

// S12AD_S12ADI
void Excep_S12AD_S12ADI(void){ }

// S12AD_S12GBADI
void Excep_S12AD_S12GBADI(void){ }

// S12AD_S12GCADI
void Excep_S12AD_S12GCADI(void){ }

// S12AD1_S12ADI1
void Excep_S12AD1_S12ADI1(void){ }

// S12AD1_S12GBADI1
void Excep_S12AD1_S12GBADI1(void){ }

// S12AD1_S12GCADI1
void Excep_S12AD1_S12GCADI1(void){ }

// S12AD2_S12ADI2
void Excep_S12AD2_S12ADI2(void){ }

// S12AD2_S12GBADI2
void Excep_S12AD2_S12GBADI2(void){ }

// S12AD2_S12GCADI2
void Excep_S12AD2_S12GCADI2(void){ }

// TMR0_CMIA0
void Excep_TMR0_CMIA0(void){ }

// TMR0_CMIB0
void Excep_TMR0_CMIB0(void){ }

// TMR0_OVI0
void Excep_TMR0_OVI0(void){ }

// TMR1_CMIA1
void Excep_TMR1_CMIA1(void){ }

// TMR1_CMIB1
void Excep_TMR1_CMIB1(void){ }

// TMR1_OVI1
void Excep_TMR1_OVI1(void){ }

// TMR2_CMIA2
void Excep_TMR2_CMIA2(void){ }

// TMR2_CMIB2
void Excep_TMR2_CMIB2(void){ }

// TMR2_OVI2
void Excep_TMR2_OVI2(void){ }

// TMR3_CMIA3
void Excep_TMR3_CMIA3(void){ }

// TMR3_CMIB3
void Excep_TMR3_CMIB3(void){ }

// TMR3_OVI3
void Excep_TMR3_OVI3(void){ }

// TMR4_CMIA4
void Excep_TMR4_CMIA4(void){ }

// TMR4_CMIB4
void Excep_TMR4_CMIB4(void){ }

// TMR4_OVI4
void Excep_TMR4_OVI4(void){ }

// TMR5_CMIA5
void Excep_TMR5_CMIA5(void){ }

// TMR5_CMIB5
void Excep_TMR5_CMIB5(void){ }

// TMR5_OVI5
void Excep_TMR5_OVI5(void){ }

// TMR6_CMIA6
void Excep_TMR6_CMIA6(void){ }

// TMR6_CMIB6
void Excep_TMR6_CMIB6(void){ }

// TMR6_OVI6
void Excep_TMR6_OVI6(void){ }

// TMR7_CMIA7
void Excep_TMR7_CMIA7(void){ }

// TMR7_CMIB7
void Excep_TMR7_CMIB7(void){ }

// TMR7_OVI7
void Excep_TMR7_OVI7(void){ }

// CAN0_RXF0
void Excep_CAN0_RXF0(void){ }

// CAN0_TXF0
void Excep_CAN0_TXF0(void){ }

// CAN0_RXM0
void Excep_CAN0_RXM0(void){ }

// CAN0_TXM0
void Excep_CAN0_TXM0(void){ }

// USB0_USBI0
void Excep_USB0_USBI0(void){ }

// ELC_ELSR18I
void Excep_ELC_ELSR18I(void){ }

// ELC_ELSR19I
void Excep_ELC_ELSR19I(void){ }

// TSIP-Lite_RD
void Excep_TSIP_Lite_RD(void){ }

// TSIP-Lite_WR
void Excep_TSIP_Lite_WR(void){ }

// TSIP-Lite_Error
void Excep_TSIP_Lite_Error(void){ }

// CMPC0_CMPC0
void Excep_CMPC0_CMPC0(void){ }

// CMPC1_CMPC1
void Excep_CMPC1_CMPC1(void){ }

// CMPC2_CMPC2
void Excep_CMPC2_CMPC2(void){ }

// CMPC3_CMPC3
void Excep_CMPC3_CMPC3(void){ }

// CMPC4_CMPC4
void Excep_CMPC4_CMPC4(void){ }

// CMPC5_CMPC5
void Excep_CMPC5_CMPC5(void){ }

// PERIA_INTA208
void Excep_PERIA_INTA208(void){ }

// PERIA_INTA209
void Excep_PERIA_INTA209(void){ }

// PERIA_INTA210
void Excep_PERIA_INTA210(void){ }

// PERIA_INTA211
void Excep_PERIA_INTA211(void){ }

// PERIA_INTA212
void Excep_PERIA_INTA212(void){ }

// PERIA_INTA213
void Excep_PERIA_INTA213(void){ }

// PERIA_INTA214
void Excep_PERIA_INTA214(void){ }

// PERIA_INTA215
void Excep_PERIA_INTA215(void){ }

// PERIA_INTA216
void Excep_PERIA_INTA216(void){ }

// PERIA_INTA217
void Excep_PERIA_INTA217(void){ }

// PERIA_INTA218
void Excep_PERIA_INTA218(void){ }

// PERIA_INTA219
void Excep_PERIA_INTA219(void){ }

// PERIA_INTA220
void Excep_PERIA_INTA220(void){ }

// PERIA_INTA221
void Excep_PERIA_INTA221(void){ }

// PERIA_INTA222
void Excep_PERIA_INTA222(void){ }

// PERIA_INTA223
void Excep_PERIA_INTA223(void){ }

// PERIA_INTA224
void Excep_PERIA_INTA224(void){ }

// PERIA_INTA225
void Excep_PERIA_INTA225(void){ }

// PERIA_INTA226
void Excep_PERIA_INTA226(void){ }

// PERIA_INTA227
void Excep_PERIA_INTA227(void){ }

// PERIA_INTA228
void Excep_PERIA_INTA228(void){ }

// PERIA_INTA229
void Excep_PERIA_INTA229(void){ }

// PERIA_INTA230
void Excep_PERIA_INTA230(void){ }

// PERIA_INTA231
void Excep_PERIA_INTA231(void){ }

// PERIA_INTA232
void Excep_PERIA_INTA232(void){ }

// PERIA_INTA233
void Excep_PERIA_INTA233(void){ }

// PERIA_INTA234
void Excep_PERIA_INTA234(void){ }

// PERIA_INTA235
void Excep_PERIA_INTA235(void){ }

// PERIA_INTA236
void Excep_PERIA_INTA236(void){ }

// PERIA_INTA237
void Excep_PERIA_INTA237(void){ }

// PERIA_INTA238
void Excep_PERIA_INTA238(void){ }

// PERIA_INTA239
void Excep_PERIA_INTA239(void){ }

// PERIA_INTA240
void Excep_PERIA_INTA240(void){ }

// PERIA_INTA241
void Excep_PERIA_INTA241(void){ }

// PERIA_INTA242
void Excep_PERIA_INTA242(void){ }

// PERIA_INTA243
void Excep_PERIA_INTA243(void){ }

// PERIA_INTA244
void Excep_PERIA_INTA244(void){ }

// PERIA_INTA245
void Excep_PERIA_INTA245(void){ }

// PERIA_INTA246
void Excep_PERIA_INTA246(void){ }

// PERIA_INTA247
void Excep_PERIA_INTA247(void){ }

// PERIA_INTA248
void Excep_PERIA_INTA248(void){ }

// PERIA_INTA249
void Excep_PERIA_INTA249(void){ }

// PERIA_INTA250
void Excep_PERIA_INTA250(void){ }

// PERIA_INTA251
void Excep_PERIA_INTA251(void){ }

// PERIA_INTA252
void Excep_PERIA_INTA252(void){ }

// PERIA_INTA253
void Excep_PERIA_INTA253(void){ }

// PERIA_INTA254
void Excep_PERIA_INTA254(void){ }

// PERIA_INTA255
void Excep_PERIA_INTA255(void){ }

