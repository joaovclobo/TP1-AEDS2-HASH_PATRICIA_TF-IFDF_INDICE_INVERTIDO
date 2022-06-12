// VEM CABEÇALHO
#include "listaEncadPares.h"

#include <sys/time.h>
#define MAX 10

int main(int argc, char *argv[])
{
    struct timeval t;

    listaEncadPares lista;
    tipoPar parTeste;
    int mat[MAX][2];
    tipoApontadorPar p;
    int i, j, k, n;
    float tamanho = 0;
    gettimeofday(&t, NULL);
    srand((unsigned int)t.tv_usec);
    flParesVazia(&lista);

    /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
    for (i = 0; i < MAX; i++) mat[i][0] = i + 1;
    for (i = 0; i < MAX; i++)
    {
        k = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        j = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        n = mat[k][0];
        mat[k][0] = mat[j][0];
        mat[j][0] = n;
    }

    for (i = 0; i < MAX; i++) mat[i][1] = i + 1;
    for (i = 0; i < MAX; i++)
    {
        k = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        j = (int)(10.0 * rand() / (RAND_MAX + 1.0));
        n = mat[k][1];
        mat[k][1] = mat[j][1];
        mat[j][1] = n;
    }
    /*Insere cada chave na lista */
    for (i = 0; i < MAX; i++)
    {
        parTeste.qtde = mat[i][0];
        parTeste.idDoc = mat[i][1];

        insereListaPares(parTeste, &lista);
        tamanho++;
        printf("Inseriu: "); imprimePar(parTeste);
    }

    imprimeListaPares(lista);

    /*Retira cada chave da lista */
    for (i = 0; i < MAX/2; i++)
    { /*escolhe uma chave aleatoriamente */
        k = (int)((tamanho)*rand() / (RAND_MAX + 1.0));
        p = lista.primeiro;
        /*retira chave apontada */
        retiraListaPares(p, &lista, &parTeste);
        tamanho--;
        printf("Retirou: "); imprimePar(parTeste);
        printf("Nova lista:\n"); imprimeListaPares(lista);
    }

    return (0);
}