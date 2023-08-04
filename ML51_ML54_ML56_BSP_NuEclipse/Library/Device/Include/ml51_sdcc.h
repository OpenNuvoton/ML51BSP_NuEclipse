/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
/***********************************************************************************************************/
/*  MS51_8K_SDCC.H                                                                                        */
/*                                                                                                         */
/*  Header file of Nuvoton MS51 8k Series for SDCC                                                        */
/***********************************************************************************************************/

/******************************************************************************/
/*                         Macro define header files                          */
/******************************************************************************/
#include "sfr_macro_ml51_sdcc.h"

/* ML56 SFR BYTE page 0  */
__sfr __at     (0x80)    P0          ;
__sfr __at     (0x81)    SP          ;
__sfr __at     (0x82)    DPL         ;
__sfr __at     (0x83)    DPH         ;
__sfr __at     (0x84)    RCTRIM0     ;
__sfr __at     (0x85)    RCTRIM1     ;
__sfr __at     (0x86)    RWKL        ;
__sfr __at     (0x87)    PCON        ;

__sfr __at     (0x88)    TCON        ;
__sfr __at     (0x89)    TMOD        ;
__sfr __at     (0x8A)    TL0         ;
__sfr __at     (0x8B)    TL1         ;
__sfr __at     (0x8C)    TH0         ;
__sfr __at     (0x8D)    TH1         ;
__sfr __at     (0x8E)    CKCON       ;
__sfr __at     (0x8F)    WKCON       ;

__sfr __at     (0x90)    P1          ;
__sfr __at     (0x91)    SFRS        ;
__sfr __at     (0x92)    DMA0CR0     ;
__sfr __at     (0x93)    DMA0MAL     ;
__sfr __at     (0x94)    DMA0CNT     ;
__sfr __at     (0x95)    DMA0CCNT    ;
__sfr __at     (0x96)    CKSWT       ;
__sfr __at     (0x97)    CKEN        ;

__sfr __at     (0x98)    SCON        ;
__sfr __at     (0x99)    SBUF        ;
__sfr __at     (0x9A)    SBUF1       ;
__sfr __at     (0x9B)    EIE0        ;
__sfr __at     (0x9C)    EIE1        ;
__sfr __at     (0x9D)    RSR         ;
__sfr __at     (0x9F)    CHPCON      ;

__sfr __at     (0xA0)    P2          ;
__sfr __at     (0xA1)    ADCCON0     ;
__sfr __at     (0xA2)    AUXR0       ;
__sfr __at     (0xA3)    BODCON0     ;
__sfr __at     (0xA4)    IAPTRG      ;
__sfr __at     (0xA5)    IAPUEN      ;
__sfr __at     (0xA6)    IAPAL       ;
__sfr __at     (0xA7)    IAPAH       ;

__sfr __at     (0xA8)    IE          ;
__sfr __at     (0xA9)    SADDR       ;
__sfr __at     (0xAA)    WDCON       ;
__sfr __at     (0xAB)    BODCON1     ;
__sfr __at     (0xAC)    EIP2        ;
__sfr __at     (0xAD)    EIPH2       ;
__sfr __at     (0xAE)    IAPFD       ;
__sfr __at     (0xAF)    IAPCN       ;

__sfr __at     (0xB0)    P3          ;
__sfr __at     (0xB1)    P5          ;
__sfr __at     (0xB2)    I2C1ADDR0   ;
__sfr __at     (0xB3)    I2C1DAT     ;
__sfr __at     (0xB4)    I2C1STAT    ;
__sfr __at     (0xB5)    I2C1CLK     ;
__sfr __at     (0xB6)    I2C1TOC     ;
__sfr __at     (0xB7)    IPH         ;

__sfr __at     (0xB8)    IP          ;
__sfr __at     (0xB9)    SADEN       ;
__sfr __at     (0xBA)    SADEN1      ;
__sfr __at     (0xBB)    SADDR1      ;
__sfr __at     (0xBC)    I2C0DAT     ;
__sfr __at     (0xBD)    I2C0STAT    ;
__sfr __at     (0xBE)    I2C0CLK     ;
__sfr __at     (0xBF)    I2C0TOC     ;

