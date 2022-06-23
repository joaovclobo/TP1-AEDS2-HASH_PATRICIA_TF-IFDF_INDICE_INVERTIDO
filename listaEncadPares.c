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
        listaEncadPares.c
        Descrição do arquivo: Arquivo de código do TAD tipo lista encadeada de pares (qtde, idDoc)
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadPares.h"

void inicializaPar(tipoPar* par, int idDoc){
    par->idDoc = idDoc;
    par->qtde = 1;
}

void imprimePar(tipoPar par){
    printf("<%3d, %3d> | ", par.qtde, par.idDoc);
}

void flParesVazia(listaEncadPares *listaPares){
    listaPares->primeiro = (apontadorCelPar) malloc(sizeof(tipoCelulaPar));

    listaPares->ultimo = listaPares->primeiro;
    listaPares->primeiro->prox = NULL;
}

int listaParesVazia(listaEncadPares listaPares){
    return (listaPares.primeiro == listaPares.ultimo);
}

void insereListaPares(tipoPar par, listaEncadPares *listaPares){        //Função adaptada para inserir ordenadamente

    apontadorCelPar novaCelula, ant, atual = listaPares->primeiro->prox;
    novaCelula = (apontadorCelPar) malloc(sizeof(tipoCelulaPar));
    novaCelula->par = par;
    
    if (listaParesVazia(*listaPares)){
        novaCelula->prox = NULL;
        listaPares->primeiro->prox = novaCelula;
        listaPares->ultimo = novaCelula;

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

void imprimeListaPares(listaEncadPares listaPares){
    apontadorCelPar aux;

    aux = listaPares.primeiro->prox;

    while (aux != NULL){
        imprimePar(aux->par);
        aux = aux->prox;

    }
    printf("\n");

}

void aumentaQtde(listaEncadPares listaPares, int idDoc){
    apontadorCelPar aux;

    aux = listaPares.primeiro->prox;

    while (aux != NULL){
        if (aux->par.idDoc == idDoc){
            aux->par.qtde++;
            return;

        } else{
            aux = aux->prox;

        }

    }
    printf("idDoc nao encontrado: %d\n", idDoc);
}

int buscaIdDoc(listaEncadPares listaPares, int idDoc){
    apontadorCelPar aux;

    aux = listaPares.primeiro->prox;

    while (aux != NULL){
        if (aux->par.idDoc == idDoc) {
            return 1;

        }else{
            aux = aux->prox;

        }

   }
    return 0;
}
