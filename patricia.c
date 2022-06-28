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
        patricia.c
        Descrição do arquivo: Arquivo de código do TAD árvore patricia;
        Ultima modificação: 27/06 - Por: Guilherme Augusto Schwann Wilke

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "patricia.h"

// Retorna o i-ésimo caractere da palavra, caso esse número exceda o tamanho da palavra, retorna um espaço em branco;
char letra(tipoPalavra k, int i){
    if (strlen(k.valPalavra) < i)
        return ' ';
    return k.valPalavra[i-1];
}

short eExterno(tipoArvore p){
    return (p->nt == externo);
}

//Função que cria nó externo;
tipoArvore criaNoInt(int i, tipoArvore *esq,  tipoArvore *dir){
    tipoArvore p = (tipoArvore)malloc(sizeof(tipoNo));
    p->nt = interno;
    printf("debug TESTE\n");
    p->no.nInterno.esq = *esq;
    p->no.nInterno.dir = *dir;
    p->no.nInterno.index = i;
    tipoArvore aux = (tipoArvore)malloc(sizeof(tipoNo));
    tipoArvore aux2 = (tipoArvore)malloc(sizeof(tipoNo));
    aux = p;
    aux2 = p;
    while (!eExterno(aux)){
        aux = aux->no.nInterno.dir;
    }
    while (!eExterno(aux2)){
        aux2 = aux2->no.nInterno.esq;
    }
    if (letra(aux2->no.palavra, i) > letra(aux->no.palavra, i))
        p->no.nInterno.indexLetra = letra(aux2->no.palavra, i);
    else
        p->no.nInterno.indexLetra = letra(aux->no.palavra, i);
    printf("Debug no int esq %s | dir %s | index %d %c\n", (*esq)->no.palavra.valPalavra, (*dir)->no.palavra.valPalavra, i, p->no.nInterno.indexLetra);
    return p;
} 


tipoArvore criaNoExt(tipoPalavra k){
    tipoArvore p;
    printf("debug criou no externo\n");
    p = (tipoArvore)malloc(sizeof(tipoNo));
    p->nt = externo;
    p->no.palavra = k;
    printf("debug ertorna no externo\n");
    return p;
}  

tipoArvore insereEntre(tipoPalavra k, tipoArvore *t, int i)
{ tipoArvore p;
  if (eExterno(*t) || i < (*t)->no.nInterno.index){
    /* cria um novo no externo */
    p = criaNoExt(k);
    printf("debug TA VINDO O INTERNO\n");
    if (letra(k, i) == (*t)->no.nInterno.indexLetra) 
        return (criaNoInt(i, t, &p));
    else
        return (criaNoInt(i, &p, t));
  } 
  else{
    if (letra(k, (*t)->no.nInterno.index) == (*t)->no.nInterno.indexLetra)
        (*t)->no.nInterno.dir = insereEntre(k,&(*t)->no.nInterno.dir,i);
    else
        (*t)->no.nInterno.esq = insereEntre(k,&(*t)->no.nInterno.esq,i);
    return (*t);
  }
}

tipoArvore inserePatricia(char* valPalavra, int idDoc, tipoArvore *t){
    tipoPalavra* palavra = (tipoPalavra*) malloc(sizeof(tipoPalavra));
    inicializaPalavra(palavra, valPalavra, idDoc);
    tipoArvore p;
    int i;
    if (*t == NULL) 
        return (criaNoExt(*palavra));
    else {
        p = *t;
        printf("debug passou do null\n");
        while (!eExterno(p)){
            if (letra(*palavra, p->no.nInterno.index) != p->no.nInterno.indexLetra)
                p = p->no.nInterno.esq;
            else
                p = p->no.nInterno.dir;
        }
        /* acha o primeiro bit diferente */
        i = 1;
        while ((i <= tamMaxPalavra) && (letra(*palavra, i) == letra(p->no.palavra, i))){
            i++;
        }
        printf("%d", i);
        if (i > tamMaxPalavra){
            printf("debug AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
            if(buscaIdDoc(*p->no.palavra.listaPares, idDoc) == 1){
                aumentaQtdePar(&(*t)->no.palavra, idDoc);
                printf("asdasd");
            }
            else{
                insereNovoIdDoc(&(*t)->no.palavra, idDoc);
                printf("NOVO ID DOC");
            }
            return (*t);
        } 
        else
            return (insereEntre(*palavra, t, i));
    }
}


tipoPalavra* pesquisaPatricia(char palavra[50], tipoArvore t){
    if (eExterno(t)){
        printf("%s", t->no.palavra.valPalavra);
        if (strcmp(palavra, t->no.palavra.valPalavra) == 0)
            return &t->no.palavra;
        else
            return NULL;
    }
    tipoPalavra* aux = (tipoPalavra*) malloc(sizeof(tipoPalavra));
    inicializaPalavra(aux, palavra, 0);
    if (letra(*aux, t->no.nInterno.index) == t->no.nInterno.indexLetra){
        pesquisaPatricia(palavra, t->no.nInterno.dir);
    }
    else{
        pesquisaPatricia(palavra, t->no.nInterno.esq);
    }
}

int quantasPalavrasPatricia(tipoArvore t, int idDoc){
    int num = 0;
    if (eExterno(t)){
        return getQtde(*t->no.palavra.listaPares, idDoc);
    }
    num += quantasPalavrasPatricia(t->no.nInterno.esq, idDoc);
    num += quantasPalavrasPatricia(t->no.nInterno.dir, idDoc);
    return num;
}

void imprimePatriciaI(tipoArvore t){
    if (t == NULL)
        return;
    if (eExterno(t)){
        imprimePalavra(t->no.palavra);
        return;
    }
    printf("debug\n");
    imprimePatriciaI(t->no.nInterno.esq);
    imprimePatriciaI(t->no.nInterno.dir);
}

void imprimePatricia(tipoArvore t){
    printf("Árvore patricia em ordem alfabetica:\n");
    imprimePatriciaI(t);
}