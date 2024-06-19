#include "libTrabalho.h"

void ruido(int **mat, int lin, int col) {
    int i, j;
    int ruido, novo_valor;
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++) 
        {
            ruido = rand() % 201 - 100; 
            novo_valor = mat[i][j] + ruido;

            if (novo_valor > 255) 
            {
                novo_valor = 255;
            } 
            else 
            if(novo_valor < 0) 
            {
                novo_valor = 0;
            }
            mat[i][j] = novo_valor;
        }
    }
}


