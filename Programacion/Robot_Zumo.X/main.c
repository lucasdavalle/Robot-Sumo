#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"

void main(void)
{
    //Inicializar el sistema
    SYSTEM_Initialize();
    TMR0_StopTimer();
    TMR0_WriteTimer(60196U);
    TMR0_StartTimer();

    interrupt_flags.mediciones_en_peligro_b = 0;
    interrupt_flags.mediciones_en_peligro_f = 0;
    interrupt_flags.mediciones_en_peligro_l = 0;
    interrupt_flags.mediciones_en_peligro_r = 0;

    interrupt_flags.detector_activado = 0;
    interrupt_flags.robot_en_peligro = 0;

    interrupt_flags.borde_activado = 0;
    interrupt_flags.borde_detectado = 0;

    interrupt_flags.int_delay_activado = 0;

    interrupt_flags.sentidoBusqueda = 0;

    tacticas_init();
    usonic_init();
    drv_cny70_init();


    //Habilitar Interrupciones.
    INTERRUPT_GlobalInterruptHighEnable();
    INTERRUPT_GlobalInterruptLowEnable();
    INTERRUPT_PeripheralInterruptEnable();

#ifdef DEBUG_HABILITADO
    //  debugInit();
#endif

    //esperar a leer los ultrasonicos
    while (usonic.distancia.front == 0 || usonic.distancia.back == 0 || usonic.distancia.left == 0 || usonic.distancia.right == 0);

    while (TMR0_ReadTimer() <= 64000U)
    {
        LED_2_PORT = ~SWITCH_2_GetValue();
    }

    detectarPosInicio();

    elegirTactica(posInicio.lado, posInicio.distancia);

    //esperar a que terminen los 5s
    while (TMR0_HasOverflowOccured() == false);
    PIR0bits.TMR0IF = 0;
    TMR0_StopTimer();
    TMR0_Reload();

    //ejecutar tactica elegida si se habilito la ejecucion de tacticas.

    interrupt_flags.borde_activado = 1;
    interrupt_flags.borde_detectado = 0;

    if (SWITCH_2_GetValue() == 0)
        tactica_ejecutar();
    else
        interrupt_flags.manualOverride = 1;

    interrupt_flags.borde_detectado = 0;

    while (1)
    {
        if (usonic.distancia.front < 20)
        {
            modoNonStop = 1;
            atacar();
        } else
        {
            if (buscarEnemigo())
            {
                med_final.distMin += 30;
                modoNonStop = 0;
                atacar();
            } else
            {
                marcharAdelanteTiempo(3000U);
            }
        }

        //        if (buscarEnemigo())
        //        {
        //            med_final.distMin += 10;
        //            atacar();
        //        }
        //        else
        //        {
        //            marcharAdelanteTiempo(3000U);
        //        }
    }
}

void acomodarse()
{
    interrupt_flags.borde_activado = 0;
    /*
     * Sera ejecutada cuando se detecte el borde blanco en alguno de los sensores
     * Debe ser obviada la ejecucion si el robot esta considerablemente cerca, o en frente!
     * 
     */
    if (bordes.backleft && bordes.backright)
    {
        marcharAdelanteTiempo(3000U);
        interrupt_flags.borde_activado = 1;
        return;
    }

    if (bordes.backleft)
    {
        marcharAdelanteTiempo(3000U);
        girarXgradosderecha(45U);
        interrupt_flags.borde_activado = 1;
        return;
    }

    if (bordes.backright)
    {
        marcharAdelanteTiempo(3000U);
        girarXgradosizquierda(45U);
        interrupt_flags.borde_activado = 1;
        return;
    }

    if (bordes.frontleft && bordes.frontright)
    {
        marcharAtrasTiempo(3000U);
        interrupt_flags.borde_activado = 1;
        return;
    }

    if (bordes.frontright)
    {
        marcharAtrasTiempo(3000U);
        girarXgradosizquierda(90U);
        interrupt_flags.borde_activado = 1;
        return;
    }

    if (bordes.frontleft)
    {
        marcharAtrasTiempo(3000U);
        girarXgradosderecha(90U);
        interrupt_flags.borde_activado = 1;
        return;
    }
}

void atacar()
{
    uint8_t pararAtaque = 0;

    marcharAdelante();
    LED_1_SetHigh();
    interrupt_flags.borde_detectado = 0;
    interrupt_flags.borde_activado = 1;

    while (pararAtaque + interrupt_flags.borde_detectado + modoNonStop == 0)
    {
        if (interrupt_flags.nuevaMuestraFront)
        {
            interrupt_flags.nuevaMuestraFront = 0;
            if (usonic.distancia.front < 5)
            {
                modoNonStop = 1;
                pararAtaque = 1;
            }

            //verificar que el sensor frontal tenga la menor distancia de los 4 sensores
            if (med_final.distMin < usonic.distancia.front)
            {
                med_final.distMin = usonic.distancia.front + 30;
                pararAtaque = 1;
            }
        }
    }

    interrupt_flags.borde_detectado = 0;

    while (modoNonStop && interrupt_flags.borde_detectado == 0);

    interrupt_flags.borde_detectado = 0;
    detenerse();
    modoNonStop = 0;
    LED_1_SetLow();

    return; //volver a buscar
}

uint8_t delayTmr(uint16_t miliSegundos)
{
    TMR0_WriteTimer(0xFFFF - (miliSegundos / 1.03));
    TMR0_StartTimer();
    while (PIR0bits.TMR0IF == 0)
    {
        if ((interrupt_flags.borde_activado * interrupt_flags.borde_detectado) * interrupt_flags.int_delay_activado)
            return 1; //Si se detecto alguna interrupcion retornar con valor 1!
    }
    PIR0bits.TMR0IF = 0;
    TMR0_StopTimer();
    TMR0_Reload();
    return 0;
}
