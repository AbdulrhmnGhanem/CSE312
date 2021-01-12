#include <avr/io.h>
#include "lcd.h"

void lcd_data_write(char data)
{
    // i. Write the enable instruction
    LCD_CONTROL_PORT |= (1 << LCD_EN);
    // ii. The write pin is pulled low
    // iii. Send the write command instruction
    LCD_CONTROL_PORT |= (1 << LCD_RS);
    // iv. Write hte actual data to the LCD
    LCD_DATA_PORT = data;
    // v. 1ms delay
    _delay_ms(5);
    // vi. Disable writing once again
    LCD_CONTROL_PORT &= ~(1 << LCD_EN);
}

void lcd_string_write(char *string)
{
    for (uint8_t i = 0; string[i] != 0; i++)
    {
        lcd_data_write(string[i]);
    }
}

void lcd_command_write(char command)
{
    // i. Write the enable instruction
    LCD_CONTROL_PORT |= (1 << LCD_EN);
    // ii. The write pin is pulled low as it's grounded in the schematic
    // iii. Send the write command instruction
    LCD_CONTROL_PORT &= ~(1 << LCD_RS);
    // iv. Write the actual command to the LCD
    LCD_DATA_PORT = command;
    // v. 1ms delay
    _delay_ms(5);
    // vi. Disable writing once again
    LCD_CONTROL_PORT &= ~(1 << LCD_EN);
}

void lcd_init()
{
    DDRA = 0xFF;
    DDRB = 0xFF;
    // Initialization delay from datasheet.
    _delay_ms(20);

    //  8bit mode
    lcd_command_write(0x38);
    // Display ON Cursor OFF
    lcd_command_write(0x0C);
    // Auto Increment cursor
    lcd_command_write(0x06);
    // Clear
    lcd_command_write(0x01);
    // Reset cursor
    lcd_command_write(0x80);
}
