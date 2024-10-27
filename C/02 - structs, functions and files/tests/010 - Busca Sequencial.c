// Algoritmo de Busca Sequencial

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void sortear_vetor(int vetor[]);
int ler_palpite();
int buscar_palpite(int palpite, int vetor[]);

int main()
{
	int vetor[8];
	int palpite;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("[M�quina] > Vou sortear um vetor de 8 posi��es.\n");
	sortear_vetor(vetor);
	sleep(2);
	
	printf("[M�quina] > Sorteando...\n");
	sleep(3);
	
	printf("[M�quina] > Tente adivinhar um n�mero desse vetor!\n");
	sleep(2);
	
	while(1)
	{
		palpite = ler_palpite();
		
		if(buscar_palpite(palpite, vetor) == 1)
		{
			printf("\n[M�quina] > Parab�ns! O n�mero %i est� no vetor!\n", palpite);
			break;
		}
		else
		{
			printf("\n[M�quina] > Voc� errou :(\n");
			printf("[M�quina] > Tente de novo!\n");
		}
	}
	
	return 0;
}

void sortear_vetor(int vetor[])
{
	int i;
	
	for(i=0; i<8; i++)
	{
		vetor[i] = (rand() % 15) + 1;
	}
}

int ler_palpite()
{
	int palpite;
	
	printf("[M�quina] > Insira aqui sua proposta: ");
	scanf("%i", &palpite);
	
	return palpite;
}

int buscar_palpite(int palpite, int vetor[])
{
	int i;
	
	for(i=0; i<8; i++)
	{
		if(vetor[i] == palpite)
			return 1;
	}
	
	return 0;
}
