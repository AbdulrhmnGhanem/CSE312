#ifndef ADC_H_
#define ADC_H_

#define F_CPU 8000000UL

#define ADC_PORT DDRA
#define ADC_SR ADCSRA
#define ADC_V_Conv_FACTOR (10 / 4.88)


#include<avr/io.h>
#include <util/delay.h>


void adc_init(void);
const uint16_t adc_read_from_ch(uint8_t ch);
const double adc_val_in_volts(uint16_t reading);

#endif /* ADC_H_ */