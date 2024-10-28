// Creating a function to do the RIGHT ROTATION

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left;
	struct Node *right;
	int height;
} Node;

Node* createNode(int value);
Node* insert(Node *root, int value);
Node* search(Node *root, int value);
Node* removeNode(Node *root, int value);

int nodeHeight(Node *node);
int higherHeight(int leftHeight, int eightHeight);
int balanceFactor(Node *node);
Node* leftRotation(Node *root);
Node* rightRotation(Node *root);

void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	Node *root = NULL;
	
	Node *searchResult;
	int option, value;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Search a value\n[4] Remove nodes\n[5] Exit\nR: ");
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

Node* createNode(int value) {
	Node *new_node = (Node*)malloc(sizeof(Node));
		
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 0;
	
	printf("\nThe value was successfully inserted into the tree.\n");
	
	return new_node;
}

Node* insert(Node *root, int value) {
	if(root == NULL) {
		root = createNode(value);
		return root;
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

int nodeHeight(Node *node) {
	if(node == NULL)
		return -1;
	else
		return node->height;
}

int higherHeight(int leftHeight, int eightHeight) {
	return (leftHeight > rightHeight)? leftHeight: rightHeight;
}

// balance factor = left sub tree height - right sub tree height
int balanceFactor(Node *node) {
	if(node != NULL)
		return (nodeHeight(node->left) - nodeHeight(node->right));
	else
		return 0;
}

Node* leftRotation(Node *root) {
	Node *child, *aux;
	
	child = root->right;
	aux = child->left;
	
	child->left = root;
	root->right = aux;
	
	root->height = higherHeight(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	child->height = higherHeight(nodeHeight(child->left), nodeHeight(child->right)) + 1;
	
	return child;
}

Node* rightRotation(Node *root) {
	Node *child, *aux;
	
	child = root->left;
	aux = child->right;
	
	child->right = root;
	root->left = aux;
	
	root->height = higherHeight(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	child->height = higherHeight(nodeHeight(child->left), nodeHeight(child->right)) + 1;
	
	return child;
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
