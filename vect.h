/************************************************************************
*
* Device     : RX/RX600/RX66T
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 0.5  (2018-01-12)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2018 Renesas Electronics Corporation.
*
************************************************************************/

// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Access Instruction)
#pragma interrupt (Excep_AccessInst)
void Excep_AccessInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector 1 reserved
// vector 2 reserved
// vector 3 reserved
// vector 4 reserved
// vector 5 reserved
// vector 6 reserved
// vector 7 reserved
// vector 8 reserved
// vector 9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BSC BUSERR
#pragma interrupt (Excep_BSC_BUSERR(vect=16))
void Excep_BSC_BUSERR(void);

// vector 17 reserved

// RAM RAMERR
#pragma interrupt (Excep_RAM_RAMERR(vect=18))
void Excep_RAM_RAMERR(void);

// vector 19 reserved
// vector 20 reserved

// FCU FIFERR
#pragma interrupt (Excep_FCU_FIFERR(vect=21))
void Excep_FCU_FIFERR(void);

// vector 22 reserved

// FCU FRDYI
#pragma interrupt (Excep_FCU_FRDYI(vect=23))
void Excep_FCU_FRDYI(void);

// vector 24 reserved
// vector 25 reserved

// ICU SWINT2
#pragma interrupt (Excep_ICU_SWINT2(vect=26))
void Excep_ICU_SWINT2(void);

// ICU SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMT0 CMI0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMT1 CMI1
#pragma interrupt (Excep_CMT1_CMI1(vect=29))
void Excep_CMT1_CMI1(void);

// CMT2 CMI2
#pragma interrupt (Excep_CMT2_CMI2(vect=30))
void Excep_CMT2_CMI2(void);

// CMT3 CMI3
#pragma interrupt (Excep_CMT3_CMI3(vect=31))
void Excep_CMT3_CMI3(void);

// vector 32 reserved
// vector 33 reserved

// USB0 D0FIFO0
#pragma interrupt (Excep_USB0_D0FIFO0(vect=34))
void Excep_USB0_D0FIFO0(void);

// USB0 D1FIFO0
#pragma interrupt (Excep_USB0_D1FIFO0(vect=35))
void Excep_USB0_D1FIFO0(void);

// vector 36 reserved
// vector 37 reserved

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=38))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=39))
void Excep_RSPI0_SPTI0(void);

// vector 40 reserved
// vector 41 reserved
// vector 42 reserved
// vector 43 reserved
// vector 44 reserved
// vector 45 reserved
// vector 46 reserved
// vector 47 reserved
// vector 48 reserved
// vector 49 reserved
// vector 50 reserved
// vector 51 reserved

// RIIC0 RXI0
#pragma interrupt (Excep_RIIC0_RXI0(vect=52))
void Excep_RIIC0_RXI0(void);

// RIIC0 TXI0
#pragma interrupt (Excep_RIIC0_TXI0(vect=53))
void Excep_RIIC0_TXI0(void);

// vector 54 reserved
// vector 55 reserved
// vector 56 reserved
// vector 57 reserved
// vector 58 reserved
// vector 59 reserved

// SCI1 RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=60))
void Excep_SCI1_RXI1(void);

// SCI1 TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=61))
void Excep_SCI1_TXI1(void);

// vector 62 reserved
// vector 63 reserved

// ICU IRQ0
#pragma interrupt (Excep_ICU_IRQ0(vect=64))
void Excep_ICU_IRQ0(void);

// ICU IRQ1
#pragma interrupt (Excep_ICU_IRQ1(vect=65))
void Excep_ICU_IRQ1(void);

// ICU IRQ2
#pragma interrupt (Excep_ICU_IRQ2(vect=66))
void Excep_ICU_IRQ2(void);

// ICU IRQ3
#pragma interrupt (Excep_ICU_IRQ3(vect=67))
void Excep_ICU_IRQ3(void);

// ICU IRQ4
#pragma interrupt (Excep_ICU_IRQ4(vect=68))
void Excep_ICU_IRQ4(void);

// ICU IRQ5
#pragma interrupt (Excep_ICU_IRQ5(vect=69))
void Excep_ICU_IRQ5(void);

