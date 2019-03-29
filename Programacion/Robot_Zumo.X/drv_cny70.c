#include "mcc_generated_files/mcc.h"
#include "header.h"

void drv_cny70_init()
{
    IOCBF0_SetInterruptHandler(borde_isr);
    IOCBF1_SetInterruptHandler(borde_isr);
    IOCBF2_SetInterruptHandler(borde_isr);
    IOCBF3_SetInterruptHandler(borde_isr);
    bordes.frontleft = 0;
    bordes.frontright = 0;
    bordes.backleft = 0;
    bordes.backright = 0;
}

void borde_isr()
{
    __delay_ms(15);
    
    bordes.frontleft = PORTBbits.RB3;
    bordes.frontright = PORTBbits.RB1;
    bordes.backleft = PORTBbits.RB2;
    bordes.backright = 1U - PORTBbits.RB0;
    borde_detectado();
}