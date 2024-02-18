/*
	009 - Stacks
	"Invertendo uma Stack"
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, int num);
Node* pop(Stack *s);
void reverseStack(Stack *s);
void printStack(Stack *s);

int main()
{
	Stack s;
	Node *removed_value;
	int answer, num;
	
	createStack(&s);
	
	while(1)
	{
		printf("What would you like to do?\n[1] Push Value\n[2] Pop Value\n[3] Print Stack\n[4] Reverse Stack\n[5] Exit\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				printf("\nInsert the value: ");
				scanf("%i", &num);
				push(&s, num);
				printf("\n");
				break;
			case 2:
				removed_value = pop(&s);
				
				if(removed_value)
					printf("\nThe followed item was removed.\n        --- ( %i ) ---\n\n", removed_value -> value);
				else
					printf("\nThe stack is empty.\n\n");
				
				free(removed_value);
				
				break;
			case 3:
				printStack(&s);
				break;
			case 4:
				reverseStack(&s);
				break;
			case 5:
				printf("\nIt was a pleasure to have you here! See you.\n");
				break;
			default:
				printf("\nError. Insert a valid option.\n\n");
				break;
		}
		
		if(answer == 5)
			break;
	}
	
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
		new_node -> value = num;
		new_node -> next = s -> top;
		s -> top = new_node;
	}
	else
		printf("\nSomething went wrong! :(\n");
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

void reverseStack(Stack *s)
{
	if(s -> top)
	{
		Stack aux_s1, aux_s2;
		Node *removed;
		
		createStack(&aux_s1);
		createStack(&aux_s2);
		
		while(s -> top)
		{
			removed = pop(s);
			push(&aux_s1, removed -> value);
		}
		
		while(aux_s1.top)
		{
			removed = pop(&aux_s1);
			push(&aux_s2, removed -> value);
		}
		
		while(aux_s2.top)
		{
			removed = pop(&aux_s2);
			push(s, removed -> value);
		}
		
		printf("\nStack reversed with success! Here's your new stack:\n");
		printStack(s);
	}
	else
		printf("\nUnable to reverse. The stack is empty.\n\n");
}

void printStack(Stack *s)
{
	if(s -> top)
	{
		Node *aux = s -> top;
		
		printf("\n== Stack  Top ==\n");
		
		while(aux)
		{
			printf("       %2i\n", aux -> value);
			aux = aux -> next;
		}
		
		printf("\n== Stack Base ==\n\n");
	}
	else
		printf("\nNothing to print.\n\n");
}
