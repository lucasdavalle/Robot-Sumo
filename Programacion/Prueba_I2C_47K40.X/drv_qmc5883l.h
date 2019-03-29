#ifndef DRV_QMC5883L_H
#define	DRV_QMC5883L_H

/*
 * Libreria para manejo de sensor Magnetómetro con el IC
 * QMC-5883-L, procediente de modulo GY-273.
 * Por Enrique Walter Philippeaux, el día 9 de Mayo de 2018
 * 
 * Esta libreria utiliza rutinas de la libreria i2c1_driver,
 * i2c_master y i2c_simple_master de Team Foundation Services.
 */


//#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <stdio.h>

#define QMC5883_ADDR 0x0D


//REG CONTROL

#define Mode_Standby    0x00
#define Mode_Continuous 0x01

#define ODR_10Hz        0x00
#define ODR_50Hz        0x04
#define ODR_100Hz       0x08
#define ODR_200Hz       0x0C

#define RNG_2G          0x00
#define RNG_8G          0x10

#define OSR_512         0x00
#define OSR_256         0x40
#define OSR_128         0x80
#define OSR_64          0xC0


void XYZ_Init();
void XYZ_WriteReg(uint8_t reg, uint8_t val);
void XYZ_setMode(uint8_t mode, uint8_t odr, uint8_t rng, uint8_t osr);
void XYZ_softReset();
float XYZ_azimuth(int *a, int *b); //Insertar Y, X.
void XYZ_Read(int* x, int* y, int* z);
float XYZ_ReadTemp();

//Ejemplo de uso de la libreria:
//while (1) {
//    __delay_ms(250);
//    int x, y, z;
//
//    XYZ_Read(&x, &y, &z);
//    float az = XYZ_azimuth(&y, &x);
//
//    sprintf(vectorString, "D:%f", az);
//    LCD_setCursor(0, 1);
//    LCD_print(vectorString);
//}
#endif	/* DRV_QMC5883L_H */

