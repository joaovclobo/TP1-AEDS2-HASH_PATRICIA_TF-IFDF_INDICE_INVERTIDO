#include "patricia.h"

char letra(tipoPalavra k, int i){
    return k.valPalavra[i-1];
}

short eExterno(tipoArvore p){
    /* Verifica se p^ e nodo externo */
    return (p->nt == externo);
}

tipoArvore criaNoExt(tipoPalavra k){
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoNo));
    p->nt = externo;
    p->no.palavra = k;
    return p;
}  

tipoArvore insereEntre(tipoPalavra k, tipoArvore *t, int i)
{ tipoArvore p;
  if (eExterno(*t) || i < (*t)->no.nInterno.index){
    /* cria um novo no externo */
    p = criaNoExt(k);
    if (letra(k, i) != (*t)->no.nInterno.indexLetra) 
        return (criaNoInt(i, t, &p));
    else
        return (criaNoInt(i, &p, t));
  } 
  else{
    if (letra(k, (*t)->no.nInterno.index) != (*t)->no.nInterno.indexLetra)
        (*t)->no.nInterno.dir = insereEntre(k,&(*t)->no.nInterno.dir,i);
    else
        (*t)->no.nInterno.esq = insereEntre(k,&(*t)->no.nInterno.esq,i);
    return (*t);
  }
}

tipoArvore insere(tipoPalavra k, tipoArvore *t){
    tipoArvore p;
    int i;
    if (*t == NULL) 
    return (criaNoExt(k));
    else {
        p = *t;
        while (!eExterno(p)){
            if (letra(k, p->no.nInterno.index) == p->no.nInterno.indexLetra)
                p = p->no.nInterno.esq;
            else
                p = p->no.nInterno.dir;
        }
        /* acha o primeiro bit diferente */
        i = 1;
    while ((i <= tamMaxPalavra) & (letra(k, i) == letra(p->no.palavra, i))) 
            i++;
        if (i > tamMaxPalavra){
            printf("Erro: chave ja esta na arvore\n"); // mudar para acrescentar quantidade de iddoc
            return (*t);
        } 
        else
            return (insereEntre(k, t, i));
    }
}