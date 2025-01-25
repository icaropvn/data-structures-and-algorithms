#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node* push(Node *top, int data);
Node* pop(Node **top);
void printStack(Node *top);

int main() {
	Node *top = NULL;
	Node *removed;
	int option, number;
	
	while(1) {
		printf("Choose an option:\n[1] Push data\n[2] Pop data\n[3] Print stack\nR: ");
		scanf("%i", &option);
		getchar();
		
		switch(option) {
			case 1:
				printf("\nInsert the number to push: ");
				scanf("%i", &number);
				getchar();
				
				top = push(top, number);
				printf("\n");
				break;
			case 2:
				removed = pop(&top);
				
				if(removed) {
					printf("\nNumber %i removed from the stack top.\n\n", removed->data);
					free(removed);
				}
				break;
			case 3:
				printStack(top);
				break;
			default:
				printf("\nInvalid option.\n\n");
				break;
		}
	}
	
	return 0;
}

Node* push(Node *top, int data) {
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node) { // verify the memory allocation
		new_node->data = data;
		new_node->next = top;
		return new_node;
	}
	else
		printf("\nMemory allocation failed.\n");
		
	return NULL;
}

Node* pop(Node **top) {	
	if(*top) {
		Node *remove = *top;
		*top = (*top)->next;
		
		return remove;
	}
	else
		printf("\nNothing to remove.\n\n");
	
	return NULL;
}

void printStack(Node *top) {
	Node *aux = top;
	
	if(aux) {
		while(aux) {
			if(aux == top)
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
