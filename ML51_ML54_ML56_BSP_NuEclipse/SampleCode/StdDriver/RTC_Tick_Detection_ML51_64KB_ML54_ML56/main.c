/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************
*  File Function: ML51 RTC Tick interrupt code
* @Note 12-Hour Time 12:00:00 AM ~ 11:59:59AM / 12:00:00PM ~ 11:59:59PM
*       24-Hour Time 00:00:00    ~ 11:59:59   / 12:00:00 ~ 23:59:59
*       For 12-Hour Time avoid 00:00:00 AM/PM 
        For all Time setting avoid 25:61:61 
        For Year data avoid 19xx/13/32
        
        Check P32 GPIO to confirm RTC tick time 1s.
***********************************************************************************************************/
#include "ml51_sdcc.h"

unsigned char g_u8ct=0;

void RTC_ISR (void) __interrupt (30)          // Vector @  0xF3
{
      clr_RTCINTSTS_TICKIF;
      GPIO_LED ^= 1;
      g_u8ct++;
}

//----------------------------------------------------------------------------------------------//
void main (void)
{
    S_RTC_TIME_DATA_T sCurTime;

    Enable_UART0_VCOM_printf();   /* For printf */
    printf ("\n Test start ...");
    
    P32_QUASI_MODE;               /* For interrupt gpio toggle */ 

/* RTC initial */
    RTC_Clock_Select(LIRC);   /* RTC clock source select */ /* one tick time still 1 sec. the deviation is same as the lirc deviation */ 
    RTC_Initial_Pause();
    RTC_SetDate(2020,8,11,2);
    RTC_SetTime(7,59,00,RTC_CLOCK_12,RTC_AM);
/* RTC interrupt initial */
    RTC_Interrupt_Enable(RTC_TIME_TICK);
    ENABLE_GLOBAL_INTERRUPT;
/* RTC run */
    RTC_Initial_Run();

/* print result */
    while(1)
    {
      if ((g_u8ct&0x03)==0x03)
      {
        RTC_GetDateAndTime(&sCurTime);    /* print current time each 3sec */
        SFRS=0;  printf(" Current Time:%d/%hd/%hd %hd:%hd:%hd\n",sCurTime.u16Year,sCurTime.u8Month,sCurTime.u8Day,sCurTime.u8Hour,sCurTime.u8Minute,sCurTime.u8Second);
        g_u8ct=0;
      }
    }

}

