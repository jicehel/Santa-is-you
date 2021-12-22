#include "music.h"
#include "defines.h"

int petitPapa(int noteJouee) {


  const int tempo = 4; // plus c'est petit, plus c'est rapide
  const int melodie[][3] = { {7, 2, 2}, {0, 3, 2}, {0, 3, 2}, {0, 3, 2}, {2, 3, 2}, {0, 3, 6},
    {0, 3, 1}, {2, 3, 1}, {4, 3, 2}, {4, 3, 2}, {4, 3, 2}, {5, 3, 2}, {4, 3, 6},
    {2, 3, 2}, {0, 3, 3}, {0, 3, 1}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {9, 2, 1}, {7, 2, 6},
    {7, 2, 1}, {7, 2, 1}, {0, 3, 4}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {0, 3, 1}, {2, 3, 6},
    {7, 2, 2}, {0, 3, 2}, {0, 3, 2}, {0, 3, 2}, {2, 3, 2}, {0, 3, 6},
    {0, 3, 1}, {2, 3, 1}, {4, 3, 2}, {4, 3, 2}, {4, 3, 2}, {5, 3, 2}, {4, 3, 6},
    {2, 3, 2}, {0, 3, 3}, {0, 3, 1}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {9, 2, 1}, {7, 2, 6},
    {7, 2, 1}, {7, 2, 1}, {0, 3, 4}, {0, 3, 1}, {0, 3, 1}, {2, 3, 1}, {2, 3, 1}, {0, 3, 6},
  };

  
  float frequence; 
  uint8_t duration;
  frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}
