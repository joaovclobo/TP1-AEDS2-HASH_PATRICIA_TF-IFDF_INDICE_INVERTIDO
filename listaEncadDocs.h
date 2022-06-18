#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void escrevePalavrasDocs(listaEncadDocs listaDocs);

void lerPalavras(char* arquivo);

void lerArquivos(char* arquivo, listaEncadDocs* listaDocs);
