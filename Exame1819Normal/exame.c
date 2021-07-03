#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct divisao divi, * pdiv;
typedef struct porta no, * pno;

struct divisao {
	int id;
	char nome[100];
	int n_pessoas;
	pno lista;
};

struct porta {
	int id;
	pno prox;
};

struct pessoa {
	char nome[100];
	struct {
		int d, m, a;
	} nasc;
	pdiv local;
};

struct atleta {
	char nome[100];
	int tAcumulado[10];
	int kmRapido;
};

int exercicio1A(char* nome);

struct atleta* exercicio1B(char* nome, int* tamanho);

int exercicio3A(pdiv divisoes, int nDivisoes, struct pessoa* pessoas, int nPessoas);

pdiv exercicio3B(pdiv d, int* totD, int id, struct pessoa* hab, int totP);


int main() {
	char nome[40];

	struct atleta* vetor;
	int tamanho;

	printf("Nome do ficheiro: ");
	scanf(" %s", nome);

	printf("%d\n\n", exercicio1A(nome));

	vetor = exercicio1B(nome, &tamanho);

	if (vetor != NULL)
	{
		for (int i = 0; i < tamanho; i++)
		{
			printf("%s: ", vetor[i].nome);

			for (int j = 0; j < 10; j++)
			{
				printf("\n%d ", vetor[i].tAcumulado[j]);

				if (j == 0)
				{
					printf("\n");
				}
				else
				{
					printf("- %d: %d\n", vetor[i].tAcumulado[j - 1], (vetor[i].tAcumulado[j] - vetor[i].tAcumulado[j - 1]));
				}
			}

			printf("\n%d\n\n", vetor[i].kmRapido);
		}
	}
}

int exercicio1A(char* nome) {
	FILE* f;

	int nAtletas;
	int tempoPrimeiro;
	int tempoUltimo;

	f = fopen(nome, "r");

	if (f == NULL)
	{
		return -1;
	}

	if (fscanf(f, "Atletas: %d\n", &nAtletas) != 1)
	{
		fclose(f);
		return -1;
	}

	printf("Atletas: %d\n", nAtletas);

	for (int i = 0; i < 10; i++)
	{
		char buffer[20];

		fgets(buffer, 20, f);

		for (int j = 0; j < nAtletas; j++)
		{
			int posicao;
			int tempo;

			if (fscanf(f, "%d. %[^:]: %d\n", &posicao, buffer, &tempo) != 3)
			{
				fclose(f);
				return -1;
			}

			if (j == 0)
			{
				tempoPrimeiro = tempo;
			}

			if (posicao == nAtletas)
			{
				tempoUltimo = tempo;
			}

			printf("%d. %s: %d\n", posicao, buffer, tempo);
		}

		printf("\n");
	}

	fclose(f);

	return tempoUltimo - tempoPrimeiro;
}

struct atleta* exercicio1B(char* nome, int* tamanho)
{
	FILE* f;

	struct atleta* vetor;

	f = fopen(nome, "r");

	if (f == NULL)
	{
		return -1;
	}

	if (fscanf(f, "Atletas: %d\n", tamanho) != 1)
	{
		fclose(f);
		return -1;
	}

	vetor = malloc(sizeof(struct atleta) * (*tamanho));

	if (vetor == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < 10; i++)
	{
		char buffer[20];

		fgets(buffer, 20, f);

		for (int j = 0; j < (*tamanho); j++)
		{
			int posicao;
			int tempo;

			if (fscanf(f, "%d. %[^:]: %d\n", &posicao, buffer, &tempo) != 3)
			{
				fclose(f);
				return NULL;
			}

			if (i == 0)
			{
				strcpy(vetor[j].nome, buffer);
				vetor[j].tAcumulado[i] = tempo;
				vetor[j].kmRapido = tempo;
			}
			else
			{
				for (int k = 0; k < (*tamanho); k++)
				{
					if (strcmp(buffer, vetor[k].nome) == 0) {
						vetor[k].tAcumulado[i] = tempo;

						if (tempo - vetor[k].tAcumulado[i - 1] < vetor[k].kmRapido)
						{
							vetor[k].kmRapido = tempo - vetor[k].tAcumulado[i - 1];
						}

						break;
					}
				}
			}
		}
	}

	fclose(f);

	return vetor;
}

int exercicio3A(pdiv divisoes, int nDivisoes, struct pessoa* pessoas, int nPessoas)
{
	int atualizados = 0;

	for (int i = 0; i < nDivisoes; i++)
	{
		int contador = 0;

		for (int j = 0; j < nPessoas; j++)
		{
			if (pessoas[j].local->id == divisoes[i].id)
				contador++;
		}

		if (divisoes[i].n_pessoas != contador)
		{
			divisoes[i].n_pessoas = contador;
			atualizados++;
		}
	}

	return atualizados;
}

pdiv exercicio3B(pdiv d, int* totD, int id, struct pessoa* hab, int totP)
{
	int i;

	for (i = 0; i < totP; i++)
	{
		if (hab[i].local->id == id)
		{
			int idMov = hab[i].local->lista->id;

			for (int j = 0; j < (*totD); j++)
			{
				if (idMov == d[j].id)
				{
					hab[i].local = &d[j];

					d[j].n_pessoas++;

					break;
				}
			}
		}
	}

	for (i = 0; i < (*totD); i++)
	{
		if (d[i].id == id)
		{
			pno apagar;

			while (d[i].lista != NULL)
			{
				apagar = d[i].lista;
				d[i].lista = d[i].lista->prox;
				free(apagar);
			}

			break;
		}
	}

	if (i == (*totD))
	{
		return d;
	}

	for (i; i < (*totD) - 1; i++)
	{
		d[i].id = d[i + 1].id;
		d[i].n_pessoas = d[i + 1].n_pessoas;
		strcpy(d[i].nome, d[i + 1].nome);
		d[i].lista = d[i + 1].lista;

		for (int j = 0; j < totP; j++)
		{
			if (hab[j].local->id == d[i + 1].id)
			{
				hab[j].local = &d[i];
			}
		}
	}

	(*totD) -= 1;

	d = realloc(d, sizeof(divi) * (*totD));

	if (d == NULL)
	{
		printf("Erro na alocacao\n\n");
		return NULL;
	}

	for (i = 0; i < (*totD); i++)
	{
		pno atual, anterior;

		atual = d[i].lista;
		anterior = NULL;

		while (atual != NULL)
		{
			if (atual->id == id)
			{
				if (anterior == NULL)
				{
					d[i].lista = atual->prox;
					free(atual);

					break;
				}
				else
				{
					anterior->prox = atual->prox;
					free(atual);

					break;
				}
			}

			anterior = atual;
			atual = atual->prox;
		}
	}	
}
