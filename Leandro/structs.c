#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PLANTAS 20

typedef struct Data data;

struct Data
{
    int dia, mes, ano;
};

typedef struct Planta
{
    char especie[50];
    int idade;
    float temperaturaIdeal;
} planta, *pplanta;

typedef struct Jardim
{
    char nome[50];
    data fundacao;
    int nPlantas;
    pplanta plantas;
} jardim;

jardim adicionaPlanta(jardim jardimAtual)
{
    if (jardimAtual.nPlantas == 0)
    {
        jardimAtual.plantas = malloc(sizeof(planta));

        if (jardimAtual.plantas == NULL)
        {
            printf("ERRO: malloc() deu erro\n\n");
            return jardimAtual;
        }
    }
    else
    {
        jardimAtual.plantas = realloc(jardimAtual.plantas, sizeof(planta) * (jardimAtual.nPlantas + 1));

        if (jardimAtual.plantas == NULL)
        {
            printf("ERRO: realloc() deu erro\n\n");
            return jardimAtual;
        }
    }

    printf("Especie: ");
    scanf(" %[^\n]", jardimAtual.plantas[jardimAtual.nPlantas].especie);

    printf("Idade: ");
    scanf(" %d", &jardimAtual.plantas[jardimAtual.nPlantas].idade);

    printf("Temperatura ideal: ");
    scanf(" %f", &jardimAtual.plantas[jardimAtual.nPlantas].temperaturaIdeal);

    jardimAtual.nPlantas++;

    return jardimAtual;
}

jardim removePlanta(jardim jardimAtual)
{
    int posicao;

    if (jardimAtual.nPlantas == 0)
    {
        printf("Plantacao encontra-se vazia\n");
        return jardimAtual;
    }
    
    printf("Posicao a remover a planta (de 1 a %d): ", jardimAtual.nPlantas);
    scanf(" %d", &posicao);

    posicao--;

    if (posicao < 0 || posicao >= jardimAtual.nPlantas)
    {
        printf("Posicao fora dos limites\n\n");
        return jardimAtual;
    }

    for (int i = posicao; i < jardimAtual.; i++)
    {
        /* code */
    }
    

    strcpy(jardimAtual.plantas[posicao].especie, "");

    return jardimAtual;
}

jardim inicializaJardim()
{
    jardim jardimAtual;

    printf("Nome do jardim: ");
    scanf(" %[^\n]", jardimAtual.nome);

    printf("Data de fundacao (DD/MM/AAAA): ");
    scanf(" %d/%d/%d", &jardimAtual.fundacao.dia, &jardimAtual.fundacao.mes, &jardimAtual.fundacao.ano);

    jardimAtual.nPlantas = 0;

    return jardimAtual;
}

void mostraJardim(jardim jardimAtual)
{
    printf("Jardim %s fundado a %d/%d/%d\n\n", jardimAtual.nome, jardimAtual.fundacao.dia, jardimAtual.fundacao.mes, jardimAtual.fundacao.ano);

    for (int i = 0; i < jardimAtual.nPlantas; i++)
    {
        printf("Planta %d\n", i + 1);
        printf("%s com %d anos de idade tem uma temperatura ideal de %.1f graus\n\n",
               jardimAtual.plantas[i].especie,
               jardimAtual.plantas[i].idade,
               jardimAtual.plantas[i].temperaturaIdeal);
    }
}

int main()
{
    int opcao;
    jardim jardimAtual;

    jardimAtual = inicializaJardim();

    printf("Bem-vindo/a ao jardim %s\n\n", jardimAtual.nome);

    do
    {
        printf("\n");
        printf("1 - Adicionar planta\n");
        printf("2 - Remover planta\n");
        printf("3 - Ver plantas\n");
        printf("0 - Sair\n\n");

        printf("Opcao: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            jardimAtual = adicionaPlanta(jardimAtual);
            break;

        case 2:
            jardimAtual = removePlanta(jardimAtual);
            break;

        case 3:
            mostraJardim(jardimAtual);
            break;
        }

    } while (opcao != 0);
}

/*
 * Exercicio Jardim Botanico
 * Criar duas estruturas:
 *  - Estrutura planta - tem uma especie, uma idade e temperatura ideal
 *  - Estrutura jardim - tem um nome, uma data de fundação e um array para 20 plantas
 * Adiciona uma planta a uma posicao que esteja vazia à escolha (está vazia se a planta não tiver nome)
 * Remover planta do array (apagar nome)
 * 
 * Parte 2:
*/