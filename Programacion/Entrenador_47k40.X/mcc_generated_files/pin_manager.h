/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC18F47K40
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

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

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS               TRISAbits.TRISA0
#define channel_ANA0_LAT                LATAbits.LATA0
#define channel_ANA0_PORT               PORTAbits.RA0
#define channel_ANA0_WPU                WPUAbits.WPUA0
#define channel_ANA0_OD                ODCONAbits.ODCA0
#define channel_ANA0_ANS                ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()    do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()   do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()  do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode() do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS               TRISCbits.TRISC3
#define SCL1_LAT                LATCbits.LATC3
#define SCL1_PORT               PORTCbits.RC3
#define SCL1_WPU                WPUCbits.WPUC3
#define SCL1_OD                ODCONCbits.ODCC3
#define SCL1_ANS                ANSELCbits.ANSELC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()    do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()   do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCL1_SetAnalogMode()  do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCL1_SetDigitalMode() do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS               TRISCbits.TRISC4
#define SDA1_LAT                LATCbits.LATC4
#define SDA1_PORT               PORTCbits.RC4
#define SDA1_WPU                WPUCbits.WPUC4
#define SDA1_OD                ODCONCbits.ODCC4
#define SDA1_ANS                ANSELCbits.ANSELC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()      do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()    do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()    do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()   do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDA1_SetAnalogMode()  do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SDA1_SetDigitalMode() do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set LCD_D7 aliases
#define LCD_D7_TRIS               TRISDbits.TRISD0
#define LCD_D7_LAT                LATDbits.LATD0
#define LCD_D7_PORT               PORTDbits.RD0
#define LCD_D7_WPU                WPUDbits.WPUD0
#define LCD_D7_OD                ODCONDbits.ODCD0
#define LCD_D7_ANS                ANSELDbits.ANSELD0
#define LCD_D7_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LCD_D7_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LCD_D7_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LCD_D7_GetValue()           PORTDbits.RD0
#define LCD_D7_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LCD_D7_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LCD_D7_SetPullup()      do { WPUDbits.WPUD0 = 1; } while(0)
#define LCD_D7_ResetPullup()    do { WPUDbits.WPUD0 = 0; } while(0)
#define LCD_D7_SetPushPull()    do { ODCONDbits.ODCD0 = 0; } while(0)
#define LCD_D7_SetOpenDrain()   do { ODCONDbits.ODCD0 = 1; } while(0)
#define LCD_D7_SetAnalogMode()  do { ANSELDbits.ANSELD0 = 1; } while(0)
#define LCD_D7_SetDigitalMode() do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LCD_D6 aliases
#define LCD_D6_TRIS               TRISDbits.TRISD1
#define LCD_D6_LAT                LATDbits.LATD1
#define LCD_D6_PORT               PORTDbits.RD1
#define LCD_D6_WPU                WPUDbits.WPUD1
#define LCD_D6_OD                ODCONDbits.ODCD1
#define LCD_D6_ANS                ANSELDbits.ANSELD1
#define LCD_D6_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LCD_D6_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LCD_D6_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LCD_D6_GetValue()           PORTDbits.RD1
#define LCD_D6_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LCD_D6_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LCD_D6_SetPullup()      do { WPUDbits.WPUD1 = 1; } while(0)
#define LCD_D6_ResetPullup()    do { WPUDbits.WPUD1 = 0; } while(0)
#define LCD_D6_SetPushPull()    do { ODCONDbits.ODCD1 = 0; } while(0)
#define LCD_D6_SetOpenDrain()   do { ODCONDbits.ODCD1 = 1; } while(0)
#define LCD_D6_SetAnalogMode()  do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LCD_D6_SetDigitalMode() do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set LCD_D5 aliases
#define LCD_D5_TRIS               TRISDbits.TRISD2
#define LCD_D5_LAT                LATDbits.LATD2
#define LCD_D5_PORT               PORTDbits.RD2
#define LCD_D5_WPU                WPUDbits.WPUD2
#define LCD_D5_OD                ODCONDbits.ODCD2
#define LCD_D5_ANS                ANSELDbits.ANSELD2
#define LCD_D5_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LCD_D5_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LCD_D5_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LCD_D5_GetValue()           PORTDbits.RD2
#define LCD_D5_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LCD_D5_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LCD_D5_SetPullup()      do { WPUDbits.WPUD2 = 1; } while(0)
#define LCD_D5_ResetPullup()    do { WPUDbits.WPUD2 = 0; } while(0)
#define LCD_D5_SetPushPull()    do { ODCONDbits.ODCD2 = 0; } while(0)
#define LCD_D5_SetOpenDrain()   do { ODCONDbits.ODCD2 = 1; } while(0)
#define LCD_D5_SetAnalogMode()  do { ANSELDbits.ANSELD2 = 1; } while(0)
#define LCD_D5_SetDigitalMode() do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set LCD_D4 aliases
#define LCD_D4_TRIS               TRISDbits.TRISD3
#define LCD_D4_LAT                LATDbits.LATD3
#define LCD_D4_PORT               PORTDbits.RD3
#define LCD_D4_WPU                WPUDbits.WPUD3
#define LCD_D4_OD                ODCONDbits.ODCD3
#define LCD_D4_ANS                ANSELDbits.ANSELD3
#define LCD_D4_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define LCD_D4_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define LCD_D4_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define LCD_D4_GetValue()           PORTDbits.RD3
#define LCD_D4_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define LCD_D4_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define LCD_D4_SetPullup()      do { WPUDbits.WPUD3 = 1; } while(0)
#define LCD_D4_ResetPullup()    do { WPUDbits.WPUD3 = 0; } while(0)
#define LCD_D4_SetPushPull()    do { ODCONDbits.ODCD3 = 0; } while(0)
#define LCD_D4_SetOpenDrain()   do { ODCONDbits.ODCD3 = 1; } while(0)
#define LCD_D4_SetAnalogMode()  do { ANSELDbits.ANSELD3 = 1; } while(0)
#define LCD_D4_SetDigitalMode() do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS               TRISDbits.TRISD4
#define LED1_LAT                LATDbits.LATD4
#define LED1_PORT               PORTDbits.RD4
#define LED1_WPU                WPUDbits.WPUD4
#define LED1_OD                ODCONDbits.ODCD4
#define LED1_ANS                ANSELDbits.ANSELD4
#define LED1_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define LED1_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define LED1_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define LED1_GetValue()           PORTDbits.RD4
#define LED1_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define LED1_SetPullup()      do { WPUDbits.WPUD4 = 1; } while(0)
#define LED1_ResetPullup()    do { WPUDbits.WPUD4 = 0; } while(0)
#define LED1_SetPushPull()    do { ODCONDbits.ODCD4 = 0; } while(0)
#define LED1_SetOpenDrain()   do { ODCONDbits.ODCD4 = 1; } while(0)
#define LED1_SetAnalogMode()  do { ANSELDbits.ANSELD4 = 1; } while(0)
#define LED1_SetDigitalMode() do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS               TRISDbits.TRISD5
#define LED2_LAT                LATDbits.LATD5
#define LED2_PORT               PORTDbits.RD5
#define LED2_WPU                WPUDbits.WPUD5
#define LED2_OD                ODCONDbits.ODCD5
#define LED2_ANS                ANSELDbits.ANSELD5
#define LED2_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define LED2_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define LED2_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define LED2_GetValue()           PORTDbits.RD5
#define LED2_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define LED2_SetPullup()      do { WPUDbits.WPUD5 = 1; } while(0)
#define LED2_ResetPullup()    do { WPUDbits.WPUD5 = 0; } while(0)
#define LED2_SetPushPull()    do { ODCONDbits.ODCD5 = 0; } while(0)
#define LED2_SetOpenDrain()   do { ODCONDbits.ODCD5 = 1; } while(0)
#define LED2_SetAnalogMode()  do { ANSELDbits.ANSELD5 = 1; } while(0)
#define LED2_SetDigitalMode() do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS               TRISDbits.TRISD6
#define LED3_LAT                LATDbits.LATD6
#define LED3_PORT               PORTDbits.RD6
#define LED3_WPU                WPUDbits.WPUD6
#define LED3_OD                ODCONDbits.ODCD6
#define LED3_ANS                ANSELDbits.ANSELD6
#define LED3_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define LED3_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define LED3_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define LED3_GetValue()           PORTDbits.RD6
#define LED3_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define LED3_SetPullup()      do { WPUDbits.WPUD6 = 1; } while(0)
#define LED3_ResetPullup()    do { WPUDbits.WPUD6 = 0; } while(0)
#define LED3_SetPushPull()    do { ODCONDbits.ODCD6 = 0; } while(0)
#define LED3_SetOpenDrain()   do { ODCONDbits.ODCD6 = 1; } while(0)
#define LED3_SetAnalogMode()  do { ANSELDbits.ANSELD6 = 1; } while(0)
#define LED3_SetDigitalMode() do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS               TRISDbits.TRISD7
#define LED4_LAT                LATDbits.LATD7
#define LED4_PORT               PORTDbits.RD7
#define LED4_WPU                WPUDbits.WPUD7
#define LED4_OD                ODCONDbits.ODCD7
#define LED4_ANS                ANSELDbits.ANSELD7
#define LED4_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define LED4_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define LED4_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define LED4_GetValue()           PORTDbits.RD7
#define LED4_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define LED4_SetPullup()      do { WPUDbits.WPUD7 = 1; } while(0)
#define LED4_ResetPullup()    do { WPUDbits.WPUD7 = 0; } while(0)
#define LED4_SetPushPull()    do { ODCONDbits.ODCD7 = 0; } while(0)
#define LED4_SetOpenDrain()   do { ODCONDbits.ODCD7 = 1; } while(0)
#define LED4_SetAnalogMode()  do { ANSELDbits.ANSELD7 = 1; } while(0)
#define LED4_SetDigitalMode() do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set LCD_RS aliases
#define LCD_RS_TRIS               TRISEbits.TRISE0
#define LCD_RS_LAT                LATEbits.LATE0
#define LCD_RS_PORT               PORTEbits.RE0
#define LCD_RS_WPU                WPUEbits.WPUE0
#define LCD_RS_OD                ODCONEbits.ODCE0
#define LCD_RS_ANS                ANSELEbits.ANSELE0
#define LCD_RS_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define LCD_RS_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define LCD_RS_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define LCD_RS_GetValue()           PORTEbits.RE0
#define LCD_RS_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define LCD_RS_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define LCD_RS_SetPullup()      do { WPUEbits.WPUE0 = 1; } while(0)
#define LCD_RS_ResetPullup()    do { WPUEbits.WPUE0 = 0; } while(0)
#define LCD_RS_SetPushPull()    do { ODCONEbits.ODCE0 = 0; } while(0)
#define LCD_RS_SetOpenDrain()   do { ODCONEbits.ODCE0 = 1; } while(0)
#define LCD_RS_SetAnalogMode()  do { ANSELEbits.ANSELE0 = 1; } while(0)
#define LCD_RS_SetDigitalMode() do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set LCD_EN aliases
#define LCD_EN_TRIS               TRISEbits.TRISE1
#define LCD_EN_LAT                LATEbits.LATE1
#define LCD_EN_PORT               PORTEbits.RE1
#define LCD_EN_WPU                WPUEbits.WPUE1
#define LCD_EN_OD                ODCONEbits.ODCE1
#define LCD_EN_ANS                ANSELEbits.ANSELE1
#define LCD_EN_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LCD_EN_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LCD_EN_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LCD_EN_GetValue()           PORTEbits.RE1
#define LCD_EN_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LCD_EN_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LCD_EN_SetPullup()      do { WPUEbits.WPUE1 = 1; } while(0)
#define LCD_EN_ResetPullup()    do { WPUEbits.WPUE1 = 0; } while(0)
#define LCD_EN_SetPushPull()    do { ODCONEbits.ODCE1 = 0; } while(0)
#define LCD_EN_SetOpenDrain()   do { ODCONEbits.ODCE1 = 1; } while(0)
#define LCD_EN_SetAnalogMode()  do { ANSELEbits.ANSELE1 = 1; } while(0)
#define LCD_EN_SetDigitalMode() do { ANSELEbits.ANSELE1 = 0; } while(0)

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



#endif // PIN_MANAGER_H
/**
 End of File
*/