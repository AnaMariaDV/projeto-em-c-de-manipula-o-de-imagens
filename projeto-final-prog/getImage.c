#include "libTrabalho.h"

//Nesta função, se existe imagem com nomeImagem cadastrada em arqFisicoImagensBase, 
//esta imagem (img) é retornada. Caso a nomeImagem não esteja cadastrada, retorna-se img com 
//o campo img.nome = nulo (usado para verificação da existência da imagem na chamada desta função).
Imagem getImage(char arqFisicoImagensBase[], char nomeImagem[]){
   Imagem img;
   copiaString("nulo", img.nome);
   FILE *arq = fopen(arqFisicoImagensBase,"r");

   if (arq == NULL){
	   printf("\nProblema ao abrir arquivo - getImage\n"); 
	   return img;
   }
   //Le os registros img na base arqFisicoImagensBase
   while(fread(&img,sizeof(Imagem), 1, arq)!=0){
	//Encontrou nomeImagem cadastrada   
	if (comparaStrings(img.nome,nomeImagem)==1){
   		fclose(arq);  
		return img;
	}	      
   }
   fclose(arq);  
   return img;
	
}