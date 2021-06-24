#include <stdio.h>
#include <stdlib.h>

#define DIM 7

int main()
{
    float media = 0;
    float arrayTemperaturas[DIM];

    for (int i = 0; i < DIM; i++)
    {
        do
        {
            printf("Temperatura no dia %d: ", i + 1);
            scanf(" %f", &arrayTemperaturas[i]);
        } while (arrayTemperaturas[i] > 50 || arrayTemperaturas[i] < -50);

        media += arrayTemperaturas[i];
    }

    media /= DIM;

    for (int i = 0; i < DIM; i++)
    {
        printf("%.1f ", arrayTemperaturas[i]);
    }


    printf("\n%.2f\n", media);
    
}

/*
 * Criar programa de meteorologia
 * Pedir ao utilizador a temperatura dos 7 dias de uma semana
 * Não aceitar temperaturas menores que -50 nem maiores que 50
 * No final imprimir as temperaturas e a média das temperaturas
 * NOTA: As temperaturas serão números decimais
*/