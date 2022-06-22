#include "patricia.h"

short eExterno(tipoArvore p){
    /* Verifica se p^ e nodo externo */
    return (p->nt == Externo);
}

void insere(tipoPalavra k, tipoArvore *t){
    tipoArvore p;
    int i;
    if (*t == NULL) 
    return (criaNoExt(k));
    else {
        p = *t;
        while (!eExterno(p)){
            if (bit(p->no.NInterno.index, k) == 1)
                p = p->no.NInterno.Dir;
            else
                p = p->no.NInterno.Esq;
        }
        /* acha o primeiro bit diferente */
        i = 1;
        while ((i <= tamMaxPalavra) & (bit((int)i, k) == bit((int)i, p->no.palavra))) 
            i++;
        if (i > tamMaxPalavra){
            printf("Erro: chave ja esta na arvore\n");  return (*t);
        } 
        else
            return (insereEntre(k, t, i));
    }
}