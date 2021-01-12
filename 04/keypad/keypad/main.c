#define F_CPU 8000000UL

#include "lcd.h"
#include "keypad.h"

int main(void)
{
    lcd_init();
    keypad_init();

    while (1)
    {
        if (keypad_read() != KEYPAD_NULL_SENTINEL)
        // Only if a button is pressed
        {
            char key = keypad_read();

            // Write `prefix`, then the button value.
            lcd_string_write(KEYPAD_BUTTON_PREFIX);
            lcd_string_write(&key);

            // Clear LCD on release.
            while (keypad_read() != KEYPAD_NULL_SENTINEL)
            {
                continue;
            }

            lcd_clear();
        }
        _delay_ms(40);
    }
}
