#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 5

int main() {
    int matriz[LINHAS][COLUNAS];

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            matriz[i][j] = i + j;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

/*
Exercicio igual ao dos pares e impares
Copies a matriz para uma matrizes que terá só os valores pares, da seguinte forma:

1 2 3    0 2 0
2 3 4 -> 2 0 4
3 4 5    0 4 0

Indicar tamanho da matriz (altura e largura) no início do programa através de um scanf
*/