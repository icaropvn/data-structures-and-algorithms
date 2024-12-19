/*
Exerc�cio 03 - Treino de Stacks

	Escreva um programa em C que utilize
uma pilha para converter um n�mero decimal para
sua representa��o bin�ria.

	O programa deve pedir ao usu�rio para inserir
um n�mero decimal e, em seguida, usar uma pilha para
realizar a convers�o para bin�rio. Por fim, o programa
deve imprimir a representa��o bin�ria do n�mero inserido.
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
	
	printf("Insira um n�mero para ser convertido para bin�rio: ");
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
	printf("\nN�mero no sistema decimal: %i\n", aux_num);
	printf("N�mero em bin�rio: ");
	
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