// ICU IRQ6
#pragma interrupt (Excep_ICU_IRQ6(vect=70))
void Excep_ICU_IRQ6(void);

// ICU IRQ7
#pragma interrupt (Excep_ICU_IRQ7(vect=71))
void Excep_ICU_IRQ7(void);

// ICU IRQ8
#pragma interrupt (Excep_ICU_IRQ8(vect=72))
void Excep_ICU_IRQ8(void);

// ICU IRQ9
#pragma interrupt (Excep_ICU_IRQ9(vect=73))
void Excep_ICU_IRQ9(void);

// ICU IRQ10
#pragma interrupt (Excep_ICU_IRQ10(vect=74))
void Excep_ICU_IRQ10(void);

// ICU IRQ11
#pragma interrupt (Excep_ICU_IRQ11(vect=75))
void Excep_ICU_IRQ11(void);

// ICU IRQ12
#pragma interrupt (Excep_ICU_IRQ12(vect=76))
void Excep_ICU_IRQ12(void);

// ICU IRQ13
#pragma interrupt (Excep_ICU_IRQ13(vect=77))
void Excep_ICU_IRQ13(void);

// ICU IRQ14
#pragma interrupt (Excep_ICU_IRQ14(vect=78))
void Excep_ICU_IRQ14(void);

// ICU IRQ15
#pragma interrupt (Excep_ICU_IRQ15(vect=79))
void Excep_ICU_IRQ15(void);

// vector 80 reserved
// vector 81 reserved
// vector 82 reserved
// vector 83 reserved

// SCI5 RXI5
#pragma interrupt (Excep_SCI5_RXI5(vect=84))
void Excep_SCI5_RXI5(void);

// SCI5 TXI5
#pragma interrupt (Excep_SCI5_TXI5(vect=85))
void Excep_SCI5_TXI5(void);

// SCI6 RXI6
#pragma interrupt (Excep_SCI6_RXI6(vect=86))
void Excep_SCI6_RXI6(void);

// SCI6 TXI6
#pragma interrupt (Excep_SCI6_TXI6(vect=87))
void Excep_SCI6_TXI6(void);

// LVD1 LVD1
#pragma interrupt (Excep_LVD1_LVD1(vect=88))
void Excep_LVD1_LVD1(void);

// LVD2 LVD2
#pragma interrupt (Excep_LVD2_LVD2(vect=89))
void Excep_LVD2_LVD2(void);

// USB0 USBR0
#pragma interrupt (Excep_USB0_USBR0(vect=90))
void Excep_USB0_USBR0(void);

// vector 91 reserved
// vector 92 reserved
// vector 93 reserved
// vector 94 reserved

// IWDT IWUNI
#pragma interrupt (Excep_IWDT_IWUNI(vect=95))
void Excep_IWDT_IWUNI(void);

// WDT WUNI
#pragma interrupt (Excep_WDT_WUNI(vect=96))
void Excep_WDT_WUNI(void);

// vector 97 reserved
// vector 98 reserved
// vector 99 reserved

// SCI8 RXI8
#pragma interrupt (Excep_SCI8_RXI8(vect=100))
void Excep_SCI8_RXI8(void);

// SCI8 TXI8
#pragma interrupt (Excep_SCI8_TXI8(vect=101))
void Excep_SCI8_TXI8(void);

// SCI9 RXI9
#pragma interrupt (Excep_SCI9_RXI9(vect=102))
void Excep_SCI9_RXI9(void);

// SCI9 TXI9
#pragma interrupt (Excep_SCI9_TXI9(vect=103))
void Excep_SCI9_TXI9(void);

// vector 104 reserved
// vector 105 reserved

// ICU GROUPBE0
#pragma interrupt (Excep_ICU_GROUPBE0(vect=106))
void Excep_ICU_GROUPBE0(void);

// vector 107 reserved
// vector 108 reserved
// vector 109 reserved

// ICU GROUPBL0
#pragma interrupt (Excep_ICU_GROUPBL0(vect=110))
void Excep_ICU_GROUPBL0(void);

// ICU GROUPBL1
#pragma interrupt (Excep_ICU_GROUPBL1(vect=111))
void Excep_ICU_GROUPBL1(void);

