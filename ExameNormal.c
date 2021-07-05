#include <stdio.h>
#include <stdlib.h>

#define DIM 100

typedef struct criador Criador, *pCriador;
typedef struct ave Ave, *pAve;
typedef struct 
{
    int d, m, a;
} Data;

struct criador
{
    char nome[DIM];
    int contador;
    pAve lista;
    pCriador prox;
};

struct ave
{
    int id;
    int gaiola;
    Data avender, venda;
    pAve prox;
};

struct cc 
{
    char nome[DIM];
    int nif;
    int id;
};

struct dono
{
    char nome[DIM];
    int nif;
    char mat[15];
};

int contaGaiolas(pCriador listaCriadores, int gaiola)
{
    int contagem = 0;

    pCriador auxCriadores;

    auxCriadores = listaCriadores;

    while (auxCriadores != NULL)
    {
        pAve auxAves;

        auxAves = auxCriadores->lista;

        while (auxAves != NULL)
        {
            if (auxAves->gaiola == gaiola && auxAves->venda.a == 0)
            {
                contagem++;
            }
            
            auxAves = auxAves->prox;
        }

        auxCriadores = auxCriadores->prox;
    }

    return contagem;
}

pCriador RetiraVendidas(pCriador lista)
{
    pCriador atualCriador, anteriorCriador;

    atualCriador = lista;
    anteriorCriador = NULL;

    while (atualCriador != NULL)
    {
        pAve atualAves, anteriorAves;

        atualAves = atualCriador->lista;
        anteriorAves = NULL;

        while (atualAves != NULL)
        {
            if (atualAves->venda.a != 0 && atualAves->venda.m != 0 && atualAves->venda.d != 0)
            {
                if (anteriorAves == NULL)
                {
                    atualCriador->lista = atualAves->prox;
                    free(atualAves);

                    atualAves = atualCriador->lista;
                } 
                else
                {
                    anteriorAves->prox = anteriorAves->prox;
                    free(atualAves);

                    atualAves = anteriorAves->prox;
                }

                atualCriador->contador--;
            }
            else
            {
                anteriorAves = atualAves;
                atualAves = atualAves->prox;
            }
        }
        
        if (atualCriador->contador <= 0 || atualCriador->lista == NULL)
        {
            if (anteriorCriador == NULL)
            {
                lista = atualCriador->prox;
                free(atualCriador);

                atualCriador = lista;
            }
            else
            {
                anteriorCriador->prox = atualCriador->prox;
                free(atualCriador);

                atualCriador = anteriorCriador->prox;
            }
        }
        else
        {
            anteriorCriador = atualCriador;
            atualCriador = atualCriador->prox;
        }
    }
    
    return lista;
}

void criarFicheiro(char* nomeCC, char* nomeDonos)
{
    FILE* fCC;
    FILE* fDonos;

    struct cc ccLido;
    struct dono donoLido;

    struct cc* vetorCC = NULL;
    struct dono* vetorDonos = NULL;

    int nCC = 0;
    int nDonos = 0;

    fCC = fopen(nomeCC, "rb");

    if (fCC == NULL)
    {
        printf("O ficheiro de cartas de conducao nao foi encontrado\n");
        return;
    }

    fDonos = fopen(nomeDonos, "rb");

    if (fDonos == NULL)
    {
        printf("O ficheiro de donos nao foi encontrado\n");
        return;
    }

    while (fread(&ccLido, sizeof(struct cc), 1, fCC) == 1)
    {
        if (vetorCC == NULL)
        {
            vetorCC = malloc(sizeof(struct cc));

            if (vetorCC == NULL)
            {
                printf("Erro de memoria\n\n");

                return;
            }
        }
        else
        {
            vetorCC = realloc(vetorCC, sizeof(struct cc) * (nCC + 1));

            if (vetorCC == NULL)
            {
                printf("Erro de memoria\n\n");

                return;
            }
        }

        vetorCC[nCC] = ccLido;

        nCC++;
    }

    fclose(fCC);

    while (fread(&donoLido, sizeof(struct dono), 1, fCC) == 1)
    {
        if (vetorDonos == NULL)
        {
            vetorDonos = malloc(sizeof(struct dono));

            if (vetorDonos == NULL)
            {
                printf("Erro de memoria\n\n");

                return;
            }
        }
        else
        {
            vetorDonos = realloc(vetorDonos, sizeof(struct dono) * (nDonos + 1));

            if (vetorDonos == NULL)
            {
                printf("Erro de memoria\n\n");

                return;
            }
        }

        vetorDonos[nDonos] = donoLido;

        nDonos++;
    }

    fclose(fDonos);
    
    if (nDonos == 0)
    {
        printf("Nao existem donos no ficheiro\n\n");

        return;
    }

    FILE* fTexto;

    fTexto = fopen("resumo.txt", "wt");

    if (fTexto == NULL)
    {
        printf("Nao foi possivel escrever para o ficheiro\n");

        return ;
    }

    int j;

    for (int i = 0; i < nDonos; i++)
    {
        fprintf(fTexto, "%s, %d, ", vetorDonos[i].nome, vetorDonos[i].nif);

        for (j = 0; j < nCC; j++)
        {
            if (vetorCC[j].nif == vetorDonos[i].nif)
            {
                fprintf(fTexto, "%d\n", vetorCC[j].id);

                break;
            }
        }

        if (j == nCC)
        {
            fprintf(fTexto, "indisponivel\n");
        }
    }
    
    fclose(fTexto);

    free(vetorCC);
    free(vetorDonos);
}