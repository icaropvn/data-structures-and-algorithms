/*
016 - C�lculo de ICMS

Escreva uma fun��o que receba um valor de venda de algum
produto e retorne o novo valor com o c�lculo do ICMS (considere 18%).
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcular_icms(float preco_produto);

int main()
{
	float preco_produto, valor_icms ;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira o pre�o cobrado pelo produto: R$");
	scanf("%f", &preco_produto);
	
	valor_icms = calcular_icms(preco_produto);
	
	printf("Valor do ICMS embutido: R$%.2f\n", valor_icms);
	
	return 0;
}

float calcular_icms(float preco_produto)
{
	return preco_produto * 0.18 ;
}
