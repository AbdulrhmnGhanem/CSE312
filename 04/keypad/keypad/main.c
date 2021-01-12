#include <avr/io.h>

#include "lcd.h"
#include "keypad.h"

int main(void)
{
    lcd_init();
    keypad_init();
    lcd_string_write("lcd works!");
}
