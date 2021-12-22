#include "music.h"
#include "defines.h"

int nombreDeNotes;

// Petit Papa Noël
int petitPapa(int noteJouee) {
  nombreDeNotes = 58;
  const int tempo = 4; // plus c'est petit, plus c'est rapide
  const int melodie1[][3] = { {7, 2, 2}, {0, 3, 2}, {0, 3, 2}, {0, 3, 2}, {2, 3, 2}, {0, 3, 6},
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
  frequence = round(note[melodie1[noteJouee][0]] * 2 * (melodie1[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie1[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie1[noteJouee][2] * tempo;
}


//
// Vive le vent

int jingleBells(int noteJouee) {
  nombreDeNotes = 49;
  const int tempo = 3; // plus c'est petit, plus c'est rapide
  const int melodie2[][3] = { {4, 2, 2}, {4, 2, 2}, {4, 2, 4}, {4, 2, 2}, {4, 2, 2}, {4, 2, 4},
    {4, 2, 2}, {7, 2, 2},  {0, 2, 3},  {2, 2, 1},  {4, 2, 8},
    {5, 2, 2}, {5, 2, 2}, {5, 2, 3}, {5, 2, 1}, {5, 2, 2}, {4, 2, 2}, {4, 2, 3},
    {4, 2, 1}, {4, 2, 2}, {2, 2, 2}, {2, 2, 2}, {4, 2, 2}, {2, 2, 4}, {7, 2, 4},
    {4, 2, 2}, {4, 2, 2}, {4, 2, 4}, {4, 2, 2}, {4, 2, 2}, {4, 2, 4},
    {4, 2, 2}, {7, 2, 2},  {0, 2, 3},  {2, 2, 1},  {4, 2, 8},
    {5, 2, 2}, {5, 2, 2}, {5, 2, 3}, {5, 2, 1}, {5, 2, 2}, {4, 2, 2}, {4, 2, 3},
    {4, 2, 1}, {7, 2, 2}, {7, 2, 2}, {5, 2, 2}, {2, 2, 2}, {0, 2, 8}
  };

  float frequence; 
  uint8_t duration;
  frequence = round(note[melodie2[noteJouee][0]] * 2 * (melodie2[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie2[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie2[noteJouee][2] * tempo;
}


//
// We wish you a merry Christmas

int weWishYou(int noteJouee) {
  nombreDeNotes = 29;
  const int tempo = 4; // plus c'est petit, plus c'est rapide
  const int melodie[][3] = { {7, 2, 2}, {0, 3, 2}, {0, 3, 1}, {2, 3, 1}, {0, 3, 1}, {11, 2, 1},
    {9, 2, 2}, {9, 2, 2}, {9, 2, 2}, {2, 3, 2}, {2, 3, 1}, {4, 3, 1}, {2, 3, 1}, {0, 3, 1},
    {11, 2, 2}, {7, 2, 2}, {7, 2, 2}, {4, 3, 2}, {4, 3, 1}, {5, 3, 1}, {4, 3, 1}, {2, 3, 1},
    {0, 3, 2}, {9, 2, 2}, {7, 2, 2}, {9, 2, 2}, {2, 3, 2}, {11, 2, 2}, {0, 3, 4}
  };
  
   float frequence; 
  uint8_t duration;
  frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}


//
// le petit renne au  nez rouge

int petitRenne(int noteJouee) {
  nombreDeNotes = 56;
  const int tempo = 3; // plus c'est petit, plus c'est rapide
  const int melodie[][3] = { {7, 2, 2}, {9, 2, 1}, {7, 2, 1}, {4, 2, 2}, {0, 3, 2}, {9, 2, 2}, {7, 2, 6},
    {7, 2, 1}, {9, 2, 1}, {7, 2, 1}, {9, 2, 1}, {7, 2, 2}, {0, 3, 2}, {11, 2, 6},
    {5, 2, 2}, {7, 2, 1}, {5, 2, 1}, {2, 2, 2}, {11, 2, 2}, {9, 2, 2}, {7, 2, 6},
    {7, 2, 1}, {9, 2, 1}, {7, 2, 1}, {9, 2, 1}, {7, 2, 2}, {9, 2, 2}, {4, 2, 6},
    {7, 2, 2}, {9, 2, 1}, {7, 2, 1}, {4, 2, 2}, {0, 3, 2}, {9, 2, 2}, {7, 2, 6},
    {7, 2, 1}, {9, 2, 1}, {7, 2, 1}, {9, 2, 1}, {7, 2, 2}, {0, 3, 2}, {11, 2, 6},
    {5, 2, 2}, {7, 2, 1}, {5, 2, 1}, {2, 2, 2}, {11, 2, 2}, {9, 2, 2}, {7, 2, 6},
    {7, 2, 1}, {9, 2, 1}, {7, 2, 1}, {9, 2, 1}, {7, 2, 2}, {2, 3, 2}, {0, 3, 6},
  };
  
  float frequence; 
  uint8_t duration;
  frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}


//
// Winter Wonderland

int auRoyaume(int noteJouee) {
  nombreDeNotes = 33;
  const int tempo = 2; // plus c'est petit, plus c'est rapide
  const int melodie[][3] = { {7, 2, 2}, {7, 2, 1}, {7, 2, 9}, {7, 2, 2}, {7, 2, 1}, {4, 2, 2}, {7, 2, 6},
    {7, 2, 2}, {7, 2, 1}, {7, 2, 9}, {7, 2, 2}, {7, 2, 1}, {5, 2, 2}, {7, 2, 6},
    {7, 2, 1}, {11, 2, 2}, {11, 2, 1}, {11, 2, 2}, {9, 2, 6},
    {9, 2, 1}, {7, 2, 2}, {7, 2, 1}, {7, 2, 2}, {5, 2, 6},
    {4, 2, 2}, {4, 2, 1}, {4, 2, 2}, {4, 2, 1}, {2, 2, 2}, {2, 2, 1}, {2, 2, 1}, {2, 2, 1}, {0, 2, 9},
  };
  
  float frequence; 
  uint8_t duration;
  frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}
