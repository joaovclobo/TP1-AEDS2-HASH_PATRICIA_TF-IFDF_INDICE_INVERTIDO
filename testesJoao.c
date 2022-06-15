/*  
    Universidade Federal De Viçosa - Campus Florestal
    Trabalho prático 1 de Algorítimos e estrutura de dados
    
    Professora responsável: 
        Glaucia Braga e Silva
    Integrantes do Gupo:
        Caio Oliveira Almeida - 4237
        Guilherme Augusto Schwann Wilke - 4685
        João Vitor Chagas Lobo - 4693

    Arquivo: 
        anotacoes-branch-Joao.txt
        Descrição do arquivo: Arquivo para testes de funções implementadas sob pelo aluno João Vitor Chagas Lobo
        Ultima modificação: 14/06 - Por: João Vitor Chagas Lobo
*/

#include "tipoPalavra.h"

int main()
{

    tipoPalavra *palavra1 = (tipoPalavra*) malloc(sizeof(tipoPalavra));
    tipoPalavra *palavra2 = (tipoPalavra*) malloc(sizeof(tipoPalavra));
    char* valpalavra1 = "Joao";
    char* valPalavra2 = "Guto";

    inicializaPalavra(palavra1, valpalavra1, 1);
    inicializaPalavra(palavra2, valPalavra2, 35);

    imprimePalavra(*palavra1);
    imprimePalavra(*palavra2);

    printf("Aumentou\n"); aumentaQtdePar(palavra1, 1); aumentaQtdePar(palavra1, 1); aumentaQtdePar(palavra1, 1);
    imprimePalavra(*palavra1);

    printf("Insere 2\n"); insereNovoIdDoc(palavra2, 5); insereNovoIdDoc(palavra2, 13);
    imprimePalavra(*palavra2);

    printf("Aumentou\n");
    aumentaQtdePar(palavra2, 5); aumentaQtdePar(palavra2, 13); aumentaQtdePar(palavra2, 13);
    imprimePalavra(*palavra2);

    printf("Insere 5\n"); insereNovoIdDoc(palavra1, 23); insereNovoIdDoc(palavra1, 36); insereNovoIdDoc(palavra1, 6); insereNovoIdDoc(palavra1, 156); insereNovoIdDoc(palavra1, 2);
    imprimePalavra(*palavra1);

    return (0);
}
