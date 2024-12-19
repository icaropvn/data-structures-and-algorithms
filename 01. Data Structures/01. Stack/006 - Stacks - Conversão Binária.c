/*
Exercício 03 - Treino de Stacks

	Escreva um programa em C que utilize
uma pilha para converter um número decimal para
sua representação binária.

	O programa deve pedir ao usuário para inserir
um número decimal e, em seguida, usar uma pilha para
realizar a conversão para binário. Por fim, o programa
deve imprimir a representação binária do número inserido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node {
	int remainder;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, int num);
Node* pop(Stack *s);
void convertNumber(Stack *s, int num);
// void printStack(Stack *s);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Stack s;
	int num;
	
	createStack(&s);
	
	printf("Insira um número para ser convertido para binário: ");
	scanf("%i", &num);
	
	convertNumber(&s, num);
	
	return 0;
}

void createStack(Stack *s)
{
	s -> top = NULL;
}

void push(Stack *s, int num)
{
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node)
	{
		new_node -> remainder = num;
		new_node -> next = s -> top;
		s -> top = new_node;
	}
	else
		printf("\nOps! Parece que algo deu errado.\n");
}

Node* pop(Stack *s)
{
	Node *remove = NULL;
	
	if(s -> top)
	{
		remove = s -> top;
		s -> top = s -> top -> next;
	}
	
	return remove;
}

void convertNumber(Stack *s, int num)
{
	Node *removed = NULL;
	int aux_num = num;
	
	while(1)
	{
		push(s, num % 2);
		num = num / 2;
		
		if(num == 0)
			break;
	}
	
	// printStack(s);
	printf("\nNúmero no sistema decimal: %i\n", aux_num);
	printf("Número em binário: ");
	
	while(s -> top)
	{
		removed = pop(s);
		printf("%i", removed -> remainder);
		free(removed);
	}
	
	printf("\n");
}

/*
void printStack(Stack *s).........print da stack para debug
{
	Node *aux = s -> top;
	
	while(aux)
	{
		printf("%i\n", aux -> remainder);
		aux = aux -> next;
	}
}
*/
