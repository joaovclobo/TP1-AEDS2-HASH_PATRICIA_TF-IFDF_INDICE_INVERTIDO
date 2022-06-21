#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashTablePalavras.h"

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
} listaEncadDocs;

void flDocsVazia(listaEncadDocs *listaDocs);

int listaDocsVazia(listaEncadDocs listaDocs);

void insereDocI(tipoDoc doc, listaEncadDocs *listaDocs);

void insereDoc(char *nomeDoc, listaEncadDocs *listaDocs);

void imprimeListaDocs(listaEncadDocs listaDocs);

int buscaNomeDoc(char *nomeDoc, listaEncadDocs listaDocs);

void escrevePalavrasDocs(tipoVetPesos p, TipoDicionario T, listaEncadDocs listaDocs);

void lerPalavras(char* arquivo, int idDoc, tipoVetPesos p, TipoDicionario T);

void lerArquivos(char* arquivo, listaEncadDocs* listaDocs);
