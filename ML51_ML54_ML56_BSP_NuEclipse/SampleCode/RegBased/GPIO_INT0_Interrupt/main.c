/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 INT0 pin demo 
//***********************************************************************************************************
#include "ml51_sdcc.h"

BIT int0flag ;

/* External pin interrupt INT0 subroutine */
void INT0_ISR (void) __interrupt (0)          // Vector @  0x03
{
  
    PUSH_SFRS;

    clr_TCON_IE0;          //clr int flag wait next falling edge
    int0flag = 1;
    POP_SFRS;
}


void main (void) 
{

    Enable_UART0_VCOM_printf();
    printf ("\n P25 INT0 external interrupt initial!!");
  
/*INT0 ENABLE */
    MFP_P25_INT0;                      //setting INT0 pin P0.6 as Quasi mode
    P25_INPUT_MODE;                    //Set input mode
    ENABLE_P25_PULLUP;                 //set pull up resistor.
    INT0_FALLING_EDGE_TRIG;            //setting trig condition level or edge
    ENABLE_INT0_INTERRUPT;             //INT0_Enable;
    ENABLE_GLOBAL_INTERRUPT;           //Global interrupt enable

    while(!int0flag);

    PUSH_SFRS;
    SFRS = 0;
    printf ("\n INT0 interrupt !!");
    POP_SFRS;


    while(1);
}