__sfr __at     (0xC0)    I2C0CON     ;
__sfr __at     (0xC1)    I2C0ADDR0   ;
__sfr __at     (0xC2)    ADCRL       ;
__sfr __at     (0xC3)    ADCRH       ;
__sfr __at     (0xC4)    T3CON       ;
__sfr __at     (0xC5)    RL3         ;
__sfr __at     (0xC6)    RH3         ;
__sfr __at     (0xC7)    TA          ;

__sfr __at     (0xC8)    T2CON       ;
__sfr __at     (0xC9)    T2MOD       ;
__sfr __at     (0xCA)    PIF         ;
__sfr __at     (0xCB)    ADCBAL      ;
__sfr __at     (0xCC)    TL2         ;
__sfr __at     (0xCD)    TH2         ;
__sfr __at     (0xCE)    ADCMPL      ;
__sfr __at     (0xCF)    ADCMPH      ;

__sfr __at     (0xD0)    PSW         ;
__sfr __at     (0xD1)    PWM0CON0    ;
__sfr __at     (0xD2)    ACMPCR0     ;
__sfr __at     (0xD3)    ACMPCR1     ;
__sfr __at     (0xD4)    ACMPSR      ;
__sfr __at     (0xD5)    ACMPVREF    ;
__sfr __at     (0xD6)    SC0CR0      ;
__sfr __at     (0xD7)    SC0CR1      ;

__sfr __at     (0xD8)    P4          ;
__sfr __at     (0xD9)    SC0DR       ;
__sfr __at     (0xDA)    SC0EGT      ;
__sfr __at     (0xDB)    SC0ETURD0   ;
__sfr __at     (0xDC)    SC0ETURD1   ;
__sfr __at     (0xDD)    SC0IE       ;
__sfr __at     (0xDE)    SC0IS       ;
__sfr __at     (0xDF)    SC0TSR      ;

__sfr __at     (0xE0)    ACC         ;
__sfr __at     (0xE1)    ADCCON1     ;
__sfr __at     (0xE2)    ADCCON2     ;
__sfr __at     (0xE3)    ADCDLY      ;
__sfr __at     (0xE4)    ADCBAH      ;
__sfr __at     (0xE5)    ADCSN       ;
__sfr __at     (0xE6)    ADCCN       ;
__sfr __at     (0xE7)    ADCSR       ;

__sfr __at     (0xE8)    I2C1CON     ;
__sfr __at     (0xE9)    DMA0TSR     ;
__sfr __at     (0xEA)    MTM0DAL     ;
__sfr __at     (0xEB)    DMA1CR0     ;
__sfr __at     (0xEC)    DMA1MAL     ;
__sfr __at     (0xED)    DMA1CNT     ;
__sfr __at     (0xEE)    DMA1CCNT    ;
__sfr __at     (0xEF)    EIP0        ;

__sfr __at     (0xF0)    B           ;
__sfr __at     (0xF1)    DMA1TSR     ;
__sfr __at     (0xF2)    MTM1DAL     ;
__sfr __at     (0xF3)    SPI0CR0     ;
__sfr __at     (0xF4)    SPI0SR      ;
__sfr __at     (0xF5)    SPI0DR      ;
__sfr __at     (0xF6)    DMA0BAH     ;
__sfr __at     (0xF7)    EIPH0       ;

__sfr __at     (0xF8)    S1CON       ;
__sfr __at     (0xF9)    SPI1CR0     ;
__sfr __at     (0xFA)    SPI1CR1     ;
__sfr __at     (0xFB)    SPI1SR      ;
__sfr __at     (0xFC)    SPI1DR      ;
__sfr __at     (0xFD)    DMA1BAH     ;
__sfr __at     (0xFE)    EIP1        ;
__sfr __at     (0xFF)    EIPH1       ;

/*      ML56 SFR BYTE page 1  */    
__sfr __at     (0x84)    LIRCTRIM    ;
__sfr __at     (0x85)    XLTCON      ;
__sfr __at     (0x86)    CWKL        ;

__sfr __at     (0x8A)    P0DW        ;
__sfr __at     (0x8B)    P1DW        ;
__sfr __at     (0x8C)    P2DW        ;
__sfr __at     (0x8D)    P3DW        ;
__sfr __at     (0x8E)    P4DW        ;
__sfr __at     (0x8F)    P5DW        ;

__sfr __at     (0x92)    P0UP        ;
__sfr __at     (0x93)    P1UP        ;
__sfr __at     (0x94)    P2UP        ;
__sfr __at     (0x95)    P3UP        ;
__sfr __at     (0x96)    P4UP        ;
__sfr __at     (0x97)    P5UP        ;

