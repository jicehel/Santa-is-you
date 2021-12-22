#pragma once

const int nbMusiques = 5;

// musiques
int petitPapa(int noteJouee);
int jingleBells(int noteJouee);
int weWishYou(int noteJouee);
int petitRenne(int noteJouee);
int auRoyaume(int noteJouee);

// fréquence associée à chaque note
// do, do#, ré, ré#, mi, fa, fa#, sol, sol#, la, la#, si
const float note[12] = {65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83, 110.00, 116.54, 123.47 };
