#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;

    linhas = colunas = 3;

    char **tabela;

    tabela = malloc(linhas * sizeof(char *));

    for (int i = 0; i < linhas; i++)
    {
        tabela[i] = malloc(colunas * sizeof(char));
    }

    linhas++;

    tabela = realloc(tabela, linhas * sizeof(char *));

    tabela[linhas - 1] = malloc(colunas * sizeof(char));

    colunas++;

    for (int i = 0; i < linhas; i++)
    {
        tabela[i] = realloc(tabela[i], colunas * sizeof(char));
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            tabela[i][j] = ' ';
            
            printf("|%c", tabela[i][j]);
        }
        printf("|\n");
    }
    
}