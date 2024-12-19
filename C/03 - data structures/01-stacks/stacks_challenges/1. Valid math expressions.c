/*
	This challenge is based on validating a math expression
	provided by the user according to the pairs of
	parenthesis and brackets it contains.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char bracket;
	struct node *next;
} Node;

typedef struct stack {
	Node *top;
} Stack;

void createStack(Stack *stack);
void push(Stack *stack, int data);
Node* pop(Stack *stack);
void printStack(Stack *stack);
void cleanStack(Stack *stack);

void closeBracketPair(Stack *stack, char bracket);
void expressionValid(Stack *stack);

int main() {
	Stack stack;
	Node *removed;
	char expression[50];
	char brackets[6] = {'(', ')', '[', ']', '{', '}'};
	char close_brackets[3] = {')', ']', '}'};
	
	createStack(&stack);
	
	while(1) {
		printf("Insert a math expression to validate: ");
		scanf("%s", expression);
		getchar();
		
		for(int i=0; expression[i] != '\0'; i++) {
			for(int j=0; j<6; j++) {
				if(expression[i] == brackets[j]) {					
					push(&stack, expression[i]);
					
					for(int k=0; k<3; k++) {
						if(expression[i] == close_brackets[k]) {
							closeBracketPair(&stack, expression[i]);
							break;
						}
					}
					break;
				}
			}
		}
		
		expressionValid(&stack);
		cleanStack(&stack);
	}
	
	return 0;
}

void createStack(Stack *stack) {
	stack->top = NULL;
}

void push(Stack *stack, int data) {
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node) { // verify the memory allocation
		new_node->bracket = data;
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
				
			printf("%c\n", aux->bracket);
				
			if(aux->next == NULL)
				printf("\n");
			
			aux = aux->next;
		}	
	}
	else
		printf("\nThe stack is empty.\n\n");
}

void cleanStack(Stack *stack) {
	while(stack->top) {
		pop(stack);
	}
}

void closeBracketPair(Stack *stack, char bracket) {
	Node *aux = stack->top;
	
	while(aux->bracket != bracket) {
		aux = aux->next;
	}
	
	if(aux->next != NULL) {
		if(bracket == ')' && aux->next->bracket == '('
		|| bracket == ']' && aux->next->bracket == '['
		|| bracket == '}' && aux->next->bracket == '{') {
			pop(stack);
			pop(stack);
		}
	}
}

void expressionValid(Stack *stack) {
	if(stack->top)
		printf("\nInvalid expression.\n\n");
	else
		printf("\nThe expression is valid!\n\n");
}
