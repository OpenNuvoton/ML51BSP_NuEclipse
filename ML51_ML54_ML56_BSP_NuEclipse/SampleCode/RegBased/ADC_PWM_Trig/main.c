/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 SPROM 
//***********************************************************************************************************
#include "ml51_sdcc.h"

//#define   pwm0_falling_trig_adc
//#define   pwm0_rising_trig_adc
//#define   pwm0_central_trig_adc
#define     pwm0_end_trig_adc

BIT  adc_flag;

/******************************************************************************/
/* FUNCTION_PURPOSE: ADC interrupt Service Routine                            */
/******************************************************************************/
void ADC_ISR (void) __interrupt (11)          // Vector @  0x5B
{
PUSH_SFRS;
    adc_flag = 1;
    clr_ADCCON0_ADCF;                        // Clear ADC interrupt flag
    P30 ^= 1;                                // Check the P3.0 toggle at falling edge of PWM
POP_SFRS;
}

/*****************************************************************************/
/*The main C function.  Program execution starts                             */
/*here after stack initialization.                                           */
/*****************************************************************************/
void main (void) 
{

  /* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");
/*-------------------------------------------------
  ADC trig initial setting
  Please modify #if value to open diffent type
--------------------------------------------------*/
#ifdef pwm0_falling_trig_adc
    MFP_P05_PWM0_CH0;
    P05_PUSHPULL_MODE;
    ENABLE_ADC_CH10;
    ADC_EXTTRIG_PWM0_FALLINGEDGE;

#elif defined pwm0_rising_trig_adc
    MFP_P05_PWM0_CH0;
    P05_PUSHPULL_MODE;
    ENABLE_ADC_CH10;
    ADC_EXTTRIG_PWM0_RISINGEDGE;

#elif defined pwm0_central_trig_adc
    MFP_P05_PWM0_CH0;
    P05_PUSHPULL_MODE;
    ENABLE_ADC_CH10;
    PWM0_CENTER_TYPE;
    ADC_EXTTRIG_PWM_CENTRAL;

#elif defined pwm0_end_trig_adc
    MFP_P05_PWM0_CH0;
    P05_PUSHPULL_MODE;
    ENABLE_ADC_CH10; 
    PWM0_CENTER_TYPE;
    ADC_EXTTRIG_PWM_END;
#endif
  
  /* Setting PWM value  */
    SFRS = 1;
    PWM0PH = 0x07;                                //Setting PWM value
    PWM0PL = 0xFF;
    PWM0C0H = 0x02;
    PWM0C0L = 0xFF;
    set_PWM0CON0_LOAD;                            // PWM run
    set_PWM0CON0_PWMRUN;
  /* Setting ADC        */
    ENABLE_ADC_INTERRUPT;                         // Enable ADC interrupt (if use interrupt)
    ENABLE_GLOBAL_INTERRUPT;  
    while(1)
    {
      if (adc_flag)
      {
        adc_flag=0;

  /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf("\n Value = 0x%x",ADCRH);      // printf display will cause delay in ADC interrupt
      POP_SFRS;

      }
    }
}



