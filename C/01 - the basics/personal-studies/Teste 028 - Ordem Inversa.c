/*
Teste ???
"Ordem Inversa"

*INTRODU��O A VETORES*
Vetor � uma forma de acumular in�meras vari�veis numa �nica.

Ler 5 n�meros e imprimir em ordem inversa.
*/

#include <stdio.h>
#include <stdlib.h>

int i, vetor[5] ;

main()
{
	for(i=0; i<5; i++)
	{
		printf("Informe o numero %i: ", i+1);
		scanf("%i", &vetor[i]);
	}
	
	printf("\n");
	
	for(i=4; i>-1; i--)
		printf("%i ", vetor[i]);
	
	printf("\n\n");
	
	system("pause");
}
