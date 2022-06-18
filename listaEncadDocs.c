#include "listaEncadDocs.h"

void flDocsVazia(tipoListaDocs *listaDocs){
    listaDocs->primeiro = (apontadorDoc) malloc(sizeof(tipoCelulaDoc));
    
    listaDocs->qtdeDocs = 0;
    listaDocs->ultimo = listaDocs->primeiro;
    listaDocs->primeiro->prox = NULL;
}

int listaDocsVazia(tipoListaDocs listaDocs){
    return (listaDocs.primeiro == listaDocs.ultimo);
}

void insereDocI(tipoDoc doc, tipoListaDocs *listaDocs){
    listaDocs->ultimo->prox = (apontadorDoc) malloc(sizeof(tipoCelulaDoc));

    listaDocs->ultimo = listaDocs->ultimo->prox;
    listaDocs->ultimo->doc = doc;
    listaDocs->ultimo->prox = NULL;
}

apontadorDoc insereDoc(char *nomeDoc, tipoListaDocs *listaDocs){
    tipoDoc* doc = (tipoDoc*) malloc(sizeof(tipoDoc));

    listaDocs->qtdeDocs++;
    doc->idDoc = listaDocs->qtdeDocs;
    strcpy(doc->nomeDoc, nomeDoc);

    insereDocI(*doc, listaDocs);
}

void imprimeListaDocs(tipoListaDocs listaDocs){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;
    while (aux != NULL)
    {
        printf("Nome doc: %s - idDoc: %d\n", aux->doc.nomeDoc, aux->doc.idDoc);
        aux = aux->prox;
    }
}
