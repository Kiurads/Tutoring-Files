#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int num;
    int *array;

    size = 0;

    do
    {
        printf("[%d] Introduza um numero: ", size);
        scanf(" %d", &num);

        if (num != 0)
        {
            if (num > 0)
            {
                size++;

                if (size == 1)
                {
                    array = malloc(sizeof(int));
                }
                else
                {
                    array = realloc(array, sizeof(int) * size);
                }

                if (array == NULL)
                {
                    return 1;
                }

                array[size - 1] = num;
            }
            else
            {
                if (size > 0)
                {
                    size--;

                    if (size == 0)
                    {
                        free(array);

                        array = NULL;
                    }
                    else 
                    {
                        array = realloc(array, sizeof(int) * size);

                        if (array == NULL)
                        {
                           return 1;
                        }
                    }
                }
            }

            for (int i = 0; i < size; i++)
            {
                printf("[%d]", array[i]);
            }
            
            printf("\n");
        }
    } while (num != 0);

    free(array);

    return 0;
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