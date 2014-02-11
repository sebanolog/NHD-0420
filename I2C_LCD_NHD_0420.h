#ifndef I2C_LCD_NHD_0420_H
#define I2C_LCD_NHD_0420_H

/*
=====================================================================
=	Serial LCD Library (I²C Only) - (AVR-GCC) (I2C_LCD_NHD_0420.c) =
=	Author : Longo Sébastien			   http://www.sebanolog.fr =
=	Model: Newhaven NHD-0420D3Z-NSW-BBW-V3 and probably some other =
=	Type : 4X20 5.0V Transmissive Blue				   28 Jan 2014 =
=	v1.0a							Released Under The MIT License =
=====================================================================
*/


/*

 TODO : 
		
		puta, putv (displays ascii char. and variables)
*/


/*
Data sheet available at http://www.newhavendisplay.com/nhd0420dznswbbw-p-413.html

Misc : +5.0V Power Supply, I²c@100KHz (50KHz works better in some case) (J2 :Pin 3(SCL), 4(SDA), 5(VSS), 6(VDD))
	Remember to place a jumper on R1. on the back of the module to enable I²C Communications.
*/

#define  LCD_NHD_0420			0x28	// Serial Address (7bit value)

#define DISPLAY_ON				0x41	// lcd2w_on();
#define DISPLAY_OFF				0x42	// lcd2w_off();	
#define SET_CURSOR				0x45	// lcd2w_cursor_xy(uint8_t x, uint8_t y);
#define CURSOR_HOME				0x46	// lcd2w_cursor_home();
#define UNDERLINE_CURSOR_ON		0x47	// lcd2w_cursor_ul_on();
#define UNDERLINE_CURSOR_OFF	0x48	// lcd2w_cursor_ul_off();
#define MV_CURSOR_LEFT			0x49	// lcd2w_cursor_mv_left();
#define MV_CURSOR_RIGHT			0x4A	// lcd2w_cursor_mv_right();
#define BLINKING_CURSOR_ON		0x4B	// lcd2w_cursor_blink_on();
#define BLINKING_CURSOR_OFF		0x4C	// lcd2w_cursor_blink_off();
#define BACKSPACE				0x4E	// lcd2w_backspace();
#define CLEAR_SCREEN			0x51	// lcd2w_clear_screen();
#define SET_CONTRAST			0x52	// lcd2w_contrast(uint8_t data);	=> Default: 40
#define SET_BL_BRIGHTNESS		0x53	// lcd2w_brightness(uint8_t data);	=> Default:  8
#define LD_CUSTOM_CHARACTER		0x54	// lcd2w_load_char(uint8_t addr, uint8_t pattern [7]);
#define MV_DP_LEFT				0x55	// lcd2w_mvall_left();
#define MV_DP_RIGHT				0x56	// lcd2w_mvall_right();
#define Change_RS232_BAUD_RATE	0x61	// lcd2w_baud_rate(uint8_t data);
#define Change_I2C_ADDRESS		0x62	// lcd2w_i2caddr(uint8_t data);		= > Default : 0x50
#define DP_FIRM_VERSION			0x70	// lcd2w_display_fw();						= > (mine is V3.0)
#define DP_RS232_BR				0x71	// lcd2w_display_br();						= > Default : 9600
#define DP_I2C_ADDR				0x72	// lcd2w_display_i2caddr();

// Initiate Lcd  3.7ms
void lcd2w_init(void);
	
// Display string
void lcd2w_puts (const char *s);

// Display Ascii character
void lcd2w_puta (uint8_t ascii);

// Display On 100uS
void lcd2w_on(void);

// Display Off 100uS
void lcd2w_off(void);

// Set Cursor Position 100uS
void lcd2w_cursor_xy(uint8_t x, uint8_t y);

// Cursor Home 1.5mS
void lcd2w_cursor_home(void);

// Underline Cursor On 1.5mS
void lcd2w_cursor_ul_on(void);

// Underline Cursor Off 1.5mS
void lcd2w_cursor_ul_off(void);

// Move cursor left one place 100uS
void lcd2w_cursor_mv_left(void);

// Move Cursor Right One Place 100uS
void lcd2w_cursor_mv_right(void);

// Blinking Cursor On 100uS
void lcd2w_cursor_blink_on(void);

// Blinking Cursor Off 100uS
void lcd2w_cursor_blink_off(void);

// Backspace 100uS
void lcd2w_backspace(void);

// Clear Screen 1.5mS
void lcd2w_clear_screen(void);

// Set Contrast (1 Byte) 500uS
void lcd2w_contrast(uint8_t data);

// Set Backlight Brightness (1 Byte) 100uS 
// (May need a little extra, in some case,
// i figured 1.6ms is a safe value...)
void lcd2w_brightness(uint8_t data);

// Load Custom Character (9 Byte) 200uS
void lcd2w_load_char(uint8_t addr, uint8_t pattern []);

// Display all Custom Character in a row
// may be usefull from time to time...
void lcd2w_dp_all_char(void);

// Move Display One Place To The Left 100uS
void lcd2w_mvall_left(void);

// Move Display One Place To The Right 100uS
void lcd2w_mvall_right(void);

// Change RS-232 BAUD-Rate (1 Byte) 3ms
void lcd2w_baud_rate(uint8_t data);

// 1 Byte Change I2C Address (1 Byte) 3ms
void lcd2w_i2caddr(uint8_t data);

// Display Firmware Version 4ms
void lcd2w_display_fw(void);

// Display RS-232 BAUD-Rate  10ms
void lcd2w_display_br(void);

// Display I2C Address 4ms
void lcd2w_display_i2caddr(void);

#endif //I2C_LCD_NHD_0420
