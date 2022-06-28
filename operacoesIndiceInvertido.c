/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

    Universidade Federal De Viçosa - Campus Florestal
    Trabalho prático 1 de Algorítimos e estrutura de dados 2
    
    Professora responsável: 
        Glaucia Braga e Silva
        
    Integrantes do Gupo:
        Caio Oliveira Almeida - 4237
        Guilherme Augusto Schwann Wilke - 4685
        João Vitor Chagas Lobo - 4693

    Arquivo: 
        operacoesIndiceInvertido.c
        Descrição do arquivo: Arquivo que contém as funções de montagem e manipulação do indice invertido
        Ultima modificação: 27/06 - Por: Guilherme Augusto Schwann Wilke

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include <math.h>
#include "operacoesIndiceInvertido.h"

/*------------------------------------------------------------------- Leitura de arquivos -------------------------------------------------------------------*/

void escrevePalavrasDocsHash(tipoVetPesos vetPesos, hashTablePalavras tabela, listaEncadDocs listaDocs, int tamTabela){
    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (aux->doc.documentoLido == naoLido){
            lerPalavrasInsereHash(aux->doc.nomeDoc, aux->doc.idDoc, vetPesos, tabela, tamTabela);
            printf("Inseriu no TAD hash com M = %d - As palavras do arquivo %s\n", tamTabela, aux->doc.nomeDoc);

        }
        aux = aux->prox;
    }
}

void lerPalavrasInsereHash(char* arquivo, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela){
    FILE *fp;
    char palavra[50];
    char * path = strcat("textos/", arquivo);
    fp = fopen(path, "r");
    
    if(fp == NULL){
        printf("ERRO: Arquivo %s nao encontrado!\n", arquivo);
        return;
        
    } else{

    while(fscanf(fp, "%50s", palavra) != EOF){

        int len = strlen(palavra);

        for(int i=0; i<len; i++){
                palavra[i] = tolower(palavra[i]);

                if ('a' > palavra[i] || palavra[i] > 'z'){
                    for(int j=i; j<len; j++){
                        palavra[j] = palavra[j+1];
                    }
                    len--;
                    i--;
                }
            }
        insereHashTablePalavras(palavra, idDoc, vetPesos, tabela, tamTabela);
            
        }
    }
    fclose(fp);
}


void escrevePalavrasDocsPatricia(tipoArvore *t, listaEncadDocs listaDocs){
    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (aux->doc.documentoLido == naoLido){
            lerPalavrasInserePatricia(aux->doc.nomeDoc, aux->doc.idDoc, t);
            printf("Inseriu no TAD patricia - As palavras do arquivo %s\n", aux->doc.nomeDoc);
        }
        aux = aux->prox;
    }
}

void lerPalavrasInserePatricia(char* arquivo, int idDoc, tipoArvore *t){
    FILE *fp;
    char palavra[50];
    char * path = strcat("textos/", arquivo);
    fp = fopen(path, "r");
    
    if(fp == NULL){
        printf("ERRO: Arquivo %s nao encontrado!\n", arquivo);
        return;
        
    } else{

    while(fscanf(fp, "%50s", palavra) != EOF){

        int len = strlen(palavra);

        for(int i=0; i<len; i++){
                palavra[i] = tolower(palavra[i]);

                if ('a' > palavra[i] || palavra[i] > 'z'){
                    for(int j=i; j<len; j++){
                        palavra[j] = palavra[j+1];
                    }
                    len--;
                    i--;
                }
            }
        *t = inserePatricia(palavra, idDoc, t);
        }
    }
    fclose(fp);
}


void lerArquivos(char* arquivo, listaEncadDocs* listaDocs){
    FILE *fp, *fp2;
    int numArq;
    char nomeArquivo[100];
    char * path = strcat("textos/", arquivo);
    fp = fopen(path, "r");
    
    if (fp == NULL){
      printf("ERRO: Arquivo *%s* nao encontrado!\n", arquivo);
      return;

    } else{
      fscanf(fp, "%d", &numArq);

      for(int i=0; i<numArq; i++){
        fscanf(fp, "%100s", nomeArquivo);
        fp2 = fopen(nomeArquivo, "r");

        if (fp2 == NULL){
            printf("ERRO: Arquivo *%s* nao encontrado!\n", nomeArquivo);

        } else{
            insereDoc(nomeArquivo, listaDocs);
            
        }
        fclose(fp2);

        }
    }
    fclose(fp);
    
}

void atualizaListaLidos(listaEncadDocs listaDocs){
    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (aux->doc.documentoLido == naoLido){
            aux->doc.documentoLido = lido;
            printf("Status do dacounto *%s* mudou para 'lido'\n", aux->doc.nomeDoc);

        } 
        aux = aux->prox;
    }
}

/*------------------------------------------------------------------- Pesquisa Hash -------------------------------------------------------------------*/