__sfr __at     (0x99)    P0S         ;
__sfr __at     (0x9A)    P0SR        ;
__sfr __at     (0x9B)    P1S         ;
__sfr __at     (0x9C)    P1SR        ;      
__sfr __at     (0x9D)    P2S         ;      
__sfr __at     (0x9E)    P2SR        ;      
       
__sfr __at     (0xA1)    PIPS0       ;      
__sfr __at     (0xA2)    PIPS1       ;      
__sfr __at     (0xA3)    PIPS2       ;      
__sfr __at     (0xA4)    PIPS3       ;      
__sfr __at     (0xA5)    PIPS4       ;      
__sfr __at     (0xA6)    PIPS5       ;      
__sfr __at     (0xA7)    PIPS6       ;      
       
__sfr __at     (0xA9)    VRFCON      ;      
__sfr __at     (0xAA)    VRFTRIM     ;      
__sfr __at     (0xAB)    ACMPCR2     ;      
__sfr __at     (0xAC)    P3S         ;      
__sfr __at     (0xAD)    P3SR        ;      
__sfr __at     (0xAE)    P5SR        ;      
__sfr __at     (0xAF)    PIPS7       ;      
       
__sfr __at     (0xB1)    P0M1        ;      
__sfr __at     (0xB2)    P0M2        ;      
__sfr __at     (0xB3)    P1M1        ;      
__sfr __at     (0xB4)    P1M2        ;      
__sfr __at     (0xB5)    P2M1        ;      
__sfr __at     (0xB6)    P2M2        ;      
__sfr __at     (0xB7)    PWM0INTC    ;      
       
__sfr __at     (0xB9)    P4M1        ;      
__sfr __at     (0xBA)    P4M2        ;      
__sfr __at     (0xBB)    P4S         ;      
__sfr __at     (0xBC)    P4SR        ;      
__sfr __at     (0xBD)    P5M1        ;      
__sfr __at     (0xBE)    P5M2        ;      
__sfr __at     (0xBF)    P5S         ;      
       
__sfr __at     (0xC1)    CKDIV       ;      
__sfr __at     (0xC2)    P3M1        ;      
__sfr __at     (0xC3)    P3M2        ;      
__sfr __at     (0xC4)    PWM0C4H     ;      
__sfr __at     (0xC5)    PWM0C5H     ;      
__sfr __at     (0xC6)    PORDIS      ;      
       
__sfr __at     (0xC9)    AUXR1       ;      
__sfr __at     (0xCA)    RCMP2L      ;      
__sfr __at     (0xCB)    RCMP2H      ;      
__sfr __at     (0xCC)    PWM0C4L     ;      
__sfr __at     (0xCD)    PWM0C5L     ;      
__sfr __at     (0xCE)    AINDIDS0    ;      
       
__sfr __at     (0xD1)    PWM0PH      ;      
__sfr __at     (0xD2)    PWM0C0H     ;      
__sfr __at     (0xD3)    PWM0C1H     ;      
__sfr __at     (0xD4)    PWM0C2H     ;      
__sfr __at     (0xD5)    PWM0C3H     ;      
__sfr __at     (0xD6)    PWM0NP      ;      
__sfr __at     (0xD7)    PWM0FBD     ;      
       
__sfr __at     (0xD9)    PWM0PL      ;      
__sfr __at     (0xDA)    PWM0C0L     ;      
__sfr __at     (0xDB)    PWM0C1L     ;      
__sfr __at     (0xDC)    PWM0C2L     ;      
__sfr __at     (0xDD)    PWM0C3L     ;      
__sfr __at     (0xDF)    PWM0CON1    ;      
       
__sfr __at     (0xE1)    CAPCON0     ;      
__sfr __at     (0xE2)    CAPCON1     ;      
__sfr __at     (0xE3)    CAPCON2     ;      
__sfr __at     (0xE4)    C0L         ;      
__sfr __at     (0xE5)    C0H         ;      
__sfr __at     (0xE6)    C1L         ;      
__sfr __at     (0xE7)    C1H         ;      
       
__sfr __at     (0xE9)    PICON       ;      
__sfr __at     (0xEA)    PINEN       ;      
__sfr __at     (0xEB)    PIPEN       ;      
__sfr __at     (0xED)    C2L         ;      
__sfr __at     (0xEE)    C2H         ;      
__sfr __at     (0xEF)    LDOTRIM     ;      
       