// ICU GROUPAL0
#pragma interrupt (Excep_ICU_GROUPAL0(vect=112))
void Excep_ICU_GROUPAL0(void);

// vector 113 reserved

// SCI11 RXI11
#pragma interrupt (Excep_SCI11_RXI11(vect=114))
void Excep_SCI11_RXI11(void);

// SCI11 TXI11
#pragma interrupt (Excep_SCI11_TXI11(vect=115))
void Excep_SCI11_TXI11(void);

// SCI12 RXI12
#pragma interrupt (Excep_SCI12_RXI12(vect=116))
void Excep_SCI12_RXI12(void);

// SCI12 TXI12
#pragma interrupt (Excep_SCI12_TXI12(vect=117))
void Excep_SCI12_TXI12(void);

// vector 118 reserved
// vector 119 reserved

// DMAC DMAC0I
#pragma interrupt (Excep_DMAC_DMAC0I(vect=120))
void Excep_DMAC_DMAC0I(void);

// DMAC DMAC1I
#pragma interrupt (Excep_DMAC_DMAC1I(vect=121))
void Excep_DMAC_DMAC1I(void);

// DMAC DMAC2I
#pragma interrupt (Excep_DMAC_DMAC2I(vect=122))
void Excep_DMAC_DMAC2I(void);

// DMAC DMAC3I
#pragma interrupt (Excep_DMAC_DMAC3I(vect=123))
void Excep_DMAC_DMAC3I(void);

// DMAC DMAC74I
#pragma interrupt (Excep_DMAC_DMAC74I(vect=124))
void Excep_DMAC_DMAC74I(void);

// OST OSTDI
#pragma interrupt (Excep_OST_OSTDI(vect=125))
void Excep_OST_OSTDI(void);

// vector 126 reserved
// vector 127 reserved

// S12AD S12ADI
#pragma interrupt (Excep_S12AD_S12ADI(vect=128))
void Excep_S12AD_S12ADI(void);

// S12AD S12GBADI
#pragma interrupt (Excep_S12AD_S12GBADI(vect=129))
void Excep_S12AD_S12GBADI(void);

// S12AD S12GCADI
#pragma interrupt (Excep_S12AD_S12GCADI(vect=130))
void Excep_S12AD_S12GCADI(void);

// vector 131 reserved

// S12AD1 S12ADI1
#pragma interrupt (Excep_S12AD1_S12ADI1(vect=132))
void Excep_S12AD1_S12ADI1(void);

// S12AD1 S12GBADI1
#pragma interrupt (Excep_S12AD1_S12GBADI1(vect=133))
void Excep_S12AD1_S12GBADI1(void);

// S12AD1 S12GCADI1
#pragma interrupt (Excep_S12AD1_S12GCADI1(vect=134))
void Excep_S12AD1_S12GCADI1(void);

// vector 135 reserved

// S12AD2 S12ADI2
#pragma interrupt (Excep_S12AD2_S12ADI2(vect=136))
void Excep_S12AD2_S12ADI2(void);

// S12AD2 S12GBADI2
#pragma interrupt (Excep_S12AD2_S12GBADI2(vect=137))
void Excep_S12AD2_S12GBADI2(void);

// S12AD2 S12GCADI2
#pragma interrupt (Excep_S12AD2_S12GCADI2(vect=138))
void Excep_S12AD2_S12GCADI2(void);

// vector 139 reserved
// vector 140 reserved
// vector 141 reserved
// vector 142 reserved
// vector 143 reserved
// vector 144 reserved
// vector 145 reserved

// TMR0 CMIA0
#pragma interrupt (Excep_TMR0_CMIA0(vect=146))
void Excep_TMR0_CMIA0(void);

// TMR0 CMIB0
#pragma interrupt (Excep_TMR0_CMIB0(vect=147))
void Excep_TMR0_CMIB0(void);

// TMR0 OVI0
#pragma interrupt (Excep_TMR0_OVI0(vect=148))
void Excep_TMR0_OVI0(void);

// TMR1 CMIA1
#pragma interrupt (Excep_TMR1_CMIA1(vect=149))
void Excep_TMR1_CMIA1(void);

// TMR1 CMIB1
#pragma interrupt (Excep_TMR1_CMIB1(vect=150))
void Excep_TMR1_CMIB1(void);

