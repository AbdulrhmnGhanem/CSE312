#include "keypad.h"

// Rows at PC4:PC7 and Columns at PD4:PD7

void keypad_init()
{
    KEYPAD_DDR = 0xF0;
    KEYPAD_PORT= 0xF;
}

uint8_t keypad_read()
{
    return 'a';
}