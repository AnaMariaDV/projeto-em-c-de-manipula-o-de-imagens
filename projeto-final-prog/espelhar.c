#include "libTrabalho.h"
/*
 * Aqui só vamos percorrer a matriz até a metade da imagem
 assim podemos ir mudando de forma sincronizada.
 pra fazer isso ao invez de percorrer toda a coluna, soh percorremos
 metade dela col/2.
 usei a mesma tecnica que usava para inverter a ordem 
 aux=0;   b=1;  a=3;
 aux=a;
 a=b;
 b=a;
 */
void espelhar(int **mat, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col / 2; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][col - j - 1];
            mat[i][col - j - 1] = temp;
        }
    }
}
