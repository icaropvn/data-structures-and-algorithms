/*
Aquecendo: Ponteiros Pt. IV	
	
	Considere a seguinte declara��o:
	
	int A, *B, **C, ***D;
	
	Escreva um programa que leia a vari�vel A e calcule e exiba o dobro, o triplo e o qu�druplo desse
valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C
o triplo e D o qu�druplo.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, *b, **c, ***d;
	
	b = &a;
	c = &b;
	d = &c;
	
	printf("Insira o valor de A: ");
	scanf("%i", &a);
	
	printf("\nConteudos:\nA = %i\nB = %i\nC = %i\nD = %i", a, 2 * *b, 3 * **c, 4 * ***d); 
	
	return 0;
}
