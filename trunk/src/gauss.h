#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);
void zerowanie(int a, Matrix *mat, Matrix *b);
int potega(int a, int b);
double wyznacznik(Matrix *mat);

#endif
