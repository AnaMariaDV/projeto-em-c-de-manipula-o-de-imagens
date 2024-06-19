#include "libTrabalho.h"

int getDimension(char nomeImagem[], int *pAltura) {
    FILE *arq = fopen(nomeImagem, "r");
    if (arq==NULL) {
        return NULL;
    }

    char line[100];
    fgets(line, sizeof(line), arq); // P2
    fgets(line, sizeof(line), arq); // Comment or dimensions
    while (line[0] == '#') {
        fgets(line, sizeof(line), arq);
    }

    int largura, altura;
    sscanf(line, "%d %d", &largura, &altura);
    *pAltura = altura;

    fclose(arq);
    return largura;
}