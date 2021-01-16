#include <avr/iom164a.h>
#include "adc.h"

void adc_init(void)
{
    ADC_PORT = 0x0;
    ADC_SR = 0x87;
    ADMUX = 0x40;
}

const uint16_t adc_read_from_ch(uint8_t ch)
{

    ADMUX = ADMUX | (ch & 0x0f);

    ADCSRA |= (1 << ADSC);
    while ((ADCSRA & (1 << ADIF)) == 0)
    {
        continue;
    }

    _delay_us(10);
    return ADC;
}

const double adc_val_in_volts(uint16_t reading)
{
    return reading / ADC_V_Conv_FACTOR;
}
