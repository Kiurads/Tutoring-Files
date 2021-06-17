#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Recebes um numero e guardas numa variavel chamada "ciclos"
    Fazes um ciclo for que corra "ciclos" vezes
    Dentro do for receber um numero e imprimir se este numero é impar ou par (n % 2--)

    Declarar um array de inteiros com 3 posições em que todas as posições começam a 0
    Guardar os 3 maiores numeros inseridos
    Mostrar o array no final do programa
    */

    int a, b, resultado;
    int array[3] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Introduza dois numeros: ");
        scanf(" %d %d", &a, &b);

        resultado = a + b;
    
        printf("Resultado da soma: %d + %d = %d\n\n", a, b, resultado);
    }
    
}