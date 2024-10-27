/* �rea do Tri�ngulo: algoritmo para ler a base e altura do tri�ngulo e imprimir a base, altura e �rea.
Verificar se a base e/ou a altura � negativa. Caso afirmativo, imprimir mensagem de erro e n�o calcular a �rea.
Caso ambos sejam negativos, imprimir mensagem e n�o calcular �rea. */

#include <stdio.h>
#include <stdlib.h>

float base, altura, area ;

main()
{
	printf("Insira a base: ");
	scanf("%f", &base);
	
	if(base < 0)
		printf("Impossivel calcular: Base Negativa");
	
	else
	{
		printf("Insira a altura: ");
		scanf("%f", &altura);
		
		if(altura < 0)
		{
			printf("Impossivel Calcular: Altura Negativa");
		}
		else
		{
			area = (base*altura)/2 ;
			printf("A area e %.1f m2", area);
		}
	}
		
	system ("pause");
	
}
