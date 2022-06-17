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
        main.c
        Descrição do arquivo: Arquivo "main" contendo o menu e a execução das principais funções
        Ultima modificação: 17/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"

int main(){

    int opcao = 1;

    printf("\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    Joao Vitor Chagas Lobo - 4693\n\n\n");
    
    while (opcao != 0){
        printf("Selecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            //Função para ler o arquivo com os textos, armazenar o nome deles e gerar os id correspondentes
            printf("---------------1\n");
            break;

        case 2:
            //Função pra carregar as palavras de cada arquivo nos 2 TADs
            printf("---------------2\n");
            break;

        case 3:
            //Função pra imprimir os 2 TADs em ordem alfabética
            printf("---------------3\n");
            break;

        case 4:
            //Função pra buscar um ou mais termos nos TADs
            printf("---------------4\n");
            break;

        case 0:
            break;

        default:
            printf("Opcao invalida!\n");
            break;
            
        }
    }

    printf("Programa encerrado :)\n");
}