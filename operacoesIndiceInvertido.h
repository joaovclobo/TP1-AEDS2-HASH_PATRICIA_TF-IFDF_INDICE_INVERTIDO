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
        operacoesIndiceInvertido.c
        Descrição do arquivo: Arquivo do arquivo operacoesIndiceInvertido.h
        Ultima modificação: 27/06 - Por: Guilherme Augusto Schwann Wilke

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadDocs.h"

typedef struct tipoDocRelevancia{
    tipoDoc doc;
    double relevancia;
}tipoDocRelevancia;


/*------------------------------------------------------------------- Leitura de arquivos -------------------------------------------------------------------*/

void escrevePalavrasDocsHash(tipoVetPesos p, hashTablePalavras tabela, listaEncadDocs listaDocs, int tamTabela);

void lerPalavrasInsereHash(char* arquivo, int idDoc, tipoVetPesos p, hashTablePalavras tabela, int tamTabela);

void escrevePalavrasDocsPatricia(tipoArvore *t, listaEncadDocs listaDocs);

void lerPalavrasInserePatricia(char* arquivo, int idDoc, tipoArvore *t);

void lerArquivos(char* arquivo, listaEncadDocs* listaDocs);

void atualizaListaLidos(listaEncadDocs listaEncadDocs);

/*------------------------------------------------------------------- Pesquisa Hash -------------------------------------------------------------------*/

void pesquisaTFIDFHash(tipoListaPalavras listaPalavrasPesquisa, listaEncadDocs listaDocs, hashTablePalavras tabela, tipoVetPesos vetPesos, int tamTabela);

double calculaPesoDeTJemi(tipoPalavra palavra, int idDoc, int N); // Função usada tanto para o cálculo da relevância pela tabela Hash quanto pela arvore patricia 

double somatorioPesos(tipoListaPalavras listaPalavrasPesquisa, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela, int idDoc, int N);

void selecaoOrdena(tipoDocRelevancia *relevancias, int n); // Função usada tanto para o cálculo da relevância pela tabela Hash quanto pela arvore patricia 

/*------------------------------------------------------------------- Pesquisa Patricia -------------------------------------------------------------------*/

void pesquisaTFIDFPatricia(tipoListaPalavras listaPalavrasPesquisa, listaEncadDocs listaDocs, tipoArvore t);

double somatorioPesosPatricia(tipoListaPalavras listaPalavrasPesquisa, tipoArvore t, int idDoc, int N);
