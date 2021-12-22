#include <Gamebuino-Meta.h>
#include "game.h"
#include "title.h"
#include "levelselect.h"
#include "defines.h"
#include "editor.h"

uint8_t CURRENT_SCREEN = MENU_SCREEN;

void setup()
{
  gb.begin();
  gb.display.init(0, 0, ColorMode::rgb565);
  SerialUSB.begin(9600);

  gotoScreen(MENU_SCREEN);
}

void loop()
{
  gb.waitForUpdate();

  if (CURRENT_SCREEN == MENU_SCREEN)
  {
    menuTick();
  }
  else if (CURRENT_SCREEN == GAME_SCREEN)
  {
    gameTick();
  }
  else if (CURRENT_SCREEN == LEVEL_SELECT_SCREEN)
  {
    levelSelectTick();
  }
  else if (CURRENT_SCREEN == EDITOR_SCREEN)
  {
    editorTick();
  }
}

void gotoScreen(uint8_t screen)
{
  switch (screen)
  {
    case MENU_SCREEN:
      menuInit();
      break;
    case LEVEL_SELECT_SCREEN:
      levelSelectInit();
      break;
    case EDITOR_SCREEN:
      editorInit();
      break;
  }

  CURRENT_SCREEN = screen;
}