__sfr __at     (0xF3)    SPI0CR1     ;      
       
__sfr __at     (0xF9)    PWM0DTEN    ;      
__sfr __at     (0xFA)    PWM0DTCNT   ;      
__sfr __at     (0xFB)    PWM0MEN     ;      
__sfr __at     (0xFC)    PWM0MD      ;      
__sfr __at     (0xFD)    LVRFLTEN    ;      
__sfr __at     (0xFF)    LVRDIS      ;      

/*    ML56 SFR BYTE page 2  */    
__sfr __at     (0x84)    P6M1        ;
__sfr __at     (0x85)    P6M2        ;
__sfr __at     (0x86)    PWM1PH      ;

__sfr __at     (0x8A)    PWM1C0H     ;
__sfr __at     (0x8B)    PWM1C1H     ;
__sfr __at     (0x8C)    PWM1MD      ;
__sfr __at     (0x8D)    PWM1MEN     ;
__sfr __at     (0x8E)    P6SR        ;
__sfr __at     (0x8F)    P6DW        ;

__sfr __at     (0x92)    P6MF10      ;
__sfr __at     (0x93)    P6MF32      ;
__sfr __at     (0x94)    P6MF54      ;
__sfr __at     (0x95)    P6MF76      ;
__sfr __at     (0x96)    P6S         ;
__sfr __at     (0x97)    P6UP        ;

__sfr __at     (0x99)    PWM1PL      ;
__sfr __at     (0x9A)    PWM1C0L     ;
__sfr __at     (0x9B)    PWM1C1L     ;
__sfr __at     (0x9C)    PWM1CON0    ;
__sfr __at     (0x9D)    PWM1CON1    ;
__sfr __at     (0x9E)    PWM1INTC    ;

__sfr __at     (0xA1)    I2C0ADDR1   ;
__sfr __at     (0xA2)    I2C0ADDR2   ;
__sfr __at     (0xA3)    I2C0ADDR3   ;
__sfr __at     (0xA4)    I2C1ADDR1   ;
__sfr __at     (0xA5)    I2C1ADDR2   ;
__sfr __at     (0xA6)    I2C1ADDR3   ;
__sfr __at     (0xA7)    P6          ;

__sfr __at     (0xA9)    DMA3TSR     ;
__sfr __at     (0xAA)    DMA3BAH     ;
__sfr __at     (0xAB)    DMA3CR0     ;
__sfr __at     (0xAC)    DMA3MAL     ;
__sfr __at     (0xAD)    DMA3CNT     ;
__sfr __at     (0xAE)    DMA3CCNT    ;
__sfr __at     (0xAF)    MTM3DAL     ;

__sfr __at     (0xB1)    DMA2TSR     ;
__sfr __at     (0xB2)    DMA2BAH     ;
__sfr __at     (0xB3)    DMA2CR0     ;
__sfr __at     (0xB4)    DMA2MAL     ;
__sfr __at     (0xB5)    DMA2CNT     ;
__sfr __at     (0xB6)    DMA2CCNT    ;
__sfr __at     (0xB7)    MTM2DAL     ;

__sfr __at     (0xB9)    PWM2PH      ;
__sfr __at     (0xBA)    PWM2C0H     ;
__sfr __at     (0xBB)    PWM2C1H     ;
__sfr __at     (0xBC)    PWM2MD      ;
__sfr __at     (0xBD)    PWM2MEN     ;
__sfr __at     (0xBE)    CWKH        ;
__sfr __at     (0xBF)    RWKH        ;

__sfr __at     (0xC1)    PWM2PL      ;
__sfr __at     (0xC2)    PWM2C0L     ;
__sfr __at     (0xC3)    PWM2C1L     ;
__sfr __at     (0xC4)    PWM2CON0    ;
__sfr __at     (0xC5)    PWM2CON1    ;
__sfr __at     (0xC6)    PWM2INTC    ;

__sfr __at     (0xC9)    PWM3PH      ;
__sfr __at     (0xCA)    PWM3C0H     ;
__sfr __at     (0xCB)    PWM3C1H     ;
__sfr __at     (0xCC)    PWM3MD      ;
__sfr __at     (0xCD)    PWM3MEN     ;
__sfr __at     (0xCE)    AINDIDS1    ;
__sfr __at     (0xCF)    I2C0ADDRM   ;

