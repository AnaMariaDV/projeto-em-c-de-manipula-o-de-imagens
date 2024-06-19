#include "libTrabalho.h"

int **leArquivoImagem(char *nomeArqEntrada, char *tipo, int *lin, int *col, int *maxval) {
    
    FILE *arq = fopen(nomeArqEntrada, "r");
    if (arq==NULL) 
    {
        return NULL;
    }

//nunca mais esquecer:lembrar de sempre iniciar as coisas antes de usarrrrr!!!!

    //lendo o tipo da imagem
    fscanf(arq, "%s", tipo);
    //esse ler a quantidade de linhas e colunas
    fscanf(arq, "%d %d", col, lin);
    //lendo a maxval
    fscanf(arq, "%d", maxval);


    int **mat = alocaMatrizImagem(*lin, *col);
    
    if (mat==NULL) 
    {
        fclose(arq);
        return NULL;
    }
    
    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            fscanf(arq, "%d", &mat[i][j]);
        }
    }

    fclose(arq);
    return mat;
}
