#include "libTrabalho.h"

void imprimeImagem(Imagem img) 
{

    Imagem *pImg = &img;

    // Imprimir as informacões da imagem usando o ponteiro pImg
    printf("\n\nNome: %s\n", pImg->nome);
    printf("ID: %d\n", pImg->id);
    printf("Tipo: %s\n", pImg->tipo);
    printf("Tamanho: %d bytes\n", pImg->size);
    printf("Dimensoes: %dx%d\n", pImg->dimensao.altura, pImg->dimensao.largura);
    printf("Proprietario: %s\n", pImg->proprietario);
    printf("Data de Criacao: %02d/%02d/%04d\n", pImg->data_criacao.dia, pImg->data_criacao.mes, pImg->data_criacao.ano);
    printf("Data de Modificacao: %02d/%02d/%04d\n", pImg->data_modificacao.dia, pImg->data_modificacao.mes, pImg->data_modificacao.ano);
}
