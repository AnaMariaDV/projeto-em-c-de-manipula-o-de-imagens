/*NÃO PODEMOS DEVOLVER UM VETOR, MAS PODEMOS DEVOLVER UM PONTEIRO*/
#include "libTrabalho.h"

char *alocaString(int size) 
{
    
    char *st = (char *)malloc(size * sizeof(char));

    return st;
}
