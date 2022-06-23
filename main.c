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

int main(){
    hashTablePalavras Tabela = (hashTablePalavras) malloc(7*sizeof(tipoListaPalavras));              //Avaliar a necessidade
    hashTablePalavras Tabela2 = (hashTablePalavras) malloc(101*sizeof(tipoListaPalavras)); ;
    tipoPalavra Elemento;                  //Avaliar a necessidade
    tipoVetPesos p;                     //Avaliar a necessidade
    apontadorCelPalavra i;              //Avaliar a necessidade
    int opcao;
    char arqEntrada[50];
    
    int idDocTemp = 1;
    listaEncadDocs* listaDocs = (listaEncadDocs*) malloc(sizeof(listaEncadDocs));

    flDocsVazia(listaDocs);
    criaHashTablePalavras(Tabela, 7);
    criaHashTablePalavras(Tabela2, 101);
    geraVetPesos(p);

    printf("\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
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

            //Colocar confimação para cada TAD
            escrevePalavrasDocs(p, Tabela, *listaDocs, 7);
            escrevePalavrasDocs(p, Tabela2, *listaDocs, 101);

            printf("\nFim da criacao do indice invertido\n");
            break;

        case 3:
            //Função pra imprimir os 2 TADs em ordem alfabética
            imprimeHashTable(Tabela, 7);
            putchar('\n');
            imprimeHashTable(Tabela2, 101);
            break;

        case 4:
            //Função pra buscar um ou mais termos nos TADs
            printf("Pesquisar :  ");
            lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            while (strcmp(Elemento.valPalavra, "fim") != 0){
                i = pesquisaPalavra(Elemento.valPalavra, idDocTemp, p, Tabela, 7);

                if (i == NULL)
                    printf("pesquisa sem sucesso \n");

                else
                    printf("sucesso \n");

                printf("Pesquisar :  ");
                lerPalavra(Elemento.valPalavra, tamMaxPalavra);

            }
            printf("---------------4\n");
            imprimeListaDocs(*listaDocs);
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
