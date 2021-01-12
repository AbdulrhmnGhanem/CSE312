#include "lcd.h"

int main(void)
{
    lcd_init();
    lcd_string_write("LCD works!");
}
