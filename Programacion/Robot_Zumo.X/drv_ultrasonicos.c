#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"

/* ID DE SENSORES:
 * 0 - FRONT
 * 1 - BACK
 * 2 - LEFT
 * 3 - RIGHT
 */

int ak = 0;

void usonic_init()
{
    usonic.flags.modoT1G = 0;
    usonic.flags.modoT3G = 0;
    usonic.flags.pulsoCapturadoT1G = 0;
    usonic.flags.pulsoCapturadoT3G = 0;
    usonic.mamometroT1G = 0;
    usonic.mamometroT3G = 0;
    usonic.flags.T1Gmamado = 0;
    usonic.flags.T3Gmamado = 0;
    usonic.pulsoCapturadoT1G = 0;
    usonic.pulsoCapturadoT3G = 0;

    usonic.distancia.front = 0;
    usonic.distancia.back = 0;
    usonic.distancia.left = 0;
    usonic.distancia.right = 0;
    usonic.numMuestra.front = 0;
    usonic.numMuestra.back = 0;
    usonic.numMuestra.left = 0;
    usonic.numMuestra.right = 0;
    usonic.promedio.front = 0;
    usonic.promedio.back = 0;
    usonic.promedio.left = 0;
    usonic.promedio.right = 0;

    TMR5_SetInterruptHandler(usonic_tick);
    TMR1G_SetInterruptHandler(pulsoCapturadoTimer1);
    TMR3G_SetInterruptHandler(pulsoCapturadoTimer3);

    T1GPPSbits.T1GPPS = PPS_ECHO_FRONT;
    T3GPPSbits.T3GPPS = PPS_ECHO_LEFT;

    usonic_trigger(SENSOR_FRONT);
    TMR1_StartSinglePulseAcquisition();
    usonic_trigger(SENSOR_LEFT);
    TMR3_StartSinglePulseAcquisition();
}

void usonic_tick()
{
    usonic.mamometroT1G++;
    if (usonic.mamometroT1G == 10 || TMR1_HasOverflowOccured())
    {
        usonic.flags.T1Gmamado = 1;
        usonic.mamometroT1G = 0;
    }
    usonic.mamometroT3G++;
    if (usonic.mamometroT3G == 10 || TMR3_HasOverflowOccured())
    {
        usonic.flags.T3Gmamado = 1;
        usonic.mamometroT3G = 0;
    }

    if (usonic.flags.pulsoCapturadoT1G || usonic.flags.T1Gmamado)
    {
        tomaRealizadaT1G(usonic.flags.T1Gmamado);
        PIR4bits.TMR1IF = 0;
        usonic.flags.T1Gmamado = 0;
        usonic.mamometroT1G = 0;
    }
    if (usonic.flags.pulsoCapturadoT3G || usonic.flags.T3Gmamado)
    {
        tomaRealizadaT3G(usonic.flags.T3Gmamado);
        PIR4bits.TMR3IF = 0;
        usonic.flags.T3Gmamado = 0;
        usonic.mamometroT3G = 0;
    }
}

void tomaRealizadaT1G(uint8_t mamado)
{
    if (!usonic.flags.modoT1G) //0 - front | 1 - back
    {
        if (!mamado)
            computarMedicion(SENSOR_FRONT, usonic.pulsoCapturadoT1G);
        else
        {
            usonic.distancia.front = UINT8_MAX;
            usonic.promedio.front = 0;
            usonic.numMuestra.front = 0;
        }
        T1GPPSbits.T1GPPS = PPS_ECHO_BACK;
        usonic_trigger(SENSOR_BACK);
        TMR1_StartSinglePulseAcquisition();
    } else
    {
        if (!mamado)
            computarMedicion(SENSOR_BACK, usonic.pulsoCapturadoT1G);
        else
        {
            usonic.distancia.back = UINT8_MAX;
            usonic.promedio.back = 0;
            usonic.numMuestra.back = 0;
        }
        T1GPPSbits.T1GPPS = PPS_ECHO_FRONT;
        usonic_trigger(SENSOR_FRONT);
        TMR1_StartSinglePulseAcquisition();
    }
    usonic.flags.modoT1G = ~usonic.flags.modoT1G;
    usonic.flags.pulsoCapturadoT1G = 0;
}

