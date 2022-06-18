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
        Ultima modificação: 18/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "tipoPalavra.h"
#include "listaEncadDocs.h"
#include <ctype.h>

int main(){

    int opcao = 1;
    char arqEntrada[50];
    listaEncadDocs* listaDocs = (listaEncadDocs*) malloc(sizeof(listaEncadDocs));
    flDocsVazia(listaDocs);

    printf("\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    Joao Vitor Chagas Lobo - 4693\n\n\n");
    
    while (opcao != 0){
        printf("\nSelecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
        scanf("%d", &opcao);
        
        switch (opcao){

        case 1:
            printf("Digite o nome do arquivo de entrada com os textos a serem indexados com sua extensao (Ex.: entrada.txt):\n");
            scanf("%s", arqEntrada);
            lerArquivos(arqEntrada, listaDocs);
            imprimeListaDocs(*listaDocs);
            break;

        case 2:
            printf("Gerando indice invertido...\n");
            // lerPalavras();
            //Colocar confimação para cada TAD
            escrevePalavrasDocs(*listaDocs);

            printf("\nFim da criacao do indice invertido\n");
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
            printf("ERRO: Opcao invalida!\n");
            break;
            
        }
    }

    printf("Programa encerrado :)\n");
}
