#include <stdio.h>
#include <stdlib.h>

struct data
{
    int dia;
    int mes;
    int ano;
};

int main()
{
    struct data* ponteiroData;
    int d, m, a;

    ponteiroData = malloc(sizeof(struct data));

    printf("Insira uma data (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &d, &m, &a);

    ponteiroData->dia = d;
    ponteiroData->mes = m;
    ponteiroData->ano = a;

    printf("%d/%d/%d", ponteiroData->dia, ponteiroData->mes, ponteiroData->ano);
    
}