// TMR1 OVI1
#pragma interrupt (Excep_TMR1_OVI1(vect=151))
void Excep_TMR1_OVI1(void);

// TMR2 CMIA2
#pragma interrupt (Excep_TMR2_CMIA2(vect=152))
void Excep_TMR2_CMIA2(void);

// TMR2 CMIB2
#pragma interrupt (Excep_TMR2_CMIB2(vect=153))
void Excep_TMR2_CMIB2(void);

// TMR2 OVI2
#pragma interrupt (Excep_TMR2_OVI2(vect=154))
void Excep_TMR2_OVI2(void);

// TMR3 CMIA3
#pragma interrupt (Excep_TMR3_CMIA3(vect=155))
void Excep_TMR3_CMIA3(void);

// TMR3 CMIB3
#pragma interrupt (Excep_TMR3_CMIB3(vect=156))
void Excep_TMR3_CMIB3(void);

// TMR3 OVI3
#pragma interrupt (Excep_TMR3_OVI3(vect=157))
void Excep_TMR3_OVI3(void);

// TMR4 CMIA4
#pragma interrupt (Excep_TMR4_CMIA4(vect=158))
void Excep_TMR4_CMIA4(void);

// TMR4 CMIB4
#pragma interrupt (Excep_TMR4_CMIB4(vect=159))
void Excep_TMR4_CMIB4(void);

// TMR4 OVI4
#pragma interrupt (Excep_TMR4_OVI4(vect=160))
void Excep_TMR4_OVI4(void);

// TMR5 CMIA5
#pragma interrupt (Excep_TMR5_CMIA5(vect=161))
void Excep_TMR5_CMIA5(void);

// TMR5 CMIB5
#pragma interrupt (Excep_TMR5_CMIB5(vect=162))
void Excep_TMR5_CMIB5(void);

// TMR5 OVI5
#pragma interrupt (Excep_TMR5_OVI5(vect=163))
void Excep_TMR5_OVI5(void);

// TMR6 CMIA6
#pragma interrupt (Excep_TMR6_CMIA6(vect=164))
void Excep_TMR6_CMIA6(void);

// TMR6 CMIB6
#pragma interrupt (Excep_TMR6_CMIB6(vect=165))
void Excep_TMR6_CMIB6(void);

// TMR6 OVI6
#pragma interrupt (Excep_TMR6_OVI6(vect=166))
void Excep_TMR6_OVI6(void);

// TMR7 CMIA7
#pragma interrupt (Excep_TMR7_CMIA7(vect=167))
void Excep_TMR7_CMIA7(void);

// TMR7 CMIB7
#pragma interrupt (Excep_TMR7_CMIB7(vect=168))
void Excep_TMR7_CMIB7(void);

// TMR7 OVI7
#pragma interrupt (Excep_TMR7_OVI7(vect=169))
void Excep_TMR7_OVI7(void);

// CAN0 RXF0
#pragma interrupt (Excep_CAN0_RXF0(vect=170))
void Excep_CAN0_RXF0(void);

// CAN0 TXF0
#pragma interrupt (Excep_CAN0_TXF0(vect=171))
void Excep_CAN0_TXF0(void);

// CAN0 RXM0
#pragma interrupt (Excep_CAN0_RXM0(vect=172))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=173))
void Excep_CAN0_TXM0(void);

// USB0 USBI0
#pragma interrupt (Excep_USB0_USBI0(vect=174))
void Excep_USB0_USBI0(void);

// ELC ELSR18I
#pragma interrupt (Excep_ELC_ELSR18I(vect=175))
void Excep_ELC_ELSR18I(void);

// ELC ELSR19I
#pragma interrupt (Excep_ELC_ELSR19I(vect=176))
void Excep_ELC_ELSR19I(void);

// TSIP-Lite RD
#pragma interrupt (Excep_TSIP_Lite_RD(vect=177))
void Excep_TSIP_Lite_RD(void);

// TSIP-Lite WR
#pragma interrupt (Excep_TSIP_Lite_WR(vect=178))
void Excep_TSIP_Lite_WR(void);

// TSIP-Lite Error
#pragma interrupt (Excep_TSIP_Lite_Error(vect=179))
void Excep_TSIP_Lite_Error(void);

