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
* File Name    : Config_ICU.c
* Version      : 1.5.0
* Device(s)    : R5F566TEAxFP
* Description  : This file implements device driver for Config_ICU.
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
#include "Config_ICU.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ICU_Create
* Description  : This function initializes the ICU module
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_Create(void)
{
    /* Disable IRQ interrupts */
    ICU.IER[0x08].BYTE = 0x00U;
    ICU.IER[0x09].BYTE = 0x00U;

    /* Disable software interrupt */
    IEN(ICU,SWINT) = 0U;
    IEN(ICU,SWINT2) = 0U;

    /* Disable IRQ digital filter */
    ICU.IRQFLTE0.BYTE &= ~( _01_ICU_IRQ0_FILTER_ENABLE | _80_ICU_IRQ7_FILTER_ENABLE);
    ICU.IRQFLTE1.BYTE &= ~( _80_ICU_IRQ15_FILTER_ENABLE);

    /* Set IRQ digital filter sampling clock */
    ICU.IRQFLTC0.BIT.FCLKSEL0 = _0003_ICU_IRQ_FILTER_PCLK_64;
    ICU.IRQFLTC0.BIT.FCLKSEL7 = _0003_ICU_IRQ_FILTER_PCLK_64;
    ICU.IRQFLTC1.BIT.FCLKSEL15 = _0003_ICU_IRQ_FILTER_PCLK_64;

    /* Set IRQ detection type */
    ICU.IRQCR[0].BYTE = _0C_ICU_IRQ_EDGE_BOTH;
    IR(ICU,IRQ0) = 0U;
    ICU.IRQCR[7].BYTE = _0C_ICU_IRQ_EDGE_BOTH;
    IR(ICU,IRQ7) = 0U;
    ICU.IRQCR[15].BYTE = _0C_ICU_IRQ_EDGE_BOTH;
    IR(ICU,IRQ15) = 0U;

    /* Enable IRQ digital filter */
    ICU.IRQFLTE0.BYTE |= _01_ICU_IRQ0_FILTER_ENABLE | _80_ICU_IRQ7_FILTER_ENABLE;
    ICU.IRQFLTE1.BYTE |= _80_ICU_IRQ15_FILTER_ENABLE;

    /* Set IRQ priority level */
    IPR(ICU,IRQ0) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ7) = _0F_ICU_PRIORITY_LEVEL15;
    IPR(ICU,IRQ15) = _0F_ICU_PRIORITY_LEVEL15;

    /* Set IRQ0 pin */
    MPC.PE5PFS.BYTE = 0x40U;
    PORTE.PDR.BYTE &= 0xDFU;
    PORTE.PMR.BYTE &= 0xDFU;

    /* Set IRQ7 pin */
    MPC.P30PFS.BYTE = 0x40U;
    PORT3.PDR.BYTE &= 0xFEU;
    PORT3.PMR.BYTE &= 0xFEU;

    /* Set IRQ15 pin */
    MPC.P27PFS.BYTE = 0x40U;
    PORT2.PDR.BYTE &= 0x7FU;
    PORT2.PMR.BYTE &= 0x7FU;

    R_Config_ICU_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ0_Start
* Description  : This function enables IRQ0 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ0_Start(void)
{
    /* Enable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ0_Stop
* Description  : This function disables IRQ0 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ0_Stop(void)
{
    /* Disable IRQ0 interrupt */
    IEN(ICU,IRQ0) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ7_Start
* Description  : This function enables IRQ7 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ7_Start(void)
{
    /* Enable IRQ7 interrupt */
    IEN(ICU,IRQ7) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ7_Stop
* Description  : This function disables IRQ7 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ7_Stop(void)
{
    /* Disable IRQ7 interrupt */
    IEN(ICU,IRQ7) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ15_Start
* Description  : This function enables IRQ15 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ15_Start(void)
{
    /* Enable IRQ15 interrupt */
    IEN(ICU,IRQ15) = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_ICU_IRQ15_Stop
* Description  : This function disables IRQ15 interrupt
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_ICU_IRQ15_Stop(void)
{
    /* Disable IRQ15 interrupt */
    IEN(ICU,IRQ15) = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */   

