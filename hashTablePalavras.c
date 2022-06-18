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
  listaPalvras->primeiro = (tipoCelulaPalavra*) malloc(sizeof(tipoCelulaPalavra));

  listaPalvras->ultimo = listaPalvras->primeiro;
  listaPalvras->primeiro->prox = NULL;
}

short listaPalavrasVazia(tipoListaPalavras listaPalvras){
  return (listaPalvras.primeiro == listaPalvras.ultimo);
}

void geraVetPesos(tipoVetPesos p){      //Mudar nome do vetor de pesos
    int i;

    srand(13);
    for (i = 0; i < tamMaxPalavra; i++)
        p[i] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

tipoIndice hashPalavra(char* valPalavra, tipoVetPesos p){
    int i;
    unsigned int soma = 0;
    int comp = strlen(valPalavra);

    for (i = 0; i < comp; i++)
        soma += (unsigned int) valPalavra[i] * p[i];

    return (soma % M);
}

void criaHashTablePalavras(TipoDicionario T){
  int i;

  for (i = 0; i < M; i++)
    flPalavrasVazia(&T[i]);
}

void insereListaPalavrasI(tipoPalavra palavra, tipoListaPalavras *listaPalvras){
  
  listaPalvras->ultimo->prox = (tipoCelulaPalavra*) malloc(sizeof(tipoCelulaPalavra));

  listaPalvras->ultimo = listaPalvras->ultimo->prox;
  listaPalvras->ultimo->palavra = palavra;
  listaPalvras->ultimo->prox = NULL;
}

void insereListaPalavras(tipoPalavra palavra, tipoVetPesos p, TipoDicionario T){
  if (pesquisaPalavra(palavra.valPalavra, p, T) == NULL)
    insereListaPalavrasI(palavra, &T[hashPalavra(palavra.valPalavra, p)]);

  else
    printf(" Registro ja  esta  presente\n");
}

apontadorCelPalavra pesquisaPalavra(char* valPalavra, tipoVetPesos p, TipoDicionario T){ /* Obs.: apontadorCelPalavra de retorno aponta para o item anterior da lista */
  tipoIndice i;
  apontadorCelPalavra Ap;

  i = hashPalavra(valPalavra, p);
  if (listaPalavrasVazia(T[i]))
    return NULL; /* Pesquisa sem sucesso */
  else{
    Ap = T[i].primeiro;

    while (Ap->prox->prox != NULL &&
           strncmp(valPalavra, Ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))

      Ap = Ap->prox;

    if (!strncmp(valPalavra, Ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))
      return Ap;

    else
      return NULL; /* Pesquisa sem sucesso */
  }
}

void imprimeListaPalavrasI(tipoListaPalavras listaPalvras){
  apontadorCelPalavra aux;

  aux = listaPalvras.primeiro->prox;
  while (aux != NULL){
    printf("%.*s ", tamMaxPalavra, aux->palavra.valPalavra);
    aux = aux->prox;
  }
}

void imprimeListaPalavras(TipoDicionario tabela){
  int i;

  for (i = 0; i < M; i++){
    printf("%d: ", i);
    if (!listaPalavrasVazia(tabela[i]))
      imprimeListaPalavrasI(tabela[i]);

    putchar('\n');
  }
}

void lerPalavra(char *p, int Tam){ //Avaliar ncessidade
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