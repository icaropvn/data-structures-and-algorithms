/*
005 - Retornar M�ximo

=== Aula 02, Exerc�cio 06 ===

Criar fun��o que retorna o maior entre 2
n�meros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int maior(int a, int b)
{
	int maior ;
	
	if(a > b)
		maior = a;
	else
		maior = b;
	
	return maior;
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int num1, num2, maior_num ;
	
	printf("Insira um n�mero: ");
	scanf("%i", &num1);
	
	printf("Insira outro: ");
	scanf("%i", &num2);
	
	maior_num = maior(num1, num2);
	
	printf("\nO maior valor digitado foi: %i\n", maior_num);
	
	return 0;
}
