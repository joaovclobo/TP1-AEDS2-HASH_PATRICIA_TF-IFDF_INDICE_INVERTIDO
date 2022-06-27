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
        hashTablePalavras.h
        Descrição do arquivo: Cabeçalho do TAD hash table de palavras
        Ultima modificação: 27/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "patricia.h"

typedef unsigned int tipoVetPesos[tamMaxPalavra];

typedef unsigned int tipoIndice;

typedef struct tipoCelulaPalavra *apontadorCelPalavra;

typedef struct tipoCelulaPalavra{
    tipoPalavra palavra;
    apontadorCelPalavra prox;
} tipoCelulaPalavra;

typedef struct tipoListaPalavras{
    tipoCelulaPalavra *primeiro, *ultimo;
} tipoListaPalavras;

typedef tipoListaPalavras* hashTablePalavras;


/*------------------------------------------------------------------- Funções da hash table -------------------------------------------------------------------*/

void flPalavrasVazia(tipoListaPalavras *listaPalvras);  

short listaPalavrasVazia(tipoListaPalavras listaPalvras);

void geraVetPesos(tipoVetPesos vetPesos);

tipoIndice hashPalavra(char* valPalavra, tipoVetPesos vetPesos, int tamTabela);

void criaHashTablePalavras(hashTablePalavras tabela, int tamTabela);

void insereHashTablePalavrasI(char* valPalavra, int idDoc, tipoListaPalavras *listaPalvras);

void insereHashTablePalavras(char* valPalavra, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela);

apontadorCelPalavra pesquisaPalavra(char* valPalavra, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela);

void imprimeHashTable(hashTablePalavras tabela, int tamTabela);

int palavrasUnicasDoc(hashTablePalavras tabela, int tamTabela, int idDoc);

int palavrasUnicasDocI(tipoListaPalavras listaPalvras, int idDoc);

/*------------------------------------------------------------------- Funções exclusivas para lista encadeada -------------------------------------------------------------------*/

void insereListaPalavras(tipoPalavra palavra, tipoListaPalavras *listaPalvras);

void insereListaOrdenadaTemp(tipoListaPalavras listaPalvrasHash, tipoListaPalavras* listaOrdenadaTemp);

void imprimeListaPalavras(tipoListaPalavras listaPalvras);

void imprimeListaPalavrasValores(tipoListaPalavras listaPalvras);
