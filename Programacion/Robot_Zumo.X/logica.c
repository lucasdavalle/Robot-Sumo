#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"

void detectarPosInicio()
{
    getLowestDistanceOnSensors_func();
    posInicio.distancia = getLowestDistanceOnSensors.distancia;
    posInicio.lado = getLowestDistanceOnSensors.lado_ID;
}

void getLowestDistanceOnSensors_func()
{
    uint8_t distancias[4];
    distancias[LADO_ID_BACK] = usonic.distancia.back;
    distancias[LADO_ID_FRONT] = usonic.distancia.front;
    distancias[LADO_ID_LEFT] = usonic.distancia.left;
    distancias[LADO_ID_RIGHT] = usonic.distancia.right;

    uint8_t smallest_value = UINT8_MAX;
    uint8_t ladoMenor;
    uint8_t i = 0;
    for (; i < 4; ++i)
    {
        if (distancias[i] < smallest_value)
        {
            smallest_value = distancias[i];
            ladoMenor = i;
        }
    }

    getLowestDistanceOnSensors.distancia = smallest_value;
    getLowestDistanceOnSensors.lado_ID = ladoMenor;
}

//
//void initBuscarMap(uint8_t * arr)
//{
//    uint8_t i = 0;
//    for (; i < 50; ++i)
//    {
//        arr[i] = UINT8_MAX;
//    }
//}

void buscar_t_init(struct buscar_t *med, uint8_t sensID)
{
    med->distMin = UINT8_MAX;
    med->milis = 0;
    med->lado_ID = sensID;
}

uint8_t buscarEnemigo()
{
    interrupt_flags.int_delay_activado = 0;
    interrupt_flags.borde_activado = 0;

    buscar_t_init(&med_front, LADO_ID_FRONT);
    buscar_t_init(&med_back, LADO_ID_BACK);
    buscar_t_init(&med_left, LADO_ID_LEFT);
    buscar_t_init(&med_right, LADO_ID_RIGHT);
    buscar_t_init(&med_final, 0);

    uint16_t precargaTimer = 0xFFFF - ((90 * constanteGiro) / 1.03);
    TMR0_WriteTimer(precargaTimer);
    TMR0_StartTimer();

    if (interrupt_flags.sentidoBusqueda)
    {
        motorIz_set(2);
        motorDe_set(1);
    } else
    {
        motorIz_set(1);
        motorDe_set(2);
    }

    uint16_t current_milis = 0;

    while (PIR0bits.TMR0IF == 0) //Ejecutar el codigo de adentro hasta que el robot gire 90º
    {
        current_milis = TMR0_ReadTimer() - precargaTimer;

        if (interrupt_flags.nuevaMuestraFront && usonic.distancia.front > 4) //Nueva medicion detectada
        {
            interrupt_flags.nuevaMuestraFront = 0;
            if (usonic.distancia.front <= med_front.distMin)
            {
                med_front.distMin = usonic.distancia.front;
                med_front.milis = current_milis;
            }
        }

        if (interrupt_flags.nuevaMuestraBack && usonic.distancia.back > 4) //Nueva medicion detectada
        {
            interrupt_flags.nuevaMuestraBack = 0;
            if (usonic.distancia.back <= med_back.distMin)
            {
                med_back.distMin = usonic.distancia.back;
                med_back.milis = current_milis;
            }
        }

        if (interrupt_flags.nuevaMuestraLeft && usonic.distancia.left > 4) //Nueva medicion detectada
        {
            interrupt_flags.nuevaMuestraLeft = 0;
            if (usonic.distancia.left <= med_left.distMin)
            {
                med_left.distMin = usonic.distancia.left;
                med_left.milis = current_milis;
            }
        }

        if (interrupt_flags.nuevaMuestraRight && usonic.distancia.right > 4) //Nueva medicion detectada
        {
            interrupt_flags.nuevaMuestraRight = 0;
            if (usonic.distancia.right <= med_right.distMin)
            {
                med_right.distMin = usonic.distancia.right;
                med_right.milis = current_milis;
            }
        }
    }

    PIR0bits.TMR0IF = 0;
    TMR0_StopTimer();
    TMR0_Reload();

    detenerse();

    uint8_t medidas[4];

    medidas[LADO_ID_FRONT] = med_front.distMin;
    medidas[LADO_ID_BACK] = med_back.distMin;
    medidas[LADO_ID_LEFT] = med_left.distMin;
    medidas[LADO_ID_RIGHT] = med_right.distMin;

    uint8_t i = 0;
    for (; i < 4; ++i)
    {
        if (medidas[i] < med_final.distMin)
        {
            med_final.distMin = medidas[i];
            med_final.lado_ID = i;
        }
    }
    
    if (interrupt_flags.sentidoBusqueda)
    {
        switch (med_final.lado_ID)
        {
            case LADO_ID_BACK:
                med_final.milis = 90 * constanteGiro * 1.03 + med_back.milis;
                motorIz_set(2);
                motorDe_set(1);
                //            girarXgradosizquierda(90 + med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_FRONT:
                med_final.milis = 90 * constanteGiro * 1.03 - med_front.milis;
                motorIz_set(1);
                motorDe_set(2);
                //            girarXgradosderecha(90 - med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_LEFT:
                med_final.milis = med_left.milis;
                motorIz_set(2);
                motorDe_set(1);
                //            girarXgradosizquierda(med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_RIGHT:
                med_final.milis = 180 * constanteGiro * 1.03 - med_right.milis;
                motorIz_set(1);
                motorDe_set(2);
                //            girarXgradosderecha(180 - med_final.milis / (constanteGiro * 1.03));
                break;
        }
    }
    else
    {
        switch (med_final.lado_ID)
        {
            case LADO_ID_BACK:
                med_final.milis = 90 * constanteGiro * 1.03 + med_back.milis;
                motorIz_set(2);
                motorDe_set(1);
                //            girarXgradosizquierda(90 + med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_FRONT:
                med_final.milis = 90 * constanteGiro * 1.03 - med_front.milis;
                motorIz_set(1);
                motorDe_set(2);
                //            girarXgradosderecha(90 - med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_LEFT:
                med_final.milis = 180 * constanteGiro * 1.03 - med_right.milis;
                med_final.milis = med_left.milis;
                motorIz_set(2);
                motorDe_set(1);
                //            girarXgradosizquierda(med_final.milis / (constanteGiro * 1.03));
                break;
            case LADO_ID_RIGHT:
                med_final.milis = med_left.milis;
                motorIz_set(1);
                motorDe_set(2);
                //            girarXgradosderecha(180 - med_final.milis / (constanteGiro * 1.03));
                break;
        }
    }
    
    delayTmr(med_final.milis);

    detenerse();
    
    interrupt_flags.sentidoBusqueda = ~interrupt_flags.sentidoBusqueda;
    
    interrupt_flags.borde_activado = 1;
    interrupt_flags.borde_detectado = 0;
    
    
    if (med_final.distMin <= 50)
        return 1;
    else
        return 0;
}


