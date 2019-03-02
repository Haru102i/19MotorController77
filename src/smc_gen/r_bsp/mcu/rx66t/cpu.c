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
* File Name    : cpu.c
* Description  : This module implements CPU specific functions. An example is enabling/disabling interrupts. 
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 27.07.2018 1.00     First Release
*         : 31.08.2018 1.01     Added PUSHM and POPM mnemonic to the R_BSP_VoltageLevelSetting function.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Platform support. */
#include "platform.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Key code for writing PRCR register. */
#define BSP_PRV_PRCR_KEY        (0xA500)

/* The macro definition for combinations where settings of USBVON bit conflict. */
#define BSP_PRV_USBVON_CONFLICT (BSP_VOL_USB_POWEROFF | BSP_VOL_USB_POWERON)
/* The macro definition for combinations where settings of PGAVLS bit conflict. */
#define BSP_PRV_PGAVLS_CONFLICT (BSP_VOL_AD_NEGATIVE_VOLTAGE_INPUT | BSP_VOL_AD_NEGATIVE_VOLTAGE_NOINPUT)
/* The macro definition for combinations where settings of RICVLS bit conflict. */
#define BSP_PRV_RICVLS_CONFLICT (BSP_VOL_RIIC_4_5V_OROVER | BSP_VOL_RIIC_UNDER_4_5V)

/***********************************************************************************************************************
Error checking
***********************************************************************************************************************/
#if !defined(__RENESAS__)
    #error "ERROR - Need to add compiler specific code in cpu.c"
#endif

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
 
/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
/* Used for holding reference counters for protection bits. */
static volatile uint16_t g_protect_counters[BSP_REG_PROTECT_TOTAL_ITEMS];
/* Masks for setting or clearing the PRCR register. Use -1 for size because PWPR in MPC is used differently. */
static const    uint16_t g_prcr_masks[BSP_REG_PROTECT_TOTAL_ITEMS-1] = 
{
    0x0001,         /* PRC0. */
    0x0002,         /* PRC1. */
    0x0008,         /* PRC3. */
};

/***********************************************************************************************************************
* Function Name: R_BSP_InterruptsDisable
* Description  : Globally disable interrupts.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_BSP_InterruptsDisable (void)
{
#if defined(__RENESAS__)
    /* Use the compiler intrinsic function to clear the I flag. This function is available with for the Renesas RX 
       compiler. This may need to be changed for other compilers. */
    clrpsw_i();
#endif
} 

/***********************************************************************************************************************
* Function Name: R_BSP_InterruptsEnable
* Description  : Globally enable interrupts.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_BSP_InterruptsEnable (void)
{
#if defined(__RENESAS__)
    /* Use the compiler intrinsic function to set the I flag. This function is available with for the Renesas RX 
       compiler. This may need to be changed for other compilers. */
    setpsw_i();
#endif
} 

/***********************************************************************************************************************
* Function Name: R_BSP_CpuInterruptLevelRead
* Description  : Reads the processor interrupt priority level.
* Arguments    : none
* Return Value : The current processor IPL
***********************************************************************************************************************/
uint32_t R_BSP_CpuInterruptLevelRead (void)
{
#if defined(__RENESAS__)
    /* Use the compiler intrinsic function to read the CPU IPL. This function is available with for the Renesas RX 
       compiler. This may need to be changed for other compilers. */
    return (uint32_t)get_ipl();
#endif
}

/***********************************************************************************************************************
* Function Name: R_BSP_CpuInterruptLevelWrite
* Description  : Writes the processor interrupt priority level.
* Arguments    : level -
*                    The level to set the processor's IPL to.
* Return Value : true -
*                    The level was set successfully.
*                false -
*                    Invalid level input. 
***********************************************************************************************************************/
bool R_BSP_CpuInterruptLevelWrite (uint32_t level)
{
#if (BSP_CFG_PARAM_CHECKING_ENABLE == 1)
    /* Check for valid level. */
    if (level > BSP_MCU_IPL_MAX)
    {
        return false;
    }
#endif

#if defined(__RENESAS__)
    /* Use the compiler intrinsic function to set the CPU IPL. This function is available with for the Renesas RX 
       compiler. This may need to be changed for other compilers. */
    set_ipl((signed long)level);
#endif

    return true;
}

