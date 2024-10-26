// Generating a random tree

/* 

This script creates a tree by random values.
The elements quantity is chosen by the user, as well as the range of the randomization.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tree struct
typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

// Random tree stack structs
typedef struct sNode {
	int black_listed_value;
	struct sNode *next;
} sNode;

typedef struct Stack {
	sNode *top;
} Stack;

// Random tree stack functions
void createStack(Stack *stack);
int searchStack(Stack *stack, int value);
void destructStack(Stack *stack);

// Tree functions
Node* insertWithMessage(Node *root, int value);
Node* insertWithoutMessage(Node *root, int value);
Node* search(Node *root, int value);

void createRandomTree(Node **root, int elements, int min_range, int max_range);

void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	srand(time(NULL));
	
	Node *root = NULL;
	
	Node *searchResult;
	int option, value;
	int elements, min_range, max_range;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Search a value\n[4] Generate random tree\n[5] Exit\nR: ");
		scanf("%i", &option);
		
		switch(option) {
			case 1:
				printf("\nInform a value to insert into the tree: ");
				scanf("%i", &value);
				
				root = insertWithMessage(root, value);
				printf("\n");
				break;
			case 2:
				if(root != NULL) {
					printf("\nPre Order: ");
					printPreOrder(root);
					printf("\n");
					printf("In Order: ");
					printInOrder(root);
					printf("\n");
					printf("Post Order: ");
					printPostOrder(root);
					printf("\n\n");
				}
				else
					printf("\nThe tree is empty. Insert something before printing.\n\n");
				break;
			case 3:
				printf("\nInform the value to search: ");
				scanf("%i", &value);
				
				searchResult = search(root, value);
				
				if(searchResult == NULL)
					printf("\nThe value isn't in the tree.\n\n");
				else
					printf("\nThe value was found!\n\n");
				break;
			case 4:
				printf("\nHow many elements you want your tree to have?\nR: ");
				scanf("%i", &elements);
				
				printf("\nWhich's the minimum value you want your tree to have?\nR: ");
				scanf("%i", &min_range);
				
				printf("\nWhich's the maximum value you want your tree to have?\nR: ");
				scanf("%i", &max_range);
				
				createRandomTree(&root, elements, min_range, max_range);
				break;
			case 5:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\nThe option is invalid.\n\n");
				break;
		}
		
		if(option == 5)
			break;
	}
	
	return 0;
}

void createStack(Stack *stack) {
	stack->top = NULL;
}

void push(Stack *stack, int value) {
	sNode *new_node = malloc(sizeof(sNode));
	
	if(new_node)
	{
		new_node->black_listed_value = value;
		new_node->next = stack->top;
		stack->top = new_node;
	}
}

int searchStack(Stack *stack, int value) {
	sNode *aux = stack->top;
	
	while(aux) {
		if(aux->black_listed_value == value)
			return 1;
		else
			aux = aux->next;
	}
	
	return 0;
}

void destructStack(Stack *stack) {
	sNode *aux;
	
	while(stack->top) {
		aux = stack->top->next;
		free(stack->top);
		stack->top = aux;
	}
}

Node* insertWithMessage(Node *root, int value) {
	if(root == NULL) {
		Node *new_node = (Node*)malloc(sizeof(Node));
		
		new_node->value = value;
		new_node->left = NULL;
		new_node->right = NULL;
		
		printf("\nThe value was successfully inserted into the tree.\n");
		
		return new_node;
	}
	else {
		if(value < root->value)
			root->left = insertWithMessage(root->left, value);
		else if(value > root->value)
			root->right = insertWithMessage(root->right, value);
		else
			printf("\nThe value has already been added to the tree.\n");
		
		return root;
	}
}

Node* insertWithoutMessage(Node *root, int value) {
	if(root == NULL) {
		Node *new_node = (Node*)malloc(sizeof(Node));
		
		new_node->value = value;
		new_node->left = NULL;
		new_node->right = NULL;
		
		return new_node;
	}
	else {
		if(value < root->value)
			root->left = insertWithoutMessage(root->left, value);
		else if(value > root->value)
			root->right = insertWithoutMessage(root->right, value);
		
		return root;
	}
}

Node* search(Node *root, int value) {
	while(root != NULL) {
		if(value == root->value)
			return root;
		else {
			if(value < root->value)
				root = root->left;
			else
				root = root->right;
		}
	}
	
	return NULL;
}

void createRandomTree(Node **root, int elements, int min_range, int max_range) {
	Stack black_list;
	createStack(&black_list);
	
	int i, random_value, counter = 1;
	
	while(1) {
		random_value = (rand() % (max_range - min_range + 1)) + min_range;
		
		if(searchStack(&black_list, random_value) == 0) {
			*root = insertWithoutMessage(*root, random_value);
			push(&black_list, random_value);
			counter++;
		}
		
		if(counter == elements + 1)
			break;
	}
	
	destructStack(&black_list);
	
	printf("\nRandom tree generated with success!\n\n");
}

void printPreOrder(Node *root) {
	if(root != NULL) {
		printf("%i ", root->value);
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printInOrder(Node *root) {
	if(root != NULL) {
		printInOrder(root->left);
		printf("%i ", root->value);
		printInOrder(root->right);
	}
}

void printPostOrder(Node *root) {
	if(root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		printf("%i ", root->value);
	}
}
