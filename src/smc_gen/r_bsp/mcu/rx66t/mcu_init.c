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
* File Name    : mcu_init.c
* Description  : Performs initialization common to all MCUs in this Group
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 27.07.2018 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Get specifics on this MCU. */
#include "platform.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* RX MCUs come in different packages and different pin counts.
 * Each bit of PORTm.PDR corresponds to each pin of port m; I/O direction can be specified in 1-bit units.
 * Each bit of PDR corresponding to port m that does not exist is reserved.
 * Also, each bit of PDR corresponding to P40 to P42, P44 to P46, PH0, PH4, and PE2 pins is reserved, because such pins
 * are input only.
 * Make settings of the reserved bit according to the description in section 20.4, Initialization of the Port Direction
 * Register (PDR). These values are then ORed into the direction registers to set non-existent pins as outputs or 
 * inputs, which can help save power.
 */
#if (BSP_PACKAGE_PINS == 144)
    /* Refer UserÅfs Manual: Hardware Table 20.7. */
    #define BSP_PRV_PORT0_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT1_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT3_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT4_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT6_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT7_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT8_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT9_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTA_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTC_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTE_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTF_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTG_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTH_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTK_NE_PIN_MASK     (0x00)
#elif (BSP_PACKAGE_PINS == 112)
    /* Refer UserÅfs Manual: Hardware Table 20.8. */
    #define BSP_PRV_PORT0_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT1_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0x60)
    #define BSP_PRV_PORT3_NE_PIN_MASK     (0x30)
    #define BSP_PRV_PORT4_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x03)
    #define BSP_PRV_PORT6_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT7_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT8_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT9_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTA_NE_PIN_MASK     (0xC0)
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTC_NE_PIN_MASK     (0x78)
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTE_NE_PIN_MASK     (0x40)
    #define BSP_PRV_PORTF_NE_PIN_MASK     (0x0F)
    #define BSP_PRV_PORTG_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTH_NE_PIN_MASK     (0xEE)
    #define BSP_PRV_PORTK_NE_PIN_MASK     (0x07)
#elif   (BSP_PACKAGE_PINS == 100)
    /* Refer UserÅfs Manual: Hardware Table 20.9 to 20.11. */
    #define BSP_PRV_PORT0_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT1_NE_PIN_MASK     (0xFC)
#if ((0xB == BSP_CFG_MCU_PART_FUNCTION) || (0xF == BSP_CFG_MCU_PART_FUNCTION))
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0xE0)
#else
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0x60)
#endif
    #define BSP_PRV_PORT3_NE_PIN_MASK     (0x30)
    #define BSP_PRV_PORT4_NE_PIN_MASK     (0x00)
#if ((0xB == BSP_CFG_MCU_PART_FUNCTION) || (0xF == BSP_CFG_MCU_PART_FUNCTION))
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x00)
#else
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x03)
#endif
    #define BSP_PRV_PORT6_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT7_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT8_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT9_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTA_NE_PIN_MASK     (0xC0)
#if ((0xC == BSP_CFG_MCU_PART_FUNCTION) || (0x10 == BSP_CFG_MCU_PART_FUNCTION))
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x80)
#else
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x00)
#endif
    #define BSP_PRV_PORTC_NE_PIN_MASK     (0x7F)
#if ((0xC == BSP_CFG_MCU_PART_FUNCTION) || (0x10 == BSP_CFG_MCU_PART_FUNCTION))
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x03)
#else
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x00)
#endif
    #define BSP_PRV_PORTE_NE_PIN_MASK     (0x40)
    #define BSP_PRV_PORTF_NE_PIN_MASK     (0x0F)
    #define BSP_PRV_PORTG_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORTH_NE_PIN_MASK     (0xEE)
    #define BSP_PRV_PORTK_NE_PIN_MASK     (0x07)
#elif (BSP_PACKAGE_PINS == 80)
    /* Refer UserÅfs Manual: Hardware Table 20.12. */
    #define BSP_PRV_PORT0_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT1_NE_PIN_MASK     (0xFC)
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0x78)
    #define BSP_PRV_PORT3_NE_PIN_MASK     (0x3C)
    #define BSP_PRV_PORT4_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x03)
    #define BSP_PRV_PORT6_NE_PIN_MASK     (0x0B)
    #define BSP_PRV_PORT7_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT8_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORT9_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTA_NE_PIN_MASK     (0xD7)
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x80)
    #define BSP_PRV_PORTC_NE_PIN_MASK     (0x7F)
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x03)
    #define BSP_PRV_PORTE_NE_PIN_MASK     (0x63)
    #define BSP_PRV_PORTF_NE_PIN_MASK     (0x0F)
    #define BSP_PRV_PORTG_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORTH_NE_PIN_MASK     (0xEE)
    #define BSP_PRV_PORTK_NE_PIN_MASK     (0x07)
