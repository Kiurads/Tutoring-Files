#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int linha;
    int soma;
    int matrix[TAM][TAM];

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            matrix[i][j] = i + j;

            printf("|%d", matrix[i][j]);
        }

        printf("|\n");
    }

    printf("\nSelecione a linha a somar: ");
    scanf(" %d", &linha);

    if (linha < TAM && linha >= 0)
    {
        soma = 0;

        for (int i = 0; i < TAM; i++)
        {
            soma += matrix[linha][i];
        }
        
        printf("Soma = %d", soma);
    }
    else 
    {
        printf("Linha %d não existe!", linha);
    }
}