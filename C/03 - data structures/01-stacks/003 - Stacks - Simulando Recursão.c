// 003 - Stacks: simulando um algoritmo recursivo para cálculo de fatorial

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node {
	int num;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, int num);
Node* pop(Stack *s);
void printStack(Stack *s);
int factorial(int num, Stack *s);

int main()
{
	Stack s;
	int num;
	
	printf("Digite um valor (maior que 0) para obter seu fatorial: ");
	scanf("%i", &num);
	
	printf("\n %i! = %i\n", num, factorial(num, &s));
	
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
		new_node -> num = num;
		new_node -> next = s -> top;
		s -> top = new_node;
	}
	else
		printf("\nErro ao alocar memória.\n");
}

Node* pop(Stack *s)
{
	Node *remove = NULL;
	
	if(s -> top)
	{
		remove = s -> top;
		s -> top = s -> top -> next;
	}
	else
		printf("\nEmpty stack!\n");
	
	return remove;
}

void printStack(Stack *s)
{
	Node *aux = s -> top;
	
	printf("\n STACK\n");
	
	while(aux)
	{
		printf("   %i\n", aux -> num);
		aux = aux -> next;
	}
}

int factorial(int num, Stack *s)
{	
	Node *removed_node;
	
	while(num > 1)
	{
		push(&*s, num);
		num--;
	}
	
	printStack(s);
	
	while(s -> top)
	{
		removed_node = pop(&*s);
		num *= removed_node -> num;
		free(removed_node);
	}
	
	return num;
}
