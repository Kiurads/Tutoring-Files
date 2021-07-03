#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 7

int soma(int a, int b);

int maior(int array[DIM]);

int main()
{
    int i1, i2;
    int array[DIM] = {1, 5, 34, 2, 87, 9, 12};
    int resultado;

    i1 = 1;
    i2 = 2;

    resultado = soma(i1, i2);

    printf("Maior elemento: %d", maior(array));
}

int soma(int a, int b) {
    return a + b;
}

int maior(int array[DIM])
{
    int maior = 0;

    for (int i = 0; i < DIM; i++)
    {
        if (array[i] > maior)
        {
            maior = array[i];
        }
    }
    
    return maior;
}