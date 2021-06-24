#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct pessoa
{
    char nome[50];
    char apelido[50];
    data dataNascimento;
} pessoa;

typedef struct consulta
{
    char especialidade[50];
    data marcacao;
    pessoa paciente;
} consulta;

typedef struct hospital
{
    char nome[50];
    char cidade[50];
    int nConsultas;
    consulta *consultas;
} hospital;

hospital lerFicheiro(char *nome);

int main()
{
    int opcao;

    hospital h = lerFicheiro("hospitais.txt");

    printf("Bem-vindo/a ao hospital %s de %s\n\n", h.nome, h.cidade);

    do
    {
        printf("\n1 - Marcar consulta\n");
        printf("2 - Desmarcar consulta\n");
        printf("3 - Listar consultas\n");
        printf("0 - Sair\n\n");

        printf("Opcao: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            if (h.nConsultas == 0)
            {
                h.consultas = malloc(sizeof(consulta));

                if (h.consultas == NULL)
                {
                    printf("ERRO: Alocar memoria falhou!\n\n");
                    return 1;
                }
            }
            else
            {
                h.consultas = realloc(h.consultas, sizeof(consulta) * (h.nConsultas + 1));

                if (h.consultas == NULL)
                {
                    printf("ERRO: Alocar memoria falhou!\n\n");
                    return 1;
                }
            }

            printf("Especialidade: ");
            scanf(" %s", h.consultas[h.nConsultas].especialidade);

            printf("Data da consulta (DD/MM/AAAA): ");
            scanf(" %d/%d/%d", &h.consultas[h.nConsultas].marcacao.dia, &h.consultas[h.nConsultas].marcacao.mes, &h.consultas[h.nConsultas].marcacao.ano);

            printf("Paciente (Nome Apelido DD/MM/AAAA): ");
            scanf(" %s %s %d/%d/%d",
                  h.consultas[h.nConsultas].paciente.nome,
                  h.consultas[h.nConsultas].paciente.apelido,
                  &h.consultas[h.nConsultas].paciente.dataNascimento.dia,
                  &h.consultas[h.nConsultas].paciente.dataNascimento.mes,
                  &h.consultas[h.nConsultas].paciente.dataNascimento.ano);

            h.nConsultas++;

            break;

        case 2:
            break;

        case 3:
            printf("%d consultas\n\n", h.nConsultas);

            for (int i = 0; i < h.nConsultas; i++)
            {
                printf("%s: %d/%d/%d (%s %s %d/%d/%d)\n",
                       h.consultas[i].especialidade,
                       h.consultas[i].marcacao.dia,
                       h.consultas[i].marcacao.mes,
                       h.consultas[i].marcacao.ano,
                       h.consultas[i].paciente.nome,
                       h.consultas[i].paciente.apelido,
                       h.consultas[i].paciente.dataNascimento.dia,
                       h.consultas[i].paciente.dataNascimento.mes,
                       h.consultas[i].paciente.dataNascimento.ano);
            }

            break;
        }
    } while (opcao != 0);
}

hospital lerFicheiro(char *nome)
{
    FILE *f;
    hospital hp;
    consulta consultaFicheiro;

    f = fopen(nome, "rt");

    if (f == NULL)
    {
        printf("Ficheiro nao encontrado\n\n");
        exit(1);
    }

    hp.nConsultas = 0;

    fscanf(f, "Hospital %[^\n]\n", hp.nome);
    fscanf(f, "%[^\n]\n", hp.cidade);

    while (fscanf(f, "%[^:]: %d/%d/%d (%s %s %d/%d/%d)\n",
                  consultaFicheiro.especialidade,
                  &consultaFicheiro.marcacao.dia,
                  &consultaFicheiro.marcacao.mes,
                  &consultaFicheiro.marcacao.ano,
                  consultaFicheiro.paciente.nome,
                  consultaFicheiro.paciente.apelido,
                  &consultaFicheiro.paciente.dataNascimento.dia,
                  &consultaFicheiro.paciente.dataNascimento.mes,
                  &consultaFicheiro.paciente.dataNascimento.ano) == 9)
    {
        if (hp.nConsultas == 0)
        {
            hp.consultas = malloc(sizeof(consulta));

            if (hp.consultas == NULL)
            {
                printf("ERRO: Alocar memoria falhou!\n\n");
                exit(1);
            }
        }
        else
        {
            hp.consultas = realloc(hp.consultas, sizeof(consulta) * (hp.nConsultas + 1));

            if (hp.consultas == NULL)
            {
                printf("ERRO: Alocar memoria falhou!\n\n");
                exit(1);
            }
        }

        strcpy(hp.consultas[hp.nConsultas].especialidade, consultaFicheiro.especialidade);
        hp.consultas[hp.nConsultas].marcacao.dia = consultaFicheiro.marcacao.dia;
        hp.consultas[hp.nConsultas].marcacao.mes = consultaFicheiro.marcacao.mes;
        hp.consultas[hp.nConsultas].marcacao.ano = consultaFicheiro.marcacao.ano;
        strcpy(hp.consultas[hp.nConsultas].paciente.nome, consultaFicheiro.paciente.nome);
        strcpy(hp.consultas[hp.nConsultas].paciente.apelido, consultaFicheiro.paciente.apelido);
        hp.consultas[hp.nConsultas].paciente.dataNascimento.dia = consultaFicheiro.paciente.dataNascimento.dia;
        hp.consultas[hp.nConsultas].paciente.dataNascimento.mes = consultaFicheiro.paciente.dataNascimento.mes;
        hp.consultas[hp.nConsultas].paciente.dataNascimento.ano = consultaFicheiro.paciente.dataNascimento.ano;

        hp.nConsultas++;
    }

    return hp;
}