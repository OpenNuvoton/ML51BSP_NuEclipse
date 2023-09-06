/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "ml51_sdcc.h"

//#define  UART0_TX_only
#define  UART0_RXTX_loop


void UART0_ISR (void) __interrupt (4)         // Vector @  0x23
{
    PUSH_SFRS;
    if (RI)
    {
        uart0_receive_flag = 1;
        uart0_receive_data = SBUF;
        clr_SCON_RI;                                         // Clear RI (Receive Interrupt).
    }
    if (TI)
    {
            TI = 0;
    }
    POP_SFRS;
}

/************************************************************************************************************/
/*  Main function                                                                                           */
/************************************************************************************************************/
 void main(void)
{
    MFP_P32_GPIO;
    P32_QUASI_MODE;

    MFP_P31_UART0_TXD;
    P31_QUASI_MODE;
    MFP_P30_UART0_RXD;
    P30_INPUT_MODE;
    UART_Open(24000000,UART0_Timer1,115200);
    uart0_receive_flag =0;
    ENABLE_UART0_INTERRUPT;                                   /* Enable UART0 interrupt */
    ENABLE_GLOBAL_INTERRUPT;                                  /* Global interrupt enable */

#if defined UART0_TX_only
    while (1)
    {
      UART_Send_Data(UART0,0x55);
      Timer0_Delay(24000000,500,1000);
    }

#elif defined UART0_RXTX_loop
/* while receive data from RXD, send this data to TXD */
  while(1)
  {
    if (uart0_receive_flag)
    {
       P32 ^=1;
      UART_Send_Data(UART0,uart0_receive_data);
      uart0_receive_flag = 0;
    }
  }
#endif 
}
