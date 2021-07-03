#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct decimal Decimal, *pDecimal;

struct decimal
{
    float valor;

    pDecimal prox;
};

pDecimal adicionaInicio(pDecimal inicioLista)
{
    //1 - Criar o novo nó

    pDecimal novo = malloc(sizeof(Decimal));

    if (novo == NULL)
    {
        return NULL;
    }

    //2 - Preencher o novo nó

    novo->valor = (float) rand() / (float) RAND_MAX; //float aleatorio
    novo->prox = NULL;

    //3 - Adicionar nó à lista

    if (inicioLista != NULL)
    {
        novo->prox = inicioLista;
    }
    
    inicioLista = novo;
    
    
}

int main()
{
    srand(time(NULL));

    pDecimal inicioLista = NULL;

    inicioLista = adicionaInicio(inicioLista);
}