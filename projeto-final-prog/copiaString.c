//passa as informacoes da string1 para a string 2
#include "libTrabalho.h"

void copiaString(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}
