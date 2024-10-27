/*
Teste 018
"Identificador de Primos"

Algoritmo para ler um n�mero inteiro e imprimir o pr�ximo n�mero primo
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int i, num, primo, resto ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um n�mero inteiro: ");
	scanf("%i", &num);
	
	do
	{
		num++ ;
		primo = 0;
		
		for(i=2; i<10; i++)
		{
			if(num != i)
				resto = num % i ;
			
			if(resto != 0)
			    primo++ ;
		}
		
	} while(primo != 8);
	
	printf("\nO pr�ximo n�mero primo � %i\n", num);
} 

