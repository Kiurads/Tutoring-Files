#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 2;

    int *b = &a;

    printf("A: %d\n", a);

    printf("&A: %d\n", &a);

    printf("B: %d\n", b);

    printf("&B: %d\n", &b);

    printf("*B: %d\n", *b);

    *b = 5;

    printf("A: %d | *B: %d", a, *b);
}