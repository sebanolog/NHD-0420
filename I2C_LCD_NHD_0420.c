/*
=====================================================================
 =	Serial LCD Library (I²C Only) - (AVR-GCC) (I2C_LCD_NHD_0420.c) =
 =	Author : Longo Sébastien			   http://www.sebanolog.fr =
 =	Model: Newhaven NHD-0420D3Z-NSW-BBW-V3 and probably some other =
 =	Type : 4X20 5.0V Transmissive Blue				   28 Jan 2014 =
 =	v1.0a							Released Under The MIT License =
=====================================================================
*/
#include <inttypes.h>
#include "I2C_LCD_NHD_0420.h"
#include "i2cmaster.h"	// From P.Fleury under GNU GPL license ; see http://jump.to/fleury

extern int delay_ms();
extern int delay_us();

// Initiate Lcd  12.4ms
// Detail: Display On, CLS, Cursor Home, Default Contrast & Brightness
void lcd2w_init(void)	{

	lcd2w_on();
	lcd2w_clear_screen();
	lcd2w_cursor_home();
	lcd2w_contrast(40);		// Default Contrast
	lcd2w_brightness(5);	// Default Brightness
}


// Reminder : lines are interlaced (the end of the 1st line leads to the third line)
void lcd2w_puts (const char *s) {
		
		i2c_start(LCD_NHD_0420<<1);
		
		register char c;
		
		while ((c = *s++)) {
					
			i2c_write(c);
			
		}	
		
		i2c_stop();
		//delay_us(100);
};

// Display Ascii character
void lcd2w_puta (uint8_t ascii) {
	
	i2c_start(LCD_NHD_0420<<1);
	i2c_write(ascii);
	i2c_stop();
}


/*
()	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(0x);
	i2c_stop();
	delay_ms();
}
*/

// Turn On Display 100uS
void lcd2w_on(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(DISPLAY_ON);
	i2c_stop();
	delay_us(100);
}

// Turn Off Display 100uS
void  lcd2w_off(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(DISPLAY_OFF);
	i2c_stop();
	delay_us(100);
}

// Set Cursor Position (2 Byte) 100uS
// ('Human readable' x (Column) : 1-20 ; y (Line) : 1-4)
void lcd2w_cursor_xy(uint8_t x, uint8_t y)	{

	uint8_t pos = 0;
	
	if (y == 1) {
	
	pos = x-1;
	
	}
	
	if (y == 2) {
	
	pos = 0x40 + (x-1);
	
	}
	
	if (y == 3) {
	
	pos = 0x14 + (x-1);
	
	}
	
	if (y == 4) {
		
	pos = 0x54 + (x-1);
	
	}
	
	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(SET_CURSOR);
	i2c_write(pos);
	i2c_stop();
	delay_us(100);
}

// Home Cursor 1.5mS
void lcd2w_cursor_home(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(CURSOR_HOME);
	i2c_stop();
	delay_us(1500);
}

// Turn On Underline Cursor 1.5mS
void lcd2w_cursor_ul_on(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(UNDERLINE_CURSOR_ON);
	i2c_stop();
	delay_us(1500);
}

// Turn Off Underline Cursor 1.5mS
void lcd2w_cursor_ul_off(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(UNDERLINE_CURSOR_OFF);
	i2c_stop();
	delay_us(1500);
}

// Move cursor left one place 100uS
void lcd2w_cursor_mv_left(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(MV_CURSOR_LEFT);
	i2c_stop();
	delay_us(100);
}

// Move Cursor Right One Place 100uS
void lcd2w_cursor_mv_right(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(MV_CURSOR_RIGHT);
	i2c_stop();
	delay_us(100);
}

// Turn On Blinking Cursor 100uS
void lcd2w_cursor_blink_on(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(BLINKING_CURSOR_ON);
	i2c_stop();
	delay_us(100);
}

