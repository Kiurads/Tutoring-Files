#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int main()
{
    /*
    Declarar um array de inteiros com tamanho 10 que começa com todos os valores a 0
    Criar um menu utilizando um switch case em que o utilizador pode:
     - Adicionar um número ao array numa certa posição, ou seja, escolhe a posição em que vai ser guardado esse número
     - Apagar um número do array em que o utilizador indica a posição a apagar
     - Inverter o array
     - Sair do programa
    No final de todas as opções o array deve ser mostrado
    Quando o utilizador introduz uma posição deve ser verificado se é válida ou não
    */

    int array[TAM] = {0};
    int opcao, posicao, numero;

    do
    {
        for (int i = 0; i < TAM; i++)
        {
            printf("[%d]", array[i]);
        }

        printf("\n\n1 - Adicionar inteiro\n");
        printf("2 - Apagar inteiro\n");
        printf("3 - Inverter array\n");
        printf("4 - Sair\n\n");

        printf("Escolha: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Numero a guardar e posicao (numero posicao): ");
            scanf(" %d %d", &numero, &posicao);

            if (posicao < TAM && posicao > -1)
            {
                array[posicao] = numero;
            }
            else
            {
                printf("Posicao fora dos limites [0, 9]\n\n");
            }

            break;
            
        case 2:
            printf("Selecione uma posicao para apagar: ");
            scanf(" %d", &posicao);

            if (posicao < TAM && posicao > -1)
            {
                array[posicao] = 0;
            }
            else
            {
                printf("Posicao fora dos limites [0, 9]\n\n");
            }

            break;
            
        case 3:
            for (int i = 0; i < 5; i++)
            {
                int valor;

                valor = array[i];
                array[i] = array[TAM - 1 - i];

                array[TAM - 1 - i] = valor;
            }
            
            
            break;
            
        case 4:
            printf("Saiu\n");
            break;
        }

    } while (opcao != 4);
}