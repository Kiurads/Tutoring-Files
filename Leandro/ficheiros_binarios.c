#include <stdio.h>
#include <stdlib.h>

struct Dados
{
    int a;
    float b;
    char c[20];
};

int main(int argc, char **args)
{
    struct Dados dados;
    FILE *f;

    printf("Escreve um inteiro: ");
    scanf(" %d", &dados.a);

    printf("Escreve um decimal: ");
    scanf(" %f", &dados.b);

    printf("Escreve uma palavra: ");
    scanf(" %s", dados.c);

    f = fopen("dados.bin", "wb");

    if (f == NULL)
    {
        printf("ERRO: fopen()");
        return 1;
    }

    fwrite(&dados, sizeof(struct Dados), 1, f);

    fclose(f);

    f = fopen("dados.bin", "rb");

    if (f == NULL)
    {
        printf("ERRO: fopen()");
        return 1;
    }

    while (fread(&dados, sizeof(struct Dados), 1, f) == 1)
    {
        /* code */
    }

    printf("Foram lidos %d elementos\n", fread(&dados, sizeof(struct Dados), 1, f));

    fclose(f);

    printf("%d | %f | %s\n", dados.a, dados.b, dados.c);
}