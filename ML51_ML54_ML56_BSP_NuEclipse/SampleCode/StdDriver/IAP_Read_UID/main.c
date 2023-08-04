/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 Read UID demo code
//***********************************************************************************************************
#include "ml51_sdcc.h"

/**********************************/
/* *only read one byte of UID    */
/*********************************/ 
void main(void)
{
  unsigned char READ;

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");
 
  UID_Read();

  /*printf must in SFR page 0 */
    PUSH_SFRS;
    SFRS = 0;		
    printf ("\n UID = ");
    for(READ=0;READ<12;READ++)
    {
        printf (" 0x%x",UIDBuffer[READ]);
        _delay_();
    }
    POP_SFRS;

  while(1);

}