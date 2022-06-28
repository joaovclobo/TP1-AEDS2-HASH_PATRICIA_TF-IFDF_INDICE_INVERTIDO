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

#include "operacoesIndiceInvertido.h"

#define M1 37
#define M2 677
#define M3 2477

int main(){
    hashTablePalavras tabela1 = (hashTablePalavras) malloc(M1*sizeof(tipoListaPalavras));
    hashTablePalavras tabela2 = (hashTablePalavras) malloc(M2*sizeof(tipoListaPalavras));
    hashTablePalavras tabela3 = (hashTablePalavras) malloc(M3*sizeof(tipoListaPalavras));

    tipoArvore arvore;
    
    int opcao;
    char valPalavraPesq[tamMaxPalavra];
    char arqEntrada[tamMaxPalavra];

    tipoVetPesos vetPesos;
    listaEncadDocs* listaDocs = (listaEncadDocs*) malloc(sizeof(listaEncadDocs));

    flDocsVazia(listaDocs);

    criaHashTablePalavras(tabela1, M1);
    criaHashTablePalavras(tabela2, M2);
    criaHashTablePalavras(tabela3, M3);
    geraVetPesos(vetPesos);

    arvore = NULL;

    printf("\n\n|----------------- Universidade Federal De Vicosa - Campus Florestal -----------------|\n|------------- Trabalho pratico 1 de Algoritimos e estrutura de dados 2 -----------------|\n\n");
    printf("Professora responsavel:\n    Glaucia Braga e Silva\n\nIntegrantes do Gupo:\n    Caio Oliveira Almeida - 4237\n    Guilherme Augusto Schwann Wilke - 4685\n    Joao Vitor Chagas Lobo - 4693\n\n\n");
    
    printf("\nSelecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
    scanf("%d", &opcao);

    while (opcao != 0){
        
        switch (opcao){

        case 1:;
            printf("Digite o nome do arquivo de entrada com os textos a serem indexados com sua extensao (Ex.: entrada.txt): ");
            scanf("%s", arqEntrada);

            lerArquivos(arqEntrada, listaDocs);
            imprimeListaDocs(*listaDocs);

            break;

        case 2:;
            printf("Gerando indice invertido...\n");

            escrevePalavrasDocsHash(vetPesos, tabela1, *listaDocs, M1);
            putchar('\n');
            escrevePalavrasDocsHash(vetPesos, tabela2, *listaDocs, M2);
            putchar('\n');
            escrevePalavrasDocsHash(vetPesos, tabela3, *listaDocs, M3);
            putchar('\n');
            escrevePalavrasDocsPatricia(&arvore, *listaDocs);
            putchar('\n');

            atualizaListaLidos(*listaDocs);
            imprimeListaDocs(*listaDocs);
            printf("\nFim da criacao do indice invertido\n");
            break;

        case 3:;

            imprimeHashTable(tabela1, M1);
            putchar('\n');
            imprimeHashTable(tabela2, M2);
            putchar('\n');
            imprimeHashTable(tabela3, M3);
            putchar('\n');
            imprimePatricia(arvore);
            break;

        case 4:;
        
            tipoListaPalavras* listaPalavrasPesquisa = (tipoListaPalavras*) malloc(sizeof(tipoListaPalavras));

            flPalavrasVazia(listaPalavrasPesquisa);

            printf("Digite as palavras que serão pessquisadas ou '-' para pesquisar as palavras digitadas: ");
            scanf("%s", valPalavraPesq);
            
            while (strcmp(valPalavraPesq, "-") != 0){
                tipoPalavra* palavraPesquisaTemp = (tipoPalavra*) malloc(sizeof(tipoPalavra));
                inicializaPalavra(palavraPesquisaTemp, valPalavraPesq, 0);

                insereListaPalavras(*palavraPesquisaTemp, listaPalavrasPesquisa);
                
                free(palavraPesquisaTemp);
                
                printf("Digite as palavras que serão pessquisadas ou '-' para pesquisar as palavras digitadas: ");
                scanf("%s", valPalavraPesq);                
                
            }
            printf("Palavras pesquisasdas:\n");
            imprimeListaPalavrasValores(*listaPalavrasPesquisa);

            printf("\nResultado da pesquisa no TAD hash com M = %d :\n", M1);
            pesquisaTFIDFHash(*listaPalavrasPesquisa, *listaDocs, tabela1, vetPesos, M1);
            printf("\nResultado da pesquisa no TAD hash com M = %d :\n", M2);
            pesquisaTFIDFHash(*listaPalavrasPesquisa, *listaDocs, tabela2, vetPesos, M2);
            printf("\nResultado da pesquisa no TAD hash com M = %d :\n", M3);
            pesquisaTFIDFHash(*listaPalavrasPesquisa, *listaDocs, tabela3, vetPesos, M3);
            printf("\nResultado da pesquisa no TAD árvore patricia :\n");
            pesquisaTFIDFPatricia(*listaPalavrasPesquisa, *listaDocs, arvore);

            free(listaPalavrasPesquisa);
            break;

        case 0:;
            break;

        default:;
            printf("ERRO: Opcao invalida!\n");
            break;
            
        }
        printf("\nSelecione uma opcao digitando o numero correspondente:\n    1 - Ler arquivos.\n    2 - Criar indice invertido.\n    3 - Imprimir indice invertido.\n    4 - Fazer busca.\n    0 - Encerar programa.\n\n");
        scanf("%d", &opcao);

    }

    printf("Programa encerrado :)\n");
    return 0;
}
