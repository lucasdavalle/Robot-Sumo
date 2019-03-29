#include "universal_i2c.h"

#ifdef MCC
#include "mcc_generated_files/mcc.h"
#else
#include <xc.h>
#endif

#include <stdio.h>
#include <stdint.h>

void UI2C_write1Byte(uint8_t address, uint8_t data)
{
    static uint8_t wrtBuffer[1];
    wrtBuffer[0] = (data);
    UI2C_writeNBytes(address, &wrtBuffer, 1);
}

void UI2C_write2Bytes(uint8_t address, uint8_t data1, uint8_t data2)
{
    static unsigned char wrtBuffer[2];
    wrtBuffer[0] = (data1);
    wrtBuffer[1] = (data2);
    UI2C_writeNBytes(address, &wrtBuffer, 2);
}

uint8_t UI2C_read1Byte(uint8_t address)
{
    static uint8_t readBuffer[1];
    i2c_readNBytes(address, &readBuffer, 1);
    return readBuffer[0];
}

uint16_t UI2C_read2ByteReg(uint8_t address, uint8_t msbfirst)
{
    static uint8_t readBuffer[2];
    i2c_readNBytes(address, &readBuffer, 2);
    uint16_t result;
    
    if (msbfirst)
        result = readBuffer[0] << 8 | readBuffer[1];
    else
        result = readBuffer[1] << 8 | readBuffer[0];
    
    return result;
}

void UI2C_writeNBytes(uint8_t address, void* data, uint8_t len)
{
#ifdef MCC
    i2c_writeNBytes(address, &data, len);
#else
    
#endif
}

void UI2C_readNBytes(uint8_t address, void* data, uint8_t len)
{
#ifdef MCC
    i2c_readNBytes(address, &data, len);
#else
    
#endif
}