/*
	Stacks 010
	"Ordenando Stacks"
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
}Node;

typedef struct {
	Node *top;
}Stack;

void push(Stack *s, int num);
Node* pop(Stack *s);
void sortStack(Stack *s);

int main()
{
	Stack s;
	
	return 0;
}

void sortStack(Stack *s)
{
	Node *aux = s -> top;
	
	while(aux -> next < aux -> value)
	{
		
	}
}
