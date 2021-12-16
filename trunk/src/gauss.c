#include "gauss.h"
#include <math.h>
#include <stdio.h>

void zerowanie(int a, Matrix *mat, Matrix *b){
  int i;
  int j;
  double tmp;
  int wiersz;
  double *tmp1;
  
  tmp = fabs(mat->data[a][a]);
  wiersz = a;
  //wybor elementu glownego
  for (i=a; i < mat->r; i++){
    if (fabs(mat->data[i][a]) > tmp) {
      tmp = fabs(mat->data[i][a]);
      wiersz = i;
    }
  }
  //zamiana kolumn
  if (wiersz != a){
    tmp1 = mat->data[a];
    mat->data[a] = mat->data[wiersz];
    mat->data[wiersz] = tmp1;
      
    tmp1 = b->data[a];
    b->data[a] = b->data[wiersz];
    b->data[wiersz] = tmp1;
  }
  //zerowanie kolumny
  
  
  for (i=a+1; i < mat->r; i++){
    tmp = (mat->data[i][a])/(mat->data[a][a]);
    for (j=a; j < mat->c; j++){
      mat->data[i][j] = mat->data[i][j] - tmp * (mat->data[a][j]);
    }
    b->data[i][0] = b->data[i][0] - tmp * (b->data[a][0]);
  }
}

int potega(int a, int b){
  int wynik = 1;
  while(b--){
    wynik = wynik * a;
  }
  return wynik;
}

double wyznacznik(Matrix *mat) {
  double det = 0.0;
  Matrix * submat = NULL;
  submat = createMatrix(mat->r,mat->c);
  if (mat->r == 2)
    return ((mat->data[0][0] * mat->data[1][1]) - (mat->data[1][0] * mat->data[0][1]));
  else {
    for (int x = 0; x < mat->r; x++) {
      int subi = 0;
        for (int i = 1; i < mat->r; i++) {
          int subj = 0;
          for (int j = 0; j < mat->r; j++) {
            if (j == x)
              continue;
            submat->data[subi][subj] = mat->data[i][j];
            subj++;
          }
          subi++;
         }
      submat->r = submat->r - 1;
      submat->c = submat->c - 1;
      det = det + (potega(-1, x) * mat->data[0][x] * wyznacznik(submat));
    }
  }
  return det;
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
  int k;

  if (wyznacznik(mat) == 0.0)
    return 1;
  
  for(k = 0; k < (mat->c) - 1; k++){
    zerowanie(k, mat, b); 
  }
  return 0;
}
