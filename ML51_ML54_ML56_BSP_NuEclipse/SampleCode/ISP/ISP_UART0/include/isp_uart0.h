#define  Timer0Out_Counter   800

#define CMD_CONNECT          0xAE
#define CMD_SYNC_PACKNO      0xA4
#define CMD_GET_FWVER        0xA6
#define FW_VERSION           0x28
#define CMD_RUN_APROM        0xAB
#define CMD_GET_DEVICEID     0xB1
#define CMD_ERASE_ALL        0xA3
#define CMD_READ_CONFIG      0xA2
#define CMD_UPDATE_CONFIG    0xA1
#define CMD_UPDATE_APROM     0xA0
#define PAGE_ERASE_AP        0x22
#define BYTE_READ_AP         0x00
#define BYTE_PROGRAM_AP      0x21
#define BYTE_READ_ID         0x0C
#define PAGE_ERASE_CONFIG    0xE2
#define BYTE_READ_CONFIG     0xC0
#define BYTE_PROGRAM_CONFIG  0xE1
#define READ_UID             0x04
#define APROM_SIZE           61440UL   /* 60K bytes AP size , 4K LD size*/
//#define APROM_SIZE           62464UL   /* 61K bytes AP size, 3K LD size */
//#define APROM_SIZE           63488UL   /* 62K bytes PA size, 2K LD size */

extern __xdata volatile uint8_t uart_rcvbuf[64];
extern __xdata volatile uint8_t uart_txbuf[64];
extern __data volatile uint8_t bufhead;
extern __data volatile uint16_t flash_address;
extern __data volatile uint16_t AP_size;
extern __data volatile uint8_t g_timer1Counter;
extern __data volatile uint8_t count;
extern __data volatile uint16_t g_timer0Counter;
extern __data volatile uint32_t g_checksum;
extern __data volatile uint32_t g_totalchecksum;
extern BIT volatile bUartDataReady;
extern BIT volatile g_timer0Over;
extern BIT volatile g_timer1Over;
extern BIT volatile g_programflag;
extern BIT  BIT_TMP;
extern __data unsigned char PID_highB, PID_lowB, DID_highB, DID_lowB, CONF0, CONF1, CONF2, CONF4;
extern __data unsigned char recv_CONF0, recv_CONF1, recv_CONF2, recv_CONF4;


void MODIFY_HIRC_24(void);
void MODIFY_HIRC_16(void);
void TM0_ini(void);
void UART0_ini_115200_24MHz(void);
void Send_64byte_To_UART0(void);
void READ_ID(void);
void READ_CONFIG(void);
void Package_checksum(void);
 