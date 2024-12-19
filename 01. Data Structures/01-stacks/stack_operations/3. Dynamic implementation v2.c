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

int main() {
	Stack stack;
	Node *removed;
	int option, number;
	
	createStack(&stack);
	
	while(1) {
		printf("Choose an option:\n[1] Push data\n[2] Pop data\n[3] Print stack\nR: ");
		scanf("%i", &option);
		getchar();
		
		switch(option) {
			case 1:
				printf("\nInsert the number to push: ");
				scanf("%i", &number);
				getchar();
				
				push(&stack, number);
				printf("\n");
				break;
			case 2:
				removed = pop(&stack);
				
				if(removed) {
					printf("\nNumber %i removed from the stack top.\n\n", removed->data);
				}
				break;
			case 3:
				printStack(&stack);
				break;
			default:
				printf("\nInvalid option.\n\n");
				break;
		}
	}
	
	return 0;
}

void createStack(Stack *stack) {
	stack->top = NULL;
}

void push(Stack *stack, int data) {
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node) { // verify the memory allocation
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
				
			printf("%2i\n", aux->data);
				
			if(aux->next == NULL)
				printf("\n");
			
			aux = aux->next;
		}	
	}
	else
		printf("\nThe stack is empty.\n\n");
}
