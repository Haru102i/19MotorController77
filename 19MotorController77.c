/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "r_smc_entry.h"
#include "r_cg_userdefine.h"
#include "math.h"

static float A = 0.08333333333333333333333333;
static float B = 0.33333333333333333333333333;

unsigned short VR1;
unsigned short SW1, SW2 = 0;
unsigned short HU, HV, HW = 0;
unsigned short HallValue = 0;
short SectorTable[] = {-1,4,2,3,0,5,1,-1};
unsigned short Sector, LastSector = 0;
unsigned short PeriodTime = 10000;
unsigned short DeadTime = 160;
unsigned short SumTime;
unsigned short TGRB, LastTGRB = 0;
unsigned long TCNT;
unsigned long UUtime;
unsigned short UUtime_ms = 0;
float mag = 0.3;
float MI = 0.6;
float CMD_ACC;
volatile unsigned short PWM_MODE = 0;
volatile unsigned short LSPDtimer = 100;
volatile unsigned short LSPD = 0;

volatile double TEST1,TEST2 = 0;

volatile unsigned long inc_a = 0;

void main(void);

void main(void){
	R_Config_CMT0_Start();
	R_Config_ICU_IRQ0_Start();
	R_Config_ICU_IRQ7_Start();
	R_Config_ICU_IRQ15_Start();
	R_Config_MTU3_MTU4_Start();
	R_Config_MTU9_Start();
	setSector();
	while(1U){
		SW1 = PORT8.PIDR.BIT.B0;
		SW2 = PORT8.PIDR.BIT.B1;
		LED1 = HU;
		LED2 = HV;
		LED3 = HW;
		TCNT = MTU9.TCNT;
		nop();
	}
}

void setSector(void){
	HU = PORTE.PIDR.BIT.B0;	//IRQ7
	HV = PORTE.PIDR.BIT.B1;	//IRQ15
	HW = PORTE.PIDR.BIT.B5;	//IRQ0
		
	HallValue = HU + 2*HW + 4*HV;
	LastSector = Sector;
	Sector = SectorTable[HallValue];
	SixStepDrive();
}

void SixStepDrive(void){
	if(PWM_MODE == 0){
		
	if(VR1 < 800){
		PeriodTime = 10000;
	}else if(VR1 < 3000){
		PeriodTime = 10000 + VR1 - 800;
	}
	CMD_ACC = (float)VR1 / 4096;
	SumTime = PeriodTime + DeadTime;
	MTU.TCBRA = PeriodTime;
	MTU3.TGRC = SumTime;
	UUtime_ms = (float)UUtime / 625;
	switch(Sector){
		case 0:
			MTU3.TGRD = SumTime / 2 + CMD_ACC * SumTime * mag;
			MTU4.TGRC = SumTime / 2 - CMD_ACC * SumTime * mag;
			MTU4.TGRD = SumTime / 2;
			break;
		case 1:
			MTU3.TGRD = SumTime / 2 + CMD_ACC * SumTime * mag;
			MTU4.TGRC = SumTime / 2;
			MTU4.TGRD = SumTime / 2 - CMD_ACC * SumTime * mag;
			break;
		case 2:
			MTU3.TGRD = SumTime / 2;
			MTU4.TGRC = SumTime / 2 + CMD_ACC * SumTime * mag;
			MTU4.TGRD = SumTime / 2 - CMD_ACC * SumTime * mag;
			break;
		case 3:
			MTU3.TGRD = SumTime / 2 - CMD_ACC * SumTime * mag;
			MTU4.TGRC = SumTime / 2 + CMD_ACC * SumTime * mag;
			MTU4.TGRD = SumTime / 2;
			break;
		case 4:
			MTU3.TGRD = SumTime / 2 - CMD_ACC * SumTime * mag;
			MTU4.TGRC = SumTime / 2;
			MTU4.TGRD = SumTime / 2 + CMD_ACC * SumTime * mag;
			break;
		case 5:
			MTU3.TGRD = SumTime / 2;
			MTU4.TGRC = SumTime / 2 - CMD_ACC * SumTime * mag;
			MTU4.TGRD = SumTime / 2 + CMD_ACC * SumTime * mag;
			break;
		//default:
	}
	}
}

void SinusoidalDive(void){
	TCNT = MTU9.TCNT;	//MTU9:PCLK/256 = 625kHz	MTU3,4:PCLK/4 = 40MHz
	TEST1 = CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
	TEST2 = CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
	if(PWM_MODE == 1){
	if(VR1 < 800){
		PeriodTime = 10000;
	}else if(VR1 < 3000){
		PeriodTime = 10000 + VR1 - 800;
	}
	CMD_ACC = (float)VR1 / 4096;
	SumTime = PeriodTime + DeadTime;
	MTU.TCBRA = PeriodTime;
	MTU3.TGRC = SumTime;
	UUtime_ms = (float)UUtime / 625;
	
	switch(Sector){
		case 0:
			MTU3.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		case 1:
			MTU3.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		case 2:
			MTU3.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 + CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		case 3:
			MTU3.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		case 4:
			MTU3.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		case 5:
			MTU3.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A));
			MTU4.TGRC = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+2*B));
			MTU4.TGRD = SumTime / 2 - CMD_ACC * MI * SumTime * sin(2*PI*((double)TCNT/UUtime+A+B));
			break;
		//default:
	}
	}
}

void inc(void){
	inc_a++;
}
	

void getTGRB(void){
	LastTGRB = TGRB;
	TGRB = MTU9.TGRB;
	UUtime = LastTGRB + TGRB;
}

void LowSPDtimer_inc(void){
	LSPDtimer++;
	if(LSPDtimer >= 100){
		PWM_MODE = 0;
	}
	if(LSPDtimer >= 200){
		LSPDtimer = 100;
	}
}

void LowSPD_Calc(void){
	LSPD = LSPDtimer;
	LSPDtimer = 0;
	if(LSPD <= 10){
		PWM_MODE = 1;
	}
	if(LSPD >= 14){
		PWM_MODE = 0;
	}
}