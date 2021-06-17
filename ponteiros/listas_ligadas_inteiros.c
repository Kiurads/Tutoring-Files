#include <stdio.h>
#include <stdlib.h>

typedef struct nums number, *pnumber;

struct nums
{
    int num;

    pnumber prox;
};

pnumber addNode(pnumber list, int num);
pnumber removeNode(pnumber list, int num);

int main()
{
    int num;
    pnumber list, aux;

    list = NULL;

    do
    {
        printf("Introduza um numero: ");
        scanf(" %d", &num);

        if (num != 0)
        {
            if (num > 0)
            {
                list = addNode(list, num);

                if (list == NULL)
                {
                    printf("ERRO: Alocar memoria falhou!\n");
                    return 1;
                }
                
            }
            else
            {
                list = removeNode(list, (num * -1));
            }

            aux = list;

            while (aux != NULL)
            {
                if (aux != list )
                {
                    printf(" -> ");
                }
                
                printf("%d", aux->num);

                aux = aux->prox;
            }
            
            printf("\n");
        }
        
    } while (num != 0);
    
    return 0;
}

pnumber addNode(pnumber list, int num)
{
    pnumber new, aux;

    new = malloc(sizeof(number));

    if (new == NULL)
    {
        return NULL;
    }

    new->num = num;
    new->prox = NULL;

    if (list == NULL)
    {
        list = new;
    }
    else
    {
        aux = list;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
        aux->prox = new;
    }

    return list;  
}

pnumber removeNode(pnumber list, int num) 
{
    pnumber previous, aux;

    previous = NULL;
    aux = list;

    while (aux != NULL)
    {
        if (aux->num == num)
        {
            if (previous == NULL)
            {
                list = aux->prox;
            }
            else
            {
                previous->prox = aux->prox;
            }

            free(aux);
            break;
        }

        previous = aux;
        aux = aux->prox;        
    }

   return list;
}
