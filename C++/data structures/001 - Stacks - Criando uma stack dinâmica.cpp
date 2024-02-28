// Implementando uma stack dinâmica em C++

#include <iostream>
using namespace std;

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct {
	Node *top;
	int size;
} Stack;

void initStack(Stack *s);
void push(Stack *s, int num);
Node* pop(Stack *s);
void printStack(Stack *s);
void printMenu();
void switchOption(Stack *s, int answer);

int main()
{
	Stack s;
	int answer;
	
	initStack(&s);
	
	while(1)
	{
		printMenu();
		scanf("%i", &answer);
		
		switchOption(&s, answer);
		
		if(answer == 4)
			break;
	}
	
	return 0;
}

void initStack(Stack *s)
{
	s->top = NULL;
	s->size = 0;
}

void push(Stack *s, int num)
{
	Node *new_node = new Node;
	
	if(new_node)
	{
		new_node->value = num;
		new_node->next = s->top;
		s->top = new_node;
		s->size++;
	}
}

Node* pop(Stack *s)
{
	Node *remove = NULL;
	
	if(s->top)
	{
		remove = s->top;
		s->top = s->top->next;
		s->size--;
	}
	
	return remove;
}

void printStack(Stack *s)
{
	Node *aux = s->top;

	printf("\n----- Stack / Size: %02i -----\n", s->size);

	while(aux)
	{
		printf("          |  %2i  |\n", aux->value);
		
		aux = aux->next;
	}
	
	printf("----------------------------\n\n");
}

void printMenu()
{
	printf("Choose an option:\n");
	printf("[1] Push value\n[2] Pop value\n[3] Print stack\n[4] Quit\nR: ");
}

void switchOption(Stack *s, int answer)
{
	Node *removed;
	int value;
	
	switch(answer)
	{
		case 1:
			printf("\nInsert the value to push: ");
			scanf("%i", &value);
			
			push(s, value);
			printf("\n");
			
			break;
		case 2:
			removed = pop(s);
			
			if(removed)
			{
				printf("\nThe followed item was removed from the stack:\n");
				printf("----- ( %i ) -----\n\n", removed->value);
			}
			else
				printf("\nThe stack's empty!\n\n");
				
			delete removed;
			break;
		case 3:
			if(s->top)
				printStack(s);
			else
				printf("\nThe stack's empty!\n\n");
				
			break;
		case 4:
			printf("\nSee you!\n");
			break;
		default:
			printf("\nTry a valid option!\n\n");
			break;
	}
}
