#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int numeros;

    //Inicializar gerador
    srand(time(NULL));

    do
    {
        printf("Introduza um numero: ");
        scanf(" %d", &numeros);
    } while (numeros < 1);

    for (int i = 0; i < numeros; i++)
    {
        int aleatorio = rand() % 100 + 1;

        printf("Numero sorteado: %d\n", aleatorio);

        switch (aleatorio)
        {
        case 3:
            printf("Saiu o 3!\n");
            break;

        case 7:
            printf("Numero da sorte!\n");
            break;

        case 13: 
            printf("Numero do azar\n");
            break;
        }

        if (aleatorio > 50)
        {
            printf("Numero maior que 50\n");
        }

        if (aleatorio < 50)
        {
            printf("Numero menor que 50\n");
        }
        
        printf("\n");
    }
    
    
    /*
     * Fazer um programa de sorteio de numeros
     * Inicialmente pede um inteiro ao utilizador que vai representar o numero de numeros sorteados
     * Volta a pedir o numero ao utilizador ENQUANTO esse numero for menor que 1
     * Depois de introduzir um numero valido gerar numeros sorteados e imprimir cada um
     * Se o numero for 3 imprimir "Saiu o 3"
     * Se o numero for 7 imprimir "Numero da sorte!"
     * Se o numero for 13 imprimir "Numero do azar!"
     * No final da geracao de cada numero imprimir se este e maior ou menor que 50
    */
}