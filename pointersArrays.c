#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void preenche(int array[], int tam);

int main() {
    int array[TAM];
    int *ptr;

    ptr = array;

    for (int i = 0; i < TAM; i++)
    {
        printf("ARRAY[%d]: ", i + 1);

        scanf(" %d", ptr);

        ptr++;
    }

    ptr = &array[TAM - 1];

    for (int i = TAM; i > 0; i--)
    {
        printf("ARRAY[%d]: %d\n", i, *ptr);
        ptr--;
    }
}

void preenche(int *array, int tam) {
    for (int i = 0; i < tam; i++)
    {
        printf("Acesso a referencia %d\n", array + i);
        *(array++) = i*5;
    }
}

/*
Recebas um array (declarado ou pela consola) e, através de
um ponteiro auxiliar imprimir o array invertido
*/