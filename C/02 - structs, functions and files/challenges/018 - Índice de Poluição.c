/*
018 - �ndice de Polui��o

Escreva um procedimento que leia o �ndice de polui��o
e indique provid�ncias apropriadas.

*Considere �ndice de polui��o = i

Se:
- i < 0.30 				Boa: Nenhuma provid�ncia
- 0.30 = i < 0.40 		Ruim: Suspender empresas da lista A
- 0.40 = i = 0.50 		P�ssima: Suspender empresas da lista A e B
- i > 0.50				Cr�tica: Suspender todas as empresas
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificar_indice(float indice);

int main()
{
	float indice ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o �ndice de polui��o atual: ");
	scanf("%f", &indice);
	
	verificar_indice(indice);
	
	return 0;
}

void verificar_indice(float indice)
{
	if(indice < 0.3)
		printf("\n�ndice Bom.\nNenhuma provid�ncia a ser tomada.\n");
	else if(indice < 0.4)
		printf("\n�ndice Ruim.\nSuspender empresas da lista A.\n");
	else if(indice <= 0.5)
		printf("\n�ndice P�SSIMO.\nSuspender empresas da lista A e B.\n");
	else
		printf("\n�ndice CR�TICO!!!\nSUSPENDER TODAS AS EMPRESAS.");
}
