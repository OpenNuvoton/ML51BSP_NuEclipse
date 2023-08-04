/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MS51 locate data in APROM simple demo 
//***********************************************************************************************************
#include "ml51_sdcc.h"
#include "SPROM.h"

__code __at  0xFFFF char lockdata = 0xFF;  /* This byte as 0xFF means unlock SPROM. Any other value is lock*/


void main (void) 
{
    unsigned char temp = 0;
  
    set_IAPUEN_SPMEN;             //Enable SPROM memory mapping only for check SPROM in memory window
    Enable_UART0_VCOM_printf();
    printf("\n SPROM lock byte = 0x%x ", lockdata);
    
    while(1)
    {
      temp = SPROM_FUNC(temp);
      SFRS=0;
      printf("\n SPTEMP= 0x%x", temp);
      Timer0_Delay(24000000,300,1000);
    }

}
