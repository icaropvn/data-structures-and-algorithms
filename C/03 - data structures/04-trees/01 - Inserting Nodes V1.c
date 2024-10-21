// Inserting values in a binary tree - version 01

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
} Node;

Node* insert(Node *root, int value);

int main() {
	Node *root = NULL;
	
	return 0;
}

Node* insert(Node *root, int value) {
	if(root == NULL) {
		Node new_node = (Node*)malloc(sizeof(Node));
		
		new_node->value = value;
		new_node->left = NULL;
		new_node->right - NULL;
		
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
