#include <stdio.h>
#include <stdlib.h>

char funcao1(int a, int num, char caracter) {

}

int main() {
    int num1, num2;
    char a;

    printf("Introduza dois numeros: ");
    scanf(" %d %d", &num1, &num2);

    printf("Introduza um caracter: ");
    scanf(" %c", &a);

    funcao1(num1, num2, a);
}