/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 simple GPIO toggle out demo code
//***********************************************************************************************************

#include "ml51_sdcc.h"


void main (void) 
{
   /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");
    printf ("\n Hello world!");
    while(1);
}



