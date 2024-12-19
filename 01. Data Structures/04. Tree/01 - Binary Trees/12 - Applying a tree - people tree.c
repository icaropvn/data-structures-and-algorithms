/*

Building an algorithm to apply a binary tree
over people data.

*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	long long int cpf; // chave da arvore
	char data_nascimento[11];
	char email[50];
} Person;

typedef struct Node {
	Person person;
	struct Node *left;
	struct Node *right;
} Node;

Node* insert(Node *root, Person person);
Node* search(Node *root, long long int cpf);
Node* removeNode(Node *root, long long int cpf);

void printPreOrder(Node *root);
void printInOrder(Node *root);
void printPostOrder(Node *root);

int main() {
	Node *root = NULL;
	
	Node *searchResult;
	Person person;
	int option;
	long long int temp_lli;
	
	while(1) {
		printf("What would you like to do?\n");
		printf("[1] Insert value\n[2] Print tree (all traversals)\n[3] Search a value\n[4] Remove a node\n[5] Exit\nR: ");
		scanf("%i", &option);
		fflush(stdin);
		
		switch(option) {
			case 1:
				printf("\nPerson's name: ");
				scanf("%49[^\n]", person.nome);
				fflush(stdin);
				
				printf("\nPerson's CPF (only numbers): ");
				scanf("%11lli", &person.cpf);
				fflush(stdin);
				
				printf("\nPerson's birth date: ");
				scanf("%10[^\n]", person.data_nascimento);
				fflush(stdin);
				
				printf("\nPerson's e-mail: ");
				scanf("%49[^\n]", person.email);
				fflush(stdin);
				
				root = insert(root, person);
				printf("\n");
				break;
				
			case 2:
				if(root != NULL) {
					printf("\nPre Order: ");
					printPreOrder(root);
					printf("\n-------------------\n\n");
					printf("In Order: ");
					printInOrder(root);
					printf("\n-------------------\n\n");
					printf("Post Order: ");
					printPostOrder(root);
					printf("\n-------------------");
					printf("\n\n");
				}
				else
					printf("\nThe tree is empty. Insert something before printing.\n\n");
				break;
			case 3:
				printf("\nInform a person's CPF to search: ");
				scanf("%lli", &temp_lli);
				
				searchResult = search(root, temp_lli);
				
				if(searchResult == NULL)
					printf("\nThe value isn't in the tree.\n\n");
				else {
					printf("\nName: %s\n", searchResult->person.nome);
					printf("CPF: %lli\n", searchResult->person.cpf);
					printf("Birth Date: %s\n", searchResult->person.data_nascimento);
					printf("E-mail: %s\n\n", searchResult->person.email);
				}

				break;
			case 4:
				printf("\nInsert a CPF to remove the person from the tree: ");
				scanf("%lli", &temp_lli);
				
				root = removeNode(root, temp_lli);
				
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

Node* insert(Node *root, Person person) {
	if(root == NULL) {
		Node *new_node = (Node*)malloc(sizeof(Node));
		
		new_node->person = person;
		new_node->left = NULL;
		new_node->right = NULL;
		
		printf("\nThe person was successfully inserted into the tree.\n");
		
		return new_node;
	}
	else {
		if(person.cpf < root->person.cpf)
			root->left = insert(root->left, person);
		else if(person.cpf > root->person.cpf)
			root->right = insert(root->right, person);
		else
			printf("\nThe person has already been added to the tree.\n");
		
		return root;
	}
}

Node* search(Node *root, long long cpf) {
	if(root != NULL) {
		if(root->person.cpf == cpf)
			return root;
		else {
			if(cpf < root->person.cpf)
				return search(root->left, cpf);
			else
				return search(root->right, cpf);
		}
	}
	
	return NULL;
}

Node* removeNode(Node *root, long long int cpf) {
	if(root == NULL) {
		// nao achou o elemento
		printf("\nThe person wasn't find in the tree.\n\n");
		return NULL;
	}
	else {
		if(root->person.cpf == cpf) {
			// verificar o tipo do nó
			if(root->left == NULL && root->right == NULL) {
				// remover nó folha (sem filhos)
				free(root);
				printf("\nThe person (leaf element) identified by CPF %lli was removed successfully!\n\n", cpf);
				return NULL;
			}
			else {
				// verificar se nó possui um ou dois filhos
				if(root->left != NULL && root->right != NULL) {
					// remover nó com 2 filhos
					Person person_found = root->person;
					
					Node *aux = root->left;
					
					while(aux->right != NULL)
						aux = aux->right;
					
					root->person = aux->person;
					aux->person = person_found;
					
					root->left = removeNode(root->left, cpf);
					return root;
				}
				else {
					// remover nó com 1 filho
					Node *aux = (root->left != NULL)? root->left: root->right;
					
					free(root);
					printf("\nThe person identified by CPF %lli was removed successfully!\n\n", cpf);
					return aux;
				}
			}
		}
		else {
			// continua percorrendo a arvore
			if(cpf < root->person.cpf)
				root->left = removeNode(root->left, cpf);
			else
				root->right = removeNode(root->right, cpf);
			
			return root;
		}
	}
}

void printPreOrder(Node *root) {
	if(root != NULL) {
		printf("\n-------------------\n");
		printf("Name: %s\n", root->person.nome);
		printf("CPF: %lld\n", root->person.cpf);
		printf("Birth Date: %s\n", root->person.data_nascimento);
		printf("E-mail: %s", root->person.email);
		
		printPreOrder(root->left);
		printPreOrder(root->right);
	}
}

void printInOrder(Node *root) {
	if(root != NULL) {
		printInOrder(root->left);
		
		printf("\n-------------------\n");
		printf("Name: %s\n", root->person.nome);
		printf("CPF: %lld\n", root->person.cpf);
		printf("Birth Date: %s\n", root->person.data_nascimento);
		printf("E-mail: %s", root->person.email);
		
		printInOrder(root->right);
	}
}

void printPostOrder(Node *root) {
	if(root != NULL) {
		printPostOrder(root->left);
		printPostOrder(root->right);
		
		printf("\n-------------------\n");
		printf("Name: %s\n", root->person.nome);
		printf("CPF: %lld\n", root->person.cpf);
		printf("Birth Date: %s\n", root->person.data_nascimento);
		printf("E-mail: %s", root->person.email);
	}
}
