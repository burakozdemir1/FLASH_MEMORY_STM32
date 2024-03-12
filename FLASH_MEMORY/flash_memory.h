/*
 * flash_memory.h
 *
 *  Created on: Nov 13, 2023
 *      Author: cudat
 */
#define MAX_STRING_SIZE 50

#define  FLASH_SECTOR_FOR_USERNAME FLASH_SECTOR_2
#define  FLASH_SECTOR_FOR_PASSWORD FLASH_SECTOR_2
#define  FLASH_SECTOR_FOR_STRING  FLASH_SECTOR_4  // Kullanılacak Flash sektörü
#define  FLASH_SECTOR_FOR_COIN FLASH_SECTOR_5



#define FLASH_STRING_ADDRESS    0x08010000      // Flash hafıza başlangıç adresi
#define USERNAME_FLASH_ADDRESS  0x0800C000
#define PASSWORD_FLASH_ADDRESS 0x08008000
#define COIN_FLASH_ADDRESS      0x08020000
#define UART_BUFFER_SIZE       64
#define RxBuf_SIZE   64


extern uint8_t uartRxBuffer[UART_BUFFER_SIZE];
extern char flashData[MAX_STRING_SIZE];
extern char flashData_string[MAX_STRING_SIZE];
extern char flashData_password[MAX_STRING_SIZE];

extern float RxVal;
//extern uint32_t coin;
//extern uint32_t *coin_ptr;

extern uint32_t  coin1[10];
extern uint32_t coin_read[10];

extern uint32_t  *coin_ptr1;
extern  uint32_t coin_data[10] ;
extern uint32_t flash_data ;
extern uint8_t flash_count ;
extern uint8_t kontrol  ;
extern uint8_t uartRxBuffer[UART_BUFFER_SIZE];
extern char flashData[MAX_STRING_SIZE];
extern uint8_t flashRxBuffer[MAX_STRING_SIZE];
extern char username[32];
extern char password[32];
extern char flash_read[50];

extern uint32_t coin_count[10];
extern HAL_StatusTypeDef durum;
void Split_Username_Password(const char *input, char *username, char *password) ;
void Flash_Write_String(uint32_t flashAddress, const char *data, uint32_t dataSize);
void Flash_Read_String(uint32_t flashAddress, char *data, uint32_t maxSize);
void Flash_Write_Username(uint32_t flashAddress, const char *username_data, uint32_t dataSize);
void Flash_Write_Password(uint32_t flashAddress, const char *password_data, uint32_t dataSize) ;
void Flash_Read(uint32_t m_flashAddress,uint32_t *data, uint32_t maxSize) ;


void Flash_Write(uint32_t m_flashAddress, uint32_t *m_flashData,uint32_t dataSize2) ;
void WriteStringToFlash(uint32_t sector_address, uint32_t *string);


//#define MainBuf_SIZE 25
//uint64_t size_buffer;

//char	TxBuffer[4]={0x12,0x34,0x56,0x78};
//uint8_t	RxBuffer[RxBuf_SIZE],MainBuf[MainBuf_SIZE];
//uint8_t RxData[RxBuf_SIZE];


