#include "listaEncadPares.h"
#define tamMaxPalavra 50

typedef struct tipoPalavra{
    char valPalavra[tamMaxPalavra];
    listaEncadPares* listaPares;
}tipoPalavra;

/*---------------- Gets e sets ---------------- */

char* getPalavra(tipoPalavra* palavra);

tipoPar* getPar(tipoPalavra* palavra, int idDoc); //Busca e retorna o valor de um par da lista com base em um idDoc

listaEncadPares* getListaPares(tipoPalavra* palavra);

void setPalavra(tipoPalavra* palavra, char* valPalavra); 

void setPar(tipoPalavra* palavra, tipoPar par);

void setListaPares(tipoPalavra* palavra, listaEncadPares* listapares);

/*---------------- Funções auxiliares ---------------- */

void inicializaPalavra(tipoPalavra* palavra, char* valPalavra, int idDoc); //Inicia um tipoPalavra já com o valor da palavra e um par(qnte, idDoc)

void aumentaQtdePar(tipoPalavra* palavra, int idDoc);  //Aumenta em 1 o valor de repetições de uma palavra do documento

int comparaPalavra(tipoPalavra palavra1, tipoPalavra palavra2); //Retorna 1 se forem iguais e 0 se diferentes
