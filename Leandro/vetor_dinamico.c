#include <stdio.h>
#include <stdlib.h>

typedef struct concorrente
{
    char nome[100];
    int numero;
} Concorrente, *pConcorrente;

int main(int argc, char **argv)
{
    int nConcorrentes;
    pConcorrente arrayConcorrentes;

    printf("Quantos concorrentes participam: ");
    scanf(" %d", &nConcorrentes);

    for (int i = 0; i < nConcorrentes; i++)
    {
        if (i == 0)
        {
            arrayConcorrentes = malloc(sizeof(Concorrente));

            if (arrayConcorrentes == NULL)
            {
                printf("ERRO: malloc() deu erro\n\n");
                return 1;
            }
        }
        else
        {
            arrayConcorrentes = realloc(arrayConcorrentes, sizeof(Concorrente) * (i + 1));

            if (arrayConcorrentes == NULL)
            {
                printf("ERRO: realloc() deu erro\n\n");
                return 1;
            }
        }

        printf("Nome do concorrente %d: ", i + 1);
        scanf(" %[^\n]", &arrayConcorrentes[i]);

        arrayConcorrentes[i].numero = i * (2 + i);
    }

    for (int i = 0; i < nConcorrentes; i++)
    {
        printf("Concorrente %s ficou com o numero %d\n", arrayConcorrentes[i].nome, arrayConcorrentes[i].numero);
    }

    printf("\n");

    arrayConcorrentes = realloc(arrayConcorrentes, sizeof(Concorrente) * (--nConcorrentes));

    if (arrayConcorrentes == NULL)
    {
        printf("ERRO: realloc() deu erro\n\n");
        return 1;
    }

    for (int i = 0; i < nConcorrentes; i++)
    {
        printf("Concorrente %s ficou com o numero %d\n", arrayConcorrentes[i].nome, arrayConcorrentes[i].numero);
    }

    free(arrayConcorrentes);
}