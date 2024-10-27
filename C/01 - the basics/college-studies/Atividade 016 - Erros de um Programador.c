/*
Atividade 016

Um programador est� preocupado em rela��o ao seu desempenho num curso de computa��o.
Em seu primeiro programa ele cometeu um erro; em seu segundo, dois erros; no terceiro, quatro; e assim por diante.
Ele est� cometendo por programa duas vezes o n�mero de erros que cometeu no programa anterior.
O curso dura 13 semanas, com 2 problemas por semana.

Preparar um algoritmo para calcular e imprimir o n�mero de erros que este programador comete a cada programa do curso.

13 semanas * 2 problemas/semana = 26 problemas

Week 1 = 2^0
Week 2 = 2�
Week 3 = 2�

ou

erro = erro*2
*/

#include <stdio.h>
#include <stdlib.h>

int erros = 1, week ;

main()
{
	for(week=1; week<14; week++)
	{
		if(week != 1)
		    erros = erros*2 ;
		
		printf("Semana %i\n", week);	
		printf("	Problema %i - %i Erro(s)\n", 2*week-1, erros);
		
		erros = erros*2 ;
		printf("	Problema %i - %i Erro(s)\n", 2*week, erros);
	}
		
	printf("\n");
	system("pause");
}
