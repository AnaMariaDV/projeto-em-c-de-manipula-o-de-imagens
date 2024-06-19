#include "libTrabalho.h"

int alteraImagem(char arqFisicoImagensBase[], int id) {

    Imagem img;
    Imagem *pImg;


    FILE *arq = fopen(arqFisicoImagensBase, "r+b");
    if (arq==NULL)
    {
        return 0;
    }
    while (fread(&img, sizeof(Imagem), 1, arq))
    {
        if (img.id == id) {

            printf("Digite o novo nome do proprietário: ");
            scanf("%s", img.proprietario);

            // Atualizar a data de modificacao
            struct tm tm = getSystemTime();
            img.data_modificacao.dia = tm.tm_mday;
            img.data_modificacao.mes = tm.tm_mon + 1;
            img.data_modificacao.ano = tm.tm_year + 1900;


            fseek(arq, sizeof(Imagem), SEEK_CUR);
            fwrite(&img, sizeof(Imagem), 1, arq);

            fclose(arq);
            return 1;
        }
    }

    fclose(arq);
    return 0; // Retorna 0 se a imagem nao foi encontrada
}
