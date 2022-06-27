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
#include <math.h>

#include "hashTablePalavras.h"
#include "patricia.h"

typedef enum docLido{
    lido,
    naoLido
}docLido;

typedef struct tipoDoc{
    char nomeDoc[50];
    int idDoc;
    docLido documentoLido;
} tipoDoc;

typedef struct tipoCelulaDoc *apontadorCellDoc;

typedef struct tipoCelulaDoc{
    tipoDoc doc;
    apontadorCellDoc prox;
} tipoCelulaDoc;

typedef struct{
    apontadorCellDoc primeiro, ultimo;
    int qtdeDocs;
} listaEncadDocs;

void flDocsVazia(listaEncadDocs *listaDocs);

int listaDocsVazia(listaEncadDocs listaDocs);

void insereDocI(tipoDoc doc, listaEncadDocs *listaDocs);

void insereDoc(char *nomeDoc, listaEncadDocs *listaDocs);

void imprimeListaDocs(listaEncadDocs listaDocs);

int buscaNomeDoc(char *nomeDoc, listaEncadDocs listaDocs);