/* A Secretaria do Meio Ambiente mant�m tr�s listas de ind�strias conhecidas por serem altamente poluentes da atmosfera.
Os resultados de v�rias medidas s�o combinados para formar o que � chamado de ��ndice de polui��o�. Isto � controlado regularmente.
Normalmente os valores caem entre .05 e .25 (Bom). Se o valor atingir .30 (Ruim), as ind�strias da lista A ser�o chamadas a suspender
as opera��es at� que os valores retornem ao intervalo normal. Se o �ndice atingir .40 (P�ssimo), as ind�strias da lista B ser�o notificadas tamb�m.
Se o �ndice exceder .50 (Cr�tico), ind�strias de todas as tr�s listas ser�o avisadas para suspenderem as atividades. Preparar um algoritmo
para ler o �ndice de polui��o e indicar as nota��es apropriadas.

.05 - .25 BOM
.30 RUIM - A
.40 PESSIMO - A e B
>.50 CRITICO - A, B e C

*/

#include <stdio.h>
#include <stdlib.h>

float indice ;

main()
{
	printf("Qual o INDICE DE POLUICAO atual?\n");
	scanf("%f", &indice);
	
	if (indice < 0.30)
		printf("\nO indice esta controlado. Nenhuma acao necessaria.\n\n");
	
	else if (indice < 0.40)
	{
		printf("\nO indice se encontra em estado RUIM\n");
		printf("As industrias da lista A devem suspender suas atividades.\n\n");
	}
	else if (indice <= 0.50)
	{
		printf("\nO indice se encontra em estado PESSIMO\n");
		printf("As industrias das listas A e B devem suspender suas atividades.\n\n");
	}
	else
	{
		printf("\nO indice se encontra em estado CRITICO\n");
		printf("TODAS as empresas das listas A, B e C devem suspender suas atividades.\n\n");
	}
	
	system("pause");
}

