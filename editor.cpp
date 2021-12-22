#include "defines.h"
#include "draw.h"
#include "tileset.h"
#include "game.h"
#include "levels.h"

uint8_t editorlevel[MAP_FULL_SIZE] = {};
#define SLICE_HEIGHT 12

const uint16_t RRED = 0xE4D8;
uint8_t cx = 0;
uint8_t cy = 0;

void testLevel();

void editorInit()
{
  //memset(editorlevel, EMPTY, MAP_FULL_SIZE);
  memset(buffer1, 0x00, ROW_SIZE);
  memset(buffer2, 0x00, ROW_SIZE);

  // load from SD
}

void editorTick()
{
  if (gb.buttons.repeat(BUTTON_A, 0))
  {
    uint16_t id = cx + cy * 13;

    if (gb.buttons.pressed(BUTTON_RIGHT))
    {
      editorlevel[id] = (editorlevel[id] + 1) % TILE_COUNT;
    }
    else if (gb.buttons.pressed(BUTTON_LEFT))
    {
      if (editorlevel[id])
      {
        editorlevel[id]--;
      }
      else
      {
        editorlevel[id] = TILE_COUNT - 1;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (cx > 0) cx--;
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (cx < 12) cx++;
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (cy > 0) cy--;
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if (cy < 9) cy++;
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    testLevel();
    return;
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    gotoScreen(MENU_SCREEN);
    return;
  }

  for (uint8_t sliceIndex = 0; sliceIndex < GAME_SLICES; sliceIndex++)
  {
    uint16_t * buffer = sliceIndex % 2 == 0 ? buffer1 : buffer2;
    
    for (int16_t s = 0; s < MAP_WIDTH;s++)
    {
      const uint16_t * sprBegin = &tileset[ editorlevel[sliceIndex * MAP_WIDTH + s] * TILE_SIZE * TILE_SIZE ];
      for (int y = 0; y < TILE_SIZE; y++)
      {
        memcpy(&buffer[SCREEN_WIDTH * y + s * TILE_SIZE + 2], sprBegin + y * TILE_SIZE, TILE_SIZE*2);
      }
    }

    if (cy == sliceIndex)
    {
      uint8_t realX = cx * TILE_SIZE + 2;
      for (uint8_t y = 0; y < TILE_SIZE; y++)
      {
        // top
        buffer[realX + y] = RRED;
        // bottom
        buffer[SCREEN_WIDTH * (TILE_SIZE - 1) + realX + y] = RRED;
        // left
        buffer[SCREEN_WIDTH * y + realX] = RRED;
        // right
        buffer[SCREEN_WIDTH * y + realX + TILE_SIZE - 1] = RRED;
      }
    }
    
    if (sliceIndex != 0) waitForPreviousDraw();
    
    drawScreenSlice(sliceIndex * SLICE_HEIGHT, SLICE_HEIGHT, buffer);
  }

  uint16_t * buffer_black = GAME_SLICES % 2 == 0 ? buffer1 : buffer2;
  memset(buffer_black, 0x00, SCREEN_WIDTH * 16);
  waitForPreviousDraw();

  drawScreenSlice(120, 8, buffer_black);
  waitForPreviousDraw();
}

void testLevel()
{
  startLevel(level_count);
}