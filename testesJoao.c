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
        testesJoao.c
        Descrição do arquivo: Arquivo para testes de funções implementadas sob pelo aluno João Vitor Chagas Lobo
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "hashTablePalavras.h"

int main(int argc, char *argv[]){

    criaHashTablePalavra(Tabela);
    geraVetPesos(p);

/*----------- Testa inserções -----------*/

    LerPalavra(Elemento.Chave, tamMaxPalavra);
    while (strcmp(Elemento.Chave, "aaaaaa") != 0){
        insereListaPalavra(Elemento, p, Tabela);
        LerPalavra(Elemento.Chave, tamMaxPalavra);

    }
    printf("Tabela apos insercao:\n");
    imprimeListaPalavras(Tabela);

/*----------- Testa pesquisa -----------*/

    printf("Pesquisar :  ");
    LerPalavra(Elemento.Chave, tamMaxPalavra);

    while (strcmp(Elemento.Chave, "aaaaaa") != 0){
        i = pesquisaPalavra(Elemento.Chave, p, Tabela);

        if (i == NULL)
            printf("pesquisa sem sucesso \n");

        else
            printf("sucesso \n");

        printf("Pesquisar :  ");
        LerPalavra(Elemento.Chave, tamMaxPalavra);

    }

/*----------- Testa retirada -----------*/

    printf("Retirar seguintes chaves:\n");
    LerPalavra(Elemento.Chave, tamMaxPalavra);

    while (strcmp(Elemento.Chave, "aaaaaa") != 0) {
        retiraListaPalavra(Elemento, p, Tabela);
        LerPalavra(Elemento.Chave, tamMaxPalavra);

    }
    printf("Tabela apos retiradas:\n");
    imprimeListaPalavras(Tabela);

/*----------- Testa inserções de novo -----------*/
    // printf("Inserir de novo os elementos seguintes:\n");
    // LerPalavra(Elemento.Chave, tamMaxPalavra);

    // while (strcmp(Elemento.Chave, "aaaaaa") != 0){
    //     insereListaPalavra(Elemento, p, Tabela);
    //     LerPalavra(Elemento.Chave, tamMaxPalavra);
    // }
    // printf("Tabela apos novas insxercoes:\n");
    // imprimeListaPalavras(Tabela);
    return 0;
}
