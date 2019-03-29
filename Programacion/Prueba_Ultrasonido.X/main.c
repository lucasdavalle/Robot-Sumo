/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F47K40
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

#include <stdio.h>

void echoChanged();
uint16_t timerCount = 0;
uint16_t distancia = 0;
char vectorString[32];
void serial_print(uint8_t *cadena);

#define COEFCORRECCION 1.27
#define MUESTRAS 20
uint8_t numMedicion = 0;
uint16_t mediciones[MUESTRAS];
uint16_t promedio = 0;


void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    INT0_SetInterruptHandler(echoChanged);
    EXT_INT0_risingEdgeSet();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    TMR5_StopTimer();
    TRIGGER_PORT = 1;
    __delay_us(10);
    TRIGGER_PORT = 0;

    while (1)
    {
        __delay_ms(200);
        sprintf(vectorString, "%i %i \n", timerCount, distancia);
        serial_print(vectorString);
    }
}

void echoChanged() //Tiempo de ejecucion estimado 20uS
{
    if (INTCONbits.INT0EDG)
    {
        INTCONbits.INT0EDG = 0;
        TMR5_WriteTimer(0);
        TMR5_StartTimer();
    } else
    {
        INTCONbits.INT0EDG = 1;
        TMR5_StopTimer();
        timerCount = TMR5_ReadTimer();
        mediciones[numMedicion] = timerCount * 0.017 * COEFCORRECCION;
        numMedicion++;
        promedio += mediciones[numMedicion];
        
        if (numMedicion == MUESTRAS - 1)
        {
            numMedicion = 0;
            distancia = promedio / MUESTRAS;
            promedio = 0;
        }
        //Activa la siguiente conversion
        TRIGGER_PORT = 1;
        __delay_us(10);
        TRIGGER_PORT = 0;
    }
}

void serial_print(uint8_t *cadena)
{
    uint8_t i = 0;
    while (cadena[i] != 0)
    {
        EUSART1_Write(cadena[i]);
        i++;
    }
}

/**
 End of File
 */