//#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "drv_qmc5883l.h"
#include <stdio.h>
#include <math.h>

void XYZ_Init()
{
    XYZ_WriteReg(0x0B, 0x01);
    //Define Set/Reset period
    XYZ_setMode(Mode_Continuous, ODR_200Hz, RNG_8G, OSR_512);
    /*
    Define
    OSR = 512
    Full Scale Range = 8G(Gauss)
    ODR = 200HZ
    set continuous measurement mode
     */
}

void XYZ_WriteReg(uint8_t reg, uint8_t val)
{
    static unsigned char wrtBuffer[2];
    wrtBuffer[0] = (reg);
    wrtBuffer[1] = (val);
    i2c_writeNBytes(QMC5883_ADDR, wrtBuffer, 2);
}

void XYZ_setMode(uint8_t mode, uint8_t odr, uint8_t rng, uint8_t osr)
{
    XYZ_WriteReg(0x09, mode | odr | rng | osr);
}

void XYZ_softReset()
{
    XYZ_WriteReg(0x0A, 0x80);
}

float XYZ_azimuth(int *a, int *b) //Insertar Y, X.
{
    float azimuth = atan2((int) *a, (int) *b) * 180.0 / 3.1415;
    return azimuth < 0 ? 360 + azimuth : azimuth;
}

void XYZ_Read(int* x, int* y, int* z)
{
    static unsigned char wrtBuffer[1];
    wrtBuffer[0] = (0x00);
    i2c_writeNBytes(QMC5883_ADDR, wrtBuffer, 1);
    unsigned char readBuffer[6];
    i2c_readNBytes(QMC5883_ADDR, readBuffer, 6);
    *x = readBuffer[0] | (readBuffer[1] << 8);
    *y = readBuffer[2] | (readBuffer[3] << 8);
    *z = readBuffer[4] | (readBuffer[5] << 8);
}

float XYZ_ReadTemp()
{
    static unsigned char wrtBuffer[1];
    wrtBuffer[0] = (0x07);
    i2c_writeNBytes(QMC5883_ADDR, wrtBuffer, 1);
    unsigned char readBuffer[2];
    i2c_readNBytes(QMC5883_ADDR, readBuffer, 2);
    
    int tempVal = readBuffer[0] | (readBuffer[1] << 8);
    return (tempVal / 100.0);
}