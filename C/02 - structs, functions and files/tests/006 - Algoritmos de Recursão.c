/*
Algoritmos de Recurs�o

Recurs�o �:
- repeti��es sem loop

* Ao usar Recurs�o, � preciso definir de imediato 
qual ser� a condi��o de parada

*mem�ria em stack

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int somar(int num);

int main()
{
	int num;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Insira um n�mero para somar seus antecessores: ");
	scanf("%i", &num);
	
	printf("\n%i", somar(num));
	
	return 0;
}

int somar(int num)
{
	if(num == 0)
		return 0;
	else
	    return num + somar(num - 1);
}