#elif (BSP_PACKAGE_PINS == 64)
    /* Refer UserÅfs Manual: Hardware Table 20.13. */
    #define BSP_PRV_PORT0_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT1_NE_PIN_MASK     (0xFD)
    #define BSP_PRV_PORT2_NE_PIN_MASK     (0xF8)
    #define BSP_PRV_PORT3_NE_PIN_MASK     (0x3F)
    #define BSP_PRV_PORT4_NE_PIN_MASK     (0x88)
    #define BSP_PRV_PORT5_NE_PIN_MASK     (0x23)
    #define BSP_PRV_PORT6_NE_PIN_MASK     (0x0F)
    #define BSP_PRV_PORT7_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORT8_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORT9_NE_PIN_MASK     (0x00)
    #define BSP_PRV_PORTA_NE_PIN_MASK     (0xFF)
    #define BSP_PRV_PORTB_NE_PIN_MASK     (0x80)
    #define BSP_PRV_PORTC_NE_PIN_MASK     (0x7F)
    #define BSP_PRV_PORTD_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORTE_NE_PIN_MASK     (0x7B)
    #define BSP_PRV_PORTF_NE_PIN_MASK     (0x0F)
    #define BSP_PRV_PORTG_NE_PIN_MASK     (0x07)
    #define BSP_PRV_PORTH_NE_PIN_MASK     (0xEE)
    #define BSP_PRV_PORTK_NE_PIN_MASK     (0x07)
#else
    #error "ERROR - This package is not defined in mcu_init.c"
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

/***********************************************************************************************************************
* Function Name: bsp_non_existent_port_init
* Description  : For MCUs that do not have the maximum number of pins for their group (e.g. MCU with 100 pins when
*                maximum is 144 pins) these 'non-existent' pins that are not bonded out need to be initialized to save
*                power.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void bsp_non_existent_port_init (void)
{
    /* OR in missing pin masks from above. */
    PORT0.PDR.BYTE |= BSP_PRV_PORT0_NE_PIN_MASK;
    PORT1.PDR.BYTE |= BSP_PRV_PORT1_NE_PIN_MASK;
    PORT2.PDR.BYTE |= BSP_PRV_PORT2_NE_PIN_MASK;
    PORT3.PDR.BYTE |= BSP_PRV_PORT3_NE_PIN_MASK;
    PORT4.PDR.BYTE |= BSP_PRV_PORT4_NE_PIN_MASK;
    PORT5.PDR.BYTE |= BSP_PRV_PORT5_NE_PIN_MASK;
    PORT6.PDR.BYTE |= BSP_PRV_PORT6_NE_PIN_MASK;
    PORT7.PDR.BYTE |= BSP_PRV_PORT7_NE_PIN_MASK;
    PORT8.PDR.BYTE |= BSP_PRV_PORT8_NE_PIN_MASK;
    PORT9.PDR.BYTE |= BSP_PRV_PORT9_NE_PIN_MASK;
    PORTA.PDR.BYTE |= BSP_PRV_PORTA_NE_PIN_MASK;
    PORTB.PDR.BYTE |= BSP_PRV_PORTB_NE_PIN_MASK;
    PORTC.PDR.BYTE |= BSP_PRV_PORTC_NE_PIN_MASK;
    PORTD.PDR.BYTE |= BSP_PRV_PORTD_NE_PIN_MASK;
    PORTE.PDR.BYTE |= BSP_PRV_PORTE_NE_PIN_MASK;
    PORTF.PDR.BYTE |= BSP_PRV_PORTF_NE_PIN_MASK;
    PORTG.PDR.BYTE |= BSP_PRV_PORTG_NE_PIN_MASK;
    PORTH.PDR.BYTE |= BSP_PRV_PORTH_NE_PIN_MASK;
    PORTK.PDR.BYTE |= BSP_PRV_PORTK_NE_PIN_MASK;
}

