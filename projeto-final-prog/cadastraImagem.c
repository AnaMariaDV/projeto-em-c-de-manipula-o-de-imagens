#include "libTrabalho.h"

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]) {
    Imagem img;


    if (verificaExistenciaDeImagem(nomeImagem) == 0) 
    {
        return -1;
    }
    if (verificaCadastro(arqFisicoImagensBase, nomeImagem) == 1) 
    {
        printf("Erro: Imagem ja cadastrada.\n");
        return 1;
    }

    // nome da imagem
    copiaString(nomeImagem, img.nome);

    //  ID 
    img.id = getLastId(arqFisicoImagensBase) + 1;

    // extensao da imagem
    getExtension(nomeImagem, img.tipo);

    // tamanho da imagem
    img.size = getSize(nomeImagem);

    //  dimensões da imagem
    img.dimensao.largura = getDimension(nomeImagem, &img.dimensao.altura);

    // Para pegar/usar data do sistema
    struct tm tm = getSystemTime();
    img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
    img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
    img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;

    printf("digite o nome do proprietario\n");
    scanf("%s", img.proprietario);

    // Chama gravaInfoImagem para gravar as informacões da imagem na base
    if (gravaInfoImagem(arqFisicoImagensBase, img) == 0) 
    {

        return -1;
    }

    return 0;
}
