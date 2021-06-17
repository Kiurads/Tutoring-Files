#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main()
{
    /*
    Recebes um numero e guardas numa variavel chamada "ciclos"
    Fazes um ciclo for que corra "ciclos" vezes
    Dentro do for receber um numero e imprimir se este numero é impar ou par (n % 2--)

    Declarar um array de inteiros com 3 posições em que todas as posições começam a 0
    Guardar os 3 maiores numeros inseridos
    Mostrar o array no final do programa
    */

    int n, ciclos;
    int array[TAM] = {0};

    printf("Quantos numeros quer receber: ");
    scanf(" %d", &ciclos);

    for (int i = 0; i < ciclos; i++)
    {
        printf("Introduza um inteiro: ");
        scanf(" %d", &n);

        for (int j = 0; j < TAM; j++)
        {
            if (n > array[j])
            {
                int valor = array[j];

                array[j] = n;

                n = valor;
            }
        }
    }

    printf("Os maiores numeros foram: ");

    for (int i = 0; i < TAM; i++)
    {
        printf("[%d]", array[i]);
    }
}