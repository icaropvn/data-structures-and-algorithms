/*
011 - Procendimentos com Verifica��o

Crie uma fun��o sem retorno que receba 3 par�metros inteiros positivos, sendo
os dois primeiros por valor e o terceiro por refer�ncia. A vari�vel
referenciada dever� receber o maior valor dentre as duas primeiras,
sendo que receber� zero caso os valores sejam iguais, ou algum deles
sejam negativos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void verificar(int a, int b, int *maior);

int main()
{
    int num1, num2, maior = 0 ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira um valor: ");
    scanf("%i", &num1);
    
    printf("Insira outro valor: ");
    scanf("%i", &num2);
    
    verificar(num1, num2, &maior);
    
    printf("\nMaior valor: %i\n", maior);
    
    return 0;
}

void verificar(int a, int b, int *maior)
{
    if(a == b || a < 0 || b < 0)
        *maior = 0 ;
    else if(a > b)
        *maior = a ;
    else
        *maior = b ;
}
