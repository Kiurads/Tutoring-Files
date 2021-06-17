#include <stdio.h>
#include <stdlib.h>

typedef struct coordenadas coordenadas, *pcoordenadas;

struct coordenadas
{
    int x;
    int y;

    pcoordenadas prox;
};

pcoordenadas adicionaElemento(pcoordenadas p, int x, int y) 
{
    pcoordenadas novoElemento = malloc(sizeof(coordenadas));

    novoElemento->x = x;
    novoElemento->y = y;

    novoElemento->prox = NULL;

    if (p == NULL)
    {
        p = novoElemento;
    }
    else
    {
        novoElemento->prox = p;
        p = novoElemento;
    }
    
    return p;
}

int main() 
{
    pcoordenadas lista, aux;

    lista = NULL;

    int linha, coluna;

    do
    {
        printf("Introduza as coordenadas: ");
        scanf(" %d %d", &linha, &coluna);

        lista = adicionaElemento(lista, linha, coluna);
    } while (linha >= 0 && coluna >= 0);

    aux = lista;

    while (aux != NULL)
    {
        printf("X: %d | Y: %d\n", aux->x, aux->y);

        aux = aux->prox;
    }  
}


