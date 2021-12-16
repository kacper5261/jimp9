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

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){
  int k;
  
  for(k = 0; k < (mat->c) - 1; k++){
    zerowanie(k, mat, b); 
  }
  return 0;
}
