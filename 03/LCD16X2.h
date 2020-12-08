/*
 * LCD16X2.h
 *
 * Created: 10/12/2019 7:15:13 PM
 *  Author: moram
 */

#ifndef LCD16X2_H_
#define LCD16X2_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS 0x02 //PORTA1
#define LCD_EN 0x01 //PORTA0

void lcd_data_write(char data);
void lcd_command_write(char command);
void lcd_init();

#endif /* LCD16X2_H_ */