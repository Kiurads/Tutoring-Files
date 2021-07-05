#include <stdio.h>
#include <stdlib.h>

void escreveFicheiro(char *nomeFicheiro);
void leFicheiro(char *nomeFicheiro);

int main()
{
    escreveFicheiro("Teste.txt");

    leFicheiro("Teste.txt");
}

void escreveFicheiro(char *nomeFicheiro)
{
    int tam;
    char nome[100];
    FILE *f;

    f = fopen(nomeFicheiro, "wt");

    if (f == NULL)
    {
        printf("Erro na abertura/criacao do ficheiro!");
        return;
    }

    printf("Nome para escrever: ");
    scanf(" %[^\n]", nome);

    printf("Quantos numeros vou escrever: ");
    scanf(" %d", &tam);
    
    fprintf(f, "%s: %d\n", nome, tam);

    for (int i = 0; i < tam; i++)
    {
        int num;
        printf("Numero %d: ", i + 1);
        scanf(" %d", &num);

        fprintf(f, "[%d]\n", num);
    }

    fclose(f);
}

void leFicheiro(char *nomeFicheiro)
{
    int tam;
    char nome[100];
    FILE *f;

    f = fopen(nomeFicheiro, "rt");

    if (f == NULL)
    {
        printf("Erro na abertura do ficheiro!");
        return;
    }

    fscanf(f, "%[^:]: %d\n", &nome, &tam);

    printf("%s: %d\n", nome, tam);

    for (int i = 0; i < tam; i++)
    {
        int num;

        fscanf(f, "[%d]\n", &num);

        printf("[%d]\n", num);
    }
    
    fclose(f);
}