/***********************************************************************************************************************
* Function Name: R_BSP_RegisterProtectEnable
* Description  : Enables register protection. Registers that are protected cannot be written to. Register protection is 
*                enabled by using the Protect Register (PRCR) and the MPC's Write-Protect Register (PWPR).
* Arguments    : regs_to_unprotect -
*                    Which registers to disable write protection for. See typedef defines of bsp_reg_protect_t.
* Return Value : none
***********************************************************************************************************************/
void R_BSP_RegisterProtectEnable (bsp_reg_protect_t regs_to_protect)
{

    uint32_t    ipl_value;

#if defined(__RENESAS__)
    /* Get the current Processor Interrupt Priority Level (IPL). */ 
    ipl_value = (uint32_t)get_ipl();

    /* Note: Please set this macro more than IPR for other FIT module interrupts. */ 
    if (ipl_value < BSP_CFG_FIT_IPL_MAX)
    {
        set_ipl((signed long)BSP_CFG_FIT_IPL_MAX);
    }
#endif /* defined(__RENESAS__) */ 

    /* Is it safe to disable write access? */
    if (0 != g_protect_counters[regs_to_protect])
    {
        /* Decrement the protect counter */
        g_protect_counters[regs_to_protect]--;
    }

    /* Is it safe to disable write access? */
    if (0 == g_protect_counters[regs_to_protect])
    {
        if (BSP_REG_PROTECT_MPC != regs_to_protect)
        {
            /* Enable protection using PRCR register. */
            /* When writing to the PRCR register the upper 8-bits must be the correct key. Set lower bits to 0 to 
               disable writes. 
               b15:b8 PRKEY - Write 0xA5 to upper byte to enable writing to lower byte
               b7:b4  Reserved (set to 0)
               b3     PRC3  - Enables writing to the registers related to the LVD: LVCMPCR, LVDLVLR, LVD1CR0, LVD1CR1, 
                              LVD1SR, LVD2CR0, LVD2CR1, LVD2SR.
               b2     Reserved (set to 0)
               b1     PRC1  - Enables writing to the registers related to operating modes, low power consumption, the 
                              clock generation circuit, and software reset: SYSCR0, SYSCR1, VOLSR, SBYCR, MSTPCRA,
                              MSTPCRB, MSTPCRC, MSTPCRD, RSTCKCR, DPSBYCR, DPSIER0, DPSIER1, DPSIER2, DPSIFR0, DPSIFR1,
                              DPSIFR2, DPSIEGR0, DPSIEGR1, DPSIEGR2, MOSCWTCR, MOFCR, HOCOPCR, SWRR.
               b0     PRC0  - Enables writing to the registers related to the clock generation circuit: SCKCR, SCKCR2,
                              SCKCR3, PLLCR, PLLCR2, BCKCR, MOSCCR, LOCOCR, ILOCOCR, HOCOCR, HOCOCR2, OSTDCR, OSTDSR.
            */
            SYSTEM.PRCR.WORD = (uint16_t)((SYSTEM.PRCR.WORD | BSP_PRV_PRCR_KEY) & (~g_prcr_masks[regs_to_protect]));
        }
        else
        {
            /* Enable protection for MPC using PWPR register. */
            /* Enable writing of PFSWE bit. It could be assumed that the B0WI bit is still cleared from a call to 
               protection disable function, but it is written here to make sure that the PFSWE bit always gets 
               cleared. */
            MPC.PWPR.BIT.B0WI = 0;     
            /* Disable writing to PFS registers. */ 
            MPC.PWPR.BIT.PFSWE = 0;    
            /* Disable writing of PFSWE bit. */
            MPC.PWPR.BIT.B0WI = 1;     
        }
    }

#if defined(__RENESAS__)
    /* Restore the IPL. */ 
    if (ipl_value < BSP_CFG_FIT_IPL_MAX)
    {
        set_ipl((signed long)ipl_value);
    }
#endif /* defined(__RENESAS__) */ 
}

