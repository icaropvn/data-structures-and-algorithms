/*
Teste 035
"Sistema de Hot�is"

Suponha que voc� esteja desenvolvendo o sistema de um hotel que deva 
exibir mensagens na recep��o para diferentes a��es dos hospedes, s�o elas:

1. Fazer Check-in
2. Chamar servi�o de quarto
3. Fazer pedido
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int choice ;

main()
{
	setlocale(LC_ALL, "Portugese");
	
	do
	{	
		printf("Digite o n�mero correspondente ao servi�o desejado:\n1 - Fazer Check-in\n2 - Chamar Servi�o de Quarto\n3 - Fazer Pedido\nR: ");
		scanf("%i", &choice);
		
		switch(choice)
		{
			case 1:
				printf("<check-in choice>\n\n");
				break;
			case 2:
				printf("<servi�o de quarto choice>\n\n");
				break;
			case 3:
				printf("<pedido choice>\n\n");
				break;
			default:
				printf("Escolha inv�lida.\n\n");
				break;
		}
	} while(choice != 1 && choice != 2 && choice != 3);
	
	system("pause");
}
