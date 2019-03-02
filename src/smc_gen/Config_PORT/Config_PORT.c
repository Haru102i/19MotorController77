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
* File Name    : Config_PORT.c
* Version      : 1.5.0
* Device(s)    : R5F566TEAxFP
* Description  : This file implements device driver for Config_PORT.
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
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT7 registers */
    PORT7.PCR.BYTE = _00_Pm0_PULLUP_OFF;
    PORT7.PMR.BYTE = _00_Pm0_PIN_GPIO;
    PORT7.PDR.BYTE = _00_Pm0_MODE_INPUT;

    /* Set PORT8 registers */
    PORT8.PCR.BYTE = _00_Pm0_PULLUP_OFF | _00_Pm1_PULLUP_OFF;
    PORT8.PMR.BYTE = _00_Pm0_PIN_GPIO | _00_Pm1_PIN_GPIO;
    PORT8.PDR.BYTE = _00_Pm0_MODE_INPUT | _00_Pm1_MODE_INPUT;

    /* Set PORTB registers */
    PORTB.PODR.BYTE = _00_Pm3_OUTPUT_0 | _00_Pm7_OUTPUT_0;
    PORTB.ODR0.BYTE = _00_Pm3_CMOS_OUTPUT;
    PORTB.DSCR.BYTE = _00_Pm3_HIDRV_OFF | _00_Pm7_HIDRV_OFF;
    PORTB.PMR.BYTE = _00_Pm3_PIN_GPIO | _00_Pm7_PIN_GPIO;
    PORTB.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _80_Pm7_MODE_OUTPUT;

    /* Set PORTE registers */
    PORTE.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORTE.ODR0.BYTE = _00_Pm3_CMOS_OUTPUT;
    PORTE.DSCR.BYTE = _00_Pm3_HIDRV_OFF;
    PORTE.PMR.BYTE = _00_Pm3_PIN_GPIO;
    PORTE.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _40_PDRE_DEFAULT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */   
