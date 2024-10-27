/*
Teste 017 - Registros

75% do Sal�rio < Imposto + Custo de Vida e Servi�os < 80% do Sal�rio - Primeiro Ministro com Problemas
75% do Sal�rio < Imposto + Custo de Vida e Servi�os < 80% do Sal�rio - Primeiro Ministro em Apuros

Ler sal�rio, imposto e custo de vida e servi�os
Quantas pessoas caem em cada categoria (em porcentagem)
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

int n, apuros = 0, problemas = 0 ;
float salario, custos, imposto, porcentagem ;
char answer ;

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		printf("\n\nInforme o valor do sal�rio: ");
		scanf("%f", &salario);
		
		printf("Informe o valor dos impostos: ");
		scanf("%f", &imposto);
		
		printf("Informe os Custos de Vida e Servi�os: ");
		scanf("%f", &custos);
		
		n++ ;
		
		porcentagem = (imposto + custos) / salario ;
		
		if(porcentagem >= 0.8)
			apuros++ ;
		else if(porcentagem > 0.75)
			problemas++ ;
		
		printf("\nContinuar lendo registros (s/n)? ");
		answer = getche();
		
	} while(answer == 'S' || answer == 's');
	
	printf("\n\nProlemas: %i	-	 Percentual de Cidad�os na categoria 'Problema': %.2f%%\n", problemas, 100.0*problemas/n);
	printf("Apuros..: %i	-	 Percentual de Cidad�os na categoria 'Apuros': %.2f%%\n\n", apuros, 100.0*apuros/n);
	
	system("pause");
}
