#include "game.h"
#include "defines.h"
#include "tileset.h"
#include "draw.h"
#include "title.h"
#include "music.h"

#include "levels.h"

uint8_t underlevel[MAP_FULL_SIZE];
extern uint8_t editorlevel[];

int noteCourrante;
int attente;

uint8_t level[MAP_FULL_SIZE];
uint8_t current_level = 0;
bool finished = false;
bool has_player = true;

uint8_t rules[TILE_COUNT];
void updateRules();
bool isSubject(uint8_t tile);
bool isStatus(uint8_t tile);
uint8_t getStatus(uint8_t tile);
void updateGame();
void victory();

void moveDown();
void moveUp();
void moveLeft();
void moveRight();
uint8_t getSubject(uint8_t tile);
bool isPush(uint8_t tile);
bool isStop(uint8_t tile);
bool isYou(uint8_t tile);
bool isWin(uint8_t tile);
bool isSink(uint8_t tile);
bool isKill(uint8_t tile);
bool isSwap(uint8_t tile);
bool isWord(uint8_t tile);
void moveImpl(uint8_t i, int8_t delta, uint8_t min, uint8_t max);
void convertTile(uint8_t from, uint8_t to);

void initLevel(uint8_t id) {
  noteCourrante = 0;
  attente = 0;
  if (id == level_count)
  {
    for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
    {
      level[i] = editorlevel[i];
    }
  }
  else
  {
    for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
    {
      level[i] = levels[id][i];
    }
  }
}

void updateGame()
{
  if (!has_player)
  {
    if ((gb.frameCount >> 2) % 2) {
      gb.lights.fill(RED);
    } else {
      gb.lights.clear();
    }
  }
  
  if (gb.buttons.pressed(BUTTON_DOWN))
  {
    moveDown();
  }
  else if (gb.buttons.pressed(BUTTON_UP))
  {
    moveUp();
  }
  else if (gb.buttons.pressed(BUTTON_LEFT))
  {
    moveLeft();
  }
  else if (gb.buttons.pressed(BUTTON_RIGHT))
  {
    moveRight();
  }
  else if (gb.buttons.pressed(BUTTON_B))
  {
    startLevel(current_level);
    return;
  }
  else if (gb.buttons.pressed(BUTTON_MENU))
  {
    gotoScreen(LEVEL_SELECT_SCREEN);
    return;
  }
  else
  {
    return;
  }
  
  updateRules();

  for (int i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]) && (isWin(underlevel[i]) || isWin(level[i])))
    {
      current_level++;
      finished = true;
    }
    else if (isSink(underlevel[i]))
    {
      level[i] = EMPTY;
      underlevel[i] = EMPTY;
    }
    else if (isKill(underlevel[i]))
    {
      level[i] = underlevel[i];
      underlevel[i] = EMPTY;
    }
  }
}

void victory()
{
  memset(buffer1, 0x00, ROW_SIZE);
  drawText(60, 4, "VICTORY", buffer1);
  drawScreenSlice(56, 16, buffer1);
  waitForPreviousDraw();

  for (int i = 0; i < 10; i++)
  {
    gb.lights.fill(YELLOW);
    delay(100);
    gb.lights.clear();
    delay(100);
  }

  if (current_level == level_count)
  {
    gotoScreen(MENU_SCREEN);
  }
  else if (current_level == level_count_sd)
  {
    gotoScreen(EDITOR_SCREEN);
  }
  else
  {
    startLevel(current_level);
  }
  finished = false;
}

void initRules()
{
  rules[EMPTY]  = 0;
  rules[W_SANTA] = IS_PUSH;
  rules[W_GIFT] = IS_PUSH;
  rules[W_TREE] = IS_PUSH;
  rules[W_IS]   = IS_PUSH;
  rules[W_WIN]  = IS_PUSH;
  rules[W_PUSH] = IS_PUSH;
  rules[W_WALL] = IS_PUSH;
  rules[SANTA]   = 0;
  rules[GIFT]   = 0;
  rules[TREE]   = 0;
  rules[WALL]   = 0;
  rules[W_STOP] = IS_PUSH;
  rules[W_YOU]  = IS_PUSH;
  rules[W_SNOW] = IS_PUSH;
  rules[SNOW]   = 0;
  rules[W_SINK] = IS_PUSH;
  rules[W_LAVA] = IS_PUSH;
  rules[LAVA]   = 0;
  rules[W_KILL] = IS_PUSH;
  rules[W_LOVE] = IS_PUSH;
  rules[LOVE]   = 0;
  rules[W_SWAP] = 0;
  rules[W_EMPTY]= IS_PUSH;
  rules[BALL] = 0;
  rules[W_BALL] = IS_PUSH;

  for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
  {
    underlevel[i] = EMPTY;
  }
}

