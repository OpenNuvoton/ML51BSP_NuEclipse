/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 IAP program DATAFLASH demo code
//***********************************************************************************************************
#include "ml51_sdcc.h"

//-----------------------------------------------------------------------------------------------------------
void main (void) 
{
/*****************************************************************************************************************
 Define RAM buffer data
******************************************************************************************************************/   
    unsigned  char i,temp1,temp2;
  
  /* UART0 settting for printf function */
//    Enable_UART0_VCOM_printf();
//    printf ("\n Test start ...");
    
    P32_QUASI_MODE;
    while(P32);

    for (i=0;i<128;i++)
    {
      IAPDataBuf[i]=i;
    }

    APROM_Erase(0x3800,128);
    APROM_Blank_Check(0x3800,128);
    APROM_Program(0x3800,128);
    APROM_Read_Verify(0x3800,128);

    APROM_Checksum_Run(0x3800,1);
    temp1 = APROM_Checksum_Read(0);

    for (i=0;i<128;i++)
    {
      IAPDataBuf[i]=55;
    }
    LDROM_Erase(0,128);
    LDROM_Program(0,128);
    LDROM_Read_Verify(0,128);
    LDROM_Checksum_Run(0,1);
    temp2 = LDROM_Checksum_Read(0);


  /*printf must in SFR page 0 */
      PUSH_SFRS;
      SFRS = 0;
      printf ("\n APROM 3800H Checksum = 0x%x", temp1);
      printf ("\n LDROM Checksum = 0x%x",temp2);
      POP_SFRS;

    while(1);
}
//-----------------------------------------------------------------------------------------------------------
