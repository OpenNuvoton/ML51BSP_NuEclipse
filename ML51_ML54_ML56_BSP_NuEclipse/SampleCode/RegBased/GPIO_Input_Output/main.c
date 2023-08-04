/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 GPIO toggle demo code
//***********************************************************************************************************
#include "ml51_sdcc.h"

__at 0x88          unsigned char temp;
__idata __at  0x88 unsigned char itemp;
__xdata __at  0x88 unsigned char xtemp;
__code __at 0x3000 unsigned char ctemp = 0xAA;

//----------------------------------------------------------------------------------------------//
void main (void)
{
/* As defaut all multi function define as GPIO */ 
  ALL_GPIO_QUASI_MODE;
  P60_PUSHPULL_MODE;
  P61_INPUT_MODE;

  while(1)
  {
    P1 = ~P1;
    P4 = ~P4;
    SFRS=0; set_P5_3;          /* or P5 |= SET_BIT3;  for none bit-addressable port */
    SFRS=2; P6 |= SET_BIT0;    /* or set_P6_0; for none bit-addressable port */
    if (!(P6&SET_BIT1))        /* if P6.1 == 0 , for none bit-addressable port */
    {
      CALL_NOP;
    }
    Timer2_Delay(24000000,4,2,1000);

    SFRS=0; clr_P5_3;          /* or P5 &= CLR_BIT3;  for none bit-addressable port */
    SFRS=2; P6 &= CLR_BIT0;    /* or clr_P6_0;   for none bit-addressable port */
    if (P6&SET_BIT1)           /* if P6.1 == 1  for none bit-addressable port*/
    {
      CALL_NOP;
    }
    Timer2_Delay(24000000,4,2,1000);
  }

}

