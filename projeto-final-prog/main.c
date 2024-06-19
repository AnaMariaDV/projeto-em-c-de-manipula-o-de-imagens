#include "libTrabalho.h"

int main() 
{
    //=======Variáveis para cadastro na base
    char arqFisicoImagensBase[] = "arqFisicoImagensBase.bin";
    int id;
    char nomeImagem[MAX_NAME];

    //======Variáveis para operações sobre imagens	
   int opt = 1, lin = 0, col= 0, maxval= 0, gravou;
   char *tipo, *nomeArqSaida;
   int **matImagem;
   char *auxNomeImagem;
   Imagem img;

    do {
        // Função que mostra as opções para o usuário ao executar o programa
        menuOperacoes();
        scanf("%d", &opt);

        switch (opt) {
            case 0: 
                printf("\n");
                break;
            case 1: 
                // listaImagens
                listaImagens(arqFisicoImagensBase);
                break; 
            case 2:
                // cadastraImagem
                
                printf("\nNome da imagem a cadastrar: ");
                scanf("%s", nomeImagem);
                gravou = cadastraImagem(arqFisicoImagensBase, nomeImagem);
                if (gravou == 0) {
                    printf("Imagem cadastrada com sucesso.\n");
                } else {
                    printf("Erro ao cadastrar imagem.\n");
                }
                break;
            case 3:
                // alteraImagem
                printf("\nID da imagem a alterar: ");
                scanf("%d", &id);
                gravou = alteraImagem(arqFisicoImagensBase, id);
                if (gravou == 1 ) 
                {
                    printf("Imagem alterada com sucesso.\n");
                } 
                else 
                {
                    printf("Erro ao alterar imagem.\n");
                }
                break; 
            case 4: 
                printf("\nID da imagem a remover: ");
                scanf("%d", &id);
                removeImagem(arqFisicoImagensBase, id);
                break;  
            case 5: 
                
                auxNomeImagem=alocaString(MAX_NAME);
                
                do{
                    printf("\nNome da imagem a binarizar: ");
                    scanf("%s", auxNomeImagem);
                    
                }while(verificaCadastro(arqFisicoImagensBase, auxNomeImagem)==0);
            

                tipo=alocaString(3);
 
                //if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem)) {
                    matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
                    
                    if (matImagem) {
                        binarizar(matImagem, lin, col);
                        nomeArqSaida = alocaString(MAX_NAME) ;
                        do{
                            printf("digite o nome de saida do arquivo\n");
                            scanf("%s", nomeArqSaida);
                        }while(verificaCadastro(arqFisicoImagensBase, nomeArqSaida)==1);
                        
                        if (gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem) == 0) {
                            printf("realizada com sucesso.\n");
                        } else {
                            printf("Erro ao gravar a imagem binarizada.\n");
                        }

                        desalocaMatrizImagem(matImagem, lin, col);
                        img=getImage(arqFisicoImagensBase, auxNomeImagem);
                        printf("\n %s %s\n",auxNomeImagem,img.nome);
                        copiaString(nomeArqSaida, img.nome);
                        struct tm tm = getSystemTime();
                        img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
                        img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
                        img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
                        img.id=getLastId(arqFisicoImagensBase)+1;
                        gravaInfoImagem(arqFisicoImagensBase, img);
                        
                    } 
                    else 
                    {
                        printf("Erro ao carregar a imagem.\n");
                    }
                
            

                free(nomeArqSaida);
                free(auxNomeImagem);
                free(tipo);
                break;
            case 6:
               auxNomeImagem=alocaString(MAX_NAME);  
                printf("\nNome da imagem a aplicar ruído: ");
                scanf("%s", auxNomeImagem);
                tipo=alocaString(3);
                if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem)) 
                {
                    matImagem = leArquivoImagem(img.nome, tipo, &lin, &col, &maxval);
                    if (matImagem) {
                        ruido(matImagem, lin, col);
                        nomeArqSaida=alocaString(MAX_NAME);
                        do{
                            printf("digite o nome de saida do arquivo:\n");
                            scanf("%s", nomeArqSaida);

                        }while(verificaCadastro(arqFisicoImagensBase, nomeArqSaida)==1);

                        if (gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem) == 0) {
                            printf("ruido adicionado com sucesso\n");
                        } else {
                            printf("Erro ao gravar a imagem com ruído.\n");
                        }
                        desalocaMatrizImagem(matImagem, lin, col);
                        img=getImage(arqFisicoImagensBase, auxNomeImagem);
                        copiaString(nomeArqSaida, img.nome);
                        struct tm tm = getSystemTime();
                        img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
                        img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
                        img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
                        gravaInfoImagem(arqFisicoImagensBase, img);
                    } 
                    else 
                    {
                        printf("Erro ao carregar a imagem.\n");
                    }
                } 
                else 
                {
                    printf("Erro: O arquivo %s não existe.\n", nomeImagem);
                }
                free(nomeArqSaida);
                free(auxNomeImagem);
                free(tipo);
                
                break;
            case 7: 
            
                auxNomeImagem=alocaString(MAX_NAME);  
                printf("\nNome da imagem a negativar: ");
                scanf("%s", auxNomeImagem);
                tipo=alocaString(3);

                if (verificaCadastro(arqFisicoImagensBase, auxNomeImagem)) {
                    printf("Arquivo %s existe. Tentando abrir...\n", auxNomeImagem);
                    matImagem = leArquivoImagem(auxNomeImagem, tipo, &lin, &col, &maxval);
                    if (matImagem) {
                        negativo(matImagem, lin, col);
                        nomeArqSaida = alocaString(MAX_NAME);
                        do{
                            printf("digite o nome de saida do arquivo\n");
                            scanf("%s", nomeArqSaida);

                        }while(cadastraImagem(arqFisicoImagensBase, nomeArqSaida)==1);
                        if (gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem) == 0) {
                        } else {
                            printf("Erro ao gravar a imagem negativa.\n");
                        }
                        desalocaMatrizImagem(matImagem, lin, col);
                        img=getImage(arqFisicoImagensBase, auxNomeImagem);
                        copiaString(nomeArqSaida, img.nome);
                        struct tm tm = getSystemTime();
                        img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
                        img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
                        img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
                        gravaInfoImagem(arqFisicoImagensBase, img);
                    } 
                    else 
                    {
                        printf("Erro ao carregar a imagem.\n");
                    }
                } 
                else 
                {
                    printf("Erro: O arquivo %s não existe.\n", nomeImagem);
                }
                free(nomeArqSaida);
                free(auxNomeImagem);
                free(tipo);
                
                break;
            case 8: 
            
                auxNomeImagem=alocaString(MAX_NAME);  
                printf("\nNome da imagem a espelhar: ");
                scanf("%s", nomeImagem);
                tipo=alocaString(3);

                if (verificaExistenciaDeImagem(nomeImagem)) {
                    printf("Arquivo %s existe. Tentando abrir...\n", nomeImagem);
                    matImagem = leArquivoImagem(nomeImagem, tipo, &lin, &col, &maxval);
                    if (matImagem) {
                        espelhar(matImagem, lin, col);
                        nomeArqSaida = alocaString(MAX_NAME); 
                        do{
                            printf("digite o nome de saida do arquivo\n");
                            scanf("%s", nomeArqSaida);

                        }while(cadastraImagem(arqFisicoImagensBase, nomeArqSaida)==1);
                        if (gravaImagem(nomeArqSaida, tipo, lin, col, maxval, matImagem) == 0) {
                        } else {
                            printf("Erro ao gravar a imagem espelhada.\n");
                        }
                        desalocaMatrizImagem(matImagem, lin, col);
                        img=getImage(arqFisicoImagensBase, auxNomeImagem);
                        copiaString(nomeArqSaida, img.nome);
                        struct tm tm = getSystemTime();
                        img.data_criacao.dia = img.data_modificacao.dia = tm.tm_mday;
                        img.data_criacao.mes = img.data_modificacao.mes = tm.tm_mon + 1;
                        img.data_criacao.ano = img.data_modificacao.ano = tm.tm_year + 1900;
                        gravaInfoImagem(arqFisicoImagensBase, img);
                    } else {
                        printf("Erro ao carregar a imagem.\n");
                    }
                } else {
                    printf("Erro: O arquivo %s não existe.\n", nomeImagem);
                }
                free(nomeArqSaida);
                free(auxNomeImagem);
                free(tipo);
                
                break;	   
            default: 
                printf("\nOpcao invalida");
        }
    } while (opt != 0);

    return 0;
}
