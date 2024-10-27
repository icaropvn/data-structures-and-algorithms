/* Determinar e imprimir a m�dia e o conceito do aluno com base na m�dia:
	M�dia = Parcial * 0,4 + Final * 0,6 (obs: notas de 0 a 100)
	conceito A: 80 a 100
	conceito B: 70 a 79
	conceito C: 60 a 69
	conceito D: 50 a 59
	conceito E: < 50     */
	
# include <stdio.h>
# include <stdlib.h>

int pparcial, pfinal, media ;

main()
{
	printf("Insira a nota da prova parcial (0 - 100): ");
	scanf("%i", &pparcial);
	
	printf("Insira a nota da prova final (0 - 100): ");
	scanf("%i", &pfinal);
	
	media = (pparcial*4 + pfinal*6)/10 ;
	
	printf("Media: %i\n", media);
	
	if(media < 50)
		printf("Conceito E\n\n");
	else if(media < 60)
		printf("Conceito D\n\n");
	else if(media < 70)
		printf("Conceito C\n\n");
	else if(media < 80)
		printf("Conceito B\n\n");
	else	// Nesse caso, como o valor n�o se enquadra nas outras condi��es, n�o � preciso fazer mais um teste
		printf("Conceito A\n\n");
	
	system("pause");
}
