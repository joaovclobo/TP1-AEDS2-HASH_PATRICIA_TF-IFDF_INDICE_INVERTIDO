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

// int main(int argc, char *argv[]){

//     criaHashTablePalavras(Tabela);
//     geraVetPesos(p);

// /*----------- Testa inserções -----------*/

//     lerPalavra(Elemento.valPalavra, tamMaxPalavra);
//     while (strcmp(Elemento.valPalavra, "aaaaaa") != 0){
//         insereListaPalavras(Elemento, p, Tabela);
//         lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     }
//     printf("Tabela apos insercao:\n");
//     imprimeListaPalavras(Tabela);

// /*----------- Testa pesquisa -----------*/

//     printf("Pesquisar :  ");
//     lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     while (strcmp(Elemento.valPalavra, "aaaaaa") != 0){
//         i = pesquisaPalavra(Elemento.valPalavra, p, Tabela);

//         if (i == NULL)
//             printf("pesquisa sem sucesso \n");

//         else
//             printf("sucesso \n");

//         printf("Pesquisar :  ");
//         lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     }

// /*----------- Testa retirada -----------*/

//     printf("Retirar seguintes chaves:\n");
//     lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     while (strcmp(Elemento.valPalavra, "aaaaaa") != 0) {
//         retiraListaPalavras(Elemento, p, Tabela);
//         lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     }
//     printf("Tabela apos retiradas:\n");
//     imprimeListaPalavras(Tabela);

// /*----------- Testa inserções de novo -----------*/
//     // printf("Inserir de novo os elementos seguintes:\n");
//     // lerPalavra(Elemento.valPalavra, tamMaxPalavra);

//     // while (strcmp(Elemento.valPalavra, "aaaaaa") != 0){
//     //     insereListaPalavras(Elemento, p, Tabela);
//     //     lerPalavra(Elemento.valPalavra, tamMaxPalavra);
//     // }
//     // printf("Tabela apos novas insxercoes:\n");
//     // imprimeListaPalavras(Tabela);
//     return 0;
// }

int main(){

    int opcao = 1;
    criaHashTablePalavras(Tabela);
    geraVetPesos(p);

    printf("\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    Joao Vitor Chagas Lobo - 4693\n\n\n");
    
    while (opcao != 0){
        printf("Selecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            lerPalavra(Elemento.valPalavra, tamMaxPalavra);
            while (strcmp(Elemento.valPalavra, "fim") != 0){
                insereListaPalavras(Elemento.valPalavra, 1, p, Tabela);
                lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            }
            printf("Tabela apos insercao:\n");
            imprimeListaPalavras(Tabela);

            break;

        case 2:
            //Função pra carregar as palavras de cada arquivo nos 2 TADs
            printf("---------------2\n");
            break;

        case 3:
            // printf("Retirar seguintes chaves:\n");
            // lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            // while (strcmp(Elemento.valPalavra, "fim") != 0) {
            //     retiraListaPalavras(Elemento, p, Tabela);
            //     lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            // }
            // printf("Tabela apos retiradas:\n");
            // imprimeListaPalavras(Tabela);
            break;

        case 4:
            printf("Pesquisar :  ");
            lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            while (strcmp(Elemento.valPalavra, "fim") != 0){
                i = pesquisaPalavra(Elemento.valPalavra, 1, p, Tabela);

                if (i == NULL)
                    printf("pesquisa sem sucesso \n");

                else
                    printf("sucesso \n");

                printf("Pesquisar :  ");
                lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            }
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