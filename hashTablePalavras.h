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
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"

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

void flPalavrasVazia(tipoListaPalavras *listaPalvras);  

short listaPalavrasVazia(tipoListaPalavras listaPalvras);

void geraVetPesos(tipoVetPesos p);                                      //Mudar nome do vetor de pesos

tipoIndice hashPalavra(char* valPalavra, tipoVetPesos p, int tamTabela);

void criaHashTablePalavras(hashTablePalavras tabela, int tamTabela);

void insereHashTablePalavrasI(char* valPalavra, int idDoc, tipoListaPalavras *listaPalvras);

void insereHashTablePalavras(char* valPalavra, int idDoc, tipoVetPesos p, hashTablePalavras tabela, int tamTabela);

void insereListaPalavras(tipoPalavra palavra, tipoListaPalavras *listaPalvras);

void insereListaOrdenadaTemp(tipoListaPalavras listaPalvrasHash, tipoListaPalavras* listaOrdenadaTemp);

apontadorCelPalavra pesquisaPalavra(char* valPalavra, int idDoc, tipoVetPesos p, hashTablePalavras tabela, int tamTabela);

void imprimeListaPalavras(tipoListaPalavras listaPalvras);

void imprimeHashTable(hashTablePalavras tabela, int tamTabela);

void lerPalavra(char *p, int Tam);
