/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MlL51  IAP program dataflash as EEPROM demo code
//***********************************************************************************************************

#include "ml51_sdcc.h"


struct
{
    unsigned int a;
    unsigned long b;
    unsigned char  c;

} StructData;

unsigned char ArrayData[50];
unsigned char i;

/**
 * @brief       IAP program dataflash as EEPROM
 * @param       None
 * @return      None
 * @details     define dataflash need be modify address and value,
 */

void main(void)
{
    unsigned int system16highsite;

    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");


    MFP_P32_GPIO;
    P32_QUASI_MODE;
    while(P32);

    /** IAP program APROM as EEPROM way * include eeprom.c in Library       */

    Write_DATAFLASH_BYTE(0x3882, 0x34);

    for (i = 0; i < 50; i++)
    {
        ArrayData[i] = i;
    }

    StructData.a = 0x1D55;
    StructData.b = 0xA1A2A3A4;
    StructData.c = 0xA5;

    Write_DATAFLASH_ARRAY(0x38E0, ArrayData, 50); //write 50 b0ytes
    Write_DATAFLASH_ARRAY(0x38FD, (unsigned char *)&StructData, sizeof(StructData)); //write structure


    /*call read byte */
    system16highsite = ((Read_APROM_BYTE((uint16_t __code*)0x38FD) << 8) + Read_APROM_BYTE((uint16_t __code*)0x38FE));

    PUSH_SFRS;
    SFRS = 0;
    printf("\n System 16 high site = 0x%x", system16highsite);
    DISABLE_UART0_PRINTF;
    POP_SFRS;


    while (1);
}



