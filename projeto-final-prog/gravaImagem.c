#include "libTrabalho.h"

int gravaImagem(char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat) {
    FILE *arq = fopen(nomeArqSaida, "w");
    if (arq == NULL) {
        return 1;
    }

    fprintf(arq, "%s\n", tipo);
    fprintf(arq, "%d %d\n", col, lin);
    fprintf(arq, "%d\n", maxval);

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            fprintf(arq, "%d ", mat[i][j]);
        }
        fprintf(arq, "\n");
    }

    fclose(arq);
    return 0;
}
