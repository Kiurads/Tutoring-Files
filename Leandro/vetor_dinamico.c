#include <stdio.h>
#include <stdlib.h>

typedef struct concorrente
{
    char nome[100];
    int posicao;
} Concorrente, *pConcorrente;

int main(int argc, char **argv)
{
    int opcao;
    int tamanho = 0;
    pConcorrente arrayConcorrentes;

    do
    {
        printf("\n1 - Registar concorrente\n");
        printf("0 - Terminar corrida\n\n");

        printf("Opcao: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:            
            if (tamanho == 0)
            {
                tamanho++;
                
                arrayConcorrentes = malloc(sizeof(Concorrente));

                if (arrayConcorrentes == NULL)
                {
                    printf("ERRO: malloc()\n");
                    return 1;
                }
            }
            else
            {
                tamanho++;
                
                arrayConcorrentes = realloc(arrayConcorrentes, sizeof(Concorrente) * tamanho);

                if (arrayConcorrentes == NULL)
                {
                    printf("ERRO: realloc()\n");
                    return 1;
                }
            }

            printf("Nome do concorrente: ");
            scanf(" %[^\n]", arrayConcorrentes[tamanho - 1].nome);

            arrayConcorrentes[tamanho - 1].posicao = tamanho;
            
            break;

        case 0:
            printf("Corrida terminada!\n");
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d. %s\n", arrayConcorrentes[i].posicao, arrayConcorrentes[i].nome);
    }

    free(arrayConcorrentes);
}