#include "mcc_generated_files/mcc.h"
#include "header.h"
#include "usonic_header.h"

void (*tactica_elegida)(void);

void tacticas_init()
{
    dist_tacticas_left[tactica_left_1_id] = tactica_left_1_dist;

    dist_tacticas_right[tactica_right_1_id] = tactica_right_1_dist;

    dist_tacticas_front[tactica_front_1_id] = tactica_front_1_dist;
    dist_tacticas_front[tactica_front_2_id] = tactica_front_2_dist;

    dist_tacticas_back[tactica_back_1_id] = tactica_back_1_dist;

    tactica_elegir(tactica_default);
}

void elegirTactica(uint8_t lado, uint8_t distancia)
{
    uint8_t certeza;
    switch (lado)
    {
        case LADO_ID_BACK: //back
            certeza = findClosest(dist_tacticas_back, dist_tacticas_back_size, distancia);
            switch (certeza)
            {
                case tactica_back_1_id:
                    tactica_elegir(tactica_back_1);
                    break;
            }
            break;
        case LADO_ID_FRONT: //front
            certeza = findClosest(dist_tacticas_front, dist_tacticas_front_size, distancia);
            switch (certeza)
            {
                case tactica_front_1_id:
                    tactica_elegir(tactica_front_1);
                    break;
                case tactica_front_2_id:
                    tactica_elegir(tactica_front_2);
                    break;
            }
            break;
        case LADO_ID_LEFT: //left
            certeza = findClosest(dist_tacticas_left, dist_tacticas_left_size, distancia);
            switch (certeza)
            {
                case tactica_left_1_id:
                    tactica_elegir(tactica_left_1);
                    break;
            }
            break;
        case LADO_ID_RIGHT: //right
            certeza = findClosest(dist_tacticas_right, dist_tacticas_right_size, distancia);
            switch (certeza)
            {
                case tactica_right_1_id:
                    tactica_elegir(tactica_right_1);
                    break;
            }
            break;
    }
}

void tactica_default(void)
{

}

void tactica_left_1()
{
    if (giroLeveIzquierdaRetroceder(3000U))
        return;
    if (girarXgradosizquierda(90U))
        return;
    if (giroLeveDerechaAvanzar(7000U))
        return;
}

void tactica_right_1()
{
    if (giroLeveDerechaRetroceder(3000U))
        return;
    if (girarXgradosderecha(90U))
        return;
   if (giroLeveIzquierdaAvanzar(7000U))
        return;

}

void tactica_front_1() //~30cm
{

    if (marcharAtrasTiempo(2000U))
        return;
    if (girarXgradosderecha(45U))
        return;
    if (marcharAdelanteTiempo(2000U))
        return;

}

void tactica_front_2() //~80cm
{
    if (giroLeveDerechaRetroceder(3000U))
        return;
    if (marcharAdelanteTiempo(3000U))
        return;
    if (girarXgradosizquierda(20U))
        return;
}

void tactica_back_1()
{
    if (girarXgradosizquierda(90U))
        return;
    if (marcharAtrasTiempo(3000U))
        return;
    if (girarXgradosizquierda(15U))
        return;
    if (delayTmr(1500U))
        return;
}

void tactica_ejecutar(void)
{
    // Add your custom callback code here

    if (tactica_elegida)
    {
        tactica_elegida();
    }
}

void tactica_elegir(void (* tactica_funcion)(void))
{
    tactica_elegida = tactica_funcion;
}