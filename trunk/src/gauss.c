kacper
#8114

Szkomprompa — 09.12.2021
projekt graficzny modyfikacji, podziału kodu (podział na moduły, interfejs funkcji, struktury, zależności pomiędzy modułami)
zamiana listy liniowej na wektor o zmiennej długości do przechowywania numerów linii
poprawa wyszukiwania słów we fragmentach innych słów
plik makefile
#include <cstring>
#include <cstdio>
int main()
{
    char str[] = "Rok 1525 - Hold Pruski, Krakow";
    char korektor[] = " ,.-";
    char * schowek;
    printf( "Rozdziela tekst "%s" na poszczegolne wyrazy:\n", str );
    schowek = strtok( str, korektor );
    while( schowek != NULL )
    {
        printf( "%s\n", schowek );
        schowek = strtok( NULL, korektor );
    }
    return 0;
}
kacper — 09.12.2021
https://codeshare.io/8pgQgJ
kacper — 09.12.2021
slowo1 slowo2 slowo3.
slowo slsl abcd.
asd asd asd basd.
https://codeshare.io/8pgQgJ
Szkomprompa — 09.12.2021
#include <ctype.h>
#include <string.h>

char *word_find(const char *str, const char *word) {
    const char p = NULL;
    size_t len = strlen(word);

    if (len > 0) {
        for (p = str; (p = strstr(p, word)) != NULL; p++) {
            if (p == str || !isalnum((unsigned char)p[-1])) {
                if (!isalnum((unsigned char)p[len]))
                    break;  / we have a match! /
                p += len;   / next match is at least len+1 bytes away */ 
            }
        }
    }
    return p;
}
Szkomprompa — 09.12.2021
https://stackoverflow.com/questions/42352846/matching-an-exact-word-using-in-c?fbclid=IwAR0kWv0f-vun_beYy1HXaQi2VLHsdR6sINrM33k8dWMfhf50ct-i-IfG1XQ
Stack Overflow
Matching an exact word using in c
Can I use the strstr function to match exact word? For example, let's say I have the word hello, and an input string line:

if

char* line = "hellodarkness my old friend";
and I use

result = str...
Obraz
kacper — 09.12.2021
http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/2-C-adv-data/dyn-array.html
kacper — 09.12.2021
Typ załącznika: archive
skorowidz.zip
1.93 KB
kacper — 09.12.2021
Typ załącznika: archive
skorowidz1.zip
19.02 KB
kacper — Wczoraj o 19:05
https://github.com/kacper5261/gauss
GitHub
GitHub - kacper5261/gauss
Contribute to kacper5261/gauss development by creating an account on GitHub.

kacper — Wczoraj o 19:17
wsl --set-default-version 2
Szkomprompa — Wczoraj o 19:41
http://wikidyd.iem.pw.edu.pl/LMP(2f)9.html
kacper — Wczoraj o 19:42
https://codeshare.io/eVm9jb
Typ załącznika: acrobat
Eliminacja_Gaussa_-_przykad_obliczeniowy_1.pdf
668.15 KB
kacper — Wczoraj o 21:22
#include "gauss.h"
#include <math.h>
#include <stdio.h>

