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
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"
// #include <sys/time.h>
#define M 7
// #define N 7
#define TAMALFABETO 256

typedef char TipoChave[tamMaxPalavra];          //tirar
typedef unsigned int tipoVetPesos[tamMaxPalavra];

typedef struct TipoItem{          //tirar
    /* outros componentes */
    TipoChave Chave;
} TipoItem;

typedef unsigned int tipoIndice;
typedef struct tipoCelulaPalavra *apontadorCelPalavra;

typedef struct tipoCelulaPalavra{
    TipoItem Item;          //tirar
    apontadorCelPalavra prox;
} tipoCelulaPalavra;

typedef struct tipoListaPalavras{
    tipoCelulaPalavra *primeiro, *ultimo;
} tipoListaPalavras;


typedef tipoListaPalavras TipoDicionario[M];        //Ver se da pra variar o "M"
TipoDicionario Tabela;              //Avaliar a necessidade
TipoItem Elemento;                  //Avaliar a necessidade
tipoVetPesos p;                     //Avaliar a necessidade
apontadorCelPalavra i;              //Avaliar a necessidade


void flPalavrasVazia(tipoListaPalavras *listaPalvras);

short listaPalavrasVazia(tipoListaPalavras listaPalvras);

void insereListaPalavrasI(TipoItem x, tipoListaPalavras *listaPalvras);

void retiraListaPalavrasI(apontadorCelPalavra p, tipoListaPalavras *listaPalvras, TipoItem *Item);

void geraVetPesos(tipoVetPesos p);

tipoIndice hashPalavra(TipoChave Chave, tipoVetPesos p);

void criaHashTablePalavra(TipoDicionario T);

apontadorCelPalavra pesquisaPalavra(TipoChave Ch, tipoVetPesos p, TipoDicionario T);

void insereListaPalavra(TipoItem x, tipoVetPesos p, TipoDicionario T);

void retiraListaPalavra(TipoItem x, tipoVetPesos p, TipoDicionario T);

void imprimeListaPalavrasI(tipoListaPalavras listaPalvras);

void imprimeListaPalavras(TipoDicionario Tabela);

void LerPalavra(char *p, int Tam);
