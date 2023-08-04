/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: ML51 ADC / Bandgap VDD demo code
//***********************************************************************************************************
#include "ml51_sdcc.h"

float  Bandgap_Voltage,VDD_Voltage,Bandgap_Value;      //please always use "double" mode for this
unsigned  char ADCdataH[5], ADCdataL[5];
float bgvalue;
unsigned char i;

/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void)
{
/* UART0 settting for printf function */
    Enable_UART0_VCOM_printf();
    printf ("\n Test start ...");


/* ADC Low speed initial*/
    ENABLE_ADC_BANDGAP;            /* clock divider */
    ADCCON2|=0x0E;                 /* AQT time */

/*start bandgap ADC */
    clr_ADCCON0_ADCF;
    set_ADCCON0_ADCS;
    while(!(ADCCON0&SET_BIT7));    /*while ADCF =0; */
    ADCdataH[i] = ADCRH;
    ADCdataL[i] = ADCRL;
/* to convert VDD value */
    bgvalue = (ADCRH<<4) + ADCRL;
/*Read bandgap value */
    Bandgap_Voltage= READ_BANDGAP()*3/4;
    VDD_Voltage = (0x1000/bgvalue)*Bandgap_Voltage;


/*printf result value */
    printf_fast_f ("\n BG Voltage = %f", Bandgap_Voltage);
    printf_tiny (" mV");
    printf_fast_f ("\n VDD voltage = %f", VDD_Voltage);
    printf_tiny (" mV");

    while(1);

}


