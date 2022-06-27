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
    } nInterno;
    tipoPalavra palavra;
  } no;
} tipoNo;

tipoArvore insere(char* valPalavra, int idDoc, tipoArvore *t);
tipoPalavra pesquisa(char* palavra, tipoArvore t);
int quantasPalavras(tipoArvore t, int idDoc);