__sfr __at     (0xD1)    PWM3PL      ;
__sfr __at     (0xD2)    PWM3C0L     ;
__sfr __at     (0xD3)    PWM3C1L     ;
__sfr __at     (0xD4)    PWM3CON0    ;
__sfr __at     (0xD5)    PWM3CON1    ;
__sfr __at     (0xD6)    PWM3INTC    ;
__sfr __at     (0xD7)    I2C1ADDRM   ;

__sfr __at     (0xD9)    SC1DR       ;
__sfr __at     (0xDA)    SC1EGT      ;
__sfr __at     (0xDB)    SC1ETURD0   ;
__sfr __at     (0xDC)    SC1ETURD1   ;
__sfr __at     (0xDD)    SC1IE       ;
__sfr __at     (0xDE)    SC1IS       ;
__sfr __at     (0xDF)    SC1TSR      ;

__sfr __at     (0xE1)    P5MF32      ;
__sfr __at     (0xE2)    P5MF54      ;
__sfr __at     (0xE3)    P5MF76      ;
__sfr __at     (0xE4)    BRCTRIM     ;
__sfr __at     (0xE5)    ADCCAL      ;
__sfr __at     (0xE6)    SC1CR0      ;
__sfr __at     (0xE7)    SC1CR1      ;

__sfr __at     (0xE9)    P3MF54      ;
__sfr __at     (0xEA)    P3MF76      ;
__sfr __at     (0xEB)    P4MF10      ;
__sfr __at     (0xEC)    P4MF32      ;
__sfr __at     (0xED)    P4MF54      ;
__sfr __at     (0xEE)    P4MF76      ;
__sfr __at     (0xEF)    P5MF10      ;

__sfr __at     (0xF1)    P1MF76      ;
__sfr __at     (0xF2)    P2MF10      ;
__sfr __at     (0xF3)    P2MF32      ;
__sfr __at     (0xF4)    P2MF54      ;
__sfr __at     (0xF5)    P2MF76      ;
__sfr __at     (0xF6)    P3MF10      ;
__sfr __at     (0xF7)    P3MF32      ;

__sfr __at     (0xF9)    P0MF10      ;
__sfr __at     (0xFA)    P0MF32      ;
__sfr __at     (0xFB)    P0MF54      ;
__sfr __at     (0xFC)    P0MF76      ;
__sfr __at     (0xFD)    P1MF10      ;
__sfr __at     (0xFE)    P1MF32      ;
__sfr __at     (0xFF)    P1MF54      ;

/*   ML56 SFR BYTE page 3  */    

__sfr __at     (0x8A)    DMA0CR1     ;
__sfr __at     (0x8B)    DMA1CR1     ;
__sfr __at     (0x8C)    DMA2CR1     ;
__sfr __at     (0x8D)    DMA3CR1     ;

__sfr __at     (0x92)    DMA0CRC     ;
__sfr __at     (0x93)    DMA1CRC     ;
__sfr __at     (0x94)    DMA2CRC     ;
__sfr __at     (0x95)    DMA3CRC     ;

__sfr __at     (0x99)    WDCONH      ;
__sfr __at     (0x9A)    DMA0SEED    ;
__sfr __at     (0x9B)    DMA1SEED    ;
__sfr __at     (0x9C)    DMA2SEED    ;
__sfr __at     (0x9D)    DMA3SEED    ;

__sfr __at     (0xA1)    RTCINIT     ;
__sfr __at     (0xA2)    RTCRWEN     ;
__sfr __at     (0xA3)    RTCCLKSEL   ;
__sfr __at     (0xA4)    RTCFREQADJ0 ;
__sfr __at     (0xA5)    RTCFREQADJ1 ;
__sfr __at     (0xA6)    RTCINTEN    ;
__sfr __at     (0xA7)    RTCINTSTS   ;

__sfr __at     (0xA9)    RTCTIMESEC  ;
__sfr __at     (0xAA)    RTCTIMEMIN  ;
__sfr __at     (0xAB)    RTCTIMEHR   ;
__sfr __at     (0xAD)    RTCCALDAY   ;
__sfr __at     (0xAE)    RTCCALMON   ;
__sfr __at     (0xAF)    RTCCALYEAR  ;

