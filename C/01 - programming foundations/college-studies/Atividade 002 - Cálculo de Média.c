/* C�lculo de M�dia Final
M�dia = Prova Parcial * 0.4 + Prova Final * 0.6 

**Quanto mais enxuto o c�digo, no caso tendo uma divis�o a menos, faz muita diferen�a em caso de c�digos grandes

*/

#include <stdio.h>
#include <stdlib.h>

float media, pparcial, pfinal;

main()
{
	printf("Insira a nota da Prova Parcial: ");
	scanf("%f", &pparcial);
	printf("Insira a nota da Prova Final: ");
	scanf("%f", &pfinal);
	
	media = pparcial * 0.4 + pfinal * 0.6;
	printf("A media e: %3.1f\n\n", media);
	
	system("pause");
	
}