void updateRules()
{
  rules[SANTA] = 0;
  rules[GIFT] = 0;
  rules[TREE] = 0;
  rules[WALL] = 0;
  rules[SNOW] = 0;
  rules[LAVA] = 0;
  rules[LOVE] = 0;

  for (int i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (level[i] == W_IS)
    {
      uint8_t x = i % MAP_WIDTH;
      uint8_t y = i / MAP_WIDTH;

      if (x > 0 && x < MAP_WIDTH - 1)
      {
        uint8_t subject = level[i - 1];
        uint8_t status = level[i + 1];
        if (isSubject(subject))
        {
          if (isStatus(status))
          {
            rules[ getSubject(subject) ] |= getStatus(status);
          }
          else if (isSubject(status))
          {
            convertTile(getSubject(subject), getSubject(status));
          }
        }
      }

      if (y > 0 && y < GAME_SLICES - 1)
      {
        uint8_t subject = level[i - MAP_WIDTH];
        uint8_t status = level[i + MAP_WIDTH];
        if (isSubject(subject))
        {
          if (isStatus(status))
          {
            rules[ getSubject(subject) ] |= getStatus(status);
          }
          else if (isSubject(status))
          {
            convertTile(getSubject(subject), getSubject(status));
          }
        }
      }
    }
  }
}

bool isSubject(uint8_t tile)
{
  switch (tile)
  {
    case W_SANTA:
    case W_GIFT:
    case W_TREE:
    case W_WALL:
    case W_SNOW:
    case W_LAVA:
    case W_LOVE:
    case W_EMPTY:
    case W_BALL:
      return true;
  }
  return false;
}

bool isStatus(uint8_t tile)
{
  switch (tile)
  {
    case W_PUSH:
    case W_STOP:
    case W_WIN:
    case W_YOU:
    case W_SINK:
    case W_KILL:
    case W_SWAP:
      return true;
  }
  return false;
}

uint8_t getStatus(uint8_t tile)
{
  switch (tile)
  {
    case W_PUSH: return IS_PUSH;
    case W_STOP: return IS_STOP;
    case W_WIN:  return IS_WIN;
    case W_YOU:  return IS_YOU;
    case W_SINK: return IS_SINK;
    case W_KILL: return IS_KILL;
    case W_SWAP: return IS_SWAP;
  }

  return 0;
}

uint8_t getSubject(uint8_t tile)
{
  switch (tile)
  {
    case W_SANTA: return SANTA;
    case W_WALL: return WALL;
    case W_TREE: return TREE;
    case W_GIFT: return GIFT;
    case W_SNOW: return SNOW;
    case W_LAVA: return LAVA;
    case W_LOVE: return LOVE;
    case W_EMPTY:return EMPTY;
    case W_BALL: return BALL;
  }

  return 0;
}

void moveDown()
{
  for (int8_t i = MAP_WIDTH * (GAME_SLICES - 1); i >= 0; i--)
  {
    if (isYou(level[i]))
    {
      moveImpl(i, MAP_WIDTH, 0, MAP_FULL_SIZE);
    }
  }
}

void moveUp()
{
  for (uint8_t i = MAP_WIDTH; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]))
    {
      moveImpl(i, -MAP_WIDTH, 0, MAP_FULL_SIZE);
    }
  }
}

void moveLeft()
{
  for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
  {
    if (isYou(level[i]) && (i % MAP_WIDTH) > 0)
    {
      uint8_t row_start = (i / MAP_WIDTH) * MAP_WIDTH;
      moveImpl(i, -1, row_start, row_start + MAP_WIDTH);
    }
  }
}

