/*
003 - Retornar Par

=== Aula 02, Exerc�cio 04 ===

Criar fun��o que verifica se um n�mero � par.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int par(int num)
{
    int nature;
    
    if(num % 2 == 0)
        nature = 1 ;
    else
        nature = 0 ;

    return nature;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int num, nature ;
    char answer ;
    
    printf("PAR ou �MPAR\n");
    
    do
    {
        printf("Insira um valor: ");
        scanf("%i", &num);
        nature = par(num) ;
        
        if(nature == 1)
            printf("O n�mero � PAR");
        else
            printf("O n�mero � �MPAR");
        
        printf("\n\nOutro? [S/N]\n");
        scanf(" %c", &answer);
        
        printf("\n");
        
        if(answer == 'N' || answer == 'n')
            break ;
        
    } while(1);
    
    printf("At� mais!");
    
    return 0;
}


