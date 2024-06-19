#include "libTrabalho.h"

int gravaInfoImagem(char arqFisicoImagensBase[], Imagem img) {
    FILE *arq = fopen(arqFisicoImagensBase, "ab");
    if (arq==NULL) {
        return 0;
    }

    fwrite(&img, sizeof(Imagem), 1, arq);
    fclose(arq);
    return 1;
}
