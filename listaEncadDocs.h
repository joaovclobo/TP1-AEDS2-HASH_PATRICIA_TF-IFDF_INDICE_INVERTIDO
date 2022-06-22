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
        listaEncadDocs.h
        Descrição do arquivo: Arquivo Cabeçalho do TAD listaEncadDocs
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashTablePalavras.h"

typedef enum docLido{
    lido,
    naoLido
}docLido;

typedef struct tipoDoc{
    char nomeDoc[50];
    int idDoc;
    docLido documentoLido;
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
