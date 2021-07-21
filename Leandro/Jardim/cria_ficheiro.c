#include <stdio.h>
#include <stdlib.h>

typedef struct Data data,*pdata;
struct Data
{
    int dia,mes,ano;
};

typedef struct Jardineiro jardineiro,*pjardineiro;
struct Jardineiro
{
    char nome[100];
    data data_nascimento;
    int hentrada,hsaida;
    pjardineiro prox; // em structs de listas ligadas TEM DE TER SEMPRE PONTEIRO PARA O PROX ELEMENTO
};

int main(int argc, char **args)
{
    jardineiro jardineiroAuxiliar;
    FILE *f;

    f = fopen(".\\jardineiros\\jardineiros.bin", "wb");

    if (f == NULL)
    {
        printf("ERRO: fopen()");
        return 1;
    }

    for (size_t i = 0; i < 4; i++)
    {
        printf("Nome: ");
        scanf(" %[^\n]", jardineiroAuxiliar.nome);

        printf("Data de data_nascimento: ");
        scanf(" %d/%d/%d", &jardineiroAuxiliar.data_nascimento.dia, &jardineiroAuxiliar.data_nascimento.mes, &jardineiroAuxiliar.data_nascimento.ano);

        printf("Hora de chegada: ");
        scanf(" %d", &jardineiroAuxiliar.hentrada);

        printf("Hora de saida: ");
        scanf(" %d", &jardineiroAuxiliar.hsaida);

        fwrite(&jardineiroAuxiliar, sizeof(jardineiro), 1, f);
    }

    fclose(f);
}