// Algoritmo de Busca Sequencial

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#define TAM 30

void sortear_vetor(int vetor[]);
void ordenar_vetor(int vetor[]);
int ler_palpite();
int buscar_palpite(int palpite, int vetor[]);
void imprimir(int vetor[]);

int main()
{
	int i;
	
	int vetor[TAM];
	int palpite;
	
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	
	printf("[M�quina] > Vou sortear um vetor de %i posi��es.\n", TAM);
	sortear_vetor(vetor);
	ordenar_vetor(vetor); // ordena o vetor por bubble sort
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
			
			printf("\nVetor = [");
			imprimir(vetor);
			printf("\n");
			
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
	
	for(i=0; i<TAM; i++)
	{
		vetor[i] = (rand() % 100) + 1;
	}
}

void ordenar_vetor(int vetor[])
{
	int i, j;
	int aux;
	
	for(i=0; i<TAM; i++)
	{
		for(j=i+1; j<TAM; j++)
		{
			if(vetor[j] < vetor[i])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
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
	// vari�veis para usar a busca bin�ria por 'for'
	/*
	int i;
	int loops = log2(TAM);
	*/
	
	int inicio = 0;
	int fim = TAM - 1;
	int meio;
	
	// busca bin�ria usando 'for'
	/*
	for(i=0; i<=loops; i++)
	{
		meio = (fim + inicio) / 2;
		
		if(vetor[meio] == palpite)
			return 1;
		else if(palpite > vetor[meio])
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	*/
	
	// busca bin�ria usando 'while'
	while(inicio <= fim)
	{
		meio = (fim + inicio) / 2;
		
		if(vetor[meio] == palpite)
			return 1;
		else if(palpite > vetor[meio])
			inicio = meio + 1;
		else
			fim = meio - 1;
	}
	
	return 0;
}

void imprimir(int vetor[])
{
	int i;
	
	for(i=0; i<TAM; i++)
	{
		if(i == 0)
			printf("%i, ", vetor[i]);
		else if(i == TAM-1)
			printf("%i]", vetor[i]);
		else
			printf("%i, ", vetor[i]);
	}
}
