#include "patricia.h"
#include <string.h>

int main(){
    char textos[50];
    tipoArvore a = NULL;
    for (int i = 0; i < 8; i++){
        printf("str: ");
        scanf("%s", textos);
        a = insere(textos, 1, &a);
    }
    char* cu = pesquisa("atum", a).valPalavra;
    printf("%d\n", quantasPalavras(a, 1));
    printf("valor %s\n", cu);
}