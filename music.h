#pragma once

const int nbMusiques = 8;

// ------------------------------
// Noms des notes

#define SILENCE -1
#define DO       0
#define DOd      1
#define RE       2
#define REd      3
#define MI       4
#define FA       5
#define FAd      6
#define SOL      7
#define SOLd     8
#define LA       9
#define LAd     10
#define SI      11


// ------------------------------
// Noms des durées

#define CROCHE   1
#define NOIRE    2
#define NOIREp   3
#define BLANCHE  4
#define BLANCHEp 6
#define RONDE    8


// ------------------------------
// musiques

int petitPapa(int noteJouee);
int jingleBells(int noteJouee);
int weWishYou(int noteJouee);
int petitRenne(int noteJouee);
int auRoyaume(int noteJouee);
int douceNuit(int noteJouee);
int carol(int noteJouee);
int lesAnges(int noteJouee);


// ------------------------------
// fréquence des notes     do,   do#,    ré,   ré#,    mi,    fa,   fa#,   sol,   sol#,     la,    la#,   si

const float note[12] = {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47 };
