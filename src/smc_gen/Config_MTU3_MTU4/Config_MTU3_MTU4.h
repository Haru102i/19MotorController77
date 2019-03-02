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
* File Name    : Config_MTU3_MTU4.h
* Version      : 1.3.0
* Device(s)    : R5F566TEAxFP
* Description  : This file implements device driver for Config_MTU3_MTU4.
* Creation Date: 2018-12-30
***********************************************************************************************************************/

#ifndef CFG_Config_MTU3_MTU4_H
#define CFG_Config_MTU3_MTU4_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_mtu3.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0050_3TCNT_VALUE               (0x0050U) /* MTU3.TCNT value */
#define _0050_TDDRA_VALUE               (0x0050U) /* MTU.TDDRA value */
#define _2710_TCDRA_VALUE               (0x2710U) /* MTU.TCDRA value */
#define _2760_3TGRB_VALUE               (0x2760U) /* MTU3.TGRB value */
#define _2760_4TGRA_VALUE               (0x2760U) /* MTU4.TGRA value */
#define _2760_4TGRB_VALUE               (0x2760U) /* MTU4.TGRB value */
#define _2760_SUM_VALUE                 (0x2760U) /* Timer General Register (TGR) value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_MTU3_MTU4_Create(void);
void R_Config_MTU3_MTU4_Start(void);
void R_Config_MTU3_MTU4_Stop(void);
void R_Config_MTU3_MTU4_Create_UserInit(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
