NHD-0420
========

AVR-GCC library for (I²C) Newhaven Serial LCD Module NHD-0420D3Z-NSW-BBW-V3

I2C_LCD_NHD_0420.c

History :

v1.0a - First public release


This library can be used to drive Newhaven Serial LCD Module like the NHD-0420D3Z-NSW-BBW-V3 (4x20) Transmissive Blue under AVR-GCC compiler.

See LCD Datasheet :
http://www.newhavendisplay.com/nhd0420dznswbbw-p-413.html

Use with the I²C implementation from P.Fleury (i2cmaster.h) 
under GNU GPL license,  see http://jump.to/fleury

It probably needs some additional work, i plan to write more display functions.

(C) 2014 Longo Sébastien http://sebanolog.fr/  (Release under the MIT License) 

-------------------------------------------------------------------------------------------------------

Utilisée conjointement avec l'implémentation I²C de P.Fleury: http://jump.to/fleury (sous licence GNU GPL);
Cette libraire permet de communiquer avec le module LCD Série NHD-0420D3Z-NSW-BBW-V3 de chez Newhaven et destinée aux compilateurs AVR-GCC.

Voir la Doc. constructeur :
http://www.newhavendisplay.com/nhd0420dznswbbw-p-413.html

Ce module LCD est du type Transmissif Bleu ,4x20 caractères.

Cette librairie a probablement besoin d'évoluer encore un peu, je projète d'ajouter d'autres fonctions d'écriture notamment.

(C) 2014 Longo Sébastien http://sebanolog.fr/  (sous Licence MIT) 

-------------------------------------------------------------------------------------------------------

Doc :

// Initiate Lcd
// Detail : Display On, CLS, Cursor Home, Default Contrast & Brightness
lcd2w_init();

--

// Display String
// Reminder : Lines are interlaced (the end of the 1st line leads to the third line)
lcd2w_puts (const char *s) ;

--

// Display Ascii character
lcd2w_puta (uint8_t ascii) ;

--

// Turn On Display
lcd2w_on();

--

// Turn Off Display
lcd2w_off();

--

// Set Cursor Position
// x (Column) : 1-20 ; y (Line) : 1-4
lcd2w_cursor_xy(uint8_t x, uint8_t y);

--

// Home Cursor
lcd2w_cursor_home();

--

// Turn On Underline Cursor
lcd2w_cursor_ul_on();

--

// Turn Off Underline Cursor
lcd2w_cursor_ul_off();

--

// Move cursor left one place
lcd2w_cursor_mv_left();

--

// Move cursor right one place
lcd2w_cursor_mv_right();

--

// Turn On Blinking Cursor
lcd2w_cursor_blink_on();

--

// Turn Off Blinking Cursor
lcd2w_cursor_blink_off();

--

// Back Space
lcd2w_backspace();

--

// Clear Screen (CLS)
lcd2w_clear_screen();

--

// Set Display Contrast 
//[value between 1 and 50(High)], Default: 40
lcd2w_contrast(uint8_t level);

--

//Set Backlight Brightness
// [value between 1 and 8(High)], Default: 8
lcd2w_brightness(uint8_t level);

--

// Load Custom Character
// [addr]	 1 Byte  Custom character address (0 – 7)
// [D0...D7] 8 Bytes Custom character pattern bit map
// Characters have regular 5x8 LCD shape bit[4:0]
lcd2w_load_char(uint8_t charnumber, uint8_t pattern [7]);

//Custom character may be loaded in this manner, i.e :
uint8_t charspa [] = {0x04, 0x00, 0x04, 0x08, 0x10, 0x11, 0x0E, 0x00}; // inside out Question Mark

--

// Display all Custom Character in a row
lcd2w_dp_all_char();

--

// Move Display One Place To The Left
lcd2w_mvall_left();

--

// Move Display One Place To The Right
lcd2w_mvall_right();

--

// Changing BAUD Rate
// Reminder : this library does not support RS232
// this function is here, just for conveniently switch from I²C to RS232
// parameter [1-8] : 300, 1200, 2400, 9600, 14400, 19.2K, 57.6K, 115.2K Baud
// Default: 9600 BAUD (4)
lcd2w_baud_rate(uint8_t br);

--

// Changing the I2C Slave Address
// From 0x00 To 0xFE (The LSB is always ‘0’) ; Default: 0x28 (7bit value)
lcd2w_i2caddr(uint8_t addr);

--

// Display Firmware Version
lcd2w_display_fw();

--

// Display RS-232 BAUD-Rate
lcd2w_display_br();

--

// Display I2C Address
lcd2w_display_i2caddr();

--

//EOF
