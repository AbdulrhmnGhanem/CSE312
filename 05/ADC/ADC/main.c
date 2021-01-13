#define F_CPU 8000000UL

#include <stdlib.h>
#include<util/delay.h>

#include "lcd.h"
#include "adc.h"


int main(void)
{
    adc_init();
    lcd_init();

    while (1)
    {
        _delay_ms(5000);
        lcd_clear();

        double value = adc_val_in_volts(adc_read_from_ch(0));
        char string[5];
        dtostrf(value, 5, 2, string);

        lcd_string_write(string);
    }
}
