#ifndef _ADAFRUIT_PCD8544_H
#define _ADAFRUIT_PCD8544_H

#include "stdint.h"

#define BLACK 1
#define WHITE 0

#define LCDWIDTH 84
#define LCDHEIGHT 48

#define PCD8544_POWERDOWN 0x04
#define PCD8544_ENTRYMODE 0x02
#define PCD8544_EXTENDEDINSTRUCTION 0x01

#define PCD8544_DISPLAYBLANK 0x0
#define PCD8544_DISPLAYNORMAL 0x4
#define PCD8544_DISPLAYALLON 0x1
#define PCD8544_DISPLAYINVERTED 0x5

// H = 0
#define PCD8544_FUNCTIONSET 0x20
#define PCD8544_DISPLAYCONTROL 0x08
#define PCD8544_SETYADDR 0x40
#define PCD8544_SETXADDR 0x80

// H = 1
#define PCD8544_SETTEMP 0x04
#define PCD8544_SETBIAS 0x10
#define PCD8544_SETVOP 0x80

//PIN DEFINITIONS
#define RST_HIGH		GPIOA->BSRR = GPIO_BSRR_BS_15
#define RST_LOW			GPIOA->BSRR = GPIO_BSRR_BR_15
#define CE_HIGH			
#define CE_LOW			
#define DC_HIGH			GPIOB->BSRR = GPIO_BSRR_BS_4
#define DC_LOW			GPIOB->BSRR = GPIO_BSRR_BR_4


typedef struct { // Data stored PER GLYPH
	uint16_t bitmapOffset;     // Pointer into GFXfont->bitmap
	uint8_t  width, height;    // Bitmap dimensions in pixels
	uint8_t  xAdvance;         // Distance to advance cursor (x axis)
	int8_t   xOffset, yOffset; // Dist from cursor pos to UL corner
} GFXglyph;

typedef struct { // Data stored for FONT AS A WHOLE:
	uint8_t  *bitmap;      // Glyph bitmaps, concatenated
	GFXglyph *glyph;       // Glyph array
	uint8_t   first, last; // ASCII extents
	uint8_t   yAdvance;    // Newline distance (y axis)
} GFXfont;

class LCD_5110 /*public Adafruit_GFX */
{
 public:
  void begin(uint8_t contrast = 40, uint8_t bias = 0x04);
  
  void command(uint8_t c);
  void data(uint8_t c);
  
  void setContrast(uint8_t val);
  void clearDisplay(void);
  void display();
  
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  uint8_t getPixel(int8_t x, int8_t y);
 
	//generic draw API
	void drawFillRect(int16_t x, int16_t y, int16_t w, int16_t h, bool color);
  void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, bool color);
	void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, bool color);
	void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, bool color);
 
	void setFont(const GFXfont *f);
	void drawChar(int16_t x, int16_t y, unsigned char c, bool color, bool bg, uint8_t size);
	void setCursor(uint8_t x, uint8_t y);
  void setTextColor(bool c);
  void setTextColor(uint16_t c, uint16_t bg);
  void setTextSize(uint8_t s);
	void print(char *txt);
	void printxy(char *txt, uint8_t x, uint8_t y);
	void printf(char *szFormat, ...);

 private:
  void spiWrite(uint8_t c);
	
};

#endif
