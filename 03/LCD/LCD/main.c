/*
 * LCD.c
 *
 * Created: 1/11/2021 2:23:20 PM
 * Author : AbulrhmnGhanem
 */ 

#define F_CPU 8000000UL

#include "LCD16X2.h"

int main(void)
{
    lcd_init();
    lcd_string_write("CSE 2022");
    lcd_command_write(0xC0);
    lcd_string_write("Abdulrhmn Usama");
}
