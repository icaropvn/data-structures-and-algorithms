/*
010 - Pre�o e Desconto

Crie uma fun��o que receba dois valores referentes ao pre�o de uma
mercadoria e a porcentagem para o desconto. Retorne o novo pre�o com
o desconto calculado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float descontar(float price, int descount);

int main()
{
    int descount ;
    float price, new_price ;
    
    setlocale(LC_ALL, "Portuguese");
    
    printf("Insira o pre�o do produto: R$");
    scanf("%f", &price);
    
    printf("Insira o desconto (por cento): ");
    scanf("%i", &descount);
    
    new_price = descontar(price, descount);
    
    printf("\nPre�o com desconto: R$%.2f\n", new_price);
    
    return 0;
}

float descontar(float price, int descount)
{
    return price * (1 - descount / 100.0) ;
}
