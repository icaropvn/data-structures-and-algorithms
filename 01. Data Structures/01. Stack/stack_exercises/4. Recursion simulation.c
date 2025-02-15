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
void cleanStack(Stack *stack);

int calculateFactorial(Stack *stack, int num);

int main() {
	Stack stack;
	int number, factorial;
	
	printf("Insert a number to calculate the factorial: ");
	scanf("%i", &number);
	getchar();
	
	printf("\n%i! = ", number);
	factorial = calculateFactorial(&stack, number);
	printf("%i\n", factorial);
	
	cleanStack(&stack);
	
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

void cleanStack(Stack *stack) {
	Node *aux = stack->top, *temp;
	
	while(aux) {
		temp = aux;
		aux = aux->next;
		free(aux);
	}
	
	stack->top = NULL;
}

int calculateFactorial(Stack *stack, int num) {
	int factorial = 1, aux_num = 1;
	
	while(aux_num <= num) {
		push(stack, aux_num);
		aux_num++;
	}
	
	Node *aux = stack->top;
	Node *removed;
	
	while(aux) {
		removed = pop(stack);
		factorial = factorial * removed->data;
		
		if(aux->next == NULL)
			printf("%i = ", removed->data);
		else
			printf("%i * ", removed->data);
		
		aux = aux->next;
	}
	
	return factorial;
}
