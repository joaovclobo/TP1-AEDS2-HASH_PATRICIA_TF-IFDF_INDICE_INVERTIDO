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
        Ultima modificação: 18/06 - Por: João Vitor Chagas Lobo

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

void insereListaPalavrasI(char* valPalavra, int idDoc, tipoListaPalavras *listaPalvras){

  apontadorCelPalavra novaCelula, ant, atual = listaPalvras->primeiro->prox;
  tipoPalavra* palavra = (tipoPalavra*) malloc(sizeof(tipoPalavra));
  inicializaPalavra(palavra, valPalavra, idDoc);
  novaCelula = (apontadorCelPalavra) malloc(sizeof(tipoCelulaPalavra));
  novaCelula->palavra = *palavra;

  if (listaPalavrasVazia(*listaPalvras)){
    novaCelula->prox = NULL;
    listaPalvras->primeiro->prox = novaCelula;
    listaPalvras->ultimo = novaCelula;

  } else {

     while (atual != NULL && (strcmp(atual->palavra.valPalavra, valPalavra) == -1)){
            ant = atual;
            atual = atual->prox;

        }

        if (atual == listaPalvras->primeiro->prox){
            novaCelula->prox = listaPalvras->primeiro->prox;
            listaPalvras->primeiro->prox = novaCelula;

        } else{
            novaCelula->prox = ant->prox;
            ant->prox = novaCelula;

        }
  }
}

void insereListaPalavras(char* valPalavra, int idDoc, tipoVetPesos p, TipoDicionario T){
  apontadorCelPalavra temp = pesquisaPalavra(valPalavra, idDoc, p, T);

  if (temp == NULL){
    insereListaPalavrasI(valPalavra, idDoc, &T[hashPalavra(valPalavra, p)]);

  }
  else {
    if (buscaIdDoc(*temp->prox->palavra.listaPares, idDoc)){
      aumentaQtdePar(&temp->prox->palavra, idDoc);

    } else{
      insereNovoIdDoc(&temp->prox->palavra, idDoc);

    }
  }
}

apontadorCelPalavra pesquisaPalavra(char* valPalavra, int idDoc, tipoVetPesos p, TipoDicionario T){ /* Obs.: apontadorCelPalavra de retorno aponta para o item anterior da lista */
  tipoIndice i;
  apontadorCelPalavra ap;

  i = hashPalavra(valPalavra, p);
  if (listaPalavrasVazia(T[i]))
    return NULL; /* Pesquisa sem sucesso */
  else{
    ap = T[i].primeiro;

    while (ap->prox->prox != NULL &&
           strncmp(valPalavra, ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))

      ap = ap->prox;

    if (!strncmp(valPalavra, ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))
      return ap;

    else
      return NULL; /* Pesquisa sem sucesso */
  }
}

void imprimeListaPalavrasI(tipoListaPalavras listaPalvras){
  apontadorCelPalavra aux;

  aux = listaPalvras.primeiro->prox;
  while (aux != NULL){
    imprimePalavra(aux->palavra);
    aux = aux->prox;
  }
}

void imprimeListaPalavras(TipoDicionario tabela){
  int i;

  for (i = 0; i < M; i++){
    printf("Indice %d:\n", i);
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