/*
013 - Tabuada com Fun��es

Escreva um procedimento que exiba na tela a tabuada do n�mero
passado por par�metro.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_tabuada(int num);

int main()
{
    int num ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um n�mero: ");
    scanf("%i", &num);
    
    imprimir_tabuada(num);
    
    printf("\n");
    
    return 0;
}

void imprimir_tabuada(int num)
{
    int i ;

    for(i=1; i<=10; i++)
    {
        printf("\n%2.i * %2.i = %2.i", num, i, num*i);
    }
}
