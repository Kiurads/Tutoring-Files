#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa concorrente, *pconcorrente;

struct pessoa
{
    int posicao;
    char nome[100];

    pconcorrente prox;
};

pconcorrente cria_elemento(int posicao);
pconcorrente preenche_lista(pconcorrente lista);
pconcorrente adiciona_elemento_fim(pconcorrente p);
pconcorrente remove_elemento(pconcorrente p, int posicao);
void preenche(pconcorrente p);

int main()
{
    pconcorrente lista, aux;

    lista = NULL;

    lista = preenche_lista(lista);

    /*

    lista = adiciona_elemento_fim(lista);
    lista = adiciona_elemento_fim(lista);
    lista = adiciona_elemento_fim(lista);
    lista = adiciona_elemento_fim(lista);
    lista = adiciona_elemento_fim(lista);

    */

    aux = lista;

    while (aux != NULL)
    {
        printf("Posicao: %d\n", aux->posicao);
        printf("Nome: %s\n\n", aux->nome);

        aux = aux->prox;
    }

    /*

    lista = remove_elemento(lista, 3);
    lista = remove_elemento(lista, 3);

    aux = lista;

    while (aux != NULL)
    {
        printf("Posicao: %d\n", aux->posicao);
        printf("Nome: %s\n\n", aux->nome);

        aux = aux->prox;
    }

    */
}

pconcorrente adiciona_elemento_fim(pconcorrente p)
{
    pconcorrente novo, aux;

    novo = malloc(sizeof(concorrente));

    if (novo == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return NULL;
    }

    preenche(novo);

    if (p == NULL)
    {
        novo->posicao = 1;
        p = novo;
    }
    else
    {
        int posicao = 2;
        aux = p;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
            posicao++;
        }

        novo->posicao = posicao;

        aux->prox = novo;
    }

    return p;
}

pconcorrente remove_elemento(pconcorrente p, int posicao)
{
    pconcorrente aux, atual, anterior;

    atual = p;
    anterior = NULL;

    while (atual != NULL)
    {
        if (atual->posicao == posicao)
        {
            break;
        }
        
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
    {
        return p;
    }

    if (anterior == NULL)
    {
        p = atual->prox; //P passa a apontar para o segundo elemento, que é o próximo do atual
    }
    else
    {
        anterior->prox = atual->prox; //Elemento anterior passa a apontar para o próximo do atual
    }

    aux = atual->prox;

    while (aux != NULL)
    {
        aux->posicao--;

        aux = aux->prox;
    }

    free(atual);

    return p; 
}

void preenche(pconcorrente p)
{
    p->prox = NULL;

    printf("Nome: ");
    scanf(" %99[^\n]", p->nome);
}

pconcorrente preenche_lista(pconcorrente lista)
{
    pconcorrente aux;

    for (int i = 0; i < 3; i++)
    {
        pconcorrente novo = cria_elemento(i + 1);

        if (novo == NULL)
        {
            printf("Erro na alocacao de memoria!\n");
            return NULL;
        }

        if (lista == NULL)
        {
            lista = novo;
            aux = lista;
        }
        else
        {
            aux->prox = novo;
            aux = aux->prox;
        }
    }

    return lista;
}

pconcorrente cria_elemento(int posicao)
{
    pconcorrente novo = malloc(sizeof(concorrente));

    if (novo == NULL)
    {
        printf("Erro na alocacao de memoria!\n");
        return NULL;
    }

    novo->posicao = posicao;
    printf("Nome %d: ", posicao);
    scanf(" %s", novo->nome);
    novo->prox = NULL;

    return novo;
}