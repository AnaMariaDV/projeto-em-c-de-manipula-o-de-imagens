/** @file   libTrabalho-2401
    @author Juliana de Santi
*/

#ifndef _LIBTRABALHO_H_ 
#define _LIBTRABALHO_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <sys/stat.h>

//=============== Constantes =======================
#define MAX_NAME 50 //número máximo de caracteres usado para nome do proprietario da imagem



//=============== Registros/structs =======================
//Registro para a definição do tipo Data
typedef struct data{
  int dia, mes, ano;
} Data;

//Registro para definicão do tipo Dimension
typedef struct dimension{	
  int altura;
  int largura;
} Dimension;


//Registro para a definição do tipo Imagem
typedef struct imagem{
   char nome[40];
   int id;
   //Neste trabalho, o tipo considerado é PGM
   char tipo[7];
   int size;//em bytes
   Dimension dimensao; 
   char proprietario[MAX_NAME]; 
   Data data_criacao;
   Data data_modificacao;
} Imagem;


////=============== Menu de operações possíveis ==========================
void menuOperacoes();

//=============== Assinaturas/Protótipos da parte de cadastros =======================
int listaImagens(char arqFisicoImagensBase[]);
void imprimeImagem(Imagem img);

int cadastraImagem(char arqFisicoImagensBase[], char nomeImagem[]);
int verificaCadastro(char arqFisicoImagensBase[], char nomeImagem[]);
int verificaExistenciaDeImagem(char imagem_a_verificar[]);
struct tm getSystemTime();
int getLastId(char arqFisicoImagensBase[]);
void getExtension(char nomeImagem[], char extension[]);
int getSize(char nomeImagem[]);
int getDimension(char nomeImagem[], int *pAltura);

int gravaInfoImagem(char arqFisicoImagensBase[],  Imagem img);
int alteraImagem(char arqFisicoImagensBase[], int id);
void removeImagem(char arqFisicoImagensBase[], int id);

//=============== Assinaturas/Protótipos das operações sobre as imagens =============
char *alocaString (int size);
int **alocaMatrizImagem (int lin, int col);
void desalocaMatrizImagem(int **mat, int lin, int col);

int **leArquivoImagem (char *nomeArq, char *tipo, int *lin, int *col, int *maxval);
int gravaImagem (char *nomeArqSaida, char *tipo, int lin, int col, int maxval, int **mat);
Imagem getImage(char arqFisicoImagensBase[], char auxNomeImagem[]);

void espelhar (int **mat, int lin, int col);
void binarizar (int **mat, int lin, int col);
void negativo (int **mat, int lin, int col);
void ruido (int **mat, int lin, int col);

// Assinaturas/Protótipos para manipulação de strings
int comparaStrings(char st1[], char str2[]);
void copiaString(char str1[], char str2[]);
#endif
