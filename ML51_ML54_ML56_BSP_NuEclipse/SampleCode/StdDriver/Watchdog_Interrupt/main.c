/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_sdcc.h"

/************************************************************************************************************/
/* FUNCTION_PURPOSE: WDT interrupt Service Routine                                                          */
/************************************************************************************************************/
void WDT_ISR (void) __interrupt (10)          // Vector @  0x53
{
  PUSH_SFRS;
    clr_WDCON_WDTF;
    GPIO_LED ^= 1;
  POP_SFRS;
}

/************************************************************************************************************/
/* FUNCTION_PURPOSE: Main Loop                                                                              */
/************************************************************************************************************/
/************************************************************************************************************
* Warning:
* Pleaes always check CONFIG WDT disable first
* only when WDT reset disable, WDT use as pure timer
* Since WDT reset issue can't be debug.
************************************************************************************************************/
void main (void)
{
/* Note WDT timer base is LIRC 10Khz*/
	P32_QUASI_MODE;

    ENABLE_P17_PULLDOWN;
    WDT_Open(1024);
    WDT_Interrupt(Enable);
    ENABLE_GLOBAL_INTERRUPT;
    while (P17)
    {
      set_WDCON_WDCLR;
    }

}
