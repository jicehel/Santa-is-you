#include "music.h"
#include "defines.h"

int nombreDeNotes;

// Petit Papa Noël
int petitPapa(int noteJouee) {
  // nombreDeNotes = 58;
  nombreDeNotes = 59;
  const int tempo = 4; // plus c'est petit, plus c'est rapide
  // Musique du Petit Papa Noël, transcription: 
  // Notes
  // do, do#, ré, ré#, mi, fa, fa#, sol, sol#, la, la#, si  silence
  // 0,  1  , 2 , 3 ,  4 , 5  , 6 , 7  , 8 ,   9 , 10,  11  -1
  // Durée: 1=> croche   2 => Noire   3 => noire pointée   4=> blanche    6 => blanche pointée  8: ronde

  // sol => 7, do => 0, do => 0 do => 0, ré => 2, do => 0 etc...
  
/*  const int melodie[][3] = { {7, 2, 2}, {0, 3, 2}, {0, 3, 2}, {0, 3, 2}, {2, 3, 2}, {0, 3, 6},
    {0, 3, 1}, {2, 3, 1}, {4, 3, 2}, {4, 3, 2}, {4, 3, 2}, {5, 3, 2}, {4, 3, 6},
    {2, 3, 2}, {0, 3, 3}, {0, 3, 1}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {9, 2, 1}, {7, 2, 6},
    {7, 2, 1}, {7, 2, 1}, {0, 3, 4}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {0, 3, 1}, {2, 3, 6},
    {7, 2, 2}, {0, 3, 2}, {0, 3, 2}, {0, 3, 2}, {2, 3, 2}, {0, 3, 6},
    {0, 3, 1}, {2, 3, 1}, {4, 3, 2}, {4, 3, 2}, {4, 3, 2}, {5, 3, 2}, {4, 3, 6},
    {2, 3, 2}, {0, 3, 3}, {0, 3, 1}, {0, 3, 1}, {0, 3, 1}, {11, 2, 1}, {9, 2, 1}, {7, 2, 6},
    {7, 2, 1}, {7, 2, 1}, {0, 3, 4}, {0, 3, 1}, {0, 3, 1}, {2, 3, 1}, {2, 3, 1}, {0, 3, 6},
  }; */

  const int melodie[][3] = { {0, 2, 2 },{ 5, 2, 2}, { 5, 2, 2},{ 5, 2, 2},{ 7, 2, 2}, { 5, 2, 6}, { 5, 2, 1}, { 8, 2, 2},    // 8  Notes
     { 9, 2, 2}, { 9, 2, 2}, { 9, 2, 2},{ 10, 2, 2},{ 9, 2, 6},{ 7, 2, 2},{ 5, 2, 3}, { 5, 2, 1}, { 5, 2, 1}, { 5, 2, 1},    // 10 Notes
     { 4, 2, 1}, { 2, 2, 1}, { 0, 2, 6},{  0, 2, 1},{ 0, 2, 1}, { 5, 2, 6},{ 5, 2, 1},{ 5, 2, 1}, { 7, 2, 1}, { 7, 2, 1},
     { 5, 2, 8}, {-1, 2, 2}, { 0, 2, 2},{ 5, 2, 2}, { 5, 2, 2},{ 5, 2, 2},{ 7, 2, 2}, { 5, 2, 6}, { 5, 2, 1}, { 8, 2, 2},    
     { 9, 2, 2}, { 9, 2, 2}, { 9, 2, 2},{ 10, 2, 2},{ 9, 2, 6},{ 7, 2, 2},{ 5, 2, 3}, { 5, 2, 1}, { 5, 2, 1}, { 5, 2, 1},    // 10 Notes
     { 4, 2, 1}, { 2, 2, 1}, { 0, 2, 6},{  0, 2, 1},{ 0, 2, 1}, { 5, 2, 6},{ 5, 2, 1},{ 5, 2, 1}, { 7, 2, 1}, { 7, 2, 1},
     { 5, 2, 12}
     };   // 59 notes
  
  float frequence; 
  uint8_t duration;
  if (melodie[noteJouee][0] > -1)
      frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  if (melodie[noteJouee][0] > -1) 
      gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
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


// Douce nuit, sainte nuit
int douceNuit(int noteJouee) {
  nombreDeNotes = 46;
  const int tempo = 5; // plus c'est petit, plus c'est rapide
  // Notes
  // do, do#, ré, ré#, mi, fa, fa#, sol, sol#, la, la#, si  silence
  // 0,  1  , 2 , 3 ,  4 , 5  , 6 , 7  , 8 ,   9 , 10,  11  -1
  // Durée: 1=> croche   2 => Noire   3 => noire pointée   4=> blanche    6 => blanche pointée  8: ronde
  
  const int melodie[][3] = { {7, 2, 3 },{ 9, 2, 1}, { 7, 2, 2},{ 4, 2, 6}, 
                             {7, 2, 3 },{ 9, 2, 1}, { 7, 2, 2},{ 4, 2, 6},   
                             { 2, 3, 4},{ 2, 3, 2}, {11, 2, 6},
                             { 0, 3, 4},{ 0, 3, 2}, { 7, 2, 6}, 
                             {9, 2, 4 },{ 9, 2, 2}, { 0, 3, 3}, {11, 2, 1},{ 9, 2, 2}, { 7, 2, 3},{ 9, 2, 1}, { 7, 2, 2}, { 4, 2, 6},
                             {9, 2, 4 },{ 9, 2, 2}, { 0, 3, 3}, {11, 2, 1},{ 9, 2, 2}, { 7, 2, 3},{ 9, 2, 1}, { 7, 2, 2}, { 4, 2, 6},
                             { 2, 3, 4},{ 2, 3, 2}, { 5, 3, 3}, { 2, 3, 1},{11, 2, 2}, { 0, 3, 6}, { 4, 3, 6},
                             { 0, 3, 3}, {7, 2, 1 }, {4, 2, 2 },{ 7, 2, 3},{ 5, 2, 1}, { 2, 2, 2}, { 0, 2, 6}
     };   // 46 notes
  
  float frequence; 
  uint8_t duration;
  if (melodie[noteJouee][0] > -1)
      frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  if (melodie[noteJouee][0] > -1) 
      gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}


// Carol of the Bells
int carol(int noteJouee) {
  // nombreDeNotes = 161;
  nombreDeNotes = 121;
  const int tempo = 4; // plus c'est petit, plus c'est rapide
  // Notes
  // do, do#, ré, ré#, mi, fa, fa#, sol, sol#, la, la#, si  silence
  // 0,  1  , 2 , 3 ,  4 , 5  , 6 , 7  , 8 ,   9 , 10,  11  -1
  // Durée: 1=> croche   2 => Noire   3 => noire pointée   4=> blanche    6 => blanche pointée  8: ronde
  
  const int melodie[][3] = { /* { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 },  
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, 
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 },  */
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, 
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 }, 
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2 }, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{4, 2, 2 },  
  {11, 2, 2},{ 9, 2, 1}, {11, 2, 1},{ 7, 2, 2 }, {11, 2, 2},{ 9, 2, 1}, {11, 2, 1},{7, 2, 2 }, 
  {11, 2, 2},{ 9, 2, 1}, {11, 2, 1},{ 7, 2, 2 }, {11, 2, 2},{ 9, 2, 1}, {11, 2, 1},{7, 2, 2 }, 
  { 4, 3, 2},{ 4, 3, 1}, { 4, 3, 1},{ 2, 3, 1 }, {0, 3, 1 }, 
  {11, 2, 2},{11, 2, 1}, {11, 2, 1},{ 9, 2, 1 }, {7, 2, 1 }, 
  { 9, 2, 2},{ 9, 2, 1}, { 9, 2, 1},{11, 2, 1 }, {9, 2, 1 },
  { 4, 2, 2},{ 4, 2, 1}, { 4, 2, 1},{ 4, 2, 2 }, 
  {11, 1, 1},{ 1, 2, 1}, { 3, 2, 1},{ 4, 2, 1 }, { 5, 2, 1},{ 7, 2, 1},
  { 9, 2, 1},{11, 2, 1}, { 9, 2, 2},{ 7, 2, 2}, 
  {11, 1, 1},{ 1, 2, 1}, { 3, 2, 1},{ 4, 2, 1 }, { 5, 2, 1},{ 7, 2, 1},
  { 9, 2, 1},{11, 2, 1}, { 9, 2, 2},{ 7, 2, 2}, 
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, 
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2},
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2},
  { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, { 7, 2, 2},{ 5, 2, 1}, { 7, 2, 1},{ 4, 2, 2}, 
  {11, 2, 6},{ 9, 2, 4}, {11, 2, 2},{ 4, 2, 6} 
     };   // 161 notes => 121 notes car sans la chanson sinon c'est trop répétitif...
  
  float frequence; 
  uint8_t duration;
  if (melodie[noteJouee][0] > -1)
      frequence = round(note[melodie[noteJouee][0]] * 2 * (melodie[noteJouee][1]-1));
  duration = tempo * tempsCycle * melodie[noteJouee][2];
  if (melodie[noteJouee][0] > -1) 
      gb.sound.tone(round(frequence), duration);
  return melodie[noteJouee][2] * tempo;
}
