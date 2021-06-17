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

pconcorrente iniciar_lista(pconcorrente lista);

int main()
{
    pconcorrente lista, aux; //Declara ponteiro para inicio da lista

    lista = NULL;

    lista = iniciar_lista(lista); //Chama função para inicializar a lista

    aux = lista;

    //Imprime a lista
    while (aux != NULL)
    {
        printf("Posicao: %d\n", aux->posicao);
        printf("Nome: %s\n\n", aux->nome);

        aux = aux->prox;
    }

    printf("Posicao: %d\n", lista->posicao);
    printf("Nome: %s\n\n", lista->nome);
    
    
}

//Função para inicializar a lista
pconcorrente iniciar_lista(pconcorrente lista)
{
    pconcorrente aux;

    for (int i = 0; i < 5; i++)
    {
        pconcorrente novo = malloc(sizeof(concorrente));

        if (novo == NULL)
        {
            printf("ERRO: Alocar memoria falhou!\n");
            return NULL;
        }

        novo->posicao = i + 1;
        printf("Nome do %do concorrente: ", i + 1);
        scanf(" %99[^\n]", novo->nome);
        novo->prox = NULL;

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