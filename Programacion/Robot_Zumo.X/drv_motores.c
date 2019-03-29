#include "mcc_generated_files/mcc.h"
#include "header.h"

void motorDe_set(char a) //0 parado, 1 Adelante, 2 Atras
{
    switch (a)
    {
        case 0:
            MOTORIZ_A_SetLow();
            MOTORIZ_B_SetLow();
            break;
        case 2:
            MOTORIZ_A_SetHigh();
            MOTORIZ_B_SetLow();
            break;
        case 1:
            MOTORIZ_A_SetLow();
            MOTORIZ_B_SetHigh();
            break;
    }
    
}

void motorIz_set(char a) //0 parado, 1 Adelante, 2 Atras
{
    switch (a)
    {
        case 0:
            MOTORDE_A_SetLow();
            MOTORDE_B_SetLow();
            break;
        case 1:
            MOTORDE_A_SetLow();
            MOTORDE_B_SetHigh();
            break;
        case 2:
            MOTORDE_A_SetHigh();
            MOTORDE_B_SetLow();
            break;
    }
}

void setPwmIz(char pwm) // 0 - 199
{
    PWM3_LoadDutyValue(pwm);
}

void setPwmDe(char pwm) // 0 - 199
{
    PWM4_LoadDutyValue(pwm);
}