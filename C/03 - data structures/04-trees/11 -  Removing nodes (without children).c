// Creating a function to count the binary tree leaves number

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
int countNodes(Node *root);
int countLeaves(Node *root);
Node* removeNode(Node *root, int value);

void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	Node *root = NULL;
	
	Node *searchResult;
	int option, value;
	int tree_height, tree_nodes, tree_leaves;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Search a value\n[4] Remove a node\n[5] Check tree height\n[6] Count elements\n[7] Count leaves\n[8] Exit\nR: ");
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
				printf("\nInsert the value to remove from the tree: ");
				scanf("%i", &value);
				
				root = removeNode(root, value);
				
				break;
			case 5:
				tree_height = height(root);
				
				if(tree_height == -1)
					printf("\nYour tree is empty. Add something to verify the height.\n\n");
				else if(tree_height == 0)
					printf("\nThe tree height is 0. (your tree has only one element)\n\n");
				else
					printf("\nThe tree height is: %i\n\n", tree_height);
				
				break;
			case 6:
				tree_nodes = countNodes(root);
				
				if(tree_nodes == 0)
					printf("\nThe tree has %i nodes. (the tree is empty)\n\n", tree_nodes);
				else if(tree_nodes == 1)
					printf("\nThe tree has %i node.\n\n", tree_nodes);
				else
					printf("\nThe tree has %i nodes.\n\n", tree_nodes);
					
				break;
			case 7:
				if(root != NULL) {
					tree_leaves = countLeaves(root);
				
					if(tree_leaves == 1)
						printf("\nThe tree has 1 leaf.\n\n");
					else
						printf("\nThe tree has %i leaves.\n\n", tree_leaves);
				}
				else
					printf("\nThe tree is empty. Insert something to check the leaves number.\n\n");
				break;
			case 8:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("\nThe option is invalid.\n\n");
				break;
		}
		
		if(option == 8)
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

int countNodes(Node *root) {	
	return ((root == NULL)? 0: 1 + countNodes(root->left) + countNodes(root->right));
}

int countLeaves(Node *root) {
	if(root == NULL)
		return 0;
	else {
		if(root->left == NULL && root->right == NULL)
			return 1;
		else {
			return countLeaves(root->left) + countLeaves(root->right);
		}
	}
}

Node* removeNode(Node *root, int value) {
	if(root == NULL) {
		// nao achou o elemento
		printf("\nThe node wasn't find in the tree.\n\n");
		return NULL;
	}
	else {
		if(root->value == value) {
			// verificar o tipo do nó
			if(root->left == NULL && root->right == NULL) {
				// remover nó folha (sem filhos)
				free(root);
				printf("\nThe leaf element %i was removed successfully!\n\n", value);
				return NULL;
			}
			else {
				// verificar se nó possui um ou dois filhos
				if(root->left != NULL && root->right != NULL) {
					// remover nó com 2 filhos
					Node *aux = root->left;
					
					while(aux->right != NULL)
						aux = aux->right;
					
					root->value = aux->value;
					aux->value = value;
					
					root->left = removeNode(root->left, value);
					return root;
				}
				else {
					// remover nó com 1 filho
					Node *aux = (root->left != NULL)? root->left: root->right;
					
					free(root);
					printf("\nThe element %i was removed successfully!\n\n", value);
					return aux;
				}
			}
		}
		else {
			// continua percorrendo a arvore
			if(value < root->value)
				root->left = removeNode(root->left, value);
			else
				root->right = removeNode(root->right, value);
			
			return root;
		}
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
