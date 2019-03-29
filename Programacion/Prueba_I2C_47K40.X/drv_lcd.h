#ifndef drv_lcd
#define drv_lcd

#include "mcc_generated_files/mcc.h"
#include <stdio.h>

/*
 * Libreria para manejo de LCD con el controlador HD44780
 * Basada en la libreria original de arduino LiquidCrystal
 * Por Enrique Walter Philippeaux, el día 5 de Mayo de 2018
 */

/*
 *	Libreria para el manejo de un display LCD
 *	Utiliza las rutinas de delay.c y funciona con XC8
 *	Este codigo conecta al PIC con el controlador estandar 
 *	HD44780 de Hitachi. Usa el modo de 4 bits, con el hardware 
 *	conectado segun como defina las salidas LCD_X.
 *	
 *	Para utilizar la libreria, realize la configuracion correspondiente en el archivo
 *  "drv_lcd.h" ( al final de este ) y llame luego de todas las rutinas de configuración (TRISA, TRISB, ...)
 *  a la funcion lcd_init();
 */


#define LCD_I2C //Descomentar si se utilizará modulo I2C



#ifdef LCD_I2C

unsigned char LCD_I2C_BUFFER = 0x00;
void LCD_writeI2C();
void LCD_RW_SET(char value);
void LCD_BL_SET(char value);
#define LCD_I2C_BIT_RS 1
#define LCD_I2C_BIT_RW 2
#define LCD_I2C_BIT_EN 4
#define LCD_I2C_BIT_BL 8
#define LCD_I2C_BIT_D4 16
#define LCD_I2C_BIT_D5 32
#define LCD_I2C_BIT_D6 64
#define LCD_I2C_BIT_D7 128

#endif
// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

//Variables para uso interno de la librería
char _displayfunction = 0;
char _displaycontrol = 0;
char _displaymode = 0;

void LCD_init(); //Llamar en el main
void LCD_clear(); //Limpia el LCD
void LCD_home(); //Reinicia el cursor y lo lleva a la posicion 0
void LCD_setCursor(char columna, char fila); //Se usa para mover el cursor
char LCD_print(const char * s); //Para escribir cadenas de texto
void LCD_noDisplay(); //Para dejar de mostrar los caracteres
void LCD_display(); //Para volver a mostrar los caracteres
void LCD_noCursor(); //Para apagar el cursor (se parece al guion bajo)
void LCD_cursor(); //Para encender el cursor (se parece al guion bajo)
void LCD_noBlink(); //Para que el cursor deje de titilar
void LCD_blink(); //Para que el cursor titile
void LCD_scrollDisplayLeft(); //Para mover todo el texto del lcd 1 caracter a la izquierda
void LCD_scrollDisplayRight(); //Para mover todo el texto del lcd 1 caracter a la derecha
void LCD_leftToRight(); //Para introducir el texto de izquierda a derecha
void LCD_rightToLeft(); //Para introducir el texto de derecha a izquierda
void LCD_autoscroll(); //Justifica el texto a la derecha desde el cursor
void LCD_noAutoscroll(); //Justifica el texto a la izquierda desde el cursor
void LCD_createChar(char location, char charmap[]); //Permite crear un caracter según lo siguiente:
//char carac1[] = {
//    0B01110,
//    0B10001,
//    0B10001,
//    0B01111,
//    0B01111,
//    0B10001,
//    0B10001,
//    0B01110
//};

//LCD_createChar(0, carac1); Para cargar el caracter en la RAM del LCD, posiciones 0-7 (max 8 car. personalizados)
//LCD_write(0); Para escribir el caracter personalizado en la posicion 0 de la ram en la pantalla

void LCD_command(char value); //Comando de bajo nivel para enviar un comando al lcd

void LCD_write(char value); //Funcion para escribir un char en el LCD

void LCD_send(char value, char mode); //Comando de bajo nivel para enviar los bits al lcd
void LCD_RS_SET(char value); //Comando de bajo nivel para setear el pin RS
void LCD_EN_SET(char value); //Comando de bajo nivel para setear el pin EN
void LCD_pulseEnable(); //Comando de bajo nivel para hacer un pulso en el pin EN
void LCD_write4bits(char a); //Comando de bajo nivel para escribir los pines D4-D7

//Definir el conexionado del lcd!!!
#define LCD_I2C_ADDRESS 0x27

#ifndef LCD_I2C
#define LCD_RS		(PORTEbits.RE0)
//#define LCD_RS_TRIS	(TRISEbits.TRISE0)
#define LCD_EN		(PORTEbits.RE1)
//#define LCD_EN_TRIS	(TRISEbits.TRISE1)
#define LCD_D4      (PORTDbits.RD3)
//#define LCD_D4_TRIS (TRISDbits.TRISD3)
#define LCD_D5      (PORTDbits.RD2)
//#define LCD_D5_TRIS (TRISDbits.TRISD2)
#define LCD_D6      (PORTDbits.RD1)
//#define LCD_D6_TRIS (TRISDbits.TRISD1)
#define LCD_D7      (PORTDbits.RD0)
//#define LCD_D7_TRIS (TRISDbits.TRISD0)

//#define TRISONINIT
#endif
#endif