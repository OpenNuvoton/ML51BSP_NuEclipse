/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MlL51 read UCID demo
//***********************************************************************************************************
#include "ml51_sdcc.h"


/***********************/
/* main loop            */
/***********************/ 
void main(void)
{
    unsigned char i;
    
  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");
  
    UCID_Read();

    PUSH_SFRS;
    SFRS = 0;  
    printf ("\n UCID = ");
    for(i=0;i<12;i++)
    { 
       printf (" 0x%x",UCIDBuffer[i]);
        _delay_();
    }
    POP_SFRS;    

  while(1);


}