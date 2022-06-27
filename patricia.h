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
        patricia.h
        Descrição do arquivo: Cabeçalho do TAD árvore patricia;
        Ultima modificação: 27/06 - Por: Guilherme Augusto Schwann Wilke

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipoPalavra.h"

typedef enum {
  interno, externo
} tipoLoc;

typedef struct tipoNo* tipoArvore; 
typedef struct tipoNo {
  tipoLoc nt;
  union {
    struct {
      int index;
      char indexLetra;
      tipoArvore esq, dir;
    } nInterno ;
    tipoPalavra palavra;
  } no;
} tipoNo;

tipoArvore inserePatricia(char* valPalavra, int idDoc, tipoArvore *t);

tipoPalavra* pesquisaPatricia(char palavra[50], tipoArvore t);

int quantasPalavrasPatricia(tipoArvore t, int idDoc);

void imprimePatricia(tipoArvore t);