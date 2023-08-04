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
    unsigned char i; 
    PUSH_SFRS;

    clr_WKCON_WKTR;
    for (i=0;i<10;i++)
    {
      GPIO_LED ^= 1;
      _delay_();
      _delay_();
    }
    clr_WKCON_WKTF;                                   //clear interrupt flag
    set_WKCON_WKTR;

    POP_SFRS;
}


/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
   
    P35_PUSHPULL_MODE;

//-----------------------------------------------------
//  WKT initial   
//-----------------------------------------------------  
    SFRS = 0;
    WKCON = 0x02;                     //timer base 10k, Pre-scale = 1/16
    SFRS = 2;
    RWKH = 0xFC;
    SFRS = 0;
    RWKL = 0X00;                      //  if prescale is 0x00, never set RWK = 0xff
    ENABLE_WKT_INTERRUPT;             // enable WKT interrupt
    ENABLE_GLOBAL_INTERRUPT;
    set_WKCON_WKTR;                   // Wake-up timer run 

    while(1)
    {
      GPIO_LED ^= 1;
      _delay_();
    }
}

