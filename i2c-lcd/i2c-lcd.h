#include "stm32f1xx_hal.h"

#define _LCD_DELAY 					0x32	// 50 microSeconds

#define _TURN_ON						0x0C	// Turn Lcd display on
#define _TURN_OFF						0x08	// Turn Lcd display off
#define _FIRST_ROW					0x80	// Move cursor to the 1st row
#define _SECOND_ROW					0xC0	// Move cursor to the 2nd row
#define _CLEAR							0x01	// Clear display
#define _RETURN_HOME				0x02	// Return cursor to home position, returns a shifted display to its original position. Display data RAM is unaffected.
#define _CURSOR_OFF					0x0C	// Turn off cursor
#define _UNDERLINE_ON				0x0E	// Underline cursor on
#define _BLINK_CURSOR_ON		0x0F	// Blink cursor on
#define _MOVE_CURSOR_LEFT		0x10	// Move cursor left without changing display data RAM
#define _MOVE_CURSOR_RIGHT	0x14	// Move cursor right without changing display data RAM
#define _SHIFT_LEFT					0x18	// Shift display left without changing display data RAM
#define _SHIFT_RIGHT				0x1C	// Shift display right without changing display data RAM
#define _LCD_4BIT						0x00
#define _LCD_8BIT						0x10
#define _LCD_FONT_5x8				0x00
#define _LCD_FONT_5x10			0x04
#define _LCD_1LINE					0x00
#define _LCD_2LINE					0x08

#define _LCD_INIT						0x06

void lcd_init (void);   // initialize lcd
void lcd_send_cmd (char cmd);  // send command to the lcd
void lcd_send_data (char data);  // send data to the lcd
void lcd_send_string (char *str);  // send string to the lcd
void lcd_gotoxy(uint8_t x, uint8_t y);
void lcd_home(void);
void lcd_clear(void);
void lcd_nobacklight(void);
void lcd_shiftDecrement(void);
void lcd_backlight(void);

/** Display size ------------------------------------------------------------ */
// Number of visible lines of the display (1 or 2/4)
#define LCD_LINES					4
// Visible characters per line of the display
#define LCD_DISP_LENGTH		20
// DDRAM address of first char of line 1
#define LCD_START_LINE_1	0x00
// DDRAM address of first char of line 2
#define LCD_START_LINE_2	0x40
// DDRAM address of first char of line 3
#define LCD_START_LINE_3	0x14
// DDRAM address of first char of line 4
#define LCD_START_LINE_4	0x54

#define CLEARROW 0x01

#define LCD_SET_DDRAM_ADDRESS 0x80


