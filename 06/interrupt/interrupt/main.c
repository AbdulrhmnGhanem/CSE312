#define F_CPU 8000000UL

// #include <avr/iom16a.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
    // Configure LEDS as port output
    DDRC = 0b01111111;

    // Configure button port as input, pullup mode
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);

    // Configure the interrupt as failing edge triggered
    MCUCR |= (1 << ISC01);
    GICR |= (1 << INT0); 

    sei();

    while (1) 
    {
        uint8_t current = 0x1;
        for(uint8_t i = 0; i < 7; i++)
        {
            // Shift the active 1 in each iteration
            PORTC = current;
            _delay_ms(1000);
            current = current << 1; 
        }
    }
}

ISR(INT0_vect) {
    PORTC = 0xff;
    _delay_ms(1000);
}