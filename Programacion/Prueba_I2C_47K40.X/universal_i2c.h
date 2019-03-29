#ifndef UNIVERSAL_I2C_H
#define UNIVERSAL_I2C_H


#define MCC //Descomentar si no se utilizara librerias creadas por MCC

#ifdef MCC
#include "mcc_generated_files/mcc.h"
#else
#include <xc.h>
#endif

#define MSB_FIRST 1
#define LSB_FIRST 0

void UI2C_write1Byte(uint8_t address, uint8_t data);
void UI2C_write2Bytes(uint8_t address, uint8_t regDir, uint8_t data);

uint8_t UI2C_read1Byte(uint8_t address);
uint16_t UI2C_read2ByteReg(uint8_t address, uint8_t msbfirst);

//Funciones de bajo nivel
void UI2C_writeNBytes(uint8_t address, void* data, uint8_t len);
void UI2C_readNBytes(uint8_t address, void* data, uint8_t len);

#endif