void pesquisaTFIDFHash(tipoListaPalavras listaPalavrasPesquisa, listaEncadDocs listaDocs, hashTablePalavras tabela, tipoVetPesos vetPesos, int tamTabela){
    //variaveis para os loops
    int N = listaDocs.qtdeDocs;
    int ni;
    int i = 0;
    tipoDocRelevancia* relevancias = (tipoDocRelevancia*) malloc(N*sizeof(tipoDocRelevancia));
    tipoDocRelevancia* docRelevTemp = (tipoDocRelevancia*) malloc(sizeof(tipoDocRelevancia));

    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){ //Calula a relevancia para cada documento
        
        ni = palavrasUnicasDoc(tabela, tamTabela, aux->doc.idDoc);
        docRelevTemp->relevancia = somatorioPesos(listaPalavrasPesquisa, vetPesos, tabela, tamTabela, aux->doc.idDoc, N)/ni;
        docRelevTemp->doc.idDoc = aux->doc.idDoc;
        strcpy(docRelevTemp->doc.nomeDoc, aux->doc.nomeDoc);
        
        aux = aux->prox;

        relevancias[i] = *docRelevTemp;
        i++;

    }
    selecaoOrdena(relevancias, N-1);
    
    for (int j = 0; j < N; j++){
        printf("Doc: %-3d (%s) Relevancia: %lf\n", relevancias[j].doc.idDoc, relevancias[j].doc.nomeDoc, relevancias[j].relevancia);

    }
    free(relevancias);
    free(docRelevTemp);
}

double calculaPesoDeTJemi(tipoPalavra palavra, int idDoc, int N){
    int dj = contaRepsPalavra(palavra, &dj);
    int fj = getQtdePalavra(palavra, idDoc);
    return (fj * ((log2(N))/dj));
}

double somatorioPesos(tipoListaPalavras listaPalavrasPesquisa, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela, int idDoc, int N){
    apontadorCelPalavra aux;
    apontadorCelPalavra celPesq;

    double totalPesos = 0;

    aux = listaPalavrasPesquisa.primeiro->prox;
    
    while (aux != NULL){
        celPesq = pesquisaPalavra(aux->palavra.valPalavra, 1, vetPesos, tabela, tamTabela);

        if (celPesq == NULL){
            printf("Palavra *%s* nao encontrada\n", aux->palavra.valPalavra);
            return 0;
            
        } else{
            totalPesos += calculaPesoDeTJemi(celPesq->prox->palavra, idDoc, N);

        }
        aux = aux->prox;
    }
    return totalPesos;
}

void insercaoOrdena(tipoDocRelevancia *relevancias, int tam){
   int i, j = 0;
   tipoDocRelevancia x;
 
   for (i=2; i<=tam; i++){
       x = relevancias[i];
       j=i-1;
       relevancias[0] = x;
       while (x.relevancia > relevancias[j].relevancia){
           relevancias[j+1] = relevancias[j];
           j--;
       }
   }
   relevancias[j+1] = x;
}

void pesquisaTFIDFPatricia(tipoListaPalavras listaPalavrasPesquisa, listaEncadDocs listaDocs, tipoArvore t){
    //variaveis para os loops
    int N = listaDocs.qtdeDocs;
    int ni;
    int i = 0;
    tipoDocRelevancia* relevancias = (tipoDocRelevancia*) malloc(N*sizeof(tipoDocRelevancia));
    tipoDocRelevancia* docRelevTemp = (tipoDocRelevancia*) malloc(sizeof(tipoDocRelevancia));

    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){ //Calula a relevancia para cada documento
        
        ni = quantasPalavrasPatricia(t, aux->doc.idDoc);
        docRelevTemp->relevancia = somatorioPesosPatricia(listaPalavrasPesquisa, t, aux->doc.idDoc, N)/ni;
        docRelevTemp->doc.idDoc = aux->doc.idDoc;
        strcpy(docRelevTemp->doc.nomeDoc, aux->doc.nomeDoc);
        
        aux = aux->prox;

        relevancias[i] = *docRelevTemp;
        i++;

    }
    selecaoOrdena(relevancias, N-1);
    
    for (int j = 0; j < N; j++){
        printf("Doc: %-3d (%s) Relevancia: %lf\n", relevancias[j].doc.idDoc, relevancias[j].doc.nomeDoc, relevancias[j].relevancia);

    }
    free(relevancias);
    free(docRelevTemp);
}

double somatorioPesosPatricia(tipoListaPalavras listaPalavrasPesquisa, tipoArvore t, int idDoc, int N){
    apontadorCelPalavra aux;
    tipoPalavra* celPesq;

    double totalPesos = 0;

    aux = listaPalavrasPesquisa.primeiro->prox;
    
    while (aux != NULL){
        celPesq = pesquisaPatricia(aux->palavra.valPalavra, t);

        if (celPesq == NULL){
            printf("Palavra *%s* nao encontrada\n", aux->palavra.valPalavra);
            return 0;
            
        } else{
            totalPesos += calculaPesoDeTJemi(*celPesq, idDoc, N);

        }
        aux = aux->prox;
    }
    return totalPesos;
}