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
        hashTablePalavras.c
        Descrição do arquivo: Arquivo de código do TAD hash table de palavras
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "hashTablePalavras.h"

void flPalavrasVazia(tipoListaPalavras *listaPalvras){
  listaPalvras->primeiro = (tipoCelulaPalavra *)malloc(sizeof(tipoCelulaPalavra));

  listaPalvras->ultimo = listaPalvras->primeiro;
  listaPalvras->primeiro->prox = NULL;
}

short listaPalavrasVazia(tipoListaPalavras listaPalvras){
  return (listaPalvras.primeiro == listaPalvras.ultimo);
}

void insereListaPalavrasI(TipoItem x, tipoListaPalavras *listaPalvras){
  listaPalvras->ultimo->prox = (tipoCelulaPalavra *)malloc(sizeof(tipoCelulaPalavra));

  listaPalvras->ultimo = listaPalvras->ultimo->prox;
  listaPalvras->ultimo->Item = x;
  listaPalvras->ultimo->prox = NULL;
}

void retiraListaPalavrasI(apontadorCelPalavra p, tipoListaPalavras *listaPalvras, TipoItem *Item){ /* -- Obs.: o item a ser retirado o seguinte ao apontado por p -- */
  apontadorCelPalavra q;

  if (listaPalavrasVazia(*listaPalvras) || p == NULL || p->prox == NULL){
    printf(" Erro Lista vazia ou posicao nao existe\n");
    return;

  }
  q = p->prox;
  *Item = q->Item;
  p->prox = q->prox;

  if (p->prox == NULL)
    listaPalvras->ultimo = p;
    
  free(q);
}

void geraVetPesos(tipoVetPesos p){
    int i;

    srand(13);
    for (i = 0; i < tamMaxPalavra; i++)
        p[i] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

tipoIndice hashPalavra(TipoChave Chave, tipoVetPesos p){
    int i;
    unsigned int Soma = 0;
    int comp = strlen(Chave);

    for (i = 0; i < comp; i++)
        Soma += (unsigned int)Chave[i] * p[i];

    return (Soma % M);
}

void criaHashTablePalavra(TipoDicionario T){
  int i;

  for (i = 0; i < M; i++)
    flPalavrasVazia(&T[i]);
}

apontadorCelPalavra pesquisaPalavra(TipoChave Ch, tipoVetPesos p, TipoDicionario T){ /* Obs.: apontadorCelPalavra de retorno aponta para o item anterior da lista */
  tipoIndice i;
  apontadorCelPalavra Ap;

  i = hashPalavra(Ch, p);
  if (listaPalavrasVazia(T[i]))
    return NULL; /* Pesquisa sem sucesso */
  else{
    Ap = T[i].primeiro;

    while (Ap->prox->prox != NULL &&
           strncmp(Ch, Ap->prox->Item.Chave, sizeof(TipoChave)))

      Ap = Ap->prox;

    if (!strncmp(Ch, Ap->prox->Item.Chave, sizeof(TipoChave)))
      return Ap;

    else
      return NULL; /* Pesquisa sem sucesso */
  }
}

void insereListaPalavra(TipoItem x, tipoVetPesos p, TipoDicionario T){
  if (pesquisaPalavra(x.Chave, p, T) == NULL)
    insereListaPalavrasI(x, &T[hashPalavra(x.Chave, p)]);

  else
    printf(" Registro ja  esta  presente\n");
}

void retiraListaPalavra(TipoItem x, tipoVetPesos p, TipoDicionario T){
  apontadorCelPalavra Ap;

  Ap = pesquisaPalavra(x.Chave, p, T);
  if (Ap == NULL)
    printf(" Registro nao esta  presente\n");

  else
    retiraListaPalavrasI(Ap, &T[hashPalavra(x.Chave, p)], &x);
}

void imprimeListaPalavrasI(tipoListaPalavras listaPalvras){
  apontadorCelPalavra Aux;

  Aux = listaPalvras.primeiro->prox;
  while (Aux != NULL){
    printf("%.*s ", tamMaxPalavra, Aux->Item.Chave);
    Aux = Aux->prox;
  }
}

void imprimeListaPalavras(TipoDicionario Tabela){
  int i;

  for (i = 0; i < M; i++){
    printf("%d: ", i);
    if (!listaPalavrasVazia(Tabela[i]))
      imprimeListaPalavrasI(Tabela[i]);

    putchar('\n');
  }
}

void LerPalavra(char *p, int Tam){ //Avaliar ncessidade
  char c;
  int i, j;

  fflush(stdin);
  j = 0;
  while (((c = getchar()) != '\n') && j < Tam - 1)
    p[j++] = c;

  p[j] = '\0';
  while (c != '\n')
    c = getchar();
  /* Desconsiderar espacos ao final
    da cadeia como ocorre em Pascal.*/
  for (i = j - 1; (i >= 0 && p[i] == ' '); i--)
    p[i] = '\0';
}