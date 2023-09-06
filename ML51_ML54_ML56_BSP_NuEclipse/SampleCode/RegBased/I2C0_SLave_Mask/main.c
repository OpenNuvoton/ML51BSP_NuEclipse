/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 I2C Slave demo code
//***********************************************************************************************************

#include "ml51_sdcc.h"


//***********************************************************************************************************
//  N76E885-series I2C slave mode demo code, the Slave address = 0xA4
//
//   ____________            _____________ 
//  |            |   SDA    |             |
//  |            |<-------->|             |
//  |            |          |             |
//  |  HOST      |          | ML51(S)     |
//  |(I2C_Master)|          | (I2C_Slave) |
//  |            |   SCL    |             |
//  |            |--------->|             |
//  |____________|          |_____________|
//
//  The protocol of I2C is same the "24LC64"
//***********************************************************************************************************
#define EEPROM_SLA_GPIO_HOST  0x80
#define EEPROM_SLA_ML51_SLAVE  0x80

#define I2C_CLOCK               13

#define SDA   P24
#define SCL   P25

#define EEPROM_SLA0  0xA0
#define EEPROM_SLA1  0xA2
#define EEPROM_SLA2  0xA8
#define EEPROM_SLA3  0xAA
#define EEPROM_SLA4  0xAC

unsigned char __xdata data_received[258]; 
unsigned int data_num = 0 ; 
unsigned int PAGEOFFSET_HB,READADDRESS;
BIT I2CWOVERFLAG,I2CRDOVERFLAG;

//========================================================================================================
void I2C0_ISR (void) __interrupt (6)           // Vector @  0x33
{
    switch (I2C0STAT)
    {
        case 0x00:
            set_I2C0CON_STO;
            while(STO0);
            break;

        case 0x60:
            set_I2C0CON_AA ;
            break;
        
        case 0x68:
            P02 = 0;
            while(1);
            break;

        case 0x80:
            data_received[data_num] = I2C0DAT;
            READADDRESS = (data_received[0]<<8) + data_received[1];  //This for read process
            data_num++;
            if (data_num == 258)
            {
                clr_I2C0CON_AA;
            }
            else
            {
                set_I2C0CON_AA;
            }
            break;

        case 0x88:
            data_received[data_num] = I2C0DAT;
            data_num = 0;
            clr_I2C0CON_AA;
            break;

        case 0xA0:

            if (data_num>40)
            {
               I2CWOVERFLAG = 1 ;
            }
            data_num =0;
            set_I2C0CON_AA;
            break;
        case 0xA8:
            I2C0DAT = Read_APROM_BYTE((uint16_t __code *)(READADDRESS+data_num));
            data_num++;
            set_I2C0CON_AA;
            break;
        
        case 0xB8:    
            I2C0DAT = Read_APROM_BYTE((uint16_t __code *)(READADDRESS+data_num));
            data_num++;
            set_I2C0CON_AA;
            break;

        case 0xC0:
            set_I2C0CON_AA;
            data_num = 0;
            I2CRDOVERFLAG = 1;
            break; 

        case 0xC8:
            set_I2C0CON_AA;
            break;        
    }

      clr_I2C0CON_SI;
//    while(STO);
}

//========================================================================================================
void Init_I2C_SLAVE(void)
{

    MFP_P25_I2C0_SCL;
    MFP_P24_I2C0_SDA;
    P25_QUASI_MODE;
    P24_QUASI_MODE;

    SFRS = 0;
    SDA = 1;                                        //set SDA and SCL pins high
    SCL = 1;

    set_EIE0_EI2C0;                                 //enable I2C interrupt by setting IE1 bit 0
    set_IE_EA;

    I2C0ADDR0 = EEPROM_SLA_ML51_SLAVE;              //define own slave address

    I2C_SetSlaveAddrMask(I2C0,0,0x0E);
    set_I2C0CON_I2CEN;                              //enable I2C circuit
    set_I2C0CON_AA;

}



//========================================================================================================
void main(void)
{

    /* Initial I2C function */
	Init_I2C_SLAVE();                                 //initial I2C circuit

    while (1);

/* =================== */
}

