/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/************************************************************************************************************/
/*  File Function: ML51 Wakeup timer demo code with interrupt                                               */
/************************************************************************************************************/

#include "ml51_sdcc.h"

void WKT_ISR (void) __interrupt (17)            // Vector @  0x8B
{
PUSH_SFRS;
    clr_WKCON_WKTF;
    GPIO_LED ^=1;
POP_SFRS;
}
/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
    GPIO_LED_QUASI_MODE;

/*  WKT initial  check wkt interrupt vector in wkt.c  */
//    WKT_AutoReload_Interrupt_Initial_MS(LIRC,200);   /* WKT delay 200 ms */
    WKT_AutoReload_Interrupt_Initial_S(LIRC,2);      /* WKT delay 2s */
    ENABLE_GLOBAL_INTERRUPT;

    while(1);

}

