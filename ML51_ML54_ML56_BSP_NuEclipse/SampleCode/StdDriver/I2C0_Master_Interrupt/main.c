/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "ml51_sdcc.h"
#include "Table_Data.h"

//***********************************************************************************************************
//  File Function: MUG51 I2C master mode demo code, the Slave address = 0xA4
//
//   ____________            _____________
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |ML51(M)     |          | ML51(S)     |
//  |(I2C_Master)|          | (I2C_Slave) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
//  The protocol of I2C is master: start -> write 10 byte(ACK) ->stop -> start ->read 10 byte(ACK) -> stop
//***********************************************************************************************************

#define EEPROM_ADDRESS          0xA0
#define I2C_WR                     0
#define I2C_RD                     1

#define LOOP_SIZE                 10

unsigned int Tx_Addr = 0;
unsigned char Tx_Dat = 0;
unsigned int Rx_Addr = 0;
unsigned char Rx_Dat[30];
unsigned char Write_End_Flag=0, Read_End_Flag=0 ;


void (*I2C_Func)(void);
void I2C0_ISR (void) __interrupt (6)           // Vector @  0x33
{
    I2C_Func();
}

/*=====  I2C master tranfer to eeprom process  ===========================*/
void I2C0_Master_Tx_Isr(void)
{
    static uint8_t addr_flag;
    static uint8_t u8Count;

PUSH_SFRS;
    SFRS = 0;

    switch (I2C0STAT)
    {
       /* Bus error */
       case 0x00: set_I2C0CON_STO; break;

      /* I2C start */
       case 0x08:
            clr_I2C0CON_STA;
            I2C0DAT = (EEPROM_ADDRESS | I2C_WR);
       break;

       /* Master Transmit Address ACK (to transmit the eeprom address high byte) */
       case 0x18:
            I2C0DAT = HIBYTE(Tx_Addr);
            addr_flag = 1;
       break;

       /* Master Transmit Data ACK (to transmit the eeprom address low byte) */
       case 0x28:
            if(addr_flag)
            {
                I2C0DAT = LOBYTE(Tx_Addr);
                addr_flag = 0;
                u8Count = 0;
            }
            else
            {
                if(u8Count != 30)
                {
                    I2C0DAT = Table_Data[u8Count];
                    u8Count++;
                }
                else
                {
                    Write_End_Flag = 1;
                    set_I2C0CON_STO;
                }
            }
        break;
    }

    I2C0_SI_Check();

POP_SFRS;
}

/*======== I2C master read from eeprom process======================================*/
void I2C0_Master_Rx_Isr(void)
{
	static uint8_t addr_flag;
	static uint8_t u8Count;
PUSH_SFRS;

    SFRS = 0;

    switch (I2C0STAT)
    {
       /* Bus error */
       case 0x00: set_I2C0CON_STO; break;

      /* I2C start */
       case 0x08:
            clr_I2C0CON_STA;
            I2C0DAT = (EEPROM_ADDRESS | I2C_WR);
       break;

       /* Master Transmit Address ACK (to transmit the eeprom address high byte) */
       case 0x18:
            I2C0DAT = HIBYTE(Rx_Addr);
            addr_flag = 1;
       break;

       /* Master Transmit Data ACK  (to transmit the eeprom address low byte) */
       case 0x28:
            if(addr_flag)
            {
                I2C0DAT = LOBYTE(Rx_Addr);
                addr_flag = 0;
                u8Count = 0;
            }
            else
            {
                set_I2C0CON_STA;
            }
       break;

       /* Master Repeat Start  */
       case 0x10:
           clr_I2C0CON_STA;
           I2C0DAT = (EEPROM_ADDRESS | I2C_RD);
       break;

      /* Master Receive Address ACK  */
       case 0x40:  set_I2C0CON_AA; break;

      /* Master Receive Data ACK  */  /*I2C master read from eeprom   */
       case 0x50:
                 if(u8Count != 30)
                {
                    Rx_Dat[u8Count] = I2C0DAT;
                    u8Count++;
                }
                else
                {
                    Read_End_Flag = 1;
                    set_I2C0CON_STO;
                }
       break;
    }

    I2C0_SI_Check();

POP_SFRS;
}


//========================================================================================================
unsigned char I2C0_Write(unsigned int u16I2Caddr)
{
    unsigned long count = 0;

    I2C_Func = I2C0_Master_Tx_Isr;
    Tx_Addr = u16I2Caddr;

    set_I2C0CON_STA;             /* Start transmit */
    while(1)
    {
        count++;
        if(Write_End_Flag == 1)
        {
            return 1;
        }

        if(count > 100000)
        {
            return 0;
        }
    }
}

/*========================================================================================================*/
unsigned char I2C0_Read(unsigned int u8I2Caddr)
{
    uint32_t count = 0;

    I2C_Func = I2C0_Master_Rx_Isr;
    Rx_Addr = u8I2Caddr;

    set_I2C0CON_STA;

    while(1)
    {
        count++;
        if(Read_End_Flag == 1)
        {
//            *u8I2Cdat = Rx_Dat;
            return 1;
        }

        if(count > 100000)
        {
            return 0;
        }
    }
}
/*========================================================================================================*/
void Init_I2C(void)
{
    /* Set I2C GPIO */
    MFP_P41_I2C0_SCL;
    MFP_P40_I2C0_SDA;
    GPIO_SetMode(Port4, SET_BIT0|SET_BIT1, GPIO_MODE_OPENDRAIN);      /* External pull high resister in circuit */
    GPIO_SchmittTrigger(Port4, SET_BIT0|SET_BIT1, ENABLE);            /* Setting Schmitt Trigger type input */

    /* Set I2C clock rate and enable*/
     I2C_Master_Open(I2C0,24000000,100000);
    /* Set I2C Interrupt enable*/
     I2C_Interrupt(I2C0, ENABLE);
     Global_Interrupt(ENABLE);
}

/*========================================================================================================*/
void main(void)
{
    unsigned char u8Count=0;

    Enable_UART0_VCOM_printf();
    printf("\n I2C EEPROM intial...");
    Init_I2C();


        if(I2C0_Write(0x3000) == 1)
        {
            Timer0_Delay(24000000,50,1000);
            while (I2C0_Read(0x3000) ==0);
        }
        for (u8Count=0;u8Count<32;u8Count++)
        {
          if(Rx_Dat[u8Count] != Table_Data[u8Count])
          {
                SFRS=0; printf("\n Read Byte FAIL! %x", u8Count);
          }
          else
          {
                 SFRS=0; printf("\n Read Byte PASS! %x", u8Count);
          }
          Timer0_Delay(24000000,10,1000);
        }

        I2C_Close(I2C0);

        while(1);

}

