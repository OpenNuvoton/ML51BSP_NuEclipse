/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_sdcc.h"

unsigned int __xdata u16value;


void main (void) 
{
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");
  
/* ADC initial setting 
  * include adc.c in Library for ADC setting.
*/  
    VREF_Open(LEVEL3);
    ENABLE_ADC_VTEMP;

    clr_ADCCON0_ADCF;                              /*Clear ADC flag before ADC start */
    set_ADCCON0_ADCS;                              /* Each time ADC start trig signal*/
    while(!(ADCCON0&SET_BIT7));                    /* wait ADCF = 1 */
    u16value = ADCRH<<4;
    u16value |= ADCRL;

  /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf ("\n VTEMP = 0x%x",u16value);
      POP_SFRS;


    while(1);
}