void moveRight()
{
  for (uint8_t k = 0; k < MAP_FULL_SIZE; k++)
  {
    uint8_t i = MAP_FULL_SIZE - k - 1;
    if (isYou(level[i]) && (i % MAP_WIDTH) < MAP_WIDTH - 1)
    {
      uint8_t row_start = (i / MAP_WIDTH) * MAP_WIDTH;
      moveImpl(i, 1, row_start, row_start + MAP_WIDTH);
    }
  }
}

void moveImpl(uint8_t i, int8_t delta, uint8_t min, uint8_t max)
{
  uint8_t firstEmpty = 0xff;
  for (uint8_t yy = i + delta; yy >= min && yy < max; yy += delta)
  {
    if (isStop(level[yy]))
    {
      break;
    }
    else if (isSwap(level[yy]))
    {
      uint8_t saved = level[yy];
      level[yy] = level[yy - delta];
      level[yy - delta] = saved;
      break;
    }

    if (!isPush(level[yy]) && !isYou(level[yy]))
    {
      firstEmpty = yy;
      break;
    }
  }

  if (firstEmpty < 0xff)
  {
    for (uint8_t c = firstEmpty; c != i; c -= delta)
    {
      if (!isPush(level[c]) && !isYou(level[c]))
      {
        underlevel[c] = level[c];
      }
      level[c] = level[c - delta];
      level[c - delta] = underlevel[c - delta];
      underlevel[c - delta] = EMPTY;
    }
  }
}

bool isPush(uint8_t tile)
{
  return (rules[tile] & IS_PUSH);
}

bool isStop(uint8_t tile)
{
  return (rules[tile] & IS_STOP);
}

bool isYou(uint8_t tile)
{
  return (rules[tile] & IS_YOU);
}

bool isWin(uint8_t tile)
{
  return (rules[tile] & IS_WIN);
}

bool isSink(uint8_t tile)
{
  return (rules[tile] & IS_SINK);
}

bool isKill(uint8_t tile)
{
  return (rules[tile] & IS_KILL);
}

bool isSwap(uint8_t tile)
{
  return (rules[tile] & IS_SWAP);
}

bool isWord(uint8_t tile)
{
  return isSubject(tile) || isStatus(tile) || tile == W_IS;
}

#define SLICE_HEIGHT 12

void startLevel(uint8_t id)
{
  gotoScreen(GAME_SCREEN);
  gb.lights.clear();
  has_player = true;

  current_level = id;
  initLevel(id);

  initRules();
  updateRules();
}

void gameTick()
{
  updateGame();
  if (noteCourrante == nombreDeNotes) {
      noteCourrante = 0;
      attente = 50;
  }
  if (attente <= 0) {
    attente = petitPapa(noteCourrante);
    noteCourrante++;
  } else {
      attente --;
  }
  if (CURRENT_SCREEN != GAME_SCREEN)
  {
    return;
  }

  if (!has_player)
  {
    return;
  }

  for (uint8_t sliceIndex = 0; sliceIndex < GAME_SLICES; sliceIndex++)
  {
    uint16_t * buffer = sliceIndex % 2 == 0 ? buffer1 : buffer2;
    
    for (int16_t s = 0; s < MAP_WIDTH;s++)
    {
      const uint16_t * sprBegin = &tileset[ level[sliceIndex * MAP_WIDTH + s] * TILE_SIZE * TILE_SIZE ];
      for (int y = 0; y < TILE_SIZE; y++)
      {
        memcpy(&buffer[SCREEN_WIDTH * y + s * TILE_SIZE + 2], sprBegin + y * TILE_SIZE, TILE_SIZE*2);
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

  if (finished)
  {
    victory();
  }
  else if (has_player)
  {
    has_player = false;
    for (uint8_t i = 0; i < MAP_FULL_SIZE; i++)
    {
      if (isYou(level[i]))
      {
        has_player = true;
        break;
      }
    }
  }
  if (!has_player)
  {
    memset(buffer1, 0x00, ROW_SIZE);
    drawText(32, 4, "B: RESTART LEVEL", buffer1);
    drawScreenSlice(56, 16, buffer1);
    waitForPreviousDraw();
  }
}

void convertTile(uint8_t from, uint8_t to)
{
  for (uint8_t k = 0; k < MAP_FULL_SIZE; k++)
  {
    if (level[k] == from)
    {
      level[k] = to;
    }
  }
}
