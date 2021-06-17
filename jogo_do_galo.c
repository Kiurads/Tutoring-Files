#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarJogada(int x, int y, int tamx, int tamy, char tabuleiro[tamx][tamy]);
char fazerJogada(char jogador, int x, int y, char tabuleiro[3][3]);
char verificarEstado(char tabuleiro[3][3]);
char verificaLinhas(char tabuleiro[3][3]);
char verificaColunas(char tabuleiro[3][3]);
char verificaDiagonais(char tabuleiro[3][3]);
char verificaEmpate(char tabuleiro[3][3]);
char jogo();

int main()
{
    int jogar;
    char resultado;

    do
    {
        printf("Jogo do Galo\n\n");

        printf("1 - Comecar jogo\n");
        printf("0 - Sair do jogo\n\n");

        printf("Opcao: ");
        scanf(" %d", &jogar);

        if (jogar)
        {
            resultado = jogo();

            if (resultado == 'X' || resultado == 'O') //Verificar se ganhou um jogador
            {
                printf("Ganhou o jogador %c!\n", resultado); // Imprimir quem ganhou
            }
            else
            {
                printf("Empate!\n"); // Imprimir empate
            }
        }
    } while (jogar);
}

char jogo()
{
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char jogador = 'O';

    int valido;
    int x, y;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("|%c", tabuleiro[i][j]);
        }
        printf("|\n-------\n");
    }

    do
    {
        do
        {
            printf("[%c] Posicao da jogada (linha coluna): ", jogador);
            scanf(" %d %d", &x, &y);

            valido = validarJogada(x, y, 3, 3, tabuleiro);
        } while (!valido);

        // O - ganha O | X - ganha X | 0 - empate | C - continuar
        char estado = fazerJogada(jogador, x, y, tabuleiro);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("|%c", tabuleiro[i][j]);
            }
            printf("|\n-------\n");
        }

        if (estado != 'C')
        {
            return estado;
        }

        if (jogador == 'O')
            jogador = 'X';
        else
            jogador = 'O';

    } while (1);
}

int validarJogada(int x, int y, int tamx, int tamy, char tabuleiro[tamx][tamy])
{
    if (x > 3 || y > 3 || x < 1 || y < 1)
    {
        printf("Jogada nao valida\n");
        return 0;
    }
    else
    {
        x--;
        y--;

        if (tabuleiro[x][y] != ' ')
        {
            printf("Jogada nao valida\n");
            return 0;
        }
    }

    return 1;
}

char fazerJogada(char jogador, int x, int y, char tabuleiro[3][3])
{
    tabuleiro[x - 1][y - 1] = jogador;

    return verificarEstado(tabuleiro);
}

char verificarEstado(char tabuleiro[3][3])
{
    char estado;

    if ((estado = verificaColunas(tabuleiro)) != 'C')
    {
        return estado;
    }

    if ((estado = verificaLinhas(tabuleiro)) != 'C')
    {
        return estado;
    }

    if ((estado = verificaDiagonais(tabuleiro)) != 'C')
    {
        return estado;
    }

    return verificaEmpate(tabuleiro);
}

char verificaLinhas(char tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        char primeiroElemento = tabuleiro[i][0];

        if (primeiroElemento != ' ')
        {
            int flagVitoria = 1;

            for (int j = 1; j < 3; j++)
            {
                if (primeiroElemento != tabuleiro[i][j])
                {
                    flagVitoria = 0;

                    break;
                }
            }

            if (flagVitoria)
            {
                return primeiroElemento;
            }
        }
    }

    return 'C';
}

char verificaColunas(char tabuleiro[3][3])
{
    for (int j = 0; j < 3; j++)
    {
        char primeiroElemento = tabuleiro[0][j];

        if (primeiroElemento != ' ')
        {
            int flagVitoria = 1;

            for (int i = 1; i < 3; i++)
            {
                if (primeiroElemento != tabuleiro[i][j])
                {
                    flagVitoria = 0;

                    break;
                }
            }

            if (flagVitoria)
            {
                return primeiroElemento;
            }
        }
    }

    return 'C';
}

char verificaDiagonais(char tabuleiro[3][3])
{
    if (tabuleiro[1][1] == ' ')
    {
        return 'C';
    }

    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) || (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]))
    {
        return tabuleiro[1][1];
    }

    return 'C';
}

char verificaEmpate(char tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == ' ')
            {
                return 'C';
            }
        }
    }
    return '0';
}