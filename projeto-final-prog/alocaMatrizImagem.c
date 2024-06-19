#include "libTrabalho.h"

int **alocaMatrizImagem(int lin, int col)
{
    int i;
    int **mat;

    mat = (int **)malloc(lin * sizeof(int *));
    if (mat == NULL) 
    {
        
        return NULL;
    }
    for (i = 0; i < lin; i++) 
    {
        mat[i] = (int *)malloc(col * sizeof(int));
        if (mat[i] == NULL) 
        {
            desalocaMatrizImagem(mat, i, col);
            return NULL;

        }
    }

    return mat;
}
