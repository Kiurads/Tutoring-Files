/*
*Mastermind:

Inicialmente pergunta ao utilizador se quer escolher uma sequ�ncia ou selecionar uma aleat�ria (isto na fun��o main)
As sequ�ncias devem ter 4 das seguintes cores, e t�m que ser todas diferentes:
 - Amarelo (Y)
 - Azul (B)
 - Verde (G)
 - Vermelho (R)
 - Roxo (P)
 - Branco (W)

Criar uma fun��o separada para o jogo
Guardar num array a sequ�ncia correta
Deixar o jogador tentar adivinhar a sequencia 11 vezes
Se acertar voltar ao menu inicial para poder jogar outra vez ou sair
Guardar todas as tentativas numa matriz
Avaliar quantas cores corretas tem (tem que ser a cor correta na posi��o correta) numa fun��o � parte e alterar o numero de acertos atrav�s de um ponteiro
Extra: avaliar se tem cores corretas em posi��es erradas
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void imprimir_sequencia(char *sequencia_correta);

char *escreve_sequencia();

int jogo(int escolha);

char *gerarsequencia();

char randomColour();

int main()
{
    srand(time(NULL));
    int opcao;
    do
    {
        printf("1-Escolher sequencia\n");
        printf("2-Cor aleatoria\n");
        printf("3-sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
        case 2:
            jogo(opcao);
            break;

        case 3:

            break;
        }
    } while (opcao != 3);
}
char *escreve_sequencia()
{
    static char sequenciac[4];

    for (int i = 0; i < 4; i++)
    {
        do
        {
            printf("Digite a cor %d\n", i + 1);
            scanf(" %c", &sequenciac[i]);
        } while (sequenciac[i] != 'Y' && sequenciac[i] != 'B' && sequenciac[i] != 'G' && sequenciac[i] != 'R' && sequenciac[i] != 'P' && sequenciac[i] != 'W');
    }
    
    return sequenciac;
}

//

/*int adivinha(char sequencia_certa[4])
{
    char sequencia_a_comparar[4];
    int count = 0, acertou = 0;
    do
    {
        sequencia_a_comparar[] = sequencia_correta();
        for(int a=0; a<4; a++)
        {
            if(sequencia_a_comparar[a]!=sequencia_certa[a])
            {
                break;
            }
        }

        if(a == 4 && sequencia_a_comparar[a-1]==sequencia_certa[a-1]){
            acertou = 1;}
        count++;
    }
    while(count<11 && acertou == 0);
    return acertou;
}*/
void imprimir_sequencia(char *sequencia_correta)
{
    for (int i = 0; i < 4; i++)
    {
        printf("%c ", sequencia_correta[i]);
    }
}

int jogo(int escolha)
{
    char *sequencia_certa;
    char tentativa[4];
    
    if (escolha == 1)
    {
        sequencia_certa = escreve_sequencia();
    }
    else
    {
        sequencia_certa = gerarsequencia();
    }
    
    imprimir_sequencia(sequencia_certa);

    for (int i = 0; i < 11; i++)
    {
        
    }
    
}

char *gerarsequencia()
{
    static char sequencia_cert[4];
    
    for (int i = 0; i < 4; i++)
    {
        sequencia_cert[i] = randomColour();
    }

    return sequencia_cert;
}

char randomColour()
{
    char colours[6] = {'Y', 'B', 'G', 'R', 'P', 'W'};

    return colours[rand() % 6];
}
