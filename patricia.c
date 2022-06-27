#include "patricia.h"

char letra(tipoPalavra k, int i){
    if (strlen(k.valPalavra) < i)
        return "0";
    return k.valPalavra[i-1];
}

short eExterno(tipoArvore p){
    /* Verifica se p^ e nodo externo */
    return (p->nt == externo);
}

tipoArvore CriaNoInt(int i, tipoArvore *esq,  tipoArvore *dir){
    tipoArvore p;
    p = (tipoArvore)malloc(sizeof(tipoNo));
    p->nt = interno;
    p->no.nInterno.esq = *esq;
    p->no.nInterno.dir = *dir;
    p->no.nInterno.index = i;
    return p;
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

tipoArvore inserePatricia(char* valPalavra, int idDoc, tipoArvore *t){
    tipoPalavra palavra;
    inicializaPalavra(&palavra, valPalavra, idDoc);
    tipoArvore p;
    int i;
    if (*t == NULL) 
        return (criaNoExt(palavra));
    else {
        p = *t;
        while (!eExterno(p)){
            if (letra(palavra, p->no.nInterno.index) == p->no.nInterno.indexLetra)
                p = p->no.nInterno.esq;
            else
                p = p->no.nInterno.dir;
        }
        /* acha o primeiro bit diferente */
        i = 1;
        while ((i <= tamMaxPalavra) & (letra(palavra, i) == letra(p->no.palavra, i))) 
            i++;
        if (i > tamMaxPalavra){
            aumentaQtdePar(&(*t)->no.palavra, idDoc);
            return (*t);
        } 
        else
            return (insereEntre(palavra, t, i));
    }
}


tipoPalavra pesquisaPatricia(char* palavra, tipoArvore t){
    if (eExterno(t)){
        if (palavra == t->no.palavra.valPalavra) 
            return t->no.palavra;
        else printf("Elemento nao encontrado\n");
    return;
    }
    if (palavra[t->no.nInterno.index] == t->no.nInterno.indexLetra) 
        pesquisaPatricia(palavra, t->no.nInterno.esq);
    else
        pesquisaPatricia(palavra, t->no.nInterno.dir);
}

int quantasPalavrasPatricia(tipoArvore t, int idDoc){
    int num;
    if (eExterno(t))
        return buscaIdDoc(*t->no.palavra.listaPares, idDoc);
    num += quantasPalavrasPatricia(t->no.nInterno.esq, idDoc);
    num += quantasPalavrasPatricia(t->no.nInterno.dir, idDoc);
    return num;
}