#include <stdio.h>
#include <stdlib.h>

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
    int tamanho = 4;
    animais array[4];

    for (int i = 0; i < tamanho; i++)
    {
        array[i].id = i;

        printf("Nome: ");
        scanf(" %s", array[i].nome);

        printf("Especie: ");
        scanf(" %s", array[i].especie);
    }

    f = fopen("ficheiro.bin", "wb");

    if (f == NULL)
    {
        return 1;
    }

    fwrite(&tamanho, sizeof(int), 1, f);

    for (int i = 0; i < 4; i++)
    {
        fwrite(&array[i], sizeof(animais), 1, f);
    }

    fclose(f);

    f = fopen("ficheiro.bin", "rb");

    if (f == NULL)
    {
        return 1;
    }

    fread(&tamanho, sizeof(int), 1, f);

    for (int i = 0; i < tamanho; i++)
    {
        fread(&array[i], sizeof(animais), 1, f);
    }

    fclose(f);
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("ID: %d\n", array[i].id);

        printf("Nome: %s\n", array[i].nome);

        printf("Especie: %s\n", array[i].especie);
    }
}