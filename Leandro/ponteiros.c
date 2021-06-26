#include <stdlib.h>
#include <stdio.h>

void menu();

void soma(float x, float y, float *res);

void subtrai(float x, float y, float *res);

void multiplica(float x, float y, float *res);

void divide(float x, float y, float *res);


int main()
{
    float operando1, operando2;
    float resultado;
    int operacao;

    do
    {
        printf("Insira dois operandos(x y): ");
        scanf(" %f %f", &operando1, &operando2);

        menu();
        scanf(" %d", &operacao);

        switch (operacao)
        {
        case 1:
            soma(operando1, operando2, &resultado);

            printf("%.1f + %.1f = %.1f\n\n", operando1, operando2, resultado);

            break;
        case 2:
            subtrai(operando1, operando2, &resultado);

            printf("%.1f - %.1f = %.1f\n\n", operando1, operando2, resultado);

            break;
        case 3:
            multiplica(operando1, operando2, &resultado);

            printf("%.1f * %.1f = %.1f\n\n", operando1, operando2, resultado);

            break;
        case 4:
            divide(operando1, operando2, &resultado);

            printf("%.1f / %.1f = %.1f\n\n", operando1, operando2, resultado);

            break;

        default:
            printf("Operacao invalida\n\n");
            break;
        }
        


    } while (operando1 != 0 && operando2 != 0);
}

void menu() {
    printf("1 - Somar\n");
    printf("2 - Subtrair\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
}

void soma(float x, float y, float *res)
{
    *res = x + y; 
}

void subtrai(float x, float y, float *res)
{
    *res = x - y;
}

void multiplica(float x, float y, float *res)
{
    *res = x * y;
}

void divide(float x, float y, float *res)
{
    *res = x / y;
}

/*
 * Fazer programa de calculadora
 * Em ciclo:
 * Receber dois inteiros e o tipo de operacao a fazer
 * Para cada tipo de operacao criar uma funcao que receba os dois operandos e o ponteiro para o resultado
 * Nenhuma das funcoes devolve nada nem imprime nada para a consola
 * No final de cada operacao imprimir o resultado
 * NOTA: Nao fazer nenhum calculo na funcao main()
 * 
 * Quando algum dos operandos for 0 terminar o programa
*/