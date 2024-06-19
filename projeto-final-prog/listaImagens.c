#include "libTrabalho.h"

int listaImagens(char arqFisicoImagensBase[]) {
    FILE *arq = fopen(arqFisicoImagensBase, "rb");
    if (arq==NULL) {
        printf("Erro ao abrir o arquivo %s\n", arqFisicoImagensBase);
        return 0;
    }

    Imagem img;
    int count = 0;

    // Ler e listar todas as imagens cadastradas
    while (fread(&img, sizeof(Imagem), 1, arq)) {
        imprimeImagem(img);
        count++;
    }

    fclose(arq);

    if (count == 0) {
        printf("Nenhuma imagem cadastrada.\n");
        return 0;
    }

    return 1;
}