void tomaRealizadaT3G(uint8_t mamado)
{
    if (!usonic.flags.modoT3G) //0 - left  | 1 - right
    {
        if (!mamado)
            computarMedicion(SENSOR_LEFT, usonic.pulsoCapturadoT3G);
        else
        {
            usonic.distancia.left = UINT8_MAX;
            usonic.promedio.left = 0;
            usonic.numMuestra.left = 0;
        }
        T3GPPSbits.T3GPPS = PPS_ECHO_RIGHT;
        usonic_trigger(SENSOR_RIGHT);
        TMR3_StartSinglePulseAcquisition();
    } else
    {
        if (!mamado)
            computarMedicion(SENSOR_RIGHT, usonic.pulsoCapturadoT3G);
        else
        {
            usonic.distancia.right = UINT8_MAX;
            usonic.promedio.right = 0;
            usonic.numMuestra.right = 0;
        }
        T3GPPSbits.T3GPPS = PPS_ECHO_LEFT;
        usonic_trigger(SENSOR_LEFT);
        TMR3_StartSinglePulseAcquisition();
    }
    usonic.flags.modoT3G = ~usonic.flags.modoT3G;
    usonic.flags.pulsoCapturadoT3G = 0;
}

void computarMedicion(uint8_t sensor, uint16_t anchoPulso)
{
    switch (sensor)
    {
        case SENSOR_FRONT:
            usonic.numMuestra.front++;
            usonic.promedio.front += anchoPulso;
            if (usonic.numMuestra.front == MUESTRAS - 1)
            {
                usonic.numMuestra.front = 0;
                uint16_t distancia = (usonic.promedio.front / MUESTRAS) * 0.017 * CORRECCION;
                if (distancia > UINT8_MAX)
                    distancia = UINT8_MAX;
                usonic.distancia.front = distancia;
                interrupt_flags.nuevaMuestraFront = 1;
                usonic.promedio.front = 0;
            }
            break;
        case SENSOR_BACK:
            usonic.numMuestra.back++;
            usonic.promedio.back += anchoPulso;

            if (usonic.numMuestra.back == MUESTRAS - 1)
            {
                usonic.numMuestra.back = 0;
                uint16_t distancia = (usonic.promedio.back / MUESTRAS) * 0.017 * CORRECCION;
                if (distancia > UINT8_MAX)
                    distancia = UINT8_MAX;
                usonic.distancia.back = distancia;
                interrupt_flags.nuevaMuestraBack = 1;
                usonic.promedio.back = 0;
            }
            break;
        case SENSOR_LEFT:
            usonic.numMuestra.left++;
            usonic.promedio.left += anchoPulso;

            if (usonic.numMuestra.left == MUESTRAS - 1)
            {
                usonic.numMuestra.left = 0;
                uint16_t distancia = (usonic.promedio.left / MUESTRAS) * 0.017 * CORRECCION;
                if (distancia > UINT8_MAX)
                    distancia = UINT8_MAX;
                usonic.distancia.left = distancia;
                interrupt_flags.nuevaMuestraLeft = 1;
                usonic.promedio.left = 0;
            }
            break;
        case SENSOR_RIGHT:
            usonic.numMuestra.right++;
            usonic.promedio.right += anchoPulso;

            if (usonic.numMuestra.right == MUESTRAS - 1)
            {
                usonic.numMuestra.right = 0;
                uint16_t distancia = (usonic.promedio.right / MUESTRAS) * 0.017 * CORRECCION;
                if (distancia > UINT8_MAX)
                    distancia = UINT8_MAX;
                usonic.distancia.right = distancia;
                interrupt_flags.nuevaMuestraRight = 1;
                usonic.promedio.right = 0;
            }
            break;
    }
}

void pulsoCapturadoTimer1()
{
    usonic.pulsoCapturadoT1G = TMR1_ReadTimer();
    usonic.flags.pulsoCapturadoT1G = 1;
    TMR1_Reload();
}

void pulsoCapturadoTimer3()
{
    usonic.pulsoCapturadoT3G = TMR3_ReadTimer();
    usonic.flags.pulsoCapturadoT3G = 1;
    TMR3_Reload();
}

void usonic_trigger(uint8_t sensor)
{
    switch (sensor)
    {
        case SENSOR_FRONT:
            TRIGGER_FRONT_SetHigh();
            __delay_us(10);
            TRIGGER_FRONT_SetLow();
            break;
        case SENSOR_BACK:
            TRIGGER_BACK_SetHigh();
            __delay_us(10);
            TRIGGER_BACK_SetLow();
            break;
        case SENSOR_LEFT:
            TRIGGER_LEFT_SetHigh();
            __delay_us(10);
            TRIGGER_LEFT_SetLow();
            break;
        case SENSOR_RIGHT:
            TRIGGER_RIGHT_SetHigh();
            __delay_us(10);
            TRIGGER_RIGHT_SetLow();
            break;
    }
}