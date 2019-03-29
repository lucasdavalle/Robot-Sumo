#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include "drv_lcd.h"


void LCD_init()
{
    _displayfunction = (LCD_4BITMODE | LCD_2LINE);
    
    
#ifndef LCD_I2C
#ifdef TRISONINIT
    LCD_RS_TRIS = 0;
    LCD_EN_TRIS = 0;
    LCD_D4_TRIS = 0;
    LCD_D5_TRIS = 0;
    LCD_D6_TRIS = 0;
    LCD_D7_TRIS = 0;
#endif
#endif
    
    // SEE PAGE 45/46 FOR INITIALIZATION SPECIFICATION!
    // according to datasheet, we need at least 40ms after power rises above 2.7V
    // before sending commands. Arduino can turn on way before 4.5V so we'll wait 50
    __delay_ms(50);
    
    // Now we pull both RS and R/W low to begin commands
    
#ifndef LCD_I2C
    LCD_RS_SET(0);
    LCD_EN_SET(0);
    LCD_D4 = 0;
    LCD_D5 = 0;
    LCD_D6 = 0;
    LCD_D7 = 0;
#else
    //Inicializar el modulo I2C con todo en 0.
    LCD_I2C_BUFFER = 0x00;
    LCD_BL_SET(1);
    
#endif

    //put the LCD into 4 bit mode
    // this is according to the hitachi HD44780 datasheet
    // figure 24, pg 46

    // we start in 8bit mode, try to set 4 bit mode
    LCD_write4bits(0x03);
    __delay_us(4500); // wait min 4.1ms

    // second try
    LCD_write4bits(0x03);
    __delay_us(4500); // wait min 4.1ms

    // third go!
    LCD_write4bits(0x03);
    __delay_us(150);

    // finally, set to 4-bit interface
    LCD_write4bits(0x02);

    // finally, set # lines, font size, etc.
    LCD_command(LCD_FUNCTIONSET | _displayfunction);

    // turn the display on with no cursor or blinking default
    _displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
    LCD_display();

    // clear it off
    LCD_clear();

    // Initialize to default text direction (for romance languages)
    _displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
    // set the entry mode
    LCD_command(LCD_ENTRYMODESET | _displaymode);

}

/********** high level commands, for the user! */
void LCD_clear()
{
    LCD_command(LCD_CLEARDISPLAY); // clear display, set cursor position to zero
    __delay_ms(2); // this command takes a long time!
}

void LCD_home()
{
    LCD_command(LCD_RETURNHOME); // set cursor position to zero
    __delay_ms(2); // this command takes a long time!
}

void LCD_setCursor(char columna, char fila)
{
    switch (fila)
    {
        case 0:
            LCD_command(0x80 + columna);
            break;
        case 1:
            LCD_command(0xC0 + columna);
            break;
        case 2:
            LCD_command(0x94 + columna);
            break;
        case 3:
            LCD_command(0xD4 + columna);
            break;
    }
}

char LCD_print(const char * s)
{
    char cs = 0;
    while (*s)
    {
        LCD_write(*s++);
        cs++;
    }
    return cs; //Devuelve la longitud de la cadena
}

// Turn the display on/off (quickly)

