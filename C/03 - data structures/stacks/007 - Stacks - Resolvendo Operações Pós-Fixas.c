/*
Exercício 04 - Stacks

	Resolver uma operação dada através da notação pós-fixa
(notação polonesa reversa) usando pilhas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

typedef struct node {
	float value;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} Stack;

void createStack(Stack *s);
void push(Stack *s, float num);
Node* pop(Stack *s);
float calculateExpression(Stack *s, char expression[]);
float switchOperator(float num1, float num2, char operator);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	Stack s;
	char expression[100], string_aux[100];
	float result;
	
	createStack(&s);
	
	printf("Insira a expressão pós-fixa: ");
	scanf("%[^\n]s", expression);
	
	strcpy(string_aux, expression);
	result = calculateExpression(&s, string_aux);
	
	printf("\nExpressão Dada: %s\nResultado: %.2f\n", expression, result);
	
	return 0;
}

void createStack(Stack *s)
{
	s -> top = NULL;
}

void push(Stack *s, float num)
{
	Node *new_node = malloc(sizeof(Node));
	
	if(new_node)
	{
		new_node -> value = num;
		new_node -> next = s -> top;
		s -> top = new_node;
	}
	else
		printf("\nOps! Parece que algo deu errado.\n");
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

float calculateExpression(Stack *s, char expression[])
{
	char *pointer;
	float temp_result, converted_num, value_result;
	Node *popped_num1, *popped_num2, *result;
	
	pointer = strtok(expression, " ");
	
	while(pointer)
	{
		if(*pointer == '+' || *pointer == '-' || *pointer == '*' || *pointer == '/' || *pointer == '^')
		{
			popped_num1 = pop(s);
			popped_num2 = pop(s);
			
			temp_result = switchOperator(popped_num1 -> value, popped_num2 -> value, *pointer);
			
			push(s, temp_result);
			
			free(popped_num1);
			free(popped_num2);
		}
		else
		{
			converted_num = strtol(pointer, NULL, 10);
			push(s, converted_num);
		}
		
		pointer = strtok(NULL, " ");
	}
	
	result = pop(s);
	value_result = result -> value;
	free(result);
	
	return value_result;
}

float switchOperator(float num1, float num2, char operator)
{
	switch(operator)
	{
		case '+':
			return num2 + num1;
		case '-':
			return num2 - num1;
		case '*':
			return num2 * num1;
		case '/':
			return num2 / num1;
		case '^':
			return pow(num2, num1);
		default:
			return 0.0;
	}
}
