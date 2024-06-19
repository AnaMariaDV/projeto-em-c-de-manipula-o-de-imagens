#include "libTrabalho.h"

int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]) {
    FILE *arq = fopen(arqFisicoImagensBase, "rb");
    if (arq==NULL) {
        return -1;
    }

    Imagem img;
    while (fread(&img, sizeof(Imagem), 1, arq)) {
        if (comparaStrings(img.nome, nomeImagem) == 1) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0;
}
