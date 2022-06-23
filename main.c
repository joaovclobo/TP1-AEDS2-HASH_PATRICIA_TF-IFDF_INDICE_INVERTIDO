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
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadDocs.h"
#define M1 37
#define M2 677
#define M3 7

int main(){
    hashTablePalavras tambela1 = (hashTablePalavras) malloc(M1*sizeof(tipoListaPalavras));
    hashTablePalavras tambela2 = (hashTablePalavras) malloc(M2*sizeof(tipoListaPalavras));
    hashTablePalavras tambela3 = (hashTablePalavras) malloc(M3*sizeof(tipoListaPalavras));
    
    int opcao;
    char arqEntrada[50];
    tipoVetPesos vetPesos;
    listaEncadDocs* listaDocs = (listaEncadDocs*) malloc(sizeof(listaEncadDocs));
    

    int idDocTemp = 1;
    tipoPalavra Elemento;                  // ------------------ APAGAR ---------------------
    apontadorCelPalavra i;              //Avaliar a necessidade


    flDocsVazia(listaDocs);
    criaHashTablePalavras(tambela1, M1);
    criaHashTablePalavras(tambela2, M2);
    criaHashTablePalavras(tambela3, M3);
    geraVetPesos(vetPesos);

    printf("\n\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    Joao Vitor Chagas Lobo - 4693\n\n\n");
    
    printf("\nSelecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
    scanf("%d", &opcao);

    while (opcao != 0){
        
        switch (opcao){

        case 1:
            printf("Digite o nome do arquivo de entrada com os textos a serem indexados com sua extensao (Ex.: entrada.txt):\n");
            scanf("%s", arqEntrada);

            lerArquivos(arqEntrada, listaDocs);
            imprimeListaDocs(*listaDocs);

            break;

        case 2:
            printf("Gerando indice invertido...\n");

            //Colocar confimação e dados (tempo e memória) para cada TAD
            escrevePalavrasDocs(vetPesos, tambela1, *listaDocs, M1);
            escrevePalavrasDocs(vetPesos, tambela2, *listaDocs, M2);
            escrevePalavrasDocs(vetPesos, tambela3, *listaDocs, M3);

            printf("\nFim da criacao do indice invertido\n");
            break;

        case 3:
            //Função pra imprimir os 2 TADs em ordem alfabética
            imprimeHashTable(tambela1, M1);
            putchar('\n');
            imprimeHashTable(tambela2, M2);
            putchar('\n');
            imprimeHashTable(tambela3, M3);
            break;

        case 4:
            //Função pra buscar um ou mais termos nos TADs
            printf("Pesquisar :  ");
            lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            while (strcmp(Elemento.valPalavra, "fim") != 0){
                i = pesquisaPalavra(Elemento.valPalavra, idDocTemp, vetPesos, tambela1, M1);

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
            printf("ERRO: Opcao invalida!\n");
            break;
            
        }
        printf("\nSelecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
        scanf("%d", &opcao);

    }

    printf("Programa encerrado :)\n");
    return 0;
}
