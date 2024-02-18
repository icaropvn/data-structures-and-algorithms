/*
	Stacks 008
	"Stacks Estáticas"
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
	int stack[MAXTAM];
	int top;
} Stack;

void createStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void printStack(Stack *s);

int main()
{
	Stack *s = malloc(sizeof(Stack));
	int answer, value, removed_value;
	
	createStack(s);
	
	while(1)
	{
		printf("What would you like to do?\n[1] Push Value\n[2] Pop Value\n[3] Print Stack\n[4] Quit\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 1:
				printf("\nInsert the value: ");
				scanf("%i", &value);
				push(s, value);
				break;
			case 2:
				removed_value = pop(s);
				
				if(removed_value)
					printf("\nThe followed item was removed.\n        --- ( %i ) ---\n\n", removed_value);
				
				break;
			case 3:
				printStack(s);
				break;
			case 4:
				printf("\nIt was a pleasure to have you here! See you.\n");
				break;
			default:
				printf("\nError. Insert a valid option.\n\n");
				break;
		}
		
		if(answer == 4)
			break;
	}
	
	free(s);
	
	return 0;
}

void createStack(Stack *s)
{
	s -> top = -1;
}

int isEmpty(Stack *s)
{
	if(s -> top == -1)
		return 1;
	else
		return 0;
}

int isFull(Stack *s)
{
	if(s -> top == MAXTAM-1)
		return 1;
	else
		return 0;
}

void push(Stack *s, int value)
{
	if(!isFull(s))
	{
		s -> top++;
		s -> stack[s -> top] = value;
	}
	else
		printf("\nThe stack is full.\n");
	
	printf("\n");
}

int pop(Stack *s)
{
	int remove;
	
	if(!isEmpty(s))
	{
		remove = s -> stack[s -> top];
		s -> top--;
		return remove;
	}
	else
		printf("\nThe stack is empty.\n\n");
}

void printStack(Stack *s)
{
	int i;
	
	if(!isEmpty(s))
	{
		printf("\n== Stack Top ==\n");
		
		for(i=s->top; i>=0; i--)
		{
			printf("       %2i\n", s -> stack[i]);
		}
		
		printf("\n== Stack base ==\n\n");
	}
	else
		printf("\nThe stack is empty.\n\n");
}
