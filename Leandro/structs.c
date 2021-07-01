#include <stdlib.h>
#include <stdio.h>

typedef struct Data data;

struct Data
{
    int dia, mes, ano;
};

typedef struct Nascimento
{
    char nome[50];
    float peso;
    data dataNascimento;
} nascimento;


int main()
{
    nascimento nascimentoHoje;

    printf("Introduza o nome do recem-nascido: ");
    scanf(" %s", &nascimentoHoje.nome);

    printf("Introduza o peso do recem-nascido: ");
    scanf(" %f", &nascimentoHoje.peso);

    printf("Introduza a data de nascimento (DD/MM/AAAA): ");
    scanf(" %d/%d/%d", &nascimentoHoje.dataNascimento.dia, &nascimentoHoje.dataNascimento.mes, &nascimentoHoje.dataNascimento.ano);

    printf("Nome: %s\n", nascimentoHoje.nome);
    printf("Peso: %.1f\n", nascimentoHoje.peso);
    printf("Data de nascimento: %d/%d/%d", nascimentoHoje.dataNascimento.dia, nascimentoHoje.dataNascimento.mes, nascimentoHoje.dataNascimento.ano);
}

/*
 * Exercicio Jardim Botanico
 * Criar duas estruturas:
 *  - Estrutura planta - tem uma especie, uma idade e temperatura ideal
 *  - Estrutura jardim - tem um nome, uma data de fundação e um array para 20 plantas
 * Adiciona uma planta a uma posicao que esteja vazia à escolha (está vazia se a planta não tiver nome)
 * Remover planta do array (apagar nome)
*/ 