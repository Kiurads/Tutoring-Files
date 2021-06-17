#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct animal animais, panimais;

struct animal
{
    int id;
    char nome[100];
    char especie[100];
};

int main()
{
    FILE *f;
    int tamanho = 3;
    animais array[3];

    for (int i = 0; i < tamanho; i++)
    {
        array[i].id = i;

        printf("Nome: ");
        scanf(" %s", array[i].nome);

        printf("Especie: ");
        scanf(" %s", array[i].especie);
    }

    f = fopen("ficheiro.txt", "wt");

    if (f == NULL)
    {
        return 1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        fprintf(f, "%d %s %s\n", array[i].id, array[i].nome, array[i].especie);
    }

    fclose(f);

    int id;
    int conta;
    char nome[100];
    char especie[100];

    f = fopen("ficheiro.txt", "rt");

    if (f == NULL)
    {
        return 1;
    }

    fseek(f, 0, SEEK_SET);

    conta = 0;

    while (fscanf(f, "%d %s %s", &id, nome, especie) == 3)
    {
        array[conta].id = id;
        strcpy(array[conta].nome, nome);
        strcpy(array[conta].especie, especie);

        conta++;
    }

    fclose(f);

    printf("\n");
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("ID: %d\n", array[i].id);

        printf("Nome: %s\n", array[i].nome);

        printf("Especie: %s\n", array[i].especie);
    }
    
}

/*
Dois programas

1 - Escrever linhas de texto (input do utilizador) diretamente para um ficheiro de texto.
    Quando a string introduzida for "fim" então termina o programa;

2 - Abrir ficheiro para leitura e escrever as linhas de texto uma a uma na consola.
*/