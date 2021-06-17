#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

// No final da string existe um \0

int main()
{    
    char origem[TAM]; 
    char destino[TAM];

    scanf(" %s", origem);

    strcpy(destino, origem);

    printf("%s %d\n", destino, strlen(destino));

    for (int i = 0; i <= strlen(origem); i++)
    {
        printf("%d ", origem[i]);
    }

    if (strcmp(origem, destino) == 0)
    {
        printf("Iguais\n");
    }
    
    strcat(destino, origem);

    printf("%s %d\n", destino, strlen(destino));

    if (strcmp(origem, destino) == 0)
    {
        printf("Iguais\n");
    }
}

/*
Programa de registo - declaras um username e uma password

Recebas um username e uma password e verifiques se são iguais
*/