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
        Descrição do arquivo: Arquivo de código do TAD tipo palavra
        Ultima modificação: 15/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadPares.h"
#define tamMaxPalavra 50

typedef struct tipoPalavra{
    char valPalavra[tamMaxPalavra];
    listaEncadPares* listaPares;
}tipoPalavra;

/*---------------- Gets e sets ---------------- */

char* getValPalavra(tipoPalavra* palavra){
    return palavra->valPalavra;
}

// tipoPar* getPar(tipoPalavra* palavra, int idDoc){ //Avaliar necessidade 
//     return palavra->listaPares;
// }

listaEncadPares* getListaPares(tipoPalavra* palavra){
    return palavra->listaPares;
}


void setPalavra(tipoPalavra* palavra, char* valPalavra){
    strcpy(palavra->valPalavra, valPalavra);
} 

void setPar(tipoPalavra* palavra, tipoPar par){
    insereListaPares(par, palavra->listaPares);
}

void setListaPares(tipoPalavra* palavra, listaEncadPares *listaPares){
    palavra->listaPares = listaPares;
}

/*---------------- Funções auxiliares ---------------- */

void inicializaPalavra(tipoPalavra* palavra, char* valPalavra, int idDoc){
    listaEncadPares* listaPares = (listaEncadPares*) malloc(sizeof(listaEncadPares));

    flParesVazia(listaPares);
    setListaPares(palavra, listaPares);

    setPalavra(palavra, valPalavra);

    tipoPar* primPar = (tipoPar*) malloc(sizeof(tipoPar));

    inicializaPar(primPar, idDoc);
    setPar(palavra, *primPar);
} 

void aumentaQtdePar(tipoPalavra* palavra, int idDoc){
    aumentaQtde(*getListaPares(palavra), idDoc);
}  

int comparaPalavra(tipoPalavra palavra1, tipoPalavra palavra2){
    return !strcmp(getValPalavra(&palavra1), getValPalavra(&palavra2));
} 

void imprimePalavra(tipoPalavra palavra){
    printf("Palavra - %s | ", getValPalavra(&palavra));
    imprimeListaPares(*getListaPares(&palavra));
}

void insereNovoIdDoc(tipoPalavra* palavra, int idDoc){
    tipoPar* par = (tipoPar*) malloc(sizeof(tipoPar));

    inicializaPar(par, idDoc);
    insereListaPares(*par, getListaPares(palavra));
}
