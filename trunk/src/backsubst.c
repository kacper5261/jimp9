#include "backsubst.h"

/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
 
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int j, i;

	for (i = 0; i < mat->r; i++){
		if (mat->data[i][i] == 0)
			return 1;
	}

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