__sfr __at     (0xB1)    RTCTALMSEC  ;
__sfr __at     (0xB2)    RTCTALMMIN  ;
__sfr __at     (0xB3)    RTCTALMHR   ;
__sfr __at     (0xB4)    RTCTALMHZ   ;
__sfr __at     (0xB5)    RTCCALMDAY  ;
__sfr __at     (0xB6)    RTCCALMMON  ;
__sfr __at     (0xB7)    RTCCALMYEAR ;

__sfr __at     (0xB9)    RTCCLKFMT   ;
__sfr __at     (0xBB)    RTCWEEKDAY  ;
__sfr __at     (0xBC)    RTCLEAPYEAR ;
__sfr __at     (0xBD)    RTCTICK     ;
__sfr __at     (0xBE)    RTCTAMSK    ;
__sfr __at     (0xBF)    RTCCAMSK    ;

__sfr __at     (0xCE)    PWM0FBS     ;
__sfr __at     (0xCF)    AUXR3       ;

__sfr __at     (0xE9)    LCDCPALCT1  ;
__sfr __at     (0xEA)    LCDCPCT1    ;

__sfr __at     (0xF1)    LCDCPUMP    ;
__sfr __at     (0xF4)    LCDCON1     ;
__sfr __at     (0xF5)    LCDCPALCT0  ;
__sfr __at     (0xF6)    LCDCPCT0    ;

__sfr __at     (0xF9)    LCDCON0     ;
__sfr __at     (0xFA)    LCDCLK      ;
__sfr __at     (0xFB)    LCDPTR      ;
__sfr __at     (0xFC)    LCDDAT      ;
__sfr __at     (0xFD)    LCDPWR      ;
__sfr __at     (0xFE)    LCDBL       ;
__sfr __at     (0xFF)    LCDMODE     ;



/*  BIT Registers  */

/*  S1CON (0xF8) */                             
__sbit __at    (0xF8+7)    SM0_1   ;
__sbit __at    (0xF8+7)    FE_1    ;
__sbit __at    (0xF8+6)    SM1_1   ;
__sbit __at    (0xF8+5)    SM2_1   ;
__sbit __at    (0xF8+4)    REN_1   ;
__sbit __at    (0xF8+3)    TB8_1   ;
__sbit __at    (0xF8+2)    RB8_1   ;
__sbit __at    (0xF8+1)    TI_1    ;
__sbit __at    (0xF8+0)    RI_1    ;

/*  B (0xF0) */

/*  I2C1CON  (0xE8) */
__sbit __at    (0xE8+6)    I2CEN1  ; 
__sbit __at    (0xE8+5)    STA1    ; 
__sbit __at    (0xE8+4)    STO1    ; 
__sbit __at    (0xE8+3)    SI1     ; 
__sbit __at    (0xE8+2)    AA1     ; 
__sbit __at    (0xE8+0)    I2CPX1  ; 

/*  ACC (0xE0) */

/*  P4  (0xD8) */
__sbit __at    (0xD8+7)    P47     ;
__sbit __at    (0xD8+6)    P46     ;
__sbit __at    (0xD8+5)    P45     ;
__sbit __at    (0xD8+4)    P44     ;
__sbit __at    (0xD8+3)    P43     ;
__sbit __at    (0xD8+2)    P42     ;
__sbit __at    (0xD8+1)    P41     ;
__sbit __at    (0xD8+0)    P40     ;


/*   PSW (0xD0)  */  
__sbit __at    (0xD0+7)    CY      ;
__sbit __at    (0xD0+6)    AC      ;
__sbit __at    (0xD0+5)    F0      ;
__sbit __at    (0xD0+4)    RS1     ;
__sbit __at    (0xD0+3)    RS0     ;
__sbit __at    (0xD0+2)    OV      ;
__sbit __at    (0xD0+0)    P       ;

/*  T2CON (0xC8) */                 
__sbit __at    (0xC8+7)    TF2     ;    
__sbit __at    (0xC8+2)    TR2     ;    
__sbit __at    (0xC8+0)    CM_RL2  ;

/*  I2CON  (0xC0) */
__sbit __at    (0xC0+6)    I2CEN0  ;
__sbit __at    (0xC0+5)    STA0    ;
__sbit __at    (0xC0+4)    STO0    ;
__sbit __at    (0xC0+3)    SI0     ;
__sbit __at    (0xC0+2)    AA0     ;
__sbit __at    (0xC0+0)    I2C0PX  ;

