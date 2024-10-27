/*
Teste 050
"getc"

Teste das fun��es getc() e fgetc()
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char letter1, letter2;
	
	printf("Insira uma letra (getc()): ");
	letter1 = getc(stdin);
	// A fun��o getc precisa de um par�metro que direciona de onde deve ser lido o caracter
	// stdin � a entrada padr�o do PC (teclado)
	
	printf("Insira outra letra (fgetc()): ");
	letter2 = fgetc(stdin);
	// O 'f' do fgetc() vem da palavra file, ou seja, esta fun��o � �til para ler
	// caracteres de dentro de arquivos.
	// !!! POR ALGUM MOTIVO ESSA FUN��O N�O FUNCIONA AQUI !!!
	
	printf("\nCaracteres lidos: %c - %c\n", letter1, letter2);
	
	return 0;
}
