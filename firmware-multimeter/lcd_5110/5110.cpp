//====================================================
// STM32 OPEN SOURCE MULTIMETER
// embedblog.eu/dmm
// some code of this LCD driver comes from Adafruit Industries, I've only rewriten it for STM32
// ===================================================

#ifndef _BV
  #define _BV(x) (1 << (x))
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "stm32f3xx.h"

#include "5110.h"
#include "..\delay.h"

#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }

//int32_t *gfxFont;
const GFXfont *gfxFont;
uint8_t cursor_x = 0, cursor_y = 0, textSize = 1;
bool textColor = BLACK, backgroundColor = WHITE;

// the memory buffer for the LCD
uint8_t pcd8544_buffer[LCDWIDTH * LCDHEIGHT / 8];

void LCD_5110::begin(uint8_t contrast, uint8_t bias) 
{
  //========================
	//SETUP PINS (HIGH SPEED OUTPUTS), disable JTAG functionality
	GPIOB->MODER |= GPIO_MODER_MODER4_0 | GPIO_MODER_MODER3_1 | GPIO_MODER_MODER5_1;
	GPIOB->MODER &=~GPIO_MODER_MODER4_1;
	GPIOA->MODER &=~GPIO_MODER_MODER15_1;
	GPIOA->MODER |= GPIO_MODER_MODER15_0;
	
	GPIOA->PUPDR &=~GPIO_PUPDR_PUPDR15_0;
	GPIOB->PUPDR &=~GPIO_PUPDR_PUPDR4_0;
	
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR5;
	GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;
	
	//========================
	//SETUP HARDWARE SPI
	//clock
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	
	//PB3 and PB5 for SPI
	GPIOB->AFR[0] = (5 << 12) | (5 << 20);
	
	//SPI CLK frequency 2.25 MHz (div /32), master, software slave control
	SPI1->CR1 |= SPI_CR1_BR_2;
	SPI1->CR2 |= SPI_CR2_SSOE;
	SPI1->CR1 |= SPI_CR1_SPE | SPI_CR1_MSTR;

  // toggle RST low to reset
	RST_LOW;
	_delay_ms(50);
	RST_HIGH;
	
	memset(pcd8544_buffer, 0, LCDWIDTH*LCDHEIGHT/8);

  // get into the EXTENDED mode!
  command(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION );

  // LCD bias select (4 is optimal?)
  command(PCD8544_SETBIAS | bias);

  // set VOP
  if (contrast > 0x7f)
    contrast = 0x7f;

  command(PCD8544_SETVOP | contrast); // Experimentally determined

  //normal mode
  command(PCD8544_FUNCTIONSET);

  //Set display to Normal
  command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}

void LCD_5110::command(uint8_t c) 
{
  DC_LOW;
  CE_LOW;
  spiWrite(c);
  CE_HIGH;
}

void LCD_5110::data(uint8_t c) 
{
  DC_HIGH;
  CE_LOW;
  spiWrite(c);
  CE_HIGH;
}

void LCD_5110::setContrast(uint8_t val) 
{
  if (val > 0x7f)
    val = 0x7f;
 
  command(PCD8544_FUNCTIONSET | PCD8544_EXTENDEDINSTRUCTION );
  command( PCD8544_SETVOP | val); 
  command(PCD8544_FUNCTIONSET);
}

// clear everything
void LCD_5110::clearDisplay(void) 
{
  memset(pcd8544_buffer, 0, LCDWIDTH*LCDHEIGHT/8);
  cursor_y = cursor_x = 0;
}

void LCD_5110::display(void) 
{
  uint8_t col, maxcol, p;
  
  for(p = 0; p < 6; p++) 
	{
		command(PCD8544_SETYADDR | p);
		// start at the beginning of the row
    col = 0;
    maxcol = LCDWIDTH-1;

    command(PCD8544_SETXADDR | col);

    DC_HIGH;
    CE_LOW;
    for(; col <= maxcol; col++) {
      spiWrite(pcd8544_buffer[(LCDWIDTH*p)+col]);
    }
    CE_HIGH;
  }

  command(PCD8544_SETYADDR );  // no idea why this is necessary but it is to finish the last byte?
}

// the most basic function, set a single pixel
void LCD_5110::drawPixel(int16_t x, int16_t y, uint16_t color) {
  if ((x < 0) || (x >= LCDWIDTH) || (y < 0) || (y >= LCDHEIGHT))
    return;

  if ((x < 0) || (x >= LCDWIDTH) || (y < 0) || (y >= LCDHEIGHT))
    return;

  // x is which column
  if (color) 
    pcd8544_buffer[x+ (y/8)*LCDWIDTH] |= _BV(y%8);  
  else
    pcd8544_buffer[x+ (y/8)*LCDWIDTH] &= ~_BV(y%8); 

}

