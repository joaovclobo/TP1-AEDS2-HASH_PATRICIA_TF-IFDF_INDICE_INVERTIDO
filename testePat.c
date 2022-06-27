#include "patricia.h"
#include <string.h>

int main(){
    char textos[50];
    tipoArvore a = NULL;
    for (int i = 0; i < 5; i++){
        printf("str: ");
        scanf("%s", textos);
        a = insere(textos, 1, &a);
    }
    char tes[50] = "atum";
    printf("%d\n", quantasPalavras(a, 1));
    strcpy(tes, pesquisa(tes, a).valPalavra);
    printf("%s", tes);
}