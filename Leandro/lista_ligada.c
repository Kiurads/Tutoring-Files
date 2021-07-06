#include <stdio.h>
#include <stdlib.h>

typedef struct arma Arma, *pArma;

struct arma
{
    char nome[100];
    int maxCarregador;
    int carregador;
    float tempoRecarrega;

    pArma prox;
};

pArma adicionaElementoInicio(pArma listaArmas)
{
    pArma novoElemento;

    novoElemento = malloc(sizeof(Arma));

    if (novoElemento == NULL)
    {
        printf("ERRO: malloc()\n");
        return NULL;
    }

    printf("Nome da arma: ");
    scanf(" %[^\n]", novoElemento->nome);

    printf("Capacidade do carregador: ");
    scanf(" %d", &novoElemento->maxCarregador);

    printf("Balas no carregador: ");
    scanf(" %d", &novoElemento->carregador);

    printf("Tempo de recarga: ");
    scanf(" %f", &novoElemento->tempoRecarrega);

    novoElemento->prox = NULL;

    if (listaArmas == NULL)
    {
        listaArmas = novoElemento;
    }
    else
    {
        novoElemento->prox = listaArmas;
        listaArmas = novoElemento;
    }

    return listaArmas;
}

int main()
{
    pArma listaArmas, aux;

    listaArmas = NULL;

    for (int i = 0; i < 5; i++)
    {
        listaArmas = adicionaElementoInicio(listaArmas);
    }

    aux = listaArmas;

    while (aux != NULL)
    {
        printf("Nome da arma: ");
        printf(" %s\n", aux->nome);

        printf("Capacidade do carregador: ");
        printf(" %d\n", aux->maxCarregador);

        printf("Balas no carregador: ");
        printf(" %d\n", aux->carregador);

        printf("Tempo de recarga: ");
        printf(" %f\n", aux->tempoRecarrega);

        printf("\n");

        aux = aux->prox;
    }
}