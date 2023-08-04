/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/


//***********************************************************************************************************
//  File Function: MS51 locate data in APROM simple demo 
//***********************************************************************************************************
#include "ml51_sdcc.h"
#include "SPROM.h"

/* SPROM area address define in .xcl file */
/* "SPROM_C" define in lnk51ew_ml51.xcl */
__code __at  (0xFF80)  char SPROM_FUNC(unsigned char unused)
{
  P12_PUSHPULL_MODE;
  P12 ^= 1;
  unused++;
  return unused;
}
