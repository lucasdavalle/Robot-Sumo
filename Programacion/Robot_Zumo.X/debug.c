#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"
/*
void debugInit()
{
    uint8_t exitGame = 0;
    while (exitGame == 0)
    {
        uint8_t dato = EUSART1_Read();

        switch (dato)
        {
            case 'w':
                setPwmIz(199);
                setPwmDe(199);
                marcharAdelante();
                break;
            case 'a':
                setPwmIz(199);
                setPwmDe(199);
                motorIz_set(2);
                motorDe_set(1);
                break;
            case 's':
                setPwmIz(199);
                setPwmDe(199);
                marcharAtras();
                break;
            case 'd':
                setPwmIz(199);
                setPwmDe(199);
                motorIz_set(1);
                motorDe_set(2);
                break;
            case 'r':
                detenerse();
                break;
            case 't':
                setPwmIz(140);
                setPwmDe(199);
                marcharAdelante();
                break;
            case 'y':
                setPwmIz(199);
                setPwmDe(140);
                marcharAdelante();
                break;
            case 'g':
                setPwmIz(199);
                setPwmDe(140);
                marcharAtras();
                break;
            case 'h':
                setPwmIz(140);
                setPwmDe(199);
                marcharAtras();
                break;
            case 'f':
                exitGame = 1;
                break;
            default:
                break;
        }
    }

    SERIAL_println("Sistema Iniciado");
    TMR6_SetInterruptHandler(debugTick);
}

void debugTick()
{
    //sprintf(vectorString, "F:%3u B:%3u L:%3u R:%3u", usonic.distancia.front, usonic.distancia.back, usonic.distancia.left, usonic.distancia.right);
    //    sprintf(vectorString, "M1:%3u M2:%3u M3:%3u SD:%3u", debug.meds1, debug.meds2, debug.meds3, debug.sd);
    //    SERIAL_println(vectorString);
    sprintf(vectorString, "BD:%1u PA:%1u NS:%1u", interrupt_flags.borde_detectado, debug.pararAtaque, debug.modoNonStop);
    SERIAL_println(vectorString);
}

void SERIAL_println(unsigned char *cadena)
{
    uint8_t i = 0;
    while (cadena[i] != 0)
    {
        EUSART1_Write(cadena[i]);
        i++;
    }
    EUSART1_Write('\n');
}*/