void LCD_noDisplay()
{
    _displaycontrol &= ~LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void LCD_display()
{
    _displaycontrol |= LCD_DISPLAYON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off

void LCD_noCursor()
{
    _displaycontrol &= ~LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void LCD_cursor()
{
    _displaycontrol |= LCD_CURSORON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor

void LCD_noBlink()
{
    _displaycontrol &= ~LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

void LCD_blink()
{
    _displaycontrol |= LCD_BLINKON;
    LCD_command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM

void LCD_scrollDisplayLeft()
{
    LCD_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}

void LCD_scrollDisplayRight()
{
    LCD_command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}

// This is for text that flows Left to Right

void LCD_leftToRight()
{
    _displaymode |= LCD_ENTRYLEFT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// This is for text that flows Right to Left

void LCD_rightToLeft()
{
    _displaymode &= ~LCD_ENTRYLEFT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'right justify' text from the cursor

void LCD_autoscroll()
{
    _displaymode |= LCD_ENTRYSHIFTINCREMENT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// This will 'left justify' text from the cursor

void LCD_noAutoscroll()
{
    _displaymode &= ~LCD_ENTRYSHIFTINCREMENT;
    LCD_command(LCD_ENTRYMODESET | _displaymode);
}

// Allows us to fill the first 8 CGRAM locations
// with custom characters

void LCD_createChar(char location, char charmap[])
{
    location &= 0x7; // we only have 8 locations 0-7
    LCD_command(LCD_SETCGRAMADDR | (location << 3));
    for (int i = 0; i < 8; i++)
    {
        LCD_write(charmap[i]);
    }
}

/*********** mid level commands, for sending data/cmds */

void LCD_command(char value)
{
    LCD_send(value, 0);
}

void LCD_write(char value)
{
    LCD_send(value, 1);
}

/************ low level data pushing commands **********/

// write either command or data, with automatic 4/8-bit selection



void LCD_send(char value, char mode)
{
    LCD_RS_SET(mode);
    LCD_write4bits(value >> 4);
    LCD_write4bits(value);
}

void LCD_RS_SET(char value)
{
#ifndef LCD_I2C
    LCD_RS = value;
#else
    if (value)
        LCD_I2C_BUFFER |= LCD_I2C_BIT_RS;
    else
        LCD_I2C_BUFFER &= ~LCD_I2C_BIT_RS;
    LCD_writeI2C();
#endif
}

void LCD_EN_SET(char value)
{
#ifndef LCD_I2C
    LCD_EN = value;
#else
    if (value)
        LCD_I2C_BUFFER |= LCD_I2C_BIT_EN;
    else
        LCD_I2C_BUFFER &= ~LCD_I2C_BIT_EN;
    LCD_writeI2C();
#endif
}

#ifdef LCD_I2C
void LCD_BL_SET(char value)
{
    if (value)
        LCD_I2C_BUFFER |= LCD_I2C_BIT_BL;
    else
        LCD_I2C_BUFFER &= ~LCD_I2C_BIT_BL;
    LCD_writeI2C();
}

void LCD_RW_SET(char value)
{
    if (value)
        LCD_I2C_BUFFER |= LCD_I2C_BIT_RW;
    else
        LCD_I2C_BUFFER &= ~LCD_I2C_BIT_RW;
    LCD_writeI2C();
}
#endif

void LCD_pulseEnable()
{
    LCD_EN_SET(0);
    __delay_us(1);
    LCD_EN_SET(1);
    __delay_us(1); // enable pulse must be >450ns
    LCD_EN_SET(0);
    __delay_us(100); // commands need > 37us to settle
}

void LCD_write4bits(char a)
{
#ifndef LCD_I2C
    if (a & 1)
    {
        LCD_D4 = 1;
    } else
    {
        LCD_D4 = 0;
    }

    if (a & 2)
    {
        LCD_D5 = 1;
    } else
    {
        LCD_D5 = 0;
    }

    if (a & 4)
    {
        LCD_D6 = 1;
    } else
    {
        LCD_D6 = 0;
    }

    if (a & 8)
    {
        LCD_D7 = 1;
    } else
    {
        LCD_D7 = 0;
    }
#else
    LCD_I2C_BUFFER = (a << 4) | (LCD_I2C_BUFFER & 0x0F);
#endif
    LCD_pulseEnable();
}

#ifdef LCD_I2C
//Utiliza rutinas de la libreria I2C SIMPLE MASTER de Foundation Services by Microchip (MCC)
void LCD_writeI2C()
{
    static unsigned char wrtBuffer[1];
    wrtBuffer[0] = (LCD_I2C_BUFFER);
    i2c_writeNBytes(LCD_I2C_ADDRESS, wrtBuffer, 1);
}
#endif