#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA_PORT PORTB
#define LCD_CONTROL_PORT PORTA
#define LCD_RS PA1 //PORTA1
#define LCD_EN PA0 //PORTA0

void lcd_data_write(char data);
void lcd_string_write(char *string);
void lcd_command_write(char command);
void lcd_init();

#endif /* LCD_H_ */
