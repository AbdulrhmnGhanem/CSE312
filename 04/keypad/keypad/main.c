#include <avr/io.h>
#include "lcd.h"

int main(void)
{
    lcd_init();
    lcd_string_write("lcd works!");
}
