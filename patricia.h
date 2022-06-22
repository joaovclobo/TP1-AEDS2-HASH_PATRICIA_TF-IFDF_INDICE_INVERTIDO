#include <stdio.h>
#include <stdlib.h>
#include "tipoPalavra.h"

typedef enum {
  Interno, Externo
} tipoLoc;

typedef struct tipoNo* tipoArvore; 
typedef struct tipoNo {
  tipoLoc nt;
  union {
    struct {
      char index;
      tipoArvore Esq, Dir;
    } NInterno ;
    tipoPalavra palavra;
  } no;
} tipoNo;

void insere(tipoPalavra k, tipoArvore *t);