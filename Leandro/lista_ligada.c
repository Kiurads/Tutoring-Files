#include <stdio.h>
#include <stdlib.h>

typedef struct arma Arma, *pArma;

struct arma
{
    char nome[100];

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

pArma adicionaElementoFim(pArma listaArmas)
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

    novoElemento->prox = NULL;

    if (listaArmas == NULL)
    {
        listaArmas = novoElemento;
    }
    else
    {
        pArma aux;

        aux = listaArmas;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = novoElemento;
    }

    return listaArmas;
}

pArma removeArmas(pArma listaArmas)
{
    char c;
    pArma atual, anterior;

    printf("Remover armas cujo nome comeca por: ");
    scanf(" %c", &c);

    atual = listaArmas;

    while (atual != NULL)
    {
        if (atual->nome[0] == c)
        {
            if (atual == listaArmas)
            {
                listaArmas = atual->prox;
                free(atual);

                atual = listaArmas;
            }
            else
            {
                anterior->prox = atual->prox;
                free(atual);

                atual = anterior->prox;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }

    return listaArmas;
}

int main()
{
    pArma listaArmas, aux;

    listaArmas = NULL;

    for (int i = 0; i < 5; i++)
    {
        listaArmas = adicionaElementoFim(listaArmas);
        listaArmas = adicionaElementoInicio(listaArmas);
    }

    aux = listaArmas;

    while (aux != NULL)
    {
        printf("");
        printf("%s->", aux->nome);

        aux = aux->prox;
    }

    printf("NULL\n");

    listaArmas = removeArmas(listaArmas);

    aux = listaArmas;

    while (aux != NULL)
    {
        printf("");
        printf("%s->", aux->nome);

        aux = aux->prox;
    }

    printf("NULL\n");

    while (listaArmas != NULL)
    {
        aux = listaArmas;
        listaArmas = listaArmas->prox;
        free(aux);
    }   
}