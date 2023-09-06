/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_sdcc.h"


BIT ADC_CONT_FINAL_FLAG;
__xdata __at 0x300 char ResultTable[256] ;

/**
 * @brief       ADC Interrupt Subroutine
 * @param       None
 * @return      None
 * @details     Set ADC continus finished flag.
 */
void ADC_ISR (void) __interrupt (11)          // Vector @  0x5B
{
    PUSH_SFRS;

    clr_ADCCON0_ADCF;
    ADC_CONT_FINAL_FLAG = 1;

    POP_SFRS;
}

/**
 * @brief       ADC continus mode main loop
 * @param       None
 * @return      None
 * @details     None
 */
void main (void)
{
    unsigned char i;
    unsigned int temp;


  Enable_UART0_VCOM_printf();
  printf ("\n Test start ...");
/* ADC continus mode setting .
   *include adc.c for ADC initial setting
*/
    ADC_Open(ADC_CONTINUOUS,0);                        // Opend ADC as continous mode, and input from AIN0 P2.5
    ADC_InitialContinous(0x300,128);      // Define data restore in RAM start address and ADC total sample number
    ADC_SamplingTime(2,7);                             // ADC clock = Fsys/4, sampling timer select longest value is 7
    ADC_Interrupt(Enable,ADC_INT_CONTDONE);            // Enable ADC interrupt when sampling total byte is done.
    ENABLE_GLOBAL_INTERRUPT;
    set_ADCCON0_ADCS;                                  // Trig ADCS bit to start ADC

/* ADC finished and print the result from XRAM. */
    while(!ADC_CONT_FINAL_FLAG);
    ADC_Close();
    ADC_Interrupt(Disable,0);
    ENABLE_UART0_PRINTF;
    for(i=0;i<128;i++)
    {
      temp=(ResultTable[i]<<4)+(ResultTable[i/2+128]&0x0F);

     /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf ("\n ADC No.%x",i);
      printf (" = 0x%x ", temp);
      POP_SFRS;

      i++;
      temp=(ResultTable[i]<<4)+((ResultTable[(i-1)/2+128]>>4)&0x0F);

      PUSH_SFRS;
      SFRS = 0;
      printf ("\n ADC No.%x",i);
      printf (" = 0x%x ", temp);
      POP_SFRS;

      if(i==127)
      ADC_CONT_FINAL_FLAG=0;
    }

    while(1);
}
