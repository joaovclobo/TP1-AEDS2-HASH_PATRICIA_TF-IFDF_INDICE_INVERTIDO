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

void encontraPar(tipoApontadorPar vendoPar, tipoPar* res){
    if (vendoPar->par.idDoc == res->idDoc){
        res->qtde = vendoPar->par.qtde;
    }
    if (vendoPar->prox == NULL){
        res->qtde = 0;
    }
    encontraPar(vendoPar->prox, res);
}

tipoPar getPar(tipoPalavra* palavra, int idDoc){ //Avaliar necessidade
    tipoApontadorPar vendoPar = palavra->listaPares->primeiro;
    tipoPar res;
    res.idDoc = idDoc;
    encontraPar(vendoPar, &res);
    return res;
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

void inicializaPalavra(tipoPalavra* palavra, char* valPalavra, int idDoc){
    listaEncadPares* listaPares = (listaEncadPares*) malloc(sizeof(listaEncadPares));
    flParesVazia(listaPares);
    setListaPares(palavra, listaPares);
    setPalavra(palavra, valPalavra);
    tipoPar primPar;
    inicializaPar(&primPar, idDoc);
    setPar(palavra, primPar);
} 

void aumentaQtdePar(tipoPalavra* palavra, int idDoc){
    aumentaQtde(*palavra->listaPares, idDoc);
}  

int comparaPalavra(tipoPalavra palavra1, tipoPalavra palavra2){
    return !strcmp(palavra1.valPalavra, palavra2.valPalavra);
} 
