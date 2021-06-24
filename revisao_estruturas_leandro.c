#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 8

typedef struct marcacaoEstudio
{
    char nomeGrupo[50];
    int horaChegada;
    int horaSaida;
} reservas;

int main() {
    int i;
    int opcao;
    int hora;
    reservas reservas[TAM];

    for (int i = 0; i < TAM; i++)
    {
        strcpy(reservas[i].nomeGrupo, "");
        reservas[i].horaChegada = 9 + i;
        reservas[i].horaSaida = reservas[i].horaChegada + 1;
    }

    do
    {
        printf("1 - Reservar estudio\n");
        printf("2 - Cancelar reserva\n");
        printf("3 - Mostrar reservas\n\n");

        printf("Opcao: ");
        scanf(" %d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Selecione uma hora (9 - 16): ");
            scanf(" %d", &hora);

            for (i = 0; i < TAM; i++)
            {                
                if (reservas[i].horaChegada == hora)
                {
                    if (strlen(reservas[i].nomeGrupo) > 0)
                    {
                        printf("Hora ja ocupada!\n\n");

                        break;
                    }
                    
                    printf("Nome da banda: ");
                    scanf(" %[^\n]", reservas[i].nomeGrupo);

                    break;
                }
            }

            if (i == TAM)
            {
                printf("Hora nao valida\n\n");
            }
            
            
            break;
        case 2:
            printf("Selecione uma hora (9 - 16): ");
            scanf(" %d", &hora);

            for (i = 0; i < TAM; i++)
            {
                if (reservas[i].horaChegada == hora)
                {
                    strcpy(reservas[i].nomeGrupo, "");

                    break;
                }
            }

            if (i == TAM)
            {
                printf("Hora nao valida\n\n");
            }
            
            
            break;
        case 3:
            for (i = 0; i < TAM; i++)
            {
                printf("Grupo: %s\n", reservas[i].nomeGrupo);
                printf("Chegada: %dH\n", reservas[i].horaChegada);
                printf("Saida: %dH\n\n", reservas[i].horaSaida);
            }
            
            break;
        }
    } while (opcao != 0);    
}