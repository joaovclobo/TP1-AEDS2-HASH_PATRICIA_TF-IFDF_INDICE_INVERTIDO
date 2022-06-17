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
        Descrição do arquivo: Arquivo de código do TAD tipo lista encadeada de pares (qtde, idDoc)
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadPares.h"

void inicializaPar(tipoPar* par, int idDoc){
    par->idDoc = idDoc;
    par->qtde = 1;
}

void imprimePar(tipoPar par){
    printf("<%d, %d> | ", par.qtde, par.idDoc);
}

void flParesVazia(listaEncadPares *listaPares){
    listaPares->primeiro = (tipoApontadorPar) malloc(sizeof(tipoCelulaPar));
    listaPares->ultimo = listaPares->primeiro;
    listaPares->primeiro->prox = NULL;
}

int listaParesVazia(listaEncadPares listaPares){
    return (listaPares.primeiro == listaPares.ultimo);
}

void insereListaPares(tipoPar par, listaEncadPares *listaPares){        //Função adaptada para inserir ordenadamente

    tipoApontadorPar novaCelula, ant, atual = listaPares->primeiro->prox;
    novaCelula = (tipoApontadorPar)malloc(sizeof(tipoCelulaPar));
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
    printf("\n\n");

}

void aumentaQtde(listaEncadPares listaPares, int idDoc){
    tipoApontadorPar aux;

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

tipoPar* buscaPar(listaEncadPares listaPares, int idDoc){
    tipoApontadorPar aux;

    aux = listaPares.primeiro->prox;

    while (aux != NULL){
        if (aux->par.idDoc == idDoc) {
            return &(*aux).par;

        }else{
            aux = aux->prox;

        }

   }
    printf("idDoc nao encontrado: %d\n", idDoc);
}
