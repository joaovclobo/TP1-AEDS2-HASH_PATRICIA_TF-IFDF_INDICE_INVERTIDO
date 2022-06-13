//VEM CABEÇALHO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamMaxPalavra 50

typedef struct tipoPar{
    int qtde;
    int idDoc;
}tipoPar;

typedef struct tipoCelula *tipoApontadorPar;

typedef struct tipoCelula{
    tipoPar par;
    tipoApontadorPar prox;
} tipoCelula;

typedef struct listaEncadPares{
    tipoApontadorPar primeiro, ultimo;
}listaEncadPares;

void imprimePar(tipoPar par);

void flParesVazia(listaEncadPares *lista);

int listaParesVazia(listaEncadPares lista);

void insereListaPares(tipoPar par, listaEncadPares *lista);

void retiraListaPares(tipoApontadorPar p, listaEncadPares *lista, tipoPar *par);

void imprimeListaPares(listaEncadPares lista);

void aumentaQtde(listaEncadPares lista ,int idDoc);
