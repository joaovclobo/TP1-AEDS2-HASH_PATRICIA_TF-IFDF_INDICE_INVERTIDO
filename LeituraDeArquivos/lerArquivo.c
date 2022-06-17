#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(){
    char arquivo[100] = "entrada";
    void lerPalavras();
    void lerArquivos();

    lerArquivos(arquivo);
    //lerPalavras(arquivo);
    return 0;
}


void lerPalavras(char arquivo[100]){
    FILE *fp;
    fp = fopen(arquivo, "r");
    char palavra[50];
    if(fp == NULL){
        printf("ERROR: could not open file");
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

  
void lerArquivos(char arquivo[100]){
    FILE *fp;
    fp = fopen(arquivo, "r");
    int numArq;
    char nomeArquivo[100];  
    if (fp == NULL){
      printf("ERROR: could not open file ");
    }
    else{
      fscanf(fp, "%d", &numArq);
      for(int i=0; i<numArq; i++){
        fscanf(fp, "%100s", nomeArquivo);
        printf("nome do arquivo lido: %s\n", nomeArquivo);
        lerPalavras(nomeArquivo);
        }
    }
    fclose(fp);
}