/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_sdcc.h"
BIT BIT_TMP;
unsigned char __data  TA_REG_TMP,SFRS_TMP,BYTE_TMP;


/**
 * @brief       Read Dataflash
 * @param       Dataflash start address
 * @return      Dataflash Value
 * @details     None
 */
 unsigned char Read_APROM_BYTE(unsigned int __code *u16_addr)
{
    UINT8 rdata;
    rdata = HIBYTE(*u16_addr);
   return rdata;
}

/**
 * @brief       Global Interrupt Status (EA)
 * @param       Enable / Disable
 * @return      None
 * @details     after all IP interrupt enable. Must enable gloabl interrupt.
 * @Example     Global_Interrupt(ENABLE);
 */
void Global_Interrupt(unsigned char u8IntStatus)
{
    EA = u8IntStatus;
}

/**
 * @brief       Global Interrupt Status (EA)
 * @param       Enable / Disable
 * @return      None
 * @details     after all IP interrupt enable. Must enable gloabl interrupt.
 * @Example     Global_Interrupt(ENABLE);
 */
void _delay_(void)
{
  unsigned char __data i,j;
    for (j=0;j<5;j++)
    {
       for (i=0;i<100;i++)
       {
          CALL_NOP;
       }
    }
}
