/*
 * blinking_leds.c
 *
 * Created: 1/4/2021 9:12:00 AM
 * Author : AbulrhmnGhanem
 */

#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 1000000UL

int main(void)
{
    DDRA = 0b00000110;
    DDRD = 0b00001100;
    while (1)
    {
        PORTA = 0b00000010;
        _delay_ms(1000);
        PORTA = 0b00000100;
        _delay_ms(1000);
        PORTA = 0b00000000;
        PORTD = 0b00000100;
        _delay_ms(1000);
        PORTD = 0b00001000;
        _delay_ms(1000);
        PORTA = 0b00000110;
        PORTD = 0b00001100;
        _delay_ms(1000);
        PORTA = 0b00000000;
        PORTD = 0b00000000;
        _delay_ms(1000);
    }
    return 0;
}