void zerowanie(int a, Matrix *mat, Matrix *b){


}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    int i;
      int j;
      double tmp;
      int wiersz;
    double *tmp1;



      tmp = fabs(mat->data[0][0]);
      //wybor elementu glownego
      for (i=0; i < mat->r; i++){
      if (fabs(mat->data[i][0]) > tmp) {
        tmp = fabs(mat->data[i][0]);
        wiersz = i;
      }
    }
      //zamiana kolumn
      if (wiersz != 0){
      tmp1 = mat->data[0];
      mat->data[0] = mat->data[wiersz];
      mat->data[wiersz] = tmp1;

      tmp1 = b->data[0];
      b->data[0] = b->data[wiersz];
      b->data[wiersz] = tmp1;
    }
      //zerowanie kolumny 0
      for (i=1; i < mat->r; i++){
      tmp = mat->data[i][0]/mat->data[0][0];
      for (j=0; j < mat->c; j++){
          mat->data[i][j] = mat->data[i][j] - tmp * mat->data[0][j];
      }
      b->data[i][0] = b->data[i][0] - tmp * b->data[i][0];
    }

    return 0;
}
Szkomprompa — Wczoraj o 21:41
https://matematyka.pl/viewtopic.php?t=50749
wyznacznik - C - Matematyka.pl
Witam, muszę napisac program w C liczący wyznacznik macierzy stopnia 2, 3, 4 ale koniecznie z rozwinięcia Laplace a. Nie proszę o cały program, ale tylko o podpowiedz np. czesc kodu programu dla oblicznia wyznacznika 2x2. Jeśli to będę miec to mysle ..
kacper — Wczoraj o 21:48
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
      //zerowanie kolumny 0
      for (i=a+1; i < mat->r; i++){
      tmp = mat->data[i][a]/mat->data[a][a];
      for (j=a; j < mat->c; j++){
          mat->data[i][j] = mat->data[i][j] - tmp * mat->data[a][j];
      }
      b->data[i][a] = b->data[i][a] - tmp * b->data[i][a];
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
kacper — Wczoraj o 22:11
https://www.tutorialspoint.com/cplusplus-program-to-compute-determinant-of-a-matrix
C++ Program to Compute Determinant of a Matrix
C++ Program to Compute Determinant of a Matrix - The determinant of a square matrix can be computed using its element values. The determinant of a matrix A can ...
kacper — Wczoraj o 22:54
#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
    int res;
    Matrix * A = readFromFile(argv[1]);
    Matrix * b = readFromFile(argv[2]);
    Matrix * x;

    if (A == NULL) return -1;
    if (b == NULL) return -2;
    printToScreen(A);
    printToScreen(b);

    res = eliminate(A,b);
    if(res == 1) {
        return 1;
    }
    printToScreen(A);
    printToScreen(b);
    x = createMatrix(b->r, 1);
    if (x != NULL) {
        res = backsubst(x,A,b);

        printToScreen(x);
      freeMatrix(x);
    } else {
                    fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
    }

    freeMatrix(A);
    freeMatrix(b);

    return 0;
}
#include "gauss.h"
#include <math.h>
#include <stdio.h>

void zerowanie(int a, Matrix *mat, Matrix *b){
    int i;
Rozwiń
message.txt
3 KB
kacper — Dziś o 19:21
https://codeshare.io/YLnzXE
kacper — Dziś o 20:44
3 3
1.0 1.0 1.0 1.0 2.0 3.0 1.0 3.0 4.0
3 1
3.0 1.0 -2.0
Szkomprompa — Dziś o 21:30
https://github.com/trong-le/C-Codes/blob/master/Matrix%20Multiplication%20with%20Back%20Substitution.c#:~:text=//%20Back%20substitution-,x_hat%5Bdim%2D1%5D%20%3D%20y_hat%5Bdim%2D1%5D%3B,%7D,-//%20Cast%20each%20x
GitHub
C-Codes/Matrix Multiplication with Back Substitution.c at master · ...
Contribute to trong-le/C-Codes development by creating an account on GitHub.

Szkomprompa — Dziś o 21:44
https://codeshare.io/VZmNA8
kacper — Dziś o 21:46
https://codeshare.io/MNgkmq
Szkomprompa — Dziś o 22:26
#include "gauss.h"
#include <math.h>
#include <stdio.h>

void zerowanie(int a, Matrix *mat, Matrix *b){
  int i;
Rozwiń
message.txt
3 KB
Szkomprompa — Dziś o 23:01
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
#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
 
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    int j, i;

    if (mat->r != mat->c)
        return 2;

    for(j = (mat->r) - 1; j >= 0; j--){
        double tmp = b->data[j][0];
        for (i = (mat->c) - 1; i > 0; i--){
            if (j < i)
                tmp = tmp - mat->data[j][i] * x->data[i][0];
        }
    if (mat->data[j][j] == 0)
      return 1;
        x->data[j][0] = tmp / mat->data[j][j];
    }

    return 0;
}
﻿
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
message.txt
3 KB
