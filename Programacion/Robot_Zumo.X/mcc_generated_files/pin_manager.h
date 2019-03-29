/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18F47K40
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA3 procedures
#define RA3_SetHigh()               do { LATAbits.LATA3 = 1; } while(0)
#define RA3_SetLow()                do { LATAbits.LATA3 = 0; } while(0)
#define RA3_Toggle()                do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define RA3_GetValue()              PORTAbits.RA3
#define RA3_SetDigitalInput()       do { TRISAbits.TRISA3 = 1; } while(0)
#define RA3_SetDigitalOutput()      do { TRISAbits.TRISA3 = 0; } while(0)
#define RA3_SetPullup()             do { WPUAbits.WPUA3 = 1; } while(0)
#define RA3_ResetPullup()           do { WPUAbits.WPUA3 = 0; } while(0)
#define RA3_SetAnalogMode()         do { ANSELAbits.ANSELA3 = 1; } while(0)
#define RA3_SetDigitalMode()        do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()               do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()                do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()                do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()       do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()      do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSELA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set MOTORDE_B aliases
#define MOTORDE_B_TRIS                 TRISAbits.TRISA5
#define MOTORDE_B_LAT                  LATAbits.LATA5
#define MOTORDE_B_PORT                 PORTAbits.RA5
#define MOTORDE_B_WPU                  WPUAbits.WPUA5
#define MOTORDE_B_OD                   ODCONAbits.ODCA5
#define MOTORDE_B_ANS                  ANSELAbits.ANSELA5
#define MOTORDE_B_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define MOTORDE_B_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define MOTORDE_B_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define MOTORDE_B_GetValue()           PORTAbits.RA5
#define MOTORDE_B_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define MOTORDE_B_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define MOTORDE_B_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define MOTORDE_B_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define MOTORDE_B_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define MOTORDE_B_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define MOTORDE_B_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define MOTORDE_B_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set BORDE_BR aliases
#define BORDE_BR_TRIS                 TRISBbits.TRISB0
#define BORDE_BR_LAT                  LATBbits.LATB0
#define BORDE_BR_PORT                 PORTBbits.RB0
#define BORDE_BR_WPU                  WPUBbits.WPUB0
#define BORDE_BR_OD                   ODCONBbits.ODCB0
#define BORDE_BR_ANS                  ANSELBbits.ANSELB0
#define BORDE_BR_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BORDE_BR_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BORDE_BR_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define BORDE_BR_GetValue()           PORTBbits.RB0
#define BORDE_BR_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BORDE_BR_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BORDE_BR_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define BORDE_BR_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define BORDE_BR_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define BORDE_BR_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define BORDE_BR_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define BORDE_BR_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set BORDE_FR aliases
#define BORDE_FR_TRIS                 TRISBbits.TRISB1
#define BORDE_FR_LAT                  LATBbits.LATB1
#define BORDE_FR_PORT                 PORTBbits.RB1
#define BORDE_FR_WPU                  WPUBbits.WPUB1
#define BORDE_FR_OD                   ODCONBbits.ODCB1
#define BORDE_FR_ANS                  ANSELBbits.ANSELB1
#define BORDE_FR_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BORDE_FR_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BORDE_FR_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BORDE_FR_GetValue()           PORTBbits.RB1
#define BORDE_FR_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BORDE_FR_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BORDE_FR_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BORDE_FR_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BORDE_FR_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define BORDE_FR_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define BORDE_FR_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define BORDE_FR_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set BORDE_BL aliases
#define BORDE_BL_TRIS                 TRISBbits.TRISB2
#define BORDE_BL_LAT                  LATBbits.LATB2
#define BORDE_BL_PORT                 PORTBbits.RB2
#define BORDE_BL_WPU                  WPUBbits.WPUB2
#define BORDE_BL_OD                   ODCONBbits.ODCB2
#define BORDE_BL_ANS                  ANSELBbits.ANSELB2
#define BORDE_BL_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BORDE_BL_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BORDE_BL_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BORDE_BL_GetValue()           PORTBbits.RB2
#define BORDE_BL_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BORDE_BL_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BORDE_BL_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BORDE_BL_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BORDE_BL_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define BORDE_BL_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define BORDE_BL_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define BORDE_BL_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set BORDE_FL aliases
#define BORDE_FL_TRIS                 TRISBbits.TRISB3
#define BORDE_FL_LAT                  LATBbits.LATB3
#define BORDE_FL_PORT                 PORTBbits.RB3
#define BORDE_FL_WPU                  WPUBbits.WPUB3
#define BORDE_FL_OD                   ODCONBbits.ODCB3
#define BORDE_FL_ANS                  ANSELBbits.ANSELB3
#define BORDE_FL_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define BORDE_FL_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define BORDE_FL_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define BORDE_FL_GetValue()           PORTBbits.RB3
#define BORDE_FL_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define BORDE_FL_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define BORDE_FL_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define BORDE_FL_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define BORDE_FL_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define BORDE_FL_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define BORDE_FL_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define BORDE_FL_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SWITCH_1 aliases
#define SWITCH_1_TRIS                 TRISBbits.TRISB4
#define SWITCH_1_LAT                  LATBbits.LATB4
#define SWITCH_1_PORT                 PORTBbits.RB4
#define SWITCH_1_WPU                  WPUBbits.WPUB4
#define SWITCH_1_OD                   ODCONBbits.ODCB4
#define SWITCH_1_ANS                  ANSELBbits.ANSELB4
#define SWITCH_1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SWITCH_1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SWITCH_1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SWITCH_1_GetValue()           PORTBbits.RB4
#define SWITCH_1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SWITCH_1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SWITCH_1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SWITCH_1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SWITCH_1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SWITCH_1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SWITCH_1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SWITCH_1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SWITCH_2 aliases
#define SWITCH_2_TRIS                 TRISBbits.TRISB5
#define SWITCH_2_LAT                  LATBbits.LATB5
#define SWITCH_2_PORT                 PORTBbits.RB5
#define SWITCH_2_WPU                  WPUBbits.WPUB5
#define SWITCH_2_OD                   ODCONBbits.ODCB5
#define SWITCH_2_ANS                  ANSELBbits.ANSELB5
#define SWITCH_2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SWITCH_2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SWITCH_2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SWITCH_2_GetValue()           PORTBbits.RB5
#define SWITCH_2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SWITCH_2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SWITCH_2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SWITCH_2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SWITCH_2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define SWITCH_2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define SWITCH_2_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define SWITCH_2_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set ECHO_BACK aliases
#define ECHO_BACK_TRIS                 TRISCbits.TRISC1
#define ECHO_BACK_LAT                  LATCbits.LATC1
#define ECHO_BACK_PORT                 PORTCbits.RC1
#define ECHO_BACK_WPU                  WPUCbits.WPUC1
#define ECHO_BACK_OD                   ODCONCbits.ODCC1
#define ECHO_BACK_ANS                  ANSELCbits.ANSELC1
#define ECHO_BACK_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define ECHO_BACK_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define ECHO_BACK_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define ECHO_BACK_GetValue()           PORTCbits.RC1
#define ECHO_BACK_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define ECHO_BACK_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define ECHO_BACK_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define ECHO_BACK_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define ECHO_BACK_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define ECHO_BACK_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define ECHO_BACK_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define ECHO_BACK_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set ECHO_FRONT aliases
#define ECHO_FRONT_TRIS                 TRISCbits.TRISC2
#define ECHO_FRONT_LAT                  LATCbits.LATC2
#define ECHO_FRONT_PORT                 PORTCbits.RC2
#define ECHO_FRONT_WPU                  WPUCbits.WPUC2
#define ECHO_FRONT_OD                   ODCONCbits.ODCC2
#define ECHO_FRONT_ANS                  ANSELCbits.ANSELC2
#define ECHO_FRONT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ECHO_FRONT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ECHO_FRONT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ECHO_FRONT_GetValue()           PORTCbits.RC2
#define ECHO_FRONT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ECHO_FRONT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define ECHO_FRONT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define ECHO_FRONT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define ECHO_FRONT_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define ECHO_FRONT_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define ECHO_FRONT_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define ECHO_FRONT_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set ECHO_LEFT aliases
#define ECHO_LEFT_TRIS                 TRISCbits.TRISC6
#define ECHO_LEFT_LAT                  LATCbits.LATC6
#define ECHO_LEFT_PORT                 PORTCbits.RC6
#define ECHO_LEFT_WPU                  WPUCbits.WPUC6
#define ECHO_LEFT_OD                   ODCONCbits.ODCC6
#define ECHO_LEFT_ANS                  ANSELCbits.ANSELC6
#define ECHO_LEFT_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define ECHO_LEFT_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define ECHO_LEFT_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define ECHO_LEFT_GetValue()           PORTCbits.RC6
#define ECHO_LEFT_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define ECHO_LEFT_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define ECHO_LEFT_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define ECHO_LEFT_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define ECHO_LEFT_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define ECHO_LEFT_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define ECHO_LEFT_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define ECHO_LEFT_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set ECHO_RIGHT aliases
#define ECHO_RIGHT_TRIS                 TRISCbits.TRISC7
#define ECHO_RIGHT_LAT                  LATCbits.LATC7
#define ECHO_RIGHT_PORT                 PORTCbits.RC7
#define ECHO_RIGHT_WPU                  WPUCbits.WPUC7
#define ECHO_RIGHT_OD                   ODCONCbits.ODCC7
#define ECHO_RIGHT_ANS                  ANSELCbits.ANSELC7
#define ECHO_RIGHT_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define ECHO_RIGHT_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define ECHO_RIGHT_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define ECHO_RIGHT_GetValue()           PORTCbits.RC7
#define ECHO_RIGHT_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define ECHO_RIGHT_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define ECHO_RIGHT_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define ECHO_RIGHT_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define ECHO_RIGHT_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define ECHO_RIGHT_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define ECHO_RIGHT_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define ECHO_RIGHT_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set TRIGGER_BACK aliases
#define TRIGGER_BACK_TRIS                 TRISDbits.TRISD0
#define TRIGGER_BACK_LAT                  LATDbits.LATD0
#define TRIGGER_BACK_PORT                 PORTDbits.RD0
#define TRIGGER_BACK_WPU                  WPUDbits.WPUD0
#define TRIGGER_BACK_OD                   ODCONDbits.ODCD0
#define TRIGGER_BACK_ANS                  ANSELDbits.ANSELD0
#define TRIGGER_BACK_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define TRIGGER_BACK_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define TRIGGER_BACK_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define TRIGGER_BACK_GetValue()           PORTDbits.RD0
#define TRIGGER_BACK_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define TRIGGER_BACK_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define TRIGGER_BACK_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define TRIGGER_BACK_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define TRIGGER_BACK_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define TRIGGER_BACK_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define TRIGGER_BACK_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define TRIGGER_BACK_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set TRIGGER_FRONT aliases
#define TRIGGER_FRONT_TRIS                 TRISDbits.TRISD1
#define TRIGGER_FRONT_LAT                  LATDbits.LATD1
#define TRIGGER_FRONT_PORT                 PORTDbits.RD1
#define TRIGGER_FRONT_WPU                  WPUDbits.WPUD1
#define TRIGGER_FRONT_OD                   ODCONDbits.ODCD1
#define TRIGGER_FRONT_ANS                  ANSELDbits.ANSELD1
#define TRIGGER_FRONT_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define TRIGGER_FRONT_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define TRIGGER_FRONT_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define TRIGGER_FRONT_GetValue()           PORTDbits.RD1
#define TRIGGER_FRONT_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define TRIGGER_FRONT_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define TRIGGER_FRONT_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define TRIGGER_FRONT_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define TRIGGER_FRONT_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define TRIGGER_FRONT_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define TRIGGER_FRONT_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define TRIGGER_FRONT_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set TRIGGER_LEFT aliases
#define TRIGGER_LEFT_TRIS                 TRISDbits.TRISD2
#define TRIGGER_LEFT_LAT                  LATDbits.LATD2
#define TRIGGER_LEFT_PORT                 PORTDbits.RD2
#define TRIGGER_LEFT_WPU                  WPUDbits.WPUD2
#define TRIGGER_LEFT_OD                   ODCONDbits.ODCD2
#define TRIGGER_LEFT_ANS                  ANSELDbits.ANSELD2
#define TRIGGER_LEFT_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define TRIGGER_LEFT_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define TRIGGER_LEFT_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define TRIGGER_LEFT_GetValue()           PORTDbits.RD2
#define TRIGGER_LEFT_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define TRIGGER_LEFT_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define TRIGGER_LEFT_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define TRIGGER_LEFT_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define TRIGGER_LEFT_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define TRIGGER_LEFT_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define TRIGGER_LEFT_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define TRIGGER_LEFT_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set TRIGGER_RIGHT aliases
#define TRIGGER_RIGHT_TRIS                 TRISDbits.TRISD3
#define TRIGGER_RIGHT_LAT                  LATDbits.LATD3
#define TRIGGER_RIGHT_PORT                 PORTDbits.RD3
#define TRIGGER_RIGHT_WPU                  WPUDbits.WPUD3
#define TRIGGER_RIGHT_OD                   ODCONDbits.ODCD3
#define TRIGGER_RIGHT_ANS                  ANSELDbits.ANSELD3
#define TRIGGER_RIGHT_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define TRIGGER_RIGHT_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define TRIGGER_RIGHT_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define TRIGGER_RIGHT_GetValue()           PORTDbits.RD3
#define TRIGGER_RIGHT_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define TRIGGER_RIGHT_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define TRIGGER_RIGHT_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define TRIGGER_RIGHT_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define TRIGGER_RIGHT_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define TRIGGER_RIGHT_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define TRIGGER_RIGHT_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define TRIGGER_RIGHT_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set LED_1 aliases
#define LED_1_TRIS                 TRISDbits.TRISD4
#define LED_1_LAT                  LATDbits.LATD4
#define LED_1_PORT                 PORTDbits.RD4
#define LED_1_WPU                  WPUDbits.WPUD4
#define LED_1_OD                   ODCONDbits.ODCD4
#define LED_1_ANS                  ANSELDbits.ANSELD4
#define LED_1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LED_1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LED_1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LED_1_GetValue()           PORTDbits.RD4
#define LED_1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LED_1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LED_1_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define LED_1_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define LED_1_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define LED_1_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define LED_1_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define LED_1_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set LED_2 aliases
#define LED_2_TRIS                 TRISDbits.TRISD5
#define LED_2_LAT                  LATDbits.LATD5
#define LED_2_PORT                 PORTDbits.RD5
#define LED_2_WPU                  WPUDbits.WPUD5
#define LED_2_OD                   ODCONDbits.ODCD5
#define LED_2_ANS                  ANSELDbits.ANSELD5
#define LED_2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED_2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED_2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED_2_GetValue()           PORTDbits.RD5
#define LED_2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED_2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LED_2_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define LED_2_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define LED_2_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define LED_2_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define LED_2_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define LED_2_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set LED_3 aliases
#define LED_3_TRIS                 TRISDbits.TRISD6
#define LED_3_LAT                  LATDbits.LATD6
#define LED_3_PORT                 PORTDbits.RD6
#define LED_3_WPU                  WPUDbits.WPUD6
#define LED_3_OD                   ODCONDbits.ODCD6
#define LED_3_ANS                  ANSELDbits.ANSELD6
#define LED_3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LED_3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define LED_3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LED_3_GetValue()           PORTDbits.RD6
#define LED_3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LED_3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define LED_3_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define LED_3_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define LED_3_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define LED_3_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define LED_3_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define LED_3_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set LED_4 aliases
#define LED_4_TRIS                 TRISDbits.TRISD7
#define LED_4_LAT                  LATDbits.LATD7
#define LED_4_PORT                 PORTDbits.RD7
#define LED_4_WPU                  WPUDbits.WPUD7
#define LED_4_OD                   ODCONDbits.ODCD7
#define LED_4_ANS                  ANSELDbits.ANSELD7
#define LED_4_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define LED_4_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define LED_4_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define LED_4_GetValue()           PORTDbits.RD7
#define LED_4_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define LED_4_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define LED_4_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define LED_4_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define LED_4_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define LED_4_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define LED_4_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define LED_4_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set MOTORDE_A aliases
#define MOTORDE_A_TRIS                 TRISEbits.TRISE0
#define MOTORDE_A_LAT                  LATEbits.LATE0
#define MOTORDE_A_PORT                 PORTEbits.RE0
#define MOTORDE_A_WPU                  WPUEbits.WPUE0
#define MOTORDE_A_OD                   ODCONEbits.ODCE0
#define MOTORDE_A_ANS                  ANSELEbits.ANSELE0
#define MOTORDE_A_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define MOTORDE_A_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define MOTORDE_A_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define MOTORDE_A_GetValue()           PORTEbits.RE0
#define MOTORDE_A_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define MOTORDE_A_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define MOTORDE_A_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define MOTORDE_A_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define MOTORDE_A_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define MOTORDE_A_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define MOTORDE_A_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define MOTORDE_A_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set MOTORIZ_B aliases
#define MOTORIZ_B_TRIS                 TRISEbits.TRISE1
#define MOTORIZ_B_LAT                  LATEbits.LATE1
#define MOTORIZ_B_PORT                 PORTEbits.RE1
#define MOTORIZ_B_WPU                  WPUEbits.WPUE1
#define MOTORIZ_B_OD                   ODCONEbits.ODCE1
#define MOTORIZ_B_ANS                  ANSELEbits.ANSELE1
#define MOTORIZ_B_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define MOTORIZ_B_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define MOTORIZ_B_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define MOTORIZ_B_GetValue()           PORTEbits.RE1
#define MOTORIZ_B_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define MOTORIZ_B_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define MOTORIZ_B_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define MOTORIZ_B_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define MOTORIZ_B_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define MOTORIZ_B_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define MOTORIZ_B_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define MOTORIZ_B_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set MOTORIZ_A aliases
#define MOTORIZ_A_TRIS                 TRISEbits.TRISE2
#define MOTORIZ_A_LAT                  LATEbits.LATE2
#define MOTORIZ_A_PORT                 PORTEbits.RE2
#define MOTORIZ_A_WPU                  WPUEbits.WPUE2
#define MOTORIZ_A_OD                   ODCONEbits.ODCE2
#define MOTORIZ_A_ANS                  ANSELEbits.ANSELE2
#define MOTORIZ_A_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define MOTORIZ_A_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define MOTORIZ_A_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define MOTORIZ_A_GetValue()           PORTEbits.RE2
#define MOTORIZ_A_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define MOTORIZ_A_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define MOTORIZ_A_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define MOTORIZ_A_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define MOTORIZ_A_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define MOTORIZ_A_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define MOTORIZ_A_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define MOTORIZ_A_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF3 pin functionality
 * @Example
    IOCBF3_ISR();
 */
void IOCBF3_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF3 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF3 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF3_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF3 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_InterruptHandler);

*/
extern void (*IOCBF3_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF3 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF3_SetInterruptHandler() method.
    This handler is called every time the IOCBF3 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF3_SetInterruptHandler(IOCBF3_DefaultInterruptHandler);

*/
void IOCBF3_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/