/*
Teste 044
"Fus�o de Matrizes"

Leia duas matrizes 4 x 4 e escreva uma terceira com os maiores valores de cada posi��o�
das matrizes lidas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int i, j, matriz ;
int a[4][4], b[4][4], c[4][4] ;
int maior, igual[4][4] ;
int flag = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Intervalo de rand(): 0 - %i\n", RAND_MAX); // Verificando o range m�ximo da fun��o rand() nesse PC
	srand((unsigned)time(NULL)); // Atribuindo uma seed para rand() sempre gerar valores diferentes dos anteriores
	printf("\n");
	
	// Lendo as matrizes A e B
	for(matriz=0; matriz<2; matriz++)
	{
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				if(matriz == 0)
					a[i][j] = 1 + (rand() % 15); // Gerando um n�mero aleat�rio de 1 a 15
				else
					b[i][j] = 1 + (rand() % 15);
			}
		}
	}
	
	// Comparando as matrizes A e B e atribuindo o valor � C
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{	
			if(a[i][j] > b[i][j])
				maior = a[i][j] ;
			else if(a[i][j] < b[i][j])
				maior = b[i][j];
			else if(a[i][j] == b[i][j])
				maior = igual[i][j] = a[i][j];
		
			c[i][j] = maior ;
		}
	}
	
	// Printando as matrizes
	for(matriz=0; matriz<3; matriz++)
	{	
		if(matriz == 0)
			printf("Matriz A:\n");
		else if(matriz == 1)
			printf("Matriz B:\n");
		else
			printf("Matriz C:\n");
		
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				if(matriz == 0)
					printf("%2.1i ", a[i][j]);
				else if(matriz == 1)
					printf("%2.1i ", b[i][j]);
				else
					printf("%2.1i ", c[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	printf("Valores comuns entre A e B (iguais):\n");
	
	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(igual[i][j] != 0)
			{
				printf("%i (posi��o [%i,%i])\n", igual[i][j], i+1, j+1);
				flag = 1;
			}
		}
	}
	
	if(flag == 0)
		printf("N�o h�. Todos os valores s�o diferentes.");
	
	printf("\n\n");
	
	system("pause");
}
