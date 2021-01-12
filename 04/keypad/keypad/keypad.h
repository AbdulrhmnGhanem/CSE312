#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_PORT PORTD
#define KEYPAD_DDR  DDRD
#define KEYPAD_PIN  PIND
#define KEYPAD_NULL_SENTINEL 'z'
#define KEYPAD_BUTTON_PREFIX "SW"

void keypad_init(void);
uint8_t keypad_read(void);

#endif /* KEYPAD_H_ */