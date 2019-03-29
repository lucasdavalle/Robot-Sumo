#include "mcc_generated_files/mcc.h"
#include "header.h"
#include <stdio.h>

void marcharAdelante()
{
    motorIz_set(1);
    motorDe_set(1);
    ultimoMovimiento = MOV_ADELANTE;
}

uint8_t marcharAdelanteTiempo(uint16_t tiempo)
{
    marcharAdelante();
    ultimoMovimiento = MOV_ADELANTE;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    detenerse();
    return 0;
}

uint8_t marcharAtrasTiempo(uint16_t tiempo)
{
    marcharAtras();
    ultimoMovimiento = MOV_ATRAS;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    detenerse();
    return 0;
}

void marcharAtras()
{
    motorIz_set(2);
    motorDe_set(2);
    ultimoMovimiento = MOV_ATRAS;
}

uint8_t girarXgradosizquierda(uint16_t grados)
{
    motorIz_set(2);
    motorDe_set(1);
    ultimoMovimiento = MOV_GIR_IZQ;
    if (delayTmr(grados * constanteGiro))
        return 1; //Interrupcion!
    detenerse();
    return 0;
}

uint8_t girarXgradosderecha(uint16_t grados)
{
    motorIz_set(1);
    motorDe_set(2);
    ultimoMovimiento = MOV_GIR_DER;
    if (delayTmr(grados * constanteGiro))
        return 1; //Interrupcion!
    detenerse();
    return 0;
}

uint8_t giroLeveIzquierdaAvanzar(uint16_t tiempo)
{
    setPwmIz(140);
    setPwmDe(199);
    marcharAdelante();
    ultimoMovimiento = MOV_ADELANTE;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    setPwmIz(199);
    setPwmDe(199);
    detenerse();
    return 0;
}

uint8_t giroLeveIzquierdaRetroceder(uint16_t tiempo)
{
    setPwmIz(199);
    setPwmDe(140);
    marcharAtras();
    ultimoMovimiento = MOV_ATRAS;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    setPwmIz(199);
    setPwmDe(199);
    detenerse();
    return 0;
}

uint8_t giroLeveDerechaAvanzar(uint16_t tiempo)
{
    setPwmIz(199);
    setPwmDe(140);
    marcharAdelante();
    ultimoMovimiento = MOV_ADELANTE;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    setPwmIz(199);
    setPwmDe(199);
    detenerse();
    return 0;
}

uint8_t giroLeveDerechaRetroceder(uint16_t tiempo)
{
    setPwmIz(140);
    setPwmDe(199);
    marcharAtras();
    ultimoMovimiento = MOV_ATRAS;
    if (delayTmr(tiempo))
        return 1; //Interrupcion!
    setPwmIz(199);
    setPwmDe(199);
    detenerse();
    return 0;
}

void detenerse()
{
    motorIz_set(0);
    motorDe_set(0);
}

void setVelocidadMarcha(char velocidad) //0 - 199    0% 100%
{
    setPwmIz(velocidad);
    setPwmDe(velocidad);
}