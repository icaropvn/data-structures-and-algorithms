/*
Teste 018
"Reconhecedor de Primos"

Algoritmo para ler um n�mero n e retornar o pr�ximo n�mero
primo a partir dele.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int num, aux, divisor ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um n�mero: ");
	scanf("%i", &num);
	
	if(num != 1)
	{
		for(aux=1; aux<10; aux++)
		{
			if(num != aux && num % aux == 0)
				divisor++ ;
		}
	
	    if(divisor == 1)	
		    printf("O n�mero � primo.\n\n");
	    else
		    printf("O n�mero n�o � primo.\n\n");
	}
	
	else
		printf("O n�mero 1 � inv�lido.\n\n");
	
	system("pause");
}
