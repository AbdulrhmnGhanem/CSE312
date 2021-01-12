#include "keypad.h"

void keypad_init()
{
    KEYPAD_DDR = 0xF;
    KEYPAD_PORT = 0xF0;
}

uint8_t keypad_read()
{
    KEYPAD_PORT = 0xFE;
    _delay_ms(10);
    // First row
    switch (KEYPAD_PIN)
    {
    case 0xEE:
        return '0';
    case 0xDE:
        return '1';
    case 0xBE:
        return '2';
    case 0x7E:
        return '3';
    default:
        break;
    }

    KEYPAD_PORT = 0xFD;
    _delay_ms(10);
    // Second row
    switch (KEYPAD_PIN)
    {
    case 0xED:
        return '4';
    case 0xDD:
        return '5';
    case 0xBD:
        return '6';
    case 0x7D:
        return '7';
    default:
        break;
    }

    KEYPAD_PORT = 0xFB;
    _delay_ms(10);
    // Third row
    switch (KEYPAD_PIN)
    {
    case 0xEB:
        return '8';
    case 0xDB:
        return '9';
    case 0xBB:
        return 'A';
    case 0x7B:
        return 'B';
    default:
        break;
    }

    KEYPAD_PORT = 0xF7;
    _delay_ms(10);
    // Fourth row
    switch (KEYPAD_PIN)
    {
    case 0xE7:
        return 'C';
    case 0xD7:
        return 'D';
    case 0xB7:
        return 'E';
    case 0x77:
        return 'F';
    default:
        break;
    }

    return KEYPAD_NULL_SENTINEL;
}