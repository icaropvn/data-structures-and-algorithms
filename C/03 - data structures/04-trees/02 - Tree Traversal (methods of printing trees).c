// Printing binary trees - 2 versions

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

Node* insert(Node *root, int value);
void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	Node *root = NULL;
	int option, value;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Exit\nR: ");
		scanf("%i", &option);
		
		switch(option) {
			case 1:
				printf("\nInform a value to insert into the tree: ");
				scanf("%i", &value);
				root = insert(root, value);
				printf("\n");
				break;
			case 2:
				printf("\nPre Order: ");
				printPreOrder(root);
				printf("\n");
				printf("In Order: ");
				printInOrder(root);
				printf("\n");
				printf("Post Order: ");
				printPostOrder(root);
				printf("\n\n");
				break;
			case 3:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\nThe option is invalid.\n");
				break;
		}
		
		if(option == 3)
			break;
	}
	
	return 0;
}

Node* insert(Node *root, int value) {
	if(root == NULL) {
		Node *new_node = (Node*)malloc(sizeof(Node));
		
		new_node->value = value;
		new_node->left = NULL;
		new_node->right = NULL;
		
		return new_node;
	}
	else {
		if(value < root->value)
			root->left = insert(root->left, value);
		else
			root->right = insert(root->right, value);
		
		return root;
	}
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
