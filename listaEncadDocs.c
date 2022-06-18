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

        insereDocI(*doc, listaDocs);

    }
}

void imprimeListaDocs(listaEncadDocs listaDocs){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;
    printf("\nDocumentos inseridos:\n\n");

    while (aux != NULL){
        printf("Nome doc: %-5s | idDoc: %-3d\n", aux->doc.nomeDoc, aux->doc.idDoc);
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

void escrevePalavrasDocs(listaEncadDocs listaDocs){
    apontadorDoc aux;

    aux = listaDocs.primeiro->prox;

    while (aux != NULL){
        lerPalavras(aux->doc.nomeDoc);
        aux = aux->prox;
        //Mudar flag
    }
}

void lerPalavras(char* arquivo){
    FILE *fp;
    fp = fopen(arquivo, "r");
    char palavra[50];
    if(fp == NULL){
        printf("ERRO: Arquivo *%s* nao encontrado!\n", arquivo);
    }else{
    while(fscanf(fp, "%50s", palavra) != EOF){
        for(int i=0; palavra[i] != '\0'; i++){
                palavra[i] = tolower(palavra[i]);
                if ('a' > palavra[i] || palavra[i] > 'z'){
                    strcpy(&palavra[i], &palavra[i + 1]);
                }
            }
            printf("%s\n", palavra);
        }
    }
    fclose(fp);
}

void lerArquivos(char* arquivo, listaEncadDocs* listaDocs){
    FILE *fp, *fp2;
    fp = fopen(arquivo, "r");
    int numArq;
    char nomeArquivo[100];  
    if (fp == NULL){
      printf("ERRO: Arquivo *%s* nao encontrado!\n", arquivo);
    }
    else{
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
