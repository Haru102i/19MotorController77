/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_MTU3_MTU4_user.c
* Version      : 1.3.0
* Device(s)    : R5F566TEAxFP
* Description  : This file implements device driver for Config_MTU3_MTU4.
* Creation Date: 2018-12-30
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_MTU3_MTU4.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_MTU3_MTU4_Create_UserInit
* Description  : This function adds user code after initializing the MTU3 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_MTU3_MTU4_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_c4_tgia4_interrupt
* Description  : This function is TGIA4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA228
#pragma interrupt r_Config_MTU3_MTU4_c4_tgia4_interrupt(vect=VECT(PERIA,INTA228),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_c4_tgia4_interrupt(vect=VECT(PERIA,INTA228))
#endif
static void r_Config_MTU3_MTU4_c4_tgia4_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_c4_tgia4_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_tgib3_interrupt
* Description  : This function is TGIB3 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA224
#pragma interrupt r_Config_MTU3_MTU4_tgib3_interrupt(vect=VECT(PERIA,INTA224),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_tgib3_interrupt(vect=VECT(PERIA,INTA224))
#endif
static void r_Config_MTU3_MTU4_tgib3_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_tgib3_interrupt. Do not edit comment generated here */
    SinusoidalDive();
    inc();
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_MTU3_MTU4_c4_tgib4_interrupt
* Description  : This function is TGIB4 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA229
#pragma interrupt r_Config_MTU3_MTU4_c4_tgib4_interrupt(vect=VECT(PERIA,INTA229),fint)
#else
#pragma interrupt r_Config_MTU3_MTU4_c4_tgib4_interrupt(vect=VECT(PERIA,INTA229))
#endif
static void r_Config_MTU3_MTU4_c4_tgib4_interrupt(void)
{
    /* Start user code for r_Config_MTU3_MTU4_c4_tgib4_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */   




