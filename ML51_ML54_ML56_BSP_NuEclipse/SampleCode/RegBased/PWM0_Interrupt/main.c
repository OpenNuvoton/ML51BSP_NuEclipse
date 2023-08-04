/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 PWM output falling edge trig interrupt demo
//***********************************************************************************************************
#include "ml51_sdcc.h"

BIT pwmintflag;
/***********************************************************************************************************/
/*   PWM interrupt subroutine                                                                              */
/***********************************************************************************************************/
void PWM0_ISR (void) __interrupt (13)    // Vector @  0x6B
{
    PUSH_SFRS;
  
    clr_PWM0CON0_PWMF;               // clear PWM interrupt flag
    pwmintflag = 1;

    POP_SFRS;
}  

/***********************************************************************************************************/
/*   Main function                                                                                         */
/***********************************************************************************************************/
void main(void)
{

  Enable_UART0_VCOM_printf();
  printf("\n ADC trig by GPIO intial...");

/**********************************************************************
  PWM frequency = Fpwm/((PWMPH,PWMPL) + 1) <Fpwm = Fsys/PWM_CLOCK_DIV> 
                = (24MHz/8)/(PWMH+PWML + 1)
***********************************************************************/
    MFP_P24_PWM0_CH1;
    P24_PUSHPULL_MODE;
  
    PWM0_IMDEPENDENT_MODE;
    PWM0_CLOCK_DIV_128;
    PWM0PH = 0x07;
    PWM0PL = 0xCF;
  
    ENABLE_PWM0_CHANNEL1_INT;
    PWM0_FALLING_INT;                  /* Setting Interrupt happen when PWM0 channel 1falling signal */
  
    PWM0_CLOCK_DIV_8;
    PWM0PH = 0xF0;                     /* Setting PWM period */
    PWM0PL = 0xFF;
    PWM0C1H = 0xE0;                    /* PWM0 high duty = 1/2 PWM period  */
    PWM0C1L = 0xFF;  

    ENABLE_PWMM0_INTERRUPT;            /* Enable PWM interrupt */
    ENABLE_GLOBAL_INTERRUPT;
    set_PWM0CON0_LOAD;
    set_PWM0CON0_PWMRUN;

    while(1)
    { 
       if(pwmintflag)
      {
        pwmintflag=0;

        PUSH_SFRS;
        SFRS = 0;
        printf ("\n PWM interrupt !!");
        POP_SFRS;

      }
    }
}
