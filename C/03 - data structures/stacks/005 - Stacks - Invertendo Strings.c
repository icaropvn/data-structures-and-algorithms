/*
Exercício 02 - Stacks

- Inverta uma string utilizando uma stack, mas preservando
a ordem das palavras da frase original.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct node{
	char term;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, char term);
Node* pop(Stack *s);
void invertString(Stack *s, char word[]);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Stack s;
	char word[50];
	
	createStack(&s);
	
	printf("Insira uma palavra para ser invertida: ");
	scanf("%49[^\n]s", word);
	
	invertString(&s, word);
	
	return 0;
}

void createStack(Stack *s)
{
	s -> top = NULL;
}

void push(Stack *s, char term)
{
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node)
	{
		new_node -> term = term;
		new_node -> next = s -> top;
		s -> top = new_node;
	}
	else
		printf("\nLamentamos! Parece que houve um erro.\n");
}

Node* pop(Stack *s)
{
	Node *remove = NULL;
	
	if(s -> top)
	{
		remove = s -> top;
		s -> top = s -> top -> next;
	}
	
	return remove;
}

void invertString(Stack *s, char word[])
{
	Node *remove;
	char inverted_string[strlen(word) + 1];
	int i = 0, j = 0;
	
	while(word[i] != '\0')
	{
		if(word[i] != ' ')
			push(s, word[i]);
		else
		{
			while(s -> top)
			{
				remove = pop(s);

				inverted_string[j] = remove -> term;
				free(remove);
				j++;
			}
			
			inverted_string[j] = ' ';
			j++;
		}
		
		i++;
	}
	
	while(s -> top)
	{
		remove = pop(s);

		inverted_string[j] = remove -> term;
		free(remove);
		j++;
	}
	
	inverted_string[j] = '\0';
	printf("\nFrase/palavra invertida: %s\n", inverted_string);
}
