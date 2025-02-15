/*
	This challenge is based on converting a decimal
	number to its binary syntax using stacks.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct stack {
	Node *top;
} Stack;

void createStack(Stack *stack);
void push(Stack *stack, int data);
void printStack(Stack *stack);

int main() {
	Stack stack;
	int decimal;
	int remainder, quotient;
	
	createStack(&stack);
	
	printf("Insert a decimal number to convert: ");
	scanf("%i", &decimal);
	getchar();
	
	quotient = decimal;
	
	while(quotient != 0 && quotient != 1) {
		remainder = quotient % 2;
		push(&stack, remainder);
		quotient = quotient / 2;
	}
	
	push(&stack, quotient);
	
	printStack(&stack);
	
	return 0;
}

void createStack(Stack *stack) {
	stack->top = NULL;
}

void push(Stack *stack, int data) {
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node) {
		new_node->data = data;
		new_node->next = stack->top;
		
		stack->top = new_node;
	}
	else
		printf("\nMemory allocation failed.\n");
}

void printStack(Stack *stack) {
	Node *aux = stack->top;
	
	if(aux) {
		while(aux) {
			if(aux == stack->top)
				printf("\n");
				
			printf("%i", aux->data);
				
			if(aux->next == NULL)
				printf("\n");
			
			aux = aux->next;
		}	
	}
	else
		printf("\nThe stack is empty.\n\n");
}
