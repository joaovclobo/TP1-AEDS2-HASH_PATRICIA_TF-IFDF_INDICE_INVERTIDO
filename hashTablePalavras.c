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
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

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

void geraVetPesos(tipoVetPesos vetPesos){      //Mudar nome do vetor de pesos
    int i;

    srand(13);
    for (i = 0; i < tamMaxPalavra; i++)
        vetPesos[i] = 1 + (int)(10000.0 * rand() / (RAND_MAX + 1.0));
}

tipoIndice hashPalavra(char* valPalavra, tipoVetPesos vetPesos, int tamTabela){
    int i;
    unsigned int soma = 0;
    int comp = strlen(valPalavra);

    for (i = 0; i < comp; i++)
        soma += (unsigned int) valPalavra[i] * vetPesos[i];

    return (soma % tamTabela);
}

void criaHashTablePalavras(hashTablePalavras tabela, int tamTabela){
  int i;

  for (i = 0; i < tamTabela; i++)
    flPalavrasVazia(&tabela[i]);
}

void insereListaPalavras(tipoPalavra palavra, tipoListaPalavras *listaPalvras){ /* Esta função é utilizada para ordenar em uma lista encadeada as palavras inseridas na hash table*/

  apontadorCelPalavra novaCelula, ant, atual = listaPalvras->primeiro->prox;

  novaCelula = (apontadorCelPalavra) malloc(sizeof(tipoCelulaPalavra));
  
  novaCelula->palavra = palavra;

  if (listaPalavrasVazia(*listaPalvras)){
    novaCelula->prox = NULL;
    listaPalvras->primeiro->prox = novaCelula;
    listaPalvras->ultimo = novaCelula;

  } else {

     while ((atual != NULL) && (strcmp(atual->palavra.valPalavra, palavra.valPalavra) < 0)){
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

void insereListaOrdenadaTemp(tipoListaPalavras listaPalvrasHash, tipoListaPalavras* listaOrdenadaTemp){
  apontadorCelPalavra aux;

  aux = listaPalvrasHash.primeiro->prox;

  while (aux != NULL){
    insereListaPalavras(aux->palavra, listaOrdenadaTemp);
    aux = aux->prox;

  }
}

void insereHashTablePalavrasI(char* valPalavra, int idDoc, tipoListaPalavras *listaPalvras){

  tipoPalavra* palavra = (tipoPalavra*) malloc(sizeof(tipoPalavra));

  inicializaPalavra(palavra, valPalavra, idDoc);
  
  listaPalvras->ultimo->prox = (apontadorCelPalavra) malloc(sizeof(tipoCelulaPalavra));
  listaPalvras->ultimo = listaPalvras->ultimo->prox;
  listaPalvras->ultimo->palavra = *palavra;
  listaPalvras->ultimo->prox = NULL;

}

void insereHashTablePalavras(char* valPalavra, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela){
  apontadorCelPalavra temp = pesquisaPalavra(valPalavra, idDoc, vetPesos, tabela, tamTabela);

  if (temp == NULL){
    insereHashTablePalavrasI(valPalavra, idDoc, &tabela[hashPalavra(valPalavra, vetPesos, tamTabela)]);

  }
  else {
    if (buscaIdDoc(*temp->prox->palavra.listaPares, idDoc)){
      aumentaQtdePar(&temp->prox->palavra, idDoc);

    } else{
      insereNovoIdDoc(&temp->prox->palavra, idDoc);

    }
  }
}

apontadorCelPalavra pesquisaPalavra(char* valPalavra, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela){ /* Obs.: apontadorCelPalavra de retorno aponta para o item anterior da lista */
  tipoIndice i;
  apontadorCelPalavra ap;

  i = hashPalavra(valPalavra, vetPesos, tamTabela);
  if (listaPalavrasVazia(tabela[i]))
    return NULL; /* Pesquisa sem sucesso */
  else{
    ap = tabela[i].primeiro;

    while (ap->prox->prox != NULL && strncmp(valPalavra, ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))
      ap = ap->prox;

    if (!strncmp(valPalavra, ap->prox->palavra.valPalavra, sizeof(char[tamMaxPalavra])))
      return ap;

    else
      return NULL; /* Pesquisa sem sucesso */
  }
}

void imprimeListaPalavras(tipoListaPalavras listaPalvras){
  apontadorCelPalavra aux;

  aux = listaPalvras.primeiro->prox;

  while (aux != NULL){
    imprimePalavra(aux->palavra);
    aux = aux->prox;

  }
}

void imprimeHashTable(hashTablePalavras tabela, int tamTabela){
  int i;
  
  tipoListaPalavras* listaOrdenadaTemp = (tipoListaPalavras*) malloc(sizeof(tipoListaPalavras));
  
  flPalavrasVazia(listaOrdenadaTemp);

  for (i = 0; i < tamTabela; i++){

    if (!listaPalavrasVazia(tabela[i])){

      printf("\nIndice: %d\n\n", i);
      insereListaOrdenadaTemp(tabela[i], listaOrdenadaTemp);
    }
  }

  printf("Hash Table com M = %d em ordem alfabetica:\n", tamTabela);
  imprimeListaPalavras(*listaOrdenadaTemp);

  free(listaOrdenadaTemp);
}

int palavrasUnicasDoc(hashTablePalavras tabela, int tamTabela, int idDoc){
  int conta;

  for (int i = 0; i < tamTabela; i++){

    if (!listaPalavrasVazia(tabela[i])){
      conta += palavrasUnicasDocI(tabela[i], idDoc);

    }
  }
  return conta;
  
}

int palavrasUnicasDocI(tipoListaPalavras listaPalvras, int idDoc){
  apontadorCelPalavra aux;
  int conta = 0;

  aux = listaPalvras.primeiro->prox;

  while (aux != NULL){
    conta += palavraNoDocumento(aux->palavra, idDoc);
    aux = aux->prox;

  }
  return conta;

}

void lerPalavra(char *p, int tam){ 
  char c;
  int i, j;

  fflush(stdin);
  j = 0;
  while (((c = getchar()) != '\n') && j < tam - 1)
    p[j++] = c;

  p[j] = '\0';
  while (c != '\n')
    c = getchar();
  /* Desconsiderar espacos ao final
    da cadeia como ocorre em Pascal.*/
  for (i = j - 1; (i >= 0 && p[i] == ' '); i--)
    p[i] = '\0';
}
