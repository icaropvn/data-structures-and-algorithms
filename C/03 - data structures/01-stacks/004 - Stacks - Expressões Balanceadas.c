/*
Exercício 01 de treino de stacks

- Validar se uma expressão matemática está balanceada (contém a
mesma quantidade de parênteses, colchetes ou chaves que foram abertos,
se fechando) usando uma stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node {
	char term;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, char term);
Node* pop(Stack *s);
int validateExpression(char *expression, Stack *s);
int validateCharPair(char opening_char, char closing_char);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Stack s;
	char expression[100];
	int valid_exp;
	
	createStack(&s);
	
	printf("Insira a expressão matemática: ");
	scanf("%99[^\n]", expression);
	
	validateExpression(expression, &s);
	
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
		printf("\nLamentamos! Parece que houve um erro inesperado.\n");
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

int validateExpression(char expression[], Stack *s)
{
	int i = 0, valid_exp = 1;
	Node *remove;
	
	while(1)
	{
		if(expression[i] == '\0' || valid_exp == 0)
			break;
		
		if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
			push(s, expression[i]);
		else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
		{
			remove = pop(s);
			
			if(remove)
			{
				valid_exp = validateCharPair(remove -> term, expression[i]);
				free(remove);
			}
			else
				valid_exp = 0;
		}
		
		i++;
	}
	
	if(s -> top)
		valid_exp = 0;
	
	if(valid_exp == 1)
		printf("\nExpressão válida!\n");
	else
		printf("\nNão consigo resolver esta expressão. Revise os parênteses.\n");
}

int validateCharPair(char opening_char, char closing_char)
{
	switch(opening_char)
	{
		case '(':
			return closing_char == ')';
			break;
		case '[':
			return closing_char == ']';
			break;
		case '{':
			return closing_char == '}';
			break;
	}
}
