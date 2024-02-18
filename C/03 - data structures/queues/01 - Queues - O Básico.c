/*
Queues 01
O Básico
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node {
	int value;
	struct node *next;
} Node;

typedef struct {
	Node *front;
	Node *back;
	int tam;
} Queue;

void createQueue(Queue *q);
void enqueue(Queue *q, int num);
Node* dequeue(Queue *q);
void printQueue(Queue *q);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Queue q;
	Node *removed;
	int answer, num;
	
	createQueue(&q);
	
	while(1)
	{
		printf("0 - Sair\n1 - Enqueue\n2 - Dequeue\n3 - Print Queue\nR: ");
		scanf("%i", &answer);
		
		switch(answer)
		{
			case 0:
				printf("\nAté mais!\n");
				break;
			case 1:
				printf("\nDigite um número: ");
				scanf("%i", &num);
				
				printf("\n");
				
				enqueue(&q, num);
				
				break;
			case 2:
				removed = dequeue(&q);
				
				if(removed)
				{
					printf("\nITEM REMOVIDO: %i\n\n", removed -> value);
					free(removed);
				}
				else
					printf("\nNenhum item na fila a remover!\n\n");
				
				break;
			case 3:
				printQueue(&q);
				break;
			default:
				printf("\nOpção inválida!\n\n");
				break;
		}
		
		if(!answer)
			break;
	}
	
	return 0;
}

void createQueue(Queue *q)
{
	q -> front = NULL;
	q -> back = NULL;
	q -> tam = 0;
}

void enqueue(Queue *q, int num)
{
	Node *aux, *new_node = malloc(sizeof(Node));
	
	if(new_node)
	{
		new_node -> value = num;
		new_node -> next = NULL;
		
		if(q -> front == NULL)
		{
			q -> front = new_node;
			q -> back = new_node;
		}
		else
		{
			q -> back -> next = new_node;
			q -> back = new_node;
		}
		
		q -> tam++;
	}
	else
		printf("\nOps! Parece que algo deu errado!\n");
}

Node* dequeue(Queue *q)
{
	Node *remove = NULL;
	
	if(q -> front)
	{
		remove = q -> front;
		q -> front = q -> front -> next;
		q -> tam--;
	}
	
	return remove;
}

void printQueue(Queue *q)
{
	Node *aux = q -> front;
	
	printf("\n------ Queue / Itens: %02i ------\n", q -> tam);
	
	while(aux)
	{
		printf("%i ", aux -> value);
		aux = aux -> next;
	}
	
	printf("\n---------- Queue End ----------\n\n");
}
