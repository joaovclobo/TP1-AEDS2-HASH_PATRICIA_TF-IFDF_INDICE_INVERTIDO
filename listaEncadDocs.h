#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct tipoDoc{
    char nomeDoc[50];
    int idDoc;
} tipoDoc;

typedef struct tipoCelulaDoc *apontadorDoc;

typedef struct tipoCelulaDoc{
    tipoDoc doc;
    apontadorDoc prox;
} tipoCelulaDoc;

typedef struct{
    apontadorDoc primeiro, ultimo;
    int qtdeDocs;
} tipoListaDocs;


void flDocsVazia(tipoListaDocs *listaDocs);

int listaDocsVazia(tipoListaDocs listaDocs);

void insereDocI(tipoDoc doc, tipoListaDocs *listaDocs);

apontadorDoc insereDoc(char *nomeDoc, tipoListaDocs *listaDocs);

void imprimeListaDocs(tipoListaDocs listaDocs);
