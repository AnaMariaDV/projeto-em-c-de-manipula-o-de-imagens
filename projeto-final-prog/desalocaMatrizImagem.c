#include "libTrabalho.h"

void desalocaMatrizImagem(int **mat, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        free(mat[i]);
    }
    free(mat);
}
