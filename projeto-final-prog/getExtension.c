/*Vamos pegar a extensao da imagem com essa função, para isso usamos um while que vai percorrer 
a imagem enquanto não encontrar um \0*/
#include "libTrabalho.h"

void getExtension(char nomeImagem[], char *pExtension) {
    int i = 0;
    int posicaoPonto = -1;


    while (nomeImagem[i] != '\0') {
        if (nomeImagem[i] == '.') {
            posicaoPonto = i;
        }
        i++;
    }
    
    if (posicaoPonto == -1) {
        pExtension[0] = '\0';
    } 
    else 
    {
        // Copiar a extensão para pExtension usando copiaString
        copiaString(&nomeImagem[posicaoPonto], pExtension);
    }
}
