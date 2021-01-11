/*
 * 7-seg.c
 * Created: 1/11/2021 2:22:23 PM
 * Author : AbulrhmnGhanem
 */
#include <avr/io.h>
#include <avr/delay.h>

#define F_CPU 1000000UL
// I got this number [here](http://classweb.ece.umd.edu/enee245.F2016/Lab8.pdf)
#define refresh_rate 16
#define increment_interval 1000

int main(void)
{
    DDRC = 0b00001111;
    DDRD = 0b00000011;

    // To activate a 7-seg block pull the driver transistor low,
    // according to schematic what matters is the least significant two bits.

    while (1)
    {
        for (uint8_t i = 0; i < 100; i++)
        {
            const uint8_t units = i % 10;
            const uint8_t tens = (i - units) / 10;
            
            uint16_t elapsed_time = 0;

            while (1)
            {
                if (elapsed_time >= increment_interval)
                {
                    break;
                }
                // Writing the tens is a two step process
                // i. write the value to PC
                PORTC = tens;
                // ii.  pull the PD1 low & PD0 high
                PORTD = 0b00000001;

                // wait for `refresh_interval` ms between toggling the eanble
                _delay_ms(refresh_rate);

                // Writing the units is a two step process
                // i.  pull the PD1 high PD0 low 
                PORTD = 0b00000010;
                // ii. write the value to PC
                PORTC = units;

                // wait for `refresh_interval` ms between toggling the eanble
                _delay_ms(refresh_rate);

                elapsed_time += 2 * refresh_rate;
            }   
        }
    }
}
