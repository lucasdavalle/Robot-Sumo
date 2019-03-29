#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "drv_lcd.h"

float getTemperatura();
void regularTemperatura(float temp);

bit calefactorON;
bit aireacondicionadoON;
char vectorString[32];
void timerInt();

char simboloGrados[] = {
    0b11000,
    0b11000,
    0b00000,
    0b01111,
    0b01000,
    0b01000,
    0b01000,
    0b01111
};

void main(void)
{
    // Initialize the device

    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(timerInt);

    //Inicializamos variables tipo BIT
    calefactorON = 0;
    aireacondicionadoON = 0;

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    LCD_init();

    LCD_createChar(0, simboloGrados);

    LCD_setCursor(0, 0);
    LCD_print("Temperatura:");

    while (1)
    {
        
    }
}

void timerInt() //Int cada 100mS
{
    LCD_setCursor(0, 1);
    float temperatura = getTemperatura();

    sprintf(vectorString, "%.3f", temperatura);
    LCD_print(vectorString);
    LCD_write(0); //Escribir simbolo de grados celcius   
    LCD_print("     ");


    regularTemperatura(temperatura);

    LED1_PORT = calefactorON; //Encender/Apagar el calefactor.
    LED2_PORT = aireacondicionadoON; //Encender/Apagar el AC.
}

float getTemperatura()
{
    unsigned int valorADC = 1023 - ADCC_GetSingleConversion(0);

    return (100.0 * (valorADC) / 1023);
}

void regularTemperatura(float temp)
{
    if (temp >= 60)
    {
        aireacondicionadoON = 1;
    }
    if (temp <= 50 && aireacondicionadoON)
    {
        aireacondicionadoON = 0;
    }

    if (temp <= 20)
    {
        calefactorON = 1;
    }
    if (temp >= 30 && calefactorON)
    {
        calefactorON = 0;
    }
}