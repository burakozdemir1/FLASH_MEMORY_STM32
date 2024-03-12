#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_flash.h"
#include "flash_memory.h"
#include <string.h>

HAL_StatusTypeDef durum;
//uint32_t coin_data[10];
/// uint32_t coin_count[9];
void Flash_Write(uint32_t m_flashAddress, uint32_t *m_flashData,uint32_t dataSize2)
{
    HAL_FLASH_Unlock();

    // Flash hafızasını temizle
    FLASH_Erase_Sector(FLASH_SECTOR_5, FLASH_VOLTAGE_RANGE_3);

    // Belirtilen adrese veriyi yaz


    for (uint32_t i = 0; i < dataSize2; i++)
    {
        durum=HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, m_flashAddress + i, m_flashData[i]);
    }

    durum=HAL_FLASH_Lock();


  //  HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, m_flashAddress, m_flashData);


}

void Flash_Write_String(uint32_t flashAddress, const char *data, uint32_t dataSize)
{
    HAL_FLASH_Unlock();

    // Flash hafızasını temizle
    FLASH_Erase_Sector(FLASH_SECTOR_4, FLASH_VOLTAGE_RANGE_3);

    // Belirtilen adrese string veriyi yaz
    for (uint32_t i = 0; i < dataSize; ++i)
    {
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, flashAddress + i, data[i]);
    }

    HAL_FLASH_Lock();
}

void Flash_Write_Username(uint32_t flashAddress, const char *username_data, uint32_t dataSize)
{
    HAL_FLASH_Unlock();

    // Flash hafızasını temizleme işlemi sadece ilk seferde yapılmalı
    static uint8_t flashCleared = 0;
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | FLASH_FLAG_PGAERR | FLASH_FLAG_PGSERR );

    if (!flashCleared)
    {
        FLASH_Erase_Sector(FLASH_SECTOR_4, FLASH_VOLTAGE_RANGE_3);
        flashCleared = 1;
    }

    // Belirtilen adrese kullanıcı adını yaz



    for (uint32_t i = 0; i < dataSize; ++i)
    {

        HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, flashAddress +i, username_data[i]);

       // Flash_Read_String( 0x08010000, flashData_username, MAX_STRING_SIZE);
    }


    HAL_FLASH_Lock();
}

void Flash_Write_Password(uint32_t flashAddress, const char *password_data, uint32_t dataSize)
{



    HAL_FLASH_Unlock();
   // CLEAR_BIT(FLASH->CR, (FLASH_CR_SER));
    // Flash hafızasını temizle
    FLASH_Erase_Sector(FLASH_SECTOR_FOR_PASSWORD, FLASH_VOLTAGE_RANGE_4);

    // Belirtilen adrese şifreyi yaz
    for (uint32_t i = 0; i < dataSize; ++i)
    {
	CLEAR_BIT(FLASH->CR, (FLASH_CR_SER));
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_DOUBLEWORD, flashAddress + i, password_data[i]);
    }

    HAL_FLASH_Lock();
}

void Flash_Read_String(uint32_t flashAddress, char *data, uint32_t maxSize)
{
    uint32_t i;

    for (i = 0; i <  maxSize; i++)
    {
        data[i] = (char)(*(uint8_t *)(flashAddress + i));
        if (data[i] == '\0')
        {
            break;
        }
    }

    // Okunan verinin sonuna NULL karakteri ekle
    data[i] = '\0';
}

void Flash_Read(uint32_t m_flashAddress,uint32_t *data, uint32_t maxSize)
{
    uint32_t i;

        for (i = 0; i <  maxSize; i++)
        {
            data[i] = (*(uint8_t *)(m_flashAddress + i));

        }
        data[0]=data[i];

        data[i] = '\0';
}

void Split_Username_Password(const char *input, char *username, char *password)
{

    char *separator = strchr(input, ':');
    if (separator != NULL)
    {

        strncpy(username, input, separator - input);
        username[separator - input] = '\0';  // Null karakterle bitir

        strcpy(password, separator + 1);  //
    }
    else
    {

        strcpy(username, "InvalidData");
        strcpy(password, "InvalidData");
    }
}


