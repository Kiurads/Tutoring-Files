#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {
    int array1[TAM];

    for (int i = 0; i < TAM; i++)
    {
        array1[i] = i * 2;
    }

    for (int i = TAM - 1; i >= 0; i--)
    {
        printf("[%d] = %d\n", i, array1[i]);
    }
        
}