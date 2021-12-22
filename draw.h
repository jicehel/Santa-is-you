#include "defines.h"

void waitForPreviousDraw();
void drawScreenSlice(int16_t y, int16_t h, uint16_t* buffer);
void drawRectangle(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t* buffer);
void drawText(uint8_t x, uint8_t y, const char* text, uint16_t* buffer);

extern uint16_t buffer1[SCREEN_WIDTH * 16];
extern uint16_t buffer2[SCREEN_WIDTH * 16];
