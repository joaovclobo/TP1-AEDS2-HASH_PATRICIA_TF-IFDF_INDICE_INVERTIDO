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

void insereListaPares(tipoPar par, listaEncadPares *listaPares){        //Função adaptada para inserir ordenadamente

    tipoApontadorPar novaCelula, ant, atual = listaPares->primeiro->prox;
    novaCelula = (tipoApontadorPar)malloc(sizeof(tipoCelula));
    novaCelula->par = par;
    
    if (listaParesVazia(*listaPares)){
        novaCelula->prox = NULL;
        listaPares->primeiro->prox = novaCelula;
        listaPares->ultimo = novaCelula;
        printf("inseriu lista vazia\n");

    } else{

        while (atual != NULL && atual->par.idDoc < par.idDoc){
            ant = atual;
            atual = atual->prox;
        }

        if (atual == listaPares->primeiro->prox){
            novaCelula->prox = listaPares->primeiro->prox;
            listaPares->primeiro->prox = novaCelula;
        } else{
            novaCelula->prox = ant->prox;
            ant->prox = novaCelula;
        }
    }
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
