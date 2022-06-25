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
        tipoPalavra.h
        Descrição do arquivo: Cabeçalho do TAD tipo palavra
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadPares.h"
#define tamMaxPalavra 50

typedef struct tipoPalavra{
    char valPalavra[tamMaxPalavra];
    listaEncadPares* listaPares;
} tipoPalavra;

/*---------------- Gets e sets ---------------- */

char* getValPalavra(tipoPalavra* palavra);

listaEncadPares* getListaPares(tipoPalavra* palavra);

void setPalavra(tipoPalavra* palavra, char* valPalavra); 

void setPar(tipoPalavra* palavra, tipoPar par);

void setListaPares(tipoPalavra* palavra, listaEncadPares* listapares);

/*---------------- Funções auxiliares ---------------- */

void inicializaPalavra(tipoPalavra* palavra, char* valPalavra, int idDoc); //Inicia um tipoPalavra já com o valor da palavra e um par(qnte(1), idDoc)

void aumentaQtdePar(tipoPalavra* palavra, int idDoc);  //Aumenta em 1 o valor de repetições de uma palavra do documento

int comparaPalavra(tipoPalavra palavra1, tipoPalavra palavra2); //Retorna 1 se forem iguais e 0 se diferentes

void imprimePalavra(tipoPalavra palavra);

void insereNovoIdDoc(tipoPalavra* palavra, int idDoc);

int contaRepsPalavra(tipoPalavra palavra, int* reps); // Função retorna -1 caso não encontre a palavra e um valor positvo caso encontre

int getQtdePalavra(tipoPalavra palavra, int idDoc);

int palavraNoDocumento(tipoPalavra palavra, int idDoc);
