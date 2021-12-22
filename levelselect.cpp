#include "defines.h"
#include "draw.h"
#include "game.h"
#include "levels.h"

void set_page(uint8_t page);

uint8_t selected_level = 0;
void levelSelectInit()
{
  memset(buffer1, 0x00, ROW_SIZE);
  memset(buffer2, 0x00, ROW_SIZE);

  for (uint8_t row = 0; row < ROWS_COUNT - 1; row++)
  {
    drawScreenSlice(row * 16, 16, buffer1);
    waitForPreviousDraw();
  }

  selected_level = 0;
  set_page(0);
}

const char * names[] = {
  "LEVEL 1",
  "LEVEL 2",
  "LEVEL 3",
  "LEVEL 4",
  "LEVEL 5",
  "LEVEL 6",
  "LEVEL 7",
  "LEVEL 8",
  "LEVEL 9",
  "LEVEL 10",
  "LEVEL 11",
  "LEVEL 12",
  "LEVEL 13",
  "LEVEL 14",
  "LEVEL 15",
  "LEVEL 16",
  "LEVEL 17",
  "LEVEL 18",
  "LEVEL 19",
  "LEVEL 20",
  "LEVEL 21",
  "LEVEL SD",
  "LEVEL 23",
  "LEVEL 24",
  "LEVEL 25",
  "LEVEL 26",
  "LEVEL 27",
  "LEVEL 28",
  "LEVEL 29",
  "LEVEL 30",
  "LEVEL 31",
  "LEVEL 32",
  "LEVEL 33",
  "LEVEL 34",
  "LEVEL 35",
  "LEVEL 36",
};

uint8_t current_page = 0;
uint8_t start_level = 0;
uint8_t levels_per_page = 14;
uint8_t levels_on_page = 0;
const uint8_t last_page = (level_count_sd / levels_per_page);

void set_page(uint8_t page)
{
  current_page = page;
  start_level = levels_per_page * page;
  levels_on_page = min(level_count_sd - start_level, levels_per_page);

  memset(buffer1, 0x00, ROW_SIZE);
  drawText(30, 4, "B: BACK TO TITLE", buffer1);
  if (current_page > 0)
  {
    drawText(10, 4, "<", buffer1);
  }
  if (current_page < last_page)
  {
    drawText(142, 4, ">", buffer1);
  }
  drawScreenSlice((ROWS_COUNT - 1) * 16, 16, buffer1);
  waitForPreviousDraw();
}

void levelSelectTick()
{
  if (gb.buttons.pressed(BUTTON_B))
  {
    gotoScreen(MENU_SCREEN);
    return;
  }
  else if (gb.buttons.pressed(BUTTON_A))
  {
    startLevel(selected_level + current_page * levels_per_page);
    return;
  }
  else if (gb.buttons.pressed(BUTTON_DOWN))
  {
    if ((levels_on_page % 2) == 0)
    {
      selected_level = (selected_level + 2) % levels_on_page;
    }
    else
    {
      selected_level += 2;
      if (selected_level == levels_on_page)
      {
        selected_level = 1;
      }
      else if (selected_level == levels_on_page + 1)
      {
        selected_level = 0;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    if (selected_level < 2)
    {
      if ((levels_on_page % 2) == 0)
      {
        selected_level = levels_on_page + selected_level - 2;
      }
      else
      {
        selected_level = levels_on_page - selected_level - 1;
      }
    }
    else
    {
      selected_level = (selected_level - 2);
    }
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    if (selected_level % 2)
    {
      selected_level--;
    }
    else
    {
      if (current_page > 0)
      {
        set_page(current_page - 1);
        selected_level++;
      }
    }
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    if (selected_level % 2)
    {
      if (current_page == last_page) return;

      set_page(current_page + 1);
      if (current_page == last_page)
      {
        selected_level--;
        selected_level = min(selected_level, levels_on_page - 1);
        if (selected_level % 2) selected_level--;
      }
      else
      {
        selected_level--;
      }
    }
    else
    {
      selected_level++;
      if (selected_level >= levels_on_page) selected_level -= 2;
    }
  }

  for (uint8_t row = 0; row < ((levels_per_page + 1) / 2); row++)
  {
    memset(buffer1, 0x00, ROW_SIZE);

    if (row < (levels_on_page + 1) / 2)
    {
      drawText(24, 4, names[start_level + row * 2], buffer1);
      if (row * 2 + 1 < levels_on_page)
      {
        drawText(102, 4, names[start_level + row * 2 + 1], buffer1);
      }

      if (selected_level >> 1 == row)
      {
        uint8_t column = 12 + (selected_level % 2) * 78;
        drawText(column, 4, ">", buffer1);
      }
    }

    drawScreenSlice(row * 16, 16, buffer1);
    waitForPreviousDraw();
  }
}
