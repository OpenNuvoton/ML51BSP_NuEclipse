#define  GPIO_LED  P32    /* the NuMaker board GPIO LED pin define */ 
#define  GPIO_LED_QUASI_MODE    P32_QUASI_MODE
#define  UART0_PRINTF_GPIO      P31

extern BIT BIT_TMP;
extern unsigned char __data  TA_REG_TMP,SFRS_TMP,BYTE_TMP;

unsigned char Read_APROM_BYTE(unsigned int __code *u16_addr);
void Global_Interrupt(unsigned char u8IntStatus);
void _delay_(void);
