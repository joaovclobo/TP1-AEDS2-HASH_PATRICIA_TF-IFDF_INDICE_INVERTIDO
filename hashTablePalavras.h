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
#define M 7
#define TAMALFABETO 256

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


typedef tipoListaPalavras TipoDicionario[M];        //Ver se da pra variar o "M"

void flPalavrasVazia(tipoListaPalavras *listaPalvras);  

short listaPalavrasVazia(tipoListaPalavras listaPalvras);

void geraVetPesos(tipoVetPesos p);                                      //Mudar nome do vetor de pesos

tipoIndice hashPalavra(char* valPalavra, tipoVetPesos p);

void criaHashTablePalavras(TipoDicionario T);

void insereHashTablePalavrasI(char* valPalavra, int idDoc, tipoListaPalavras *listaPalvras);

void insereHashTablePalavras(char* valPalavra, int idDoc, tipoVetPesos p, TipoDicionario T);

void insereListaPalavras(tipoPalavra palavra, tipoListaPalavras *listaPalvras);

apontadorCelPalavra pesquisaPalavra(char* valPalavra, int idDoc, tipoVetPesos p, TipoDicionario T);

void imprimeListaPalavras(tipoListaPalavras listaPalvras);

void imprimeHashTable(TipoDicionario tabela);

void lerPalavra(char *p, int Tam);