/***********************************************************************************************************************
* Function Name: R_BSP_RegisterProtectDisable
* Description  : Disables register protection. Registers that are protected cannot be written to. Register protection is
*                disabled by using the Protect Register (PRCR) and the MPC's Write-Protect Register (PWPR).
* Arguments    : regs_to_unprotect -
*                    Which registers to disable write protection for. See typedef defines of bsp_reg_protect_t.
* Return Value : none
***********************************************************************************************************************/
void R_BSP_RegisterProtectDisable (bsp_reg_protect_t regs_to_unprotect)
{

    uint32_t    ipl_value;

#if defined(__RENESAS__)
    /* Get the current Processor Interrupt Priority Level (IPL). */ 
    ipl_value = (uint32_t)get_ipl();

    /* Note: Please set this macro more than IPR for other FIT module interrupts. */ 
    if (ipl_value < BSP_CFG_FIT_IPL_MAX)
    {
        set_ipl((signed long)BSP_CFG_FIT_IPL_MAX);
    }
#endif /* defined(__RENESAS__) */ 

    /* If this is first entry then disable protection. */
    if (0 == g_protect_counters[regs_to_unprotect])
    {
        if (BSP_REG_PROTECT_MPC != regs_to_unprotect)
        {
            /* Enable protection using PRCR register. */
            /* When writing to the PRCR register the upper 8-bits must be the correct key. Set lower bits to 1 to 
               enable writes. 
               b15:b8 PRKEY - Write 0xA5 to upper byte to enable writing to lower byte
               b7:b4  Reserved (set to 0)
               b3     PRC3  - Enables writing to the registers related to the LVD: LVCMPCR, LVDLVLR, LVD1CR0, LVD1CR1, 
                              LVD1SR, LVD2CR0, LVD2CR1, LVD2SR.
               b2     Reserved (set to 0)
               b1     PRC1  - Enables writing to the registers related to operating modes, low power consumption, the 
                              clock generation circuit, and software reset: SYSCR0, SYSCR1, VOLSR, SBYCR, MSTPCRA,
                              MSTPCRB, MSTPCRC, MSTPCRD, RSTCKCR, DPSBYCR, DPSIER0, DPSIER1, DPSIER2, DPSIFR0, DPSIFR1,
                              DPSIFR2, DPSIEGR0, DPSIEGR1, DPSIEGR2, MOSCWTCR, MOFCR, HOCOPCR, SWRR.
               b0     PRC0  - Enables writing to the registers related to the clock generation circuit: SCKCR, SCKCR2,
                              SCKCR3, PLLCR, PLLCR2, BCKCR, MOSCCR, LOCOCR, ILOCOCR, HOCOCR, HOCOCR2, OSTDCR, OSTDSR.
            */
            SYSTEM.PRCR.WORD = (uint16_t)((SYSTEM.PRCR.WORD | BSP_PRV_PRCR_KEY) | g_prcr_masks[regs_to_unprotect]);
        }
        else
        {
            /* Disable protection for MPC using PWPR register. */
            /* Enable writing of PFSWE bit. */
            MPC.PWPR.BIT.B0WI = 0;
            /* Enable writing to PFS registers. */ 
            MPC.PWPR.BIT.PFSWE = 1;
        }
    }

    /* Increment the protect counter */
    g_protect_counters[regs_to_unprotect]++;

#if defined(__RENESAS__)
    /* Restore the IPL. */ 
    if (ipl_value < BSP_CFG_FIT_IPL_MAX)
    {
        set_ipl((signed long)ipl_value);
    }
#endif /* defined(__RENESAS__) */ 
}

