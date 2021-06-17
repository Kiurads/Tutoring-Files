#include <stdio.h>
#include <stdlib.h>

typedef struct Corrida pessoa;

struct Corrida
{
    char nome[50];
    int posicao;
};

int main()
{
    int tam;
    pessoa *array_pessoas; //Declarar vetor dinamico

    tam = 5;

    for (int i = 0; i < tam; i++)
    {
        if (i == 0)
        {
            int resultado = qualquerCoisa();

            if(resultado == 1)
            array_pessoas = malloc(sizeof(pessoa));  //Inicializar vetor dinamico

            if (array_pessoas == NULL)
            {
                printf("ERRO: Alocar memoria falhou!\n");
                return 1;
            }

            printf("\nMemoria alocada para a 1a posicao\n");
        }
        else
        {
            array_pessoas = realloc(array_pessoas, sizeof(pessoa) * (i + 1));
            
            if (array_pessoas == NULL)
            {
                printf("ERRO: Alocar memoria falhou!\n");
                return 1;
            }

            printf("\nMemoria alocada para a %da posicao\n", i + 1);
        }  //Adicionar posição ao vetor

        printf("Insira o nome do concorrente: ");
        scanf(" %s", array_pessoas[i].nome);

        array_pessoas[i].posicao = i + 1;
    }

    for (int i = 0; i < tam; i++)
    {
        printf("lista_pessoas[%s]: %do\n", array_pessoas[i].nome, array_pessoas[i].posicao);
    }

    free(array_pessoas); //Libertar memória

    return 0;

    /*

   int *array;

   array = malloc(sizeof(int) * 7);   

   for (int i = 0; i < 7; i++)
   {
       array[i] = i + 1;
   }

   for (int i = 0; i < 7; i++)
   {
       printf("Array[%d]: %d\n", i, array[i]);
   }

   array = realloc(array, sizeof(int) * 14);

   free(array);

   */
}


/*
 - Declarar array dinamico de inteiros
 - Receber números
 - Aumentar o array por cada número positivo e inserir esse número no array
 - Diminuir o array por cada número negativo
 - Imprimir sempre o estado atual do array
 - Terminar quando o utilizador escrever 0
 - Libertar memória
*/