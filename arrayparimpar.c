#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main() {
    int array[TAM];
    int nPares;
    int nImpares;

    nPares = nImpares = 0;

    for (int i = 0; i < TAM; i++)
        array[i] = i * 13;
    
    for (int i = 0; i < TAM; i++)
    {
        if (array[i] % 2 == 0)
            nPares++;
        else
            nImpares++;
    }

    int arrayPares[nPares];
    int arrayImpares[nImpares];
    int posPares;
    int posImpares;

    posPares = posImpares = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (array[i] % 2 == 0) 
            arrayPares[posPares++] = array[i];
        else 
            arrayImpares[posImpares++] = array[i];
    }

    for (int i = 0; i < nPares; i++)
        printf("PAR [%d] = %d\n", i, arrayPares[i]);

    printf("\n");
    
    for (int i = 0; i < nImpares; i++)
        printf("IMPAR [%d] = %d\n", i, arrayImpares[i]);
    
}