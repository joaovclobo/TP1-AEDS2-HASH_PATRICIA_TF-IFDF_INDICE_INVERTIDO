#include "listaEncadPares.h"
#define tamMaxPalavra 50

typedef struct tipoPalavra{
    char valPalavra[tamMaxPalavra];
    listaEncadPares* listaPares;
}tipoPalavra;

/*---------------- Gets e sets ---------------- */

char* getPalavra(tipoPalavra* palavra){
    return palavra->valPalavra;
}

tipoPar* getPar(tipoPalavra* palavra, int idDoc){ //Avaliar necessidade 
    return palavra->listaPares;
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

void setListaPares(tipoPalavra* palavra, listaEncadPares* listapares){
    palavra->listaPares = listapares;
}

/*---------------- Funções auxiliares ---------------- */

void inicialzaPalavra(tipoPalavra* palavra, char* valPalavra, tipoPar primPar){
    listaEncadPares* listaPares = (listaEncadPares*) malloc(sizeof(listaEncadPares));
    flParesVazia(listaPares);
    setListaPares(palavra, listaPares);
    setPalavra(palavra, valPalavra);
    setPar(palavra, primPar);
} 

void aumentaQtdePar(tipoPalavra* palavra, int idDoc){
    aumentaQtde(*palavra->listaPares, idDoc);
}  

int comparaPalavra(tipoPalavra palavra1, tipoPalavra palavra2){
    return !strcmp(palavra1.valPalavra, palavra2.valPalavra);
} 
