#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

void preenche(int m[TAM][TAM]);
void inicializa(int *a, int tam);

int main()
{
    int m[TAM][TAM];
    int a[TAM];

    inicializa(a, TAM);

    printf("\n\n");

    preenche(m);

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("|%d", m[i][j]);
        }
        
        printf("|\n");
    }
}

void inicializa(int *a, int tam) {
    for (int i = 0; i < tam; i++)
    {
        *(a++) = i * 4;
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(--a));
    }
    
}


void preenche(int m[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            m[i][j] = i + j;
        }
    }
}

/*
Começar com array vazio:
Passar array para uma função e preenchê-lo utilizando a notação de ponteiro (*(a+1))
Imprimir array na função main
*/

/*
Declarar array vazio:
Criar função que preenche array e escreve ao contrário usando a notação de ponteiro
*/