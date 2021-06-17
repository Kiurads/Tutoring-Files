#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, resultado;

    printf("Introduza dois numeros: ");
    scanf(" %d %d", &a, &b);

    resultado = a + b;
    
    printf("Resultado da soma: %d + %d = %d\n", a, b, resultado);

    if (resultado > 10)
    { 
        printf("Maior que 10!\n");
    }
    else // resultado <= 10
    {
        if (resultado >= 0)
        {
            printf("Resultado nao negativo!\n");
        }
        else // resultado < 0
        {
            printf("Resultado negativo!\n");
        }
    }

    switch (resultado)
    {
    case 5:
        printf("Resultado deu 5!\n");
    
    default:
        printf("Resultado obtido!\n");
        break;
    }
}