// CMPC0 CMPC0
#pragma interrupt (Excep_CMPC0_CMPC0(vect=180))
void Excep_CMPC0_CMPC0(void);

// CMPC1 CMPC1
#pragma interrupt (Excep_CMPC1_CMPC1(vect=181))
void Excep_CMPC1_CMPC1(void);

// CMPC2 CMPC2
#pragma interrupt (Excep_CMPC2_CMPC2(vect=182))
void Excep_CMPC2_CMPC2(void);

// CMPC3 CMPC3
#pragma interrupt (Excep_CMPC3_CMPC3(vect=183))
void Excep_CMPC3_CMPC3(void);

// CMPC4 CMPC4
#pragma interrupt (Excep_CMPC4_CMPC4(vect=184))
void Excep_CMPC4_CMPC4(void);

// CMPC5 CMPC5
#pragma interrupt (Excep_CMPC5_CMPC5(vect=185))
void Excep_CMPC5_CMPC5(void);

// vector 186 reserved
// vector 187 reserved
// vector 188 reserved
// vector 189 reserved
// vector 190 reserved
// vector 191 reserved
// vector 192 reserved
// vector 193 reserved
// vector 194 reserved
// vector 195 reserved
// vector 196 reserved
// vector 197 reserved
// vector 198 reserved
// vector 199 reserved
// vector 200 reserved
// vector 201 reserved
// vector 202 reserved
// vector 203 reserved
// vector 204 reserved
// vector 205 reserved
// vector 206 reserved
// vector 207 reserved

// PERIA INTA208
#pragma interrupt (Excep_PERIA_INTA208(vect=208))
void Excep_PERIA_INTA208(void);

// PERIA INTA209
#pragma interrupt (Excep_PERIA_INTA209(vect=209))
void Excep_PERIA_INTA209(void);

// PERIA INTA210
#pragma interrupt (Excep_PERIA_INTA210(vect=210))
void Excep_PERIA_INTA210(void);

// PERIA INTA211
#pragma interrupt (Excep_PERIA_INTA211(vect=211))
void Excep_PERIA_INTA211(void);

// PERIA INTA212
#pragma interrupt (Excep_PERIA_INTA212(vect=212))
void Excep_PERIA_INTA212(void);

// PERIA INTA213
#pragma interrupt (Excep_PERIA_INTA213(vect=213))
void Excep_PERIA_INTA213(void);

// PERIA INTA214
#pragma interrupt (Excep_PERIA_INTA214(vect=214))
void Excep_PERIA_INTA214(void);

// PERIA INTA215
#pragma interrupt (Excep_PERIA_INTA215(vect=215))
void Excep_PERIA_INTA215(void);

// PERIA INTA216
#pragma interrupt (Excep_PERIA_INTA216(vect=216))
void Excep_PERIA_INTA216(void);

// PERIA INTA217
#pragma interrupt (Excep_PERIA_INTA217(vect=217))
void Excep_PERIA_INTA217(void);

// PERIA INTA218
#pragma interrupt (Excep_PERIA_INTA218(vect=218))
void Excep_PERIA_INTA218(void);

// PERIA INTA219
#pragma interrupt (Excep_PERIA_INTA219(vect=219))
void Excep_PERIA_INTA219(void);

// PERIA INTA220
#pragma interrupt (Excep_PERIA_INTA220(vect=220))
void Excep_PERIA_INTA220(void);

// PERIA INTA221
#pragma interrupt (Excep_PERIA_INTA221(vect=221))
void Excep_PERIA_INTA221(void);

// PERIA INTA222
#pragma interrupt (Excep_PERIA_INTA222(vect=222))
void Excep_PERIA_INTA222(void);

// PERIA INTA223
#pragma interrupt (Excep_PERIA_INTA223(vect=223))
void Excep_PERIA_INTA223(void);

// PERIA INTA224
#pragma interrupt (Excep_PERIA_INTA224(vect=224))
void Excep_PERIA_INTA224(void);

// PERIA INTA225
#pragma interrupt (Excep_PERIA_INTA225(vect=225))
void Excep_PERIA_INTA225(void);

// PERIA INTA226
#pragma interrupt (Excep_PERIA_INTA226(vect=226))
void Excep_PERIA_INTA226(void);

