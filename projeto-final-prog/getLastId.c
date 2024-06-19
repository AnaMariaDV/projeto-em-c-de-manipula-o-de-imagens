/*
No while, enquanto houver imagens no arquivo vamos ler. 
com o fread retorna o numero de itens lidos.
 
 lastId recebe o id da última imagem lida.
 */
#include "libTrabalho.h"

int getLastId(char arqFisicoImagensBase[]) {
    FILE *arq = fopen(arqFisicoImagensBase, "rb");
    if (arq==NULL) {
        return 0;
    }

    Imagem img;
    int lastId = 0;
    
    while (fread(&img, sizeof(Imagem), 1, arq)) {
        lastId = img.id;
    }

    fclose(arq);
    return lastId;
}
