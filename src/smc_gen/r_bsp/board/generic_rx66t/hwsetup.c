/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2018 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : hwsetup.c
* Device(s)    : RX
* H/W Platform : GENERIC_RX66T
* Description  : Defines the initialization routines used each time the MCU is restarted.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version   Description
*         : 27.07.2018 1.00      First Release
*         : 31.08.2018 1.01      Corrected execution order for bsp_volsr_initial_configure function.
***********************************************************************************************************************/


/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* I/O Register and board definitions */
#include "platform.h"
#if BSP_CFG_CONFIGURATOR_SELECT == 1 
#include "r_cg_macrodriver.h" 
#endif 

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
/* MCU I/O port configuration function declaration */
static void output_ports_configure(void);

/* Interrupt configuration function declaration */
static void interrupts_configure(void);

/* MCU peripheral module configuration function declaration */
static void peripheral_modules_enable(void);

/* VOLSR register initial configuration function declaration */
static void bsp_volsr_initial_configure(void);


/***********************************************************************************************************************
* Function name: hardware_setup
* Description  : Contains setup functions called at device restart
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
void hardware_setup(void)
{
    output_ports_configure();
    interrupts_configure();
    bsp_volsr_initial_configure();
    peripheral_modules_enable();
    bsp_non_existent_port_init();
}

/***********************************************************************************************************************
* Function name: output_ports_configure
* Description  : Configures the port and pin direction settings, and sets the pin outputs to a safe level.
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
static void output_ports_configure(void)
{
    /* Add code here to setup additional output ports */
}

/***********************************************************************************************************************
* Function name: interrupts_configure
* Description  : Configures interrupts used
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
static void interrupts_configure(void)
{
    /* Add code here to setup additional interrupts */
}

/***********************************************************************************************************************
* Function name: peripheral_modules_enable
* Description  : Enables and configures peripheral devices on the MCU
* Arguments    : none
* Return value : none
***********************************************************************************************************************/
static void peripheral_modules_enable(void)
{
    /* Add code here to enable peripherals used by the application */
#if BSP_CFG_CONFIGURATOR_SELECT == 1 
    /* The initialization function for Smart Configurator */
    R_Systeminit();
#endif 
}

/***********************************************************************************************************************
* Function name: bsp_volsr_initial_configure
* Description  : Initializes the VOLSR register.
* Arguments    : none
* Return value : none
* Note         : none
***********************************************************************************************************************/
static void bsp_volsr_initial_configure(void)
{
    /* Used for argument of R_BSP_VoltageLevelSetting function. */
    uint8_t tmp_arg = 0;

    /* Set the pattern of the VOLSR(PGAVLS). */
#if ((0xB == BSP_CFG_MCU_PART_FUNCTION) || (0xF == BSP_CFG_MCU_PART_FUNCTION))
    /* Configure for package without PGA diffrential input. */
    tmp_arg = BSP_VOL_AD_NEGATIVE_VOLTAGE_NOINPUT;
#else
    /* Configure for package with PGA diffrential input. */
    #if ((3000 > BSP_CFG_MCU_AVCC_MV) || (5500 < BSP_CFG_MCU_AVCC_MV))
        #error "Error! Invalid setting for BSP_CFG_MCU_AVCC_MV in r_bsp_config.h"
    #elif (4000 > BSP_CFG_MCU_AVCC_MV)
    tmp_arg = BSP_VOL_AD_NEGATIVE_VOLTAGE_NOINPUT;
    #else
        #if ((((((((0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN000) && (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN001)) \
           &&  (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN002)) && (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_PGAVSS0)) \
           &&  (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN100)) && (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN101)) \
           &&  (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_AN102)) && (0 == BSP_CFG_AD_NEGATIVE_VOLTAGE_INPUT_PGAVSS1))
    tmp_arg = BSP_VOL_AD_NEGATIVE_VOLTAGE_NOINPUT;
        #else
    tmp_arg = BSP_VOL_AD_NEGATIVE_VOLTAGE_INPUT;
        #endif
    #endif
#endif /* (0xB == BSP_CFG_MCU_PART_FUNCTION) || (0xF == BSP_CFG_MCU_PART_FUNCTION) */

    /* Set the pattern of the VOLSR(RICVLS). */
#if ((4500 <= BSP_CFG_MCU_VCC_MV) && (5500 >= BSP_CFG_MCU_VCC_MV))
    tmp_arg |= BSP_VOL_RIIC_4_5V_OROVER;
#elif ((2700 <= BSP_CFG_MCU_VCC_MV) && (4500 > BSP_CFG_MCU_VCC_MV))
    tmp_arg |= BSP_VOL_RIIC_UNDER_4_5V;
#else
    #error "Error! Invalid setting for BSP_CFG_MCU_VCC_MV in r_bsp_config.h"
#endif

    R_BSP_VoltageLevelSetting(tmp_arg);
}


