#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b);
void soma(int *a, int b);

int main() {
    int a = 2;
    int b = 5;

    printf("A: %d B: %d\n", a, b);

    troca(&a, &b);

    printf("A: %d B: %d\n", a, b);

    soma(&a, b);

    printf("Soma: %d", a);
}

void soma(int *a, int b) {
    *a = *a + b;
}

void troca(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
Recebas 2 inteiros, e através de uma função calcules a soma
e guardes o resultado numa das variáveis
*/