// PERIA INTA227
#pragma interrupt (Excep_PERIA_INTA227(vect=227))
void Excep_PERIA_INTA227(void);

// PERIA INTA228
#pragma interrupt (Excep_PERIA_INTA228(vect=228))
void Excep_PERIA_INTA228(void);

// PERIA INTA229
#pragma interrupt (Excep_PERIA_INTA229(vect=229))
void Excep_PERIA_INTA229(void);

// PERIA INTA230
#pragma interrupt (Excep_PERIA_INTA230(vect=230))
void Excep_PERIA_INTA230(void);

// PERIA INTA231
#pragma interrupt (Excep_PERIA_INTA231(vect=231))
void Excep_PERIA_INTA231(void);

// PERIA INTA232
#pragma interrupt (Excep_PERIA_INTA232(vect=232))
void Excep_PERIA_INTA232(void);

// PERIA INTA233
#pragma interrupt (Excep_PERIA_INTA233(vect=233))
void Excep_PERIA_INTA233(void);

// PERIA INTA234
#pragma interrupt (Excep_PERIA_INTA234(vect=234))
void Excep_PERIA_INTA234(void);

// PERIA INTA235
#pragma interrupt (Excep_PERIA_INTA235(vect=235))
void Excep_PERIA_INTA235(void);

// PERIA INTA236
#pragma interrupt (Excep_PERIA_INTA236(vect=236))
void Excep_PERIA_INTA236(void);

// PERIA INTA237
#pragma interrupt (Excep_PERIA_INTA237(vect=237))
void Excep_PERIA_INTA237(void);

// PERIA INTA238
#pragma interrupt (Excep_PERIA_INTA238(vect=238))
void Excep_PERIA_INTA238(void);

// PERIA INTA239
#pragma interrupt (Excep_PERIA_INTA239(vect=239))
void Excep_PERIA_INTA239(void);

// PERIA INTA240
#pragma interrupt (Excep_PERIA_INTA240(vect=240))
void Excep_PERIA_INTA240(void);

// PERIA INTA241
#pragma interrupt (Excep_PERIA_INTA241(vect=241))
void Excep_PERIA_INTA241(void);

// PERIA INTA242
#pragma interrupt (Excep_PERIA_INTA242(vect=242))
void Excep_PERIA_INTA242(void);

// PERIA INTA243
#pragma interrupt (Excep_PERIA_INTA243(vect=243))
void Excep_PERIA_INTA243(void);

// PERIA INTA244
#pragma interrupt (Excep_PERIA_INTA244(vect=244))
void Excep_PERIA_INTA244(void);

// PERIA INTA245
#pragma interrupt (Excep_PERIA_INTA245(vect=245))
void Excep_PERIA_INTA245(void);

// PERIA INTA246
#pragma interrupt (Excep_PERIA_INTA246(vect=246))
void Excep_PERIA_INTA246(void);

// PERIA INTA247
#pragma interrupt (Excep_PERIA_INTA247(vect=247))
void Excep_PERIA_INTA247(void);

// PERIA INTA248
#pragma interrupt (Excep_PERIA_INTA248(vect=248))
void Excep_PERIA_INTA248(void);

// PERIA INTA249
#pragma interrupt (Excep_PERIA_INTA249(vect=249))
void Excep_PERIA_INTA249(void);

// PERIA INTA250
#pragma interrupt (Excep_PERIA_INTA250(vect=250))
void Excep_PERIA_INTA250(void);

// PERIA INTA251
#pragma interrupt (Excep_PERIA_INTA251(vect=251))
void Excep_PERIA_INTA251(void);

// PERIA INTA252
#pragma interrupt (Excep_PERIA_INTA252(vect=252))
void Excep_PERIA_INTA252(void);

// PERIA INTA253
#pragma interrupt (Excep_PERIA_INTA253(vect=253))
void Excep_PERIA_INTA253(void);

// PERIA INTA254
#pragma interrupt (Excep_PERIA_INTA254(vect=254))
void Excep_PERIA_INTA254(void);

// PERIA INTA255
#pragma interrupt (Excep_PERIA_INTA255(vect=255))
void Excep_PERIA_INTA255(void);

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>