// the most basic function, get a single pixel
uint8_t LCD_5110::getPixel(int8_t x, int8_t y) {
  if ((x < 0) || (x >= LCDWIDTH) || (y < 0) || (y >= LCDHEIGHT))
    return 0;

  return (pcd8544_buffer[x+ (y/8)*LCDWIDTH] >> (y%8)) & 0x1;  
}

void LCD_5110::spiWrite(uint8_t d) 
{
	*(uint8_t *)&SPI1->DR = (uint8_t)d;
	
	while ((SPI1->SR & SPI_SR_TXE) == 0);
	
	_delay_us(2);	//this is, for some reason, needed. TODO: research
}


void LCD_5110::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, bool color) 
	{
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        _swap_int16_t(x0, y0);
        _swap_int16_t(x1, y1);
    }

    if (x0 > x1) {
        _swap_int16_t(x0, x1);
        _swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            drawPixel(y0, x0, color);
        } else {
            drawPixel(x0, y0, color);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}
	
void LCD_5110::drawFillRect(int16_t x, int16_t y, int16_t w, int16_t h, bool color) 
	{
    for (uint16_t i = x; i < x + w; i++) 
		{
        drawLine(i, y, i, h, color);
    }
}
	
void LCD_5110::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, bool color) 
	{
    drawLine(x, y, x + w, y, color);
		drawLine(x + w, y, x + w, y + h, color);
		drawLine(x, y + h, x + w, y + h, color);
		drawLine(x, y, x, y + h, color);
}
	
void LCD_5110::drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, bool color)
	{
    int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
    uint8_t byte = 0;

    for(int16_t j=0; j<h; j++, y++) {
        for(int16_t i=0; i<w; i++) {
            if(i & 7) byte <<= 1;
            else      byte   = bitmap[j * byteWidth + i / 8];
            if(byte & 0x80) drawPixel(x+i, y, color);
        }
    }
}
	
void LCD_5110::drawChar(int16_t x, int16_t y, unsigned char c, bool color, bool bg, uint8_t size) 
	{
		c -= (uint8_t)gfxFont->first;
		GFXglyph *glyph  = &(((GFXglyph *)gfxFont->glyph)[c]);
		uint8_t  *bitmap = (uint8_t *)gfxFont->bitmap;

		uint16_t bo = glyph->bitmapOffset;
		uint8_t  w  = glyph->width,
						 h  = glyph->height;
		int8_t   xo = glyph->xOffset,
						 yo = glyph->yOffset;
		uint8_t  xx, yy, bits = 0, bit = 0;
		int16_t  xo16 = 0, yo16 = 0;

		if(size > 1) {
				xo16 = xo;
				yo16 = yo;
		}

		for(yy=0; yy<h; yy++) {
				for(xx=0; xx<w; xx++) {
						if(!(bit++ & 7)) {
								bits = bitmap[bo++];
						}
						if(bits & 0x80) {
								if(size == 1) {
										drawPixel(x+xo+xx, y+yo+yy, color);
								} else {
										drawFillRect(x+(xo16+xx)*size, y+(yo16+yy)*size,
											size, size, color);
								}
						}
						bits <<= 1;
				}
		}
		
		cursor_x += glyph->xAdvance;
}
	
void LCD_5110::setFont(const GFXfont *f) 
	{
    if(f) {            // Font struct pointer passed in?
        if(!gfxFont) { // And no current font struct?
            // Switching from classic to new font behavior.
            // Move cursor pos down 6 pixels so it's on baseline.
            cursor_y += 6;
        }
    } else if(gfxFont) { // NULL passed.  Current font struct defined?
        // Switching from new to classic font behavior.
        // Move cursor pos up 6 pixels so it's at top-left of char.
        cursor_y -= 6;
    }
    gfxFont = f;
}
	
void LCD_5110::setCursor(uint8_t x, uint8_t y)
{
	cursor_x = x;
	cursor_y = y;
}

void LCD_5110::setTextColor(bool c)
{
	textColor = c;
}

void LCD_5110::setTextColor(uint16_t c, uint16_t bg)
{
	textColor = c;
	backgroundColor = bg;
}

void LCD_5110::setTextSize(uint8_t s)
{
	textSize = s;
}

void LCD_5110::print(char *txt)
{
	while (*txt)
	{
		drawChar(cursor_x, cursor_y, *txt++, textColor, backgroundColor, textSize);
	}
}

void LCD_5110::printxy(char *txt, uint8_t x, uint8_t y)
{
	cursor_x = x;
	cursor_y = y;
	print(txt);
}

void LCD_5110::printf(char *szFormat, ...)
{
	char szBuffer[24]; //in this buffer we form the message
	int NUMCHARS = sizeof(szBuffer) / sizeof(szBuffer[0]);
	va_list pArgs;
	va_start(pArgs, szFormat);
	vsnprintf(szBuffer, NUMCHARS - 1, szFormat, pArgs);
	va_end(pArgs);
	
	print(szBuffer);
}
