// Creating a function to calculate the height of a binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

Node* insert(Node *root, int value);
Node* search(Node *root, int value);
int height(Node *root);

void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	Node *root = NULL;
	
	Node *searchResult;
	int option, value, tree_height;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Search a value\n[4] Check tree height\n[5] Exit\nR: ");
		scanf("%i", &option);
		
		switch(option) {
			case 1:
				printf("\nInform a value to insert into the tree: ");
				scanf("%i", &value);
				
				root = insert(root, value);
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
				tree_height = height(root);
				
				if(tree_height == -1)
					printf("\nYour tree is empty. Add something to verify the height.\n\n");
				else if(tree_height == 0)
					printf("\nThe tree height is 0. (your tree has only one element)\n\n");
				else
					printf("\nThe tree height is: %i\n\n", tree_height);
				
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

Node* insert(Node *root, int value) {
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
			root->left = insert(root->left, value);
		else if(value > root->value)
			root->right = insert(root->right, value);
		else
			printf("\nThe value has already been added to the tree.\n");
		
		return root;
	}
}

Node* search(Node *root, int value) {
	if(root != NULL) {
		if(root->value == value)
			return root;
		else {
			if(value < root->value)
				return search(root->left, value);
			else
				return search(root->right, value);
		}
	}
	
	return NULL;
}

int height(Node* root) {
	if(root == NULL)
		return -1;
	else {
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		
		return 1 + (leftHeight > rightHeight? leftHeight: rightHeight);
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
