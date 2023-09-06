/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_sdcc.h"


void main (void) 
{
/*
 For UART0 P3.1 as TXD output setting 
 * include uart.c in Common Setting for UART0 
*/
    Enable_UART0_VCOM_printf();

    UART0_PRINTF_GPIO = 1;
    SFRS = 0;
    printf("\n\r Hello world! \n\r");
    while(1);
}