//uint8_t buscarEnemigo()
//{
//
//    interrupt_flags.borde_activado = 0;
//
//    LED_1_SetLow();
//    LED_2_SetLow();
//
//    uint8_t mediciones_back[50];
//    uint8_t mediciones_front[50];
//    uint8_t mediciones_left[50];
//    uint8_t mediciones_right[50];
//    uint16_t millis_back[50];
//    uint16_t millis_front[50];
//    uint16_t millis_left[50];
//    uint16_t millis_right[50];
//
//    initBuscarMap(mediciones_back);
//    initBuscarMap(mediciones_front);
//    initBuscarMap(mediciones_left);
//    initBuscarMap(mediciones_right);
//
//    struct
//    {
//        uint8_t left_id;
//        uint8_t right_id;
//        uint8_t front_id;
//        uint8_t back_id;
//    } ult_medicion;
//
//    ult_medicion.left_id = 0;
//    ult_medicion.right_id = 0;
//    ult_medicion.front_id = 0;
//    ult_medicion.back_id = 0;
//
//    uint16_t precargaTimer = 0xFFFF - ((90 * constanteGiro) / 1.03);
//    TMR0_WriteTimer(precargaTimer);
//    TMR0_StartTimer();
//
//    motorIz_set(2);
//    motorDe_set(1);
//
//    uint16_t current_milis = 0;
//
//    while (PIR0bits.TMR0IF == 0) //Ejecutar el codigo de adentro hasta que el robot gire 90º
//    {
//        current_milis++;
//        __delay_ms(1);
//
//        if (interrupt_flags.nuevaMuestraFront && usonic.distancia.front > 4) //Nueva medicion detectada
//        {
//            interrupt_flags.nuevaMuestraFront = 0;
//            millis_front[ult_medicion.front_id] = current_milis;
//            mediciones_front[ult_medicion.front_id++] = usonic.distancia.front;
//        }
//
//        if (interrupt_flags.nuevaMuestraBack && usonic.distancia.back > 4) //Nueva medicion detectada
//        {
//            interrupt_flags.nuevaMuestraBack = 0;
//            millis_back[ult_medicion.back_id] = current_milis;
//            mediciones_back[ult_medicion.back_id++] = usonic.distancia.back;
//        }
//
//        if (interrupt_flags.nuevaMuestraLeft && usonic.distancia.left > 4) //Nueva medicion detectada
//        {
//            interrupt_flags.nuevaMuestraLeft = 0;
//            millis_left[ult_medicion.left_id] = current_milis;
//            mediciones_left[ult_medicion.left_id++] = usonic.distancia.left;
//        }
//
//        if (interrupt_flags.nuevaMuestraRight && usonic.distancia.right > 4) //Nueva medicion detectada
//        {
//            interrupt_flags.nuevaMuestraRight = 0;
//            millis_right[ult_medicion.right_id] = current_milis;
//            mediciones_right[ult_medicion.right_id++] = usonic.distancia.right;
//        }
//    }
//
//    detenerse();
//
//    PIR0bits.TMR0IF = 0;
//    TMR0_StopTimer();
//    TMR0_Reload();
//
//    LED_1_SetHigh();
//
//    //Analizar mapa
//
//    uint8_t sub_Array_Average[4];
//    uint8_t sub_Array_IndexMedio[4];
//
//    sub_Array_IndexMedio[LADO_ID_BACK] = targetMapDetection(mediciones_back);
//    sub_Array_Average[LADO_ID_BACK] = targetMapDetection_subArrayAvg;
//    sub_Array_IndexMedio[LADO_ID_FRONT] = targetMapDetection(mediciones_front);
//    sub_Array_Average[LADO_ID_FRONT] = targetMapDetection_subArrayAvg;
//    sub_Array_IndexMedio[LADO_ID_LEFT] = targetMapDetection(mediciones_left);
//    sub_Array_Average[LADO_ID_LEFT] = targetMapDetection_subArrayAvg;
//    sub_Array_IndexMedio[LADO_ID_RIGHT] = targetMapDetection(mediciones_right);
//    sub_Array_Average[LADO_ID_RIGHT] = targetMapDetection_subArrayAvg;
//
//    uint8_t smallest_value = UINT8_MAX;
//    uint8_t ladoMenor;
//    uint8_t i = 0;
//    for (; i < 4; ++i)
//    {
//        if (sub_Array_Average[i] < smallest_value)
//        {
//            smallest_value = sub_Array_Average[i];
//            ladoMenor = i;
//        }
//    }
//
//    med_final.lado_ID = ladoMenor;
//    uint8_t med_final_indexm = sub_Array_IndexMedio[med_final.lado_ID];
//
//    uint8_t ultMov = ultimoMovimiento;
//    uint16_t milisAgirar;
//
//    switch (med_final.lado_ID)
//    {
//        case LADO_ID_BACK:
//            med_final.distMin = mediciones_back[med_final_indexm];
//            med_final.milis = millis_back[med_final_indexm];
//            milisAgirar = 90 * constanteGiro * 1.03 + med_final.milis;
//            motorIz_set(2);
//            motorDe_set(1);
//            delayTmr(milisAgirar);
//            break;
//        case LADO_ID_FRONT:
//            med_final.distMin = mediciones_front[med_final_indexm];
//            med_final.milis = millis_front[med_final_indexm];
//            milisAgirar = 90 * constanteGiro * 1.03 - med_final.milis;
//            motorIz_set(1);
//            motorDe_set(2);
//            delayTmr(milisAgirar);
//            break;
//        case LADO_ID_LEFT:
//            med_final.distMin = mediciones_left[med_final_indexm];
//            med_final.milis = millis_left[med_final_indexm];
//            milisAgirar = med_final.milis;
//            motorIz_set(2);
//            motorDe_set(1);
//            delayTmr(milisAgirar);
//            break;
//        case LADO_ID_RIGHT:
//            med_final.distMin = mediciones_right[med_final_indexm];
//            med_final.milis = millis_right[med_final_indexm];
//            milisAgirar = 180 * constanteGiro * 1.03 - med_final.milis;
//            motorIz_set(1);
//            motorDe_set(2);
//            delayTmr(milisAgirar);
//            break;
//    }
//    
//    debug_3 = milisAgirar;
//    updateLCD();
//    
//    detenerse();
//
//    LED_2_SetHigh();
//
//    ultimoMovimiento = ultMov; //Restaurar el movimiento anterior a buscar.
//
//    interrupt_flags.borde_activado = 1;
//
//    return 1;
//}