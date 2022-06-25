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
        tipoPalavra.c
        Descrição do arquivo: Arquivo de código do TAD tipo palavra
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"

/*---------------- Gets e sets ---------------- */

char* getValPalavra(tipoPalavra* palavra){
    return palavra->valPalavra;
}

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
    printf("Palavra - %-15s | ", getValPalavra(&palavra));
    imprimeListaPares(*getListaPares(&palavra));
}

void insereNovoIdDoc(tipoPalavra* palavra, int idDoc){
    tipoPar* par = (tipoPar*) malloc(sizeof(tipoPar));

    inicializaPar(par, idDoc);
    insereListaPares(*par, getListaPares(palavra));
}

int contaRepsPalavra(tipoPalavra palavra, int* reps){
    if (contaQtdePares(*palavra.listaPares) > 0){
        return contaQtdePares(*palavra.listaPares);

    }else{
        printf("ERRO: Palavra nao essta em nenhum documento");
        return -1;
    }
}

int getQtdePalavra(tipoPalavra palavra, int idDoc){
    return getQtde(*palavra.listaPares, idDoc);
}

int palavraNoDocumento(tipoPalavra palavra, int idDoc){
    return buscaIdDoc(*palavra.listaPares, idDoc);
}
