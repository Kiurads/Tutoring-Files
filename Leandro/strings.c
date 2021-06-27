#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char string[100] = "Teste teste teste";

    printf("Barco : Casa = %d | Casa : Barco = %d | Casa : Casa = %d\n", strcmp("Barco", "Casa"), strcmp("Casa", "Barco"), strcmp("Casa", "Casa"));

    printf("%s : %d\n", string, strlen(string));

    strcpy(string, "Ola");

    printf("%s : %d\n", string, strlen(string));

    for (int i = 0; i < 100; i++)
    {
        printf("%c", string[i]);
    }
}