/*
Teste 052
"Erro de leitura de um caracter"
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char sexo ;
	int idade ;
	float peso, altura ;
	
	printf("Insira sua idade, seu peso, sua altura e seu sexo (M/F) na respectiva ordem: ");
	scanf("%i%f%f %c", &idade, &peso, &altura, &sexo);
	
	/* Para resolver o problema da leitura de caracteres em rela��o ao buffer do teclado, basta
	   adicionar um espa�o antes do '%c' no scanf. Assim a fun��o ignorar� tabs, espa�os e enters. */
	
	printf("\nIdade: %i anos\nPeso: %.2fKg\nAltura: %.2fm\nSexo: %c\n", idade, peso, altura, sexo);
	
	return 0;
}
