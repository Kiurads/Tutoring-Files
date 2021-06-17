#include <stdio.h>
#include <stdlib.h>

void atribui(int *pointer, int val);

int main()
{
    /*
    Valores
    Referências
    Ponteiros
    */

    int a = 10;
    int *b = &a;

    *b = 60;

    printf("a: %d\n\n", a);

    printf("&a: %d\n\n", &a);

    printf("b: %d\n\n", b);

    printf("&b: %d\n\n", &b);

    printf("*b: %d\n\n", *b);

    atribui(&a, 40);

    printf("a: %d\n\n", a);
}

void atribui(int *pointer, int val)
{
    *pointer = val;
}