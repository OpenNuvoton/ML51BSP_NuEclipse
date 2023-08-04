/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 ADC trig by sfr start bit demo
//***********************************************************************************************************
#include "ml51_sdcc.h"


/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
unsigned int __xdata ADCdataAIN;

void main (void)
{

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");


    ENABLE_ADC_CH4;
    ADCCON1|=0x30;                     /* clock divider */
    ADCCON2|=0x0E;                     /* AQT time */
    clr_ADCCON0_ADCF;
    set_ADCCON0_ADCS;                  // ADC start trig signal
    while(!(ADCCON0&SET_BIT7));
    ADCdataAIN = ADCRH<<4;
    ADCdataAIN |= ADCRL;

  /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf ("\n ADC result = 0x%x",ADCdataAIN);
      POP_SFRS;


    while(1);
}


