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
        listaEncadDocs.c
        Descrição do arquivo: Arquivo de codigo do TAD listaEncadDocs
        Ultima modificação: 22/06 - Por: João Vitor Chagas Lobo

------------------------------------------------------------------------------------------------------------------------------------------------------------ */

#include "listaEncadDocs.h"

void flDocsVazia(listaEncadDocs *listaDocs){
    listaDocs->primeiro = (apontadorDoc) malloc(sizeof(tipoCelulaDoc));
    
    listaDocs->qtdeDocs = 0;
    listaDocs->ultimo = listaDocs->primeiro;
    listaDocs->primeiro->prox = NULL;
}

int listaDocsVazia(listaEncadDocs listaDocs){
    return (listaDocs.primeiro == listaDocs.ultimo);
}

void insereDocI(tipoDoc doc, listaEncadDocs *listaDocs){
    listaDocs->ultimo->prox = (apontadorDoc) malloc(sizeof(tipoCelulaDoc));

    listaDocs->ultimo = listaDocs->ultimo->prox;
    listaDocs->ultimo->doc = doc;
    listaDocs->ultimo->prox = NULL;
}

void insereDoc(char *nomeDoc, listaEncadDocs *listaDocs){
    if (buscaNomeDoc(nomeDoc, *listaDocs)){
        printf("ERRO: Arquivo *%s* ja inserido\n", nomeDoc);

    }else{
        tipoDoc* doc = (tipoDoc*) malloc(sizeof(tipoDoc));

        listaDocs->qtdeDocs++;
        doc->idDoc = listaDocs->qtdeDocs;
        strcpy(doc->nomeDoc, nomeDoc);
        doc->documentoLido = naoLido;

        insereDocI(*doc, listaDocs);

    }
}

void imprimeListaDocs(listaEncadDocs listaDocs){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;
    printf("\nDocumentos inseridos:\n\n");

    while (aux != NULL){
        if (aux->doc.documentoLido == lido){
            printf("Nome doc: %-5s | idDoc: %-3d | docLido: Sim\n", aux->doc.nomeDoc, aux->doc.idDoc);

        } else{
            printf("Nome doc: %-5s | idDoc: %-3d | docLido: Nao\n", aux->doc.nomeDoc, aux->doc.idDoc);

        }
        aux = aux->prox;

    }
}

int buscaNomeDoc(char *nomeDoc, listaEncadDocs listaDocs){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (!strcmp(aux->doc.nomeDoc, nomeDoc)){
            return 1;
        }else{
            aux = aux->prox;
        }
    }
    return 0;
}

void escrevePalavrasDocs(tipoVetPesos vetPesos, hashTablePalavras tabela, listaEncadDocs listaDocs, int tamTabela){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        if (aux->doc.documentoLido == lido){
            printf("As palavras do documento *%s* ja foram inseridas no indice invertido e nao foram inseridas novamente\n", aux->doc.nomeDoc);

        } else{
            lerPalavras(aux->doc.nomeDoc, aux->doc.idDoc, vetPesos, tabela, tamTabela);
            printf("Inseriu TAD hash M = %d - Para o arquivo %s\n", tamTabela, aux->doc.nomeDoc);
            // aux->doc.documentoLido = lido;

        }
        aux = aux->prox;
    }
}

void lerPalavras(char* arquivo, int idDoc, tipoVetPesos vetPesos, hashTablePalavras tabela, int tamTabela){
    FILE *fp;
    char palavra[50];
    fp = fopen(arquivo, "r");
    
    if(fp == NULL){
        printf("ERRO: Arquivo *%s* nao encontrado!\n", arquivo);
        return;
        
    } else{

    while(fscanf(fp, "%50s", palavra) != EOF){

        for(int i=0; palavra[i] != '\0'; i++){
                palavra[i] = tolower(palavra[i]);

                if ('a' > palavra[i] || palavra[i] > 'z'){
                    strcpy(&palavra[i], &palavra[i + 1]);

                }
            }
            insereHashTablePalavras(palavra, idDoc, vetPesos, tabela, tamTabela);
            
        }
    }
    fclose(fp);
}

void lerArquivos(char* arquivo, listaEncadDocs* listaDocs){
    FILE *fp, *fp2;
    int numArq;
    char nomeArquivo[100];

    fp = fopen(arquivo, "r");
    
    if (fp == NULL){
      printf("ERRO: Arquivo *%s* nao encontrado!\n", arquivo);
      return;

    } else{
      fscanf(fp, "%d", &numArq);

      for(int i=0; i<numArq; i++){
        fscanf(fp, "%100s", nomeArquivo);
        fp2 = fopen(nomeArquivo, "r");

        if (fp2 == NULL){
            printf("ERRO: Arquivo *%s* nao encontrado!\n", nomeArquivo);

        } else{
            insereDoc(nomeArquivo, listaDocs);
            
        }
        fclose(fp2);

        }
    }
    fclose(fp);
    
}
