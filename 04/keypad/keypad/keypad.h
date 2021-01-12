#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

void keypad_init(void);
uint8_t keypad_read(void);

#endif /* KEYPAD_H_ */