// Turn Off Blinking Cursor 100uS
void lcd2w_cursor_blink_off(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(BLINKING_CURSOR_OFF);
	i2c_stop();
	delay_us(100);
}

// Back Space 100uS
void lcd2w_backspace(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(BACKSPACE);
	i2c_stop();
	delay_us(100);
}

// Clear Screen 1.5mS
void lcd2w_clear_screen(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(CLEAR_SCREEN);
	i2c_stop();
	delay_us(1500);
}

// Set Display Contrast (1 Byte) 500uS
//[value between 1 and 50(High)], Default: 40
void lcd2w_contrast(uint8_t level)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(SET_CONTRAST);
	i2c_write(level);
	i2c_stop();
	delay_us(500);
}

//Set Backlight Brightness (1 Byte) 100uS
// [value between 1 and 8(High)], Default: 8
void lcd2w_brightness(uint8_t level)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(SET_BL_BRIGHTNESS);
	i2c_write(level);
	i2c_stop();
	delay_us(1600);	// needed a little extra, in some case subsequent command failed under 1600us, go figure...
}

// Load Custom Character (1+8 Byte) 200uS
// [addr]	 1 Byte  Custom character address (0 – 7)
// [D0...D7] 8 Bytes Custom character pattern bit map
// Characters have regular 5x8 LCD shape bit[4:0]
void lcd2w_load_char(uint8_t charnumber, uint8_t pattern [7])	{

		i2c_start(LCD_NHD_0420<<1);
		i2c_write(0xFE);
		i2c_write(LD_CUSTOM_CHARACTER);
		i2c_write(charnumber);
		
		i2c_stop();
		
		i2c_rep_start(LCD_NHD_0420<<1);
		
		for (uint8_t i = 0 ; i<=7 ; i++) {
		
			i2c_write(pattern[i]);
			
		}
		
		i2c_stop();
		
		delay_us(200);
	}

// Display all Custom Character in a row
void lcd2w_dp_all_char(void) {

	i2c_start(LCD_NHD_0420<<1);

	for (uint8_t i = 0;i<=7;i++) {
	
		i2c_write(i);
	}

	i2c_stop();
}

// Move Display One Place To The Left 100uS
void lcd2w_mvall_left(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(MV_DP_LEFT);
	i2c_stop();
	delay_us(100);
}

// Move Display One Place To The Right 100uS
void lcd2w_mvall_right(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(MV_DP_RIGHT);
	i2c_stop();
	delay_us(100);
}

// Changing BAUD Rate (1 Byte) 3ms
// Reminder : this library does not support RS232
// this function is here, just for conveniently switch from I²C to RS232
// parameter [1-8] : 300, 1200, 2400, 9600, 14400, 19.2K, 57.6K, 115.2K Baud
// Default: 9600 BAUD (4)
void lcd2w_baud_rate(uint8_t br)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(Change_RS232_BAUD_RATE);
	i2c_write(br);
	i2c_stop();
	delay_ms(3);
}

// Changing the I2C Slave Address (1 Byte) 3ms
// From 0x00 To 0xFE (The LSB is always ‘0’) ; Default: 0x28 (7bit value)
void lcd2w_i2caddr(uint8_t addr)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(Change_I2C_ADDRESS);
	i2c_write(addr);
	i2c_stop();
	delay_ms(3);
}

// Display Firmware Version 4ms
void lcd2w_display_fw(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(DP_FIRM_VERSION);
	i2c_stop();
	delay_ms(4);
}

// Display RS-232 BAUD-Rate  10ms
void lcd2w_display_br(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(DP_RS232_BR);
	i2c_stop();
	delay_ms(10);
}

// Display I2C Address 4ms
void lcd2w_display_i2caddr(void)	{

	i2c_start(LCD_NHD_0420<<1);
	i2c_write(0xFE);
	i2c_write(DP_I2C_ADDR);
	i2c_stop();
	delay_ms(4);
}
