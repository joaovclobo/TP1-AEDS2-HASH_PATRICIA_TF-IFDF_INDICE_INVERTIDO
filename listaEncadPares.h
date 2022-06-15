/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

    Universidade Federal De Viçosa - Campus Florestal
    Trabalho prático 1 de Algorítimos e estrutura de dados
    
    Professora responsável: 
        Glaucia Braga e Silva
        
    Integrantes do Gupo:
        Caio Oliveira Almeida - 4237
        Guilherme Augusto Schwann Wilke - 4685
        João Vitor Chagas Lobo - 4693

    Arquivo: 
        anotacoes-branch-Joao.txt
        Descrição do arquivo: Cabeçalho do TAD tipo lista encadeada de pares (qtde, idDoc)
        Ultima modificação: 14/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

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

void inicializaPar(tipoPar* par, int idDoc);

void imprimePar(tipoPar par);

void flParesVazia(listaEncadPares *listaPares);

int listaParesVazia(listaEncadPares listaPares);

void insereListaPares(tipoPar par, listaEncadPares *listaPares);

void retiraListaPares(tipoApontadorPar p, listaEncadPares *listaPares, tipoPar *par);

void imprimeListaPares(listaEncadPares listaPares);

void aumentaQtde(listaEncadPares listaPares ,int idDoc);
