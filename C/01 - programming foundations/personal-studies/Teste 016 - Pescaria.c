/*
Teste 016

Algoritmo para ler o limite de peso de peixes pescados e
imprimir o total pescado de peixes.

Quando o limite for ultrapassado, devolver o peixe e imprimir o total levado e o n�mero de peixes.
Prever a possibilidade de interromper a pescaria antes de alcan�ar o limite di�rio.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n_peixes = 0 ;
float limite_peso, peso_peixe, peso_total = 0 ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Qual � o limite di�rio de peso hoje (kg)?\n");
	scanf("%f", &limite_peso);
	
	do
	{
		printf("Informe o peso do peixe %i (kg): ", n_peixes+1);
		scanf("%f", &peso_peixe);
		
		n_peixes++ ;
		peso_total += peso_peixe ; // peso_total = peso_total + peso_peixe
		
	} while(peso_peixe != 0 && peso_total < limite_peso);
	
	n_peixes-- ;
	
	if(peso_peixe != 0)
		peso_total -= peso_peixe ;
	
	printf("N�mero de Peixes Pescados: %i\nPeso Total de Peixes: %.2f\n\n", n_peixes, peso_total);
	
	system("pause");
}
