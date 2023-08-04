/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51  ADC  trig by GPIO
//****************************************************t*******************************************************
#include "ml51_sdcc.h"

unsigned char adc_flag;
unsigned int temp;
/******************************************************************************
 * FUNCTION_PURPOSE: ADC interrupt Service Routine
 ******************************************************************************/
void ADC_ISR (void) __interrupt (11)          // Vector @  0x5B
{
	PUSH_SFRS;
    adc_flag = 1;
    clr_ADCCON0_ADCF;                               //clear ADC interrupt flag
//    temp = (ADCRH<<4)|ADCRL;
    POP_SFRS;
}


/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void)
{
  Enable_UART0_VCOM_printf();
  printf("\n ADC trig by GPIO intial...");
  printf("\n P5.5 pull low to start ");

/*---------------------------------------------------------------
  ADC port trig initial setting toggle P5.5 to start ADC
----------------------------------------------------------------*/
    ENABLE_ADC_CH0;                              // Enable AIN0 P1.7 as ADC pin
    MFP_P55_STADC;
    P55_INPUT_MODE;
    ENABLE_P55_PULLUP;
    ADC_EXTTRIG_STADC_FALLINGEDGE;                      // P5.5 falling edge as adc start trig signal
/* Enable ADC interrupt */
    ENABLE_ADC_INTERRUPT;                                  // Enable ADC interrupt (if use interrupt)
    ENABLE_GLOBAL_INTERRUPT;
/* Trig P04 falling edge to start adc, no need set ADCS sfrs */
    while (!adc_flag);
    temp = ADCRH<<4;
    temp|=ADCRL;
    DISABLE_ADC;

  /*printf base on UART0 must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf ("\n Value = 0x%x",temp);
      POP_SFRS;


    while(1);
}


