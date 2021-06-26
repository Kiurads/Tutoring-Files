#include <stdio.h>
#include <stdlib.h>

#define DIM 7

int verifica(float temperatura);

float mediaTemperaturas(float array[DIM]);

int main()
{
    float arrayTemperaturas[DIM];

    for (int i = 0; i < DIM; i++)
    {
        do
        {
            printf("Temperatura no dia %d: ", i + 1);
            scanf(" %f", &arrayTemperaturas[i]);
        } while (!verifica(arrayTemperaturas[i]));
    }

    for (int i = 0; i < DIM; i++)
    {
        printf("%.1f ", arrayTemperaturas[i]);
    }

    mostraMenu();

    printf("\n%.2f\n", mediaTemperaturas(arrayTemperaturas));
}

int verifica(float temperatura)
{
    if (temperatura > 50 || temperatura < -50)
    {
        return 0;
    }

    return 1;    
}

float mediaTemperaturas(float array[DIM])
{
    float soma = 0;

    for (int i = 0; i < DIM; i++)
    {
        soma += array[i];
    }

    return soma / DIM;
}

/*
 * Criar programa de meteorologia
 * Pedir ao utilizador a temperatura dos 7 dias de uma semana
 * Não aceitar temperaturas menores que -50 nem maiores que 50
 * No final imprimir as temperaturas e a média das temperaturas
 * NOTA: As temperaturas serão números decimais
*/