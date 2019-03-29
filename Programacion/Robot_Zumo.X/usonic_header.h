#ifndef USONIC_HEADER
#define	USONIC_HEADER

#include "mcc_generated_files/mcc.h"
#include "header.h"
#include <stdio.h>
#include <math.h>

#define CORRECCION 1.27 //Correccion, ajustable por el usuario.
#define MUESTRAS 3 //Muestras a promediar

#define PPS_ECHO_BACK 0x11
#define PPS_ECHO_FRONT 0x12
#define PPS_ECHO_LEFT 0x16
#define PPS_ECHO_RIGHT 0x17

#define SENSOR_FRONT 0
#define SENSOR_BACK 1
#define SENSOR_LEFT 2
#define SENSOR_RIGHT 3

#define SENSOR_NO_MAMADO 0
#define SENSOR_MAMADO 1

//    T3GPPSbits.T3GPPS = 0x11;   //RC1->TMR3:T3G;
//    T1GPPSbits.T1GPPS = 0x12;   //RC2->TMR1:T1G;

struct {

    struct {
        uint8_t left;
        uint8_t right;
        uint8_t front;
        uint8_t back;
    } distancia;

    struct {
        uint8_t left;
        uint8_t right;
        uint8_t front;
        uint8_t back;
    } numMuestra;

    struct {
        uint16_t left;
        uint16_t right;
        uint16_t front;
        uint16_t back;
    } promedio;

    struct {
        volatile unsigned pulsoCapturadoT1G : 1;
        volatile unsigned pulsoCapturadoT3G : 1;
        volatile unsigned modoT1G : 1; //0 - front | 1 - back
        volatile unsigned modoT3G : 1; //0 - left  | 1 - right
        volatile unsigned T1Gmamado :1;
        volatile unsigned T3Gmamado :1;
    } flags;

    uint16_t pulsoCapturadoT1G;
    uint16_t pulsoCapturadoT3G;
    uint8_t mamometroT1G;
    uint8_t mamometroT3G;
} usonic;

void usonic_init();
void usonic_tick();
void tomaRealizadaT1G(uint8_t mamado);
void tomaRealizadaT3G(uint8_t mamado);
void computarMedicion(uint8_t sensor, uint16_t anchoPulso);
void pulsoCapturadoTimer1();
void pulsoCapturadoTimer3();
void usonic_trigger(uint8_t sensor);

#endif

