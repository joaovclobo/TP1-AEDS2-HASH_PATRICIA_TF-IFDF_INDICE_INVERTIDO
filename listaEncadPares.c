//VEM CABEÇALHO

#include "listaEncadPares.h"

void imprimePar(tipoPar par){
    printf("<%d, %d>\n", par.qtde, par.idDoc);
}

void flParesVazia(listaEncadPares *listaPares){
    listaPares->primeiro = (tipoApontadorPar) malloc(sizeof(tipoCelula));
    listaPares->ultimo = listaPares->primeiro;
    listaPares->primeiro->prox = NULL;
}

int listaParesVazia(listaEncadPares listaPares){
    return (listaPares.primeiro == listaPares.ultimo);
}

void insereListaPares(tipoPar par, listaEncadPares *listaPares){
    listaPares->ultimo->prox = (tipoApontadorPar)malloc(sizeof(tipoCelula));
    listaPares->ultimo = listaPares->ultimo->prox;
    listaPares->ultimo->par = par;
    listaPares->ultimo->prox = NULL;
}

void retiraListaPares(tipoApontadorPar p, listaEncadPares *listaPares, tipoPar *par){ /*  ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- */
    tipoApontadorPar q;
    if (listaParesVazia(*listaPares) || p == NULL || p->prox == NULL){
        printf(" Erro listaPares vazia ou posicao nao existe\n");
        return;
    }
    q = p->prox;
    *par = q->par;
    p->prox = q->prox;
    if (p->prox == NULL)
        listaPares->ultimo = p;
    free(q);
}

void imprimeListaPares(listaEncadPares listaPares){
    tipoApontadorPar aux;
    aux = listaPares.primeiro->prox;
    while (aux != NULL){
        imprimePar(aux->par);
        aux = aux->prox;
    }
}
