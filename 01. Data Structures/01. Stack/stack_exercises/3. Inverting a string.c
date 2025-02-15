/*
	This challenge is based on inverting a
	string using stacks to do so.
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
Node* pop(Stack *stack);
void printStack(Stack *stack);

void invertString(Stack *stack, char array[], int array_size);

int main() {
	Stack stack;
	int letters;
	
	createStack(&stack);
	
	printf("Insert the letters quantity for your word: ");
	scanf("%i", &letters);
	letters++;
	
	char word[letters];
	
	printf("Insert the word to invert: ");
	scanf("%s", word);
	
	for(int i=0; word[i] != '\0'; i++) {
		push(&stack, word[i]);
	}
	
	char inverted_word[letters];
	
	invertString(&stack, inverted_word, letters);
	
	printf("\nHere's your inverted word: %s", inverted_word);
	
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


Node* pop(Stack *stack) {
	if(stack->top) {
		Node *remove = stack->top;
		stack->top = stack->top->next;
		
		return remove;
	}
	else
		printf("\nNothing to remove.\n\n");
	
	return NULL;
}

void printStack(Stack *stack) {
	Node *aux = stack->top;
	
	if(aux) {
		while(aux) {
			if(aux == stack->top)
				printf("\n");
				
			printf("%c ", aux->data);
				
			if(aux->next == NULL)
				printf("\n");
			
			aux = aux->next;
		}	
	}
	else
		printf("\nThe stack is empty.\n\n");
}

void invertString(Stack *stack, char array[], int array_size) {
	Node *aux = stack->top, *removed;
	int counter = 0;
	
	while(aux) {
		array[counter] = aux->data;
		aux = aux->next;
		counter++;
	}
	
	array[array_size-1] = '\0';
}
