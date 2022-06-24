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
        listaEncadDocs.c
        Descrição do arquivo: Arquivo de codigo do TAD listaEncadDocs
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadDocs.h"

void flDocsVazia(listaEncadDocs *listaDocs){
    listaDocs->primeiro = (apontadorCellDoc) malloc(sizeof(tipoCelulaDoc));
    
    listaDocs->qtdeDocs = 0;
    listaDocs->ultimo = listaDocs->primeiro;
    listaDocs->primeiro->prox = NULL;
}

int listaDocsVazia(listaEncadDocs listaDocs){
    return (listaDocs.primeiro == listaDocs.ultimo);
}

void insereDocI(tipoDoc doc, listaEncadDocs *listaDocs){
    listaDocs->ultimo->prox = (apontadorCellDoc) malloc(sizeof(tipoCelulaDoc));

    listaDocs->ultimo = listaDocs->ultimo->prox;
    listaDocs->ultimo->doc = doc;
    listaDocs->ultimo->prox = NULL;
}

void insereDoc(char *nomeDoc, listaEncadDocs *listaDocs){
    if (buscaNomeDoc(nomeDoc, *listaDocs)){
        printf("ERRO: Arquivo *%s* ja inserido\n", nomeDoc);

    }else{
        tipoDoc* doc = (tipoDoc*) malloc(sizeof(tipoDoc));

        listaDocs->qtdeDocs++;
        doc->idDoc = listaDocs->qtdeDocs;
        strcpy(doc->nomeDoc, nomeDoc);
        doc->documentoLido = naoLido;

        insereDocI(*doc, listaDocs);

    }
}

void imprimeListaDocs(listaEncadDocs listaDocs){
    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    if (listaDocsVazia(listaDocs)){
        printf("Nenhum documento foi inserido! - Lista vazia!\n");
    } else{
        printf("\nDocumentos inseridos:\n\n");
    
        while (aux != NULL){
            if (aux->doc.documentoLido == lido){
                printf("Nome documento: %-20s | idDoc: %-3d | docLido: Sim\n", aux->doc.nomeDoc, aux->doc.idDoc);

            } else{
                printf("Nome documento: %-20s | idDoc: %-3d | docLido: Nao\n", aux->doc.nomeDoc, aux->doc.idDoc);

            }
            aux = aux->prox;

        }
    }
}

int buscaNomeDoc(char *nomeDoc, listaEncadDocs listaDocs){
    apontadorCellDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (!strcmp(aux->doc.nomeDoc, nomeDoc)){
            return 1;
        }else{
            aux = aux->prox;
        }
    }
    return 0;
}
