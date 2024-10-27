/*
Teste 049
"Revisando Matrizes III"

Escreva um programa em C que leia uma matriz quadrada de tamanho N
(onde N � um n�mero inteiro lido do usu�rio) e verifique se essa matriz
� sim�trica. Uma matriz � considerada sim�trica se ela � igual � sua transposta.
Exiba na tela se a matriz � sim�trica ou n�o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, j ;
int num ;
int flag = 0 ;

main()
{		
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o tamanho da matriz quadrada: ");
	scanf("%i", &num);
	
	int a[num][num] ;
	int at[num][num] ;
	
	printf("\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf("Insira o valor de A(%i, %i): ", i+1, j+1);
			scanf("%i", &a[i][j]);
			
			at[j][i] = a[i][j] ;
		}
	}
	
	printf("\nMatriz A:\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf(" %2.i", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nMatriz At:\n");
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			printf(" %2.i", at[i][j]);
		}
		printf("\n");
	}
	
	for(i=0; i<num; i++)
	{
		for(j=0; j<num; j++)
		{
			if(at[i][j] != a[i][j])
				flag = 1 ;
		}
	}
	
	if(flag == 1)
		printf("\nA matriz n�o � sim�trica.\n\n");
	else
		printf("\nA matriz � sim�trica!\n\n");
	
	printf("\n");
	
	system("pause");
}