/***********************************************************************************************************************
* Function Name: R_BSP_VoltageLevelSetting
* Description  : Writes the voltage level setting.
* Arguments    : ctrl_ptn -
*                    Register Setting Patterns
*                [Options]
*                    BSP_VOL_USB_POWEROFF
*                    BSP_VOL_USB_POWERON
*                    BSP_VOL_AD_NEGATIVE_VOLTAGE_INPUT
*                    BSP_VOL_AD_NEGATIVE_VOLTAGE_NOINPUT
*                    BSP_VOL_RIIC_4_5V_OROVER
*                    BSP_VOL_RIIC_UNDER_4_5V
* Return Value : true -
*                    The pattern was set successfully. The VOLSR register was updated.
*                false -
*                    The function was called under one of the following conditions, so the VOLSR register setting was 
*                    not updated.
*                    - Setting patterns that cannot be selected at the same time were specified.
*                    - A setting pattern related to the USB was selected when the USB was not in the module stop state.
*                    - A setting pattern related to the AD was selected when the AD was not in the module stop state.
*                    - A setting pattern related to the RIIC was selected when the RIIC was not in the module stop 
*                      state.
* Note         : When specifying a setting pattern related to the USB, call the function before the USB is released 
*                from the module stop state. When specifying a setting pattern related to the AD, call the function 
*                before the AD is released from the module stop state. Also when specifying a setting pattern related 
*                to the RIIC, call the function before the RIIC is released from the module stop state.
***********************************************************************************************************************/
#pragma inline_asm R_BSP_VoltageLevelSetting
bool R_BSP_VoltageLevelSetting (uint8_t ctrl_ptn)
{
    PUSHM R4-R5
    PUSHM R14-R15
#if (BSP_CFG_PARAM_CHECKING_ENABLE == 1)
    MOV.L R1, R14            ;arguments set to R14
    AND #03H, R14
    CMP #03H, R14            ;Check whether the setting of USBVON bit conflicts
    BEQ LABEL_RT_FALSE

    MOV.L R1, R15            ;arguments set to R15
    AND #0CH, R15
    CMP #0CH, R15            ;Check whether the setting of PGAVLS bit conflicts
    BEQ LABEL_RT_FALSE

    MOV.L R1, R5             ;arguments set to R5
    AND #30H, R5
    CMP #30H, R5             ;Check whether the setting of RICVLS bit conflicts
    BEQ LABEL_RT_FALSE
#endif /* BSP_CFG_PARAM_CHECKING_ENABLE == 1 */

LABEL_CHECK_USB_MODULE_STOP:
    CMP #00H, R14            ;Check whether the setting of USBVON bit inputs
    BEQ LABEL_CHECK_AD_MODULE_STOP

    MOV.L #00080014H, R14    ;MSTPCRB address set to R14
    MOV.L [R14], R4          ;MSTPCRB set to R4
    BTST #13H, R4            ;Check MSTPB19 bit(USB0 module stop setting bit)
    BEQ LABEL_RT_FALSE

LABEL_CHECK_AD_MODULE_STOP:
    CMP #00H, R15            ;Check whether the setting of PGAVLS bit inputs
    BEQ LABEL_CHECK_RIIC_MODULE_STOP

    MOV.L #00080010H, R15    ;MSTPCRA address set to R15
    MOV.L [R15], R4          ;MSTPCRA set to R4
    BTST #11H, R4            ;Check MSTPB17 bit(S12AD module stop setting bit)
    BEQ LABEL_RT_FALSE
    MOV.L [R15], R15         ;MSTPCRA set to R15
    BTST #10H, R15           ;Check MSTPB16 bit(S12AD1 module stop setting bit)
    BEQ LABEL_RT_FALSE

LABEL_CHECK_RIIC_MODULE_STOP:
    CMP #00H, R5             ;Check whether the setting of RICVLS bit inputs
    BEQ LABEL_UPDATE_VOLSR

    MOV.L #00080014H, R14    ;MSTPCRB address set to R14
    MOV.L [R14], R14         ;MSTPCRB set to R14
    BTST #15H, R14           ;Check MSTPB21 bit(RIIC0 module stop setting bit)
    BEQ LABEL_RT_FALSE

LABEL_UPDATE_VOLSR:
    MOV.L #000803FEH, R14    ;PRCR address set to R14
    MOV.L #0008C295H, R15    ;VOLSR address set to R15
    MOV.W #0A502H, [R14]     ;Protect off

LABEL_RICVLS_TO_1:
    BTST #05H, R1
    BEQ LABEL_RICVLS_TO_0
    BSET #07H, [R15].B       ;RICVLS bit set to 1

LABEL_RICVLS_TO_0:
    BTST #04H, R1
    BEQ LABEL_PGAVLS_TO_1
    BCLR #07H, [R15].B       ;RICVLS bit set to 0

LABEL_PGAVLS_TO_1:
    BTST #03H, R1
    BEQ LABEL_PGAVLS_TO_0
    BSET #06H, [R15].B       ;PGAVLS bit set to 1

LABEL_PGAVLS_TO_0:
    BTST #02H, R1
    BEQ LABEL_USBVON_TO_1
    BCLR #06H, [R15].B       ;PGAVLS bit set to 0

LABEL_USBVON_TO_1:
    BTST #01H, R1
    BEQ LABEL_USBVON_TO_0
    BSET #02H, [R15].B       ;USBVON bit set to 1

LABEL_USBVON_TO_0:
    BTST #00H, R1
    BEQ LABEL_RT_TRUE
    BCLR #02H, [R15].B       ;USBVON bit set to 0

LABEL_RT_TRUE:
    MOV.W #0A500H, [R14]     ;Protect on
    MOV.L #00000001H, R1     ;true set to R1
    POPM R14-R15
    POPM R4-R5
    RTS

LABEL_RT_FALSE:
    MOV.L #00000000H, R1     ;false set to R1
    POPM R14-R15
    POPM R4-R5
}

/***********************************************************************************************************************
* Function Name: bsp_register_protect_open
* Description  : Initializes variables needed for register protection functionality.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void bsp_register_protect_open (void)
{
    uint32_t i;

    /* Initialize reference counters to 0. */
    /* WAIT_LOOP */
    for (i = 0; i < BSP_REG_PROTECT_TOTAL_ITEMS; i++)
    {
        g_protect_counters[i] = 0;
    }
}


