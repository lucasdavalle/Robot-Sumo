#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"

void borde_detectado()
{
    if (bordes.frontleft + bordes.frontright + bordes.backleft + bordes.backright)
    {
        interrupt_flags.borde_detectado = 1;

        //Agregar codigo de acomodamiento en pista
        if (interrupt_flags.borde_activado && usonic.distancia.front > 20 && interrupt_flags.manualOverride == 0)
            acomodarse();
        else
            interrupt_flags.borde_detectado = 0;
    }
}