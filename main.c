/* ------------------------------------------------------------------------------------------------------------------------------------------------------------

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
        Descrição do arquivo: Arquivo "main" contendo o menu e a execução das principais funções
        Ultima modificação: 14/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"

int main(){

    int opcao = 1;

    printf("\n*-----------------Universidade Federal De Vicosa - Campus Florestal-----------------*\n*-------------Trabalho pratico 1 de Algorítimos e estrutura de dados 2-----------------*\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    João Vitor Chagas Lobo - 4693\n\n\n");
    
    while (opcao != 0){
        printf("Selecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            printf("---------------1\n");
            break;

        case 2:
            printf("---------------2\n");
            break;

        case 3:
            printf("---------------3\n");
            break;

        case 4:
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