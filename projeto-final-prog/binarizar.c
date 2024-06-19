#include "libTrabalho.h"

void binarizar(int **mat, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] > 127) {
                mat[i][j] = 255;
            } else {
                mat[i][j] = 0;
            }
        }
    }
}