/*  IP  (0xB8) */
__sbit __at    (0xB8+6)    PADC    ;
__sbit __at    (0xB8+5)    PBOD    ;
__sbit __at    (0xB8+4)    PS      ;
__sbit __at    (0xB8+3)    PT1     ;
__sbit __at    (0xB8+2)    PX1     ;
__sbit __at    (0xB8+1)    PT0     ;
__sbit __at    (0xB8+0)    PX0     ;

/*  P3  (0xB0) */
__sbit __at    (0xB0+7)    P37     ;
__sbit __at    (0xB0+6)    P36     ;
__sbit __at    (0xB0+5)    P35     ;
__sbit __at    (0xB0+4)    P34     ;
__sbit __at    (0xB0+3)    P33     ;
__sbit __at    (0xB0+2)    P32     ;
__sbit __at    (0xB0+1)    P31     ;
__sbit __at    (0xB0+0)    P30     ;

/*  IE  (0xA8) */
__sbit __at    (0xA8+7)    EA      ;
__sbit __at    (0xA8+6)    EADC    ;
__sbit __at    (0xA8+5)    EBOD    ;
__sbit __at    (0xA8+4)    ES      ;
__sbit __at    (0xA8+3)    ET1     ;
__sbit __at    (0xA8+2)    EX1     ;
__sbit __at    (0xA8+1)    ET0     ;
__sbit __at    (0xA8+0)    EX0     ;

/*  P2  (0xA0) */
__sbit __at    (0xA0+7)    P27     ;
__sbit __at    (0xA0+6)    P26     ;
__sbit __at    (0xA0+5)    P25     ;
__sbit __at    (0xA0+4)    P24     ;
__sbit __at    (0xA0+3)    P23     ;
__sbit __at    (0xA0+2)    P22     ;
__sbit __at    (0xA0+1)    P21     ;
__sbit __at    (0xA0+0)    P20     ;

/*  SCON  (0x98) */
__sbit __at    (0x98+7)    SM0     ;
__sbit __at    (0x98+7)    FE      ;
__sbit __at    (0x98+6)    SM1     ;
__sbit __at    (0x98+5)    SM2     ;
__sbit __at    (0x98+4)    REN     ;
__sbit __at    (0x98+3)    TB8     ;
__sbit __at    (0x98+2)    RB8     ;
__sbit __at    (0x98+1)    TI      ;
__sbit __at    (0x98+0)    RI      ;

/*  P1  (0x90) */
__sbit __at    (0x90+7)    P17     ;
__sbit __at    (0x90+6)    P16     ;
__sbit __at    (0x90+5)    P15     ;
__sbit __at    (0x90+4)    P14     ;
__sbit __at    (0x90+3)    P13     ;
__sbit __at    (0x90+2)    P12     ;
__sbit __at    (0x90+1)    P11     ;
__sbit __at    (0x90+0)    P10     ;

/*  TCON (0x88) */
__sbit __at    (0x88+7)    TF1     ;
__sbit __at    (0x88+6)    TR1     ;
__sbit __at    (0x88+5)    TF0     ;
__sbit __at    (0x88+4)    TR0     ;
__sbit __at    (0x88+3)    IE1     ;
__sbit __at    (0x88+2)    IT1     ;
__sbit __at    (0x88+1)    IE0     ;
__sbit __at    (0x88+0)    IT0     ;

/*  P0  (0x80)*/
__sbit  __at   (0x80+7)    P07     ;
__sbit  __at   (0x80+6)    P06     ;
__sbit  __at   (0x80+5)    P05     ;
__sbit  __at   (0x80+4)    P04     ;
__sbit  __at   (0x80+3)    P03     ;
__sbit  __at   (0x80+2)    P02     ;
__sbit  __at   (0x80+1)    P01     ;
__sbit  __at   (0x80+0)    P00     ;


 /*  Other Pin Name  */
__sbit __at    (0xA0+5)    AIN0    ;
__sbit __at    (0xA0+4)    AIN1    ;
__sbit __at    (0xA0+3)    AIN2    ;
__sbit __at    (0xA0+2)    AIN3    ;
__sbit __at    (0xA0+1)    AIN4    ;
__sbit __at    (0xA0+0)    AIN5    ;
__sbit __at    (0xB0+1)    AIN6    ;
__sbit __at    (0xB0+2)    AIN7    ;

