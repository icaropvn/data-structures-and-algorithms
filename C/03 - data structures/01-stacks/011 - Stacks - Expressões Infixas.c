/*
Exercício 05 - Stacks

	Implemente um programa em C que avalie expressões matemáticas
na forma infixa (convencional) usando pilhas. As expressões podem
conter operadores binários (+, -, *, /), parênteses e operandos inteiros.

	Seu programa deve ser capaz de lidar com expressões como "3 + 4 * (5 - 2)",
onde a precedência dos operadores deve ser respeitada. O programa deve
avaliar corretamente a expressão e imprimir o resultado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct node_type1 {
	float value;
	struct node_type1 *next;
} NodeType1;

typedef struct {
	NodeType1 *top;
} NumsStack;

typedef struct node_type2 {
	char math_operator;
	struct node_type2 *next;
} NodeType2;

typedef struct {
	NodeType2 *top;
} OperatorsStack;

// general function which initializes the stacks
void createStacks(NumsStack *num_stack, OperatorsStack *op_stack);

// operands stack functions
void pushNum(NumsStack *num_stack, float num);
NodeType1* popNum(NumsStack *num_stack);

// operators stack functions
void pushOperator(OperatorsStack *op_stack, char op);
NodeType2* popOperator(OperatorsStack *op_stack);

// main function that solves the expression and returns the final result
float solveExpression(NumsStack *num_stack, OperatorsStack *op_stack, char expression[]);

void organizeStacks(NumsStack *num_stack, OperatorsStack *op_stack, int parenthesis_flag);

void switchElements(NumsStack *num_stack, OperatorsStack *op_stack);

void parenthesisOperations(NumsStack *num_stack, OperatorsStack *op_stack);

void doOperation(NumsStack *num_stack, OperatorsStack *op_stack);

// debug
void printStack(NumsStack *num_stack, OperatorsStack *op_stack);

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	NumsStack num_stack;
	OperatorsStack op_stack;
	char expression[100];
	float result;
	
	createStacks(&num_stack, &op_stack);
	
	printf("Insira a expressão infixa a ser resolvida: ");
	scanf("%[^\n]s", expression);
	
	result = solveExpression(&num_stack, &op_stack, expression);
	
	printf("\nO resultado da expressão é: %.2f", result);
	
	return 0;
}

void createStacks(NumsStack *num_stack, OperatorsStack *op_stack)
{
	num_stack -> top = NULL;
	op_stack -> top = NULL;
}

void pushNum(NumsStack *num_stack, float num)
{
	NodeType1 *new_num_node = malloc(sizeof(NodeType1));
	
	if(new_num_node)
	{
		new_num_node -> value = num;
		new_num_node -> next = num_stack -> top;
		num_stack -> top = new_num_node;
	}
	else
		printf("\nOps! Parece que algo deu errado.\n");
}

NodeType1* popNum(NumsStack *num_stack)
{
	NodeType1 *remove_num = NULL;
	
	if(num_stack -> top)
	{
		remove_num = num_stack -> top;
		num_stack -> top = num_stack -> top -> next;
	}
	
	return remove_num;
}

void pushOperator(OperatorsStack *op_stack, char op)
{
	NodeType2 *new_op_node = malloc(sizeof(NodeType2));
	
	if(new_op_node)
	{
		new_op_node -> math_operator = op;
		new_op_node -> next = op_stack -> top;
		op_stack -> top = new_op_node;
	}
	else
		printf("\nOps! Parece que algo deu errado.\n");
}

NodeType2* popOperator(OperatorsStack *op_stack)
{
	NodeType2 *remove_operator = NULL;
	
	if(op_stack -> top)
	{
		remove_operator = op_stack -> top;
		op_stack -> top = op_stack -> top -> next;
	}
	
	return remove_operator;
}

float solveExpression(NumsStack *num_stack, OperatorsStack *op_stack, char expression[])
{
	NodeType1 *result_node;
	char *aux_pointer;
	int parenthesis_flag = 0;
	float converted_num, result;
	
	aux_pointer = strtok(expression, " ");
	
	while(aux_pointer)
	{
		if(*aux_pointer == '+' || *aux_pointer == '-' || *aux_pointer == '*' || *aux_pointer == '/' || *aux_pointer == '(' || *aux_pointer == ')')
		{
			pushOperator(op_stack, *aux_pointer);
			
			if(*aux_pointer == '(')
				parenthesis_flag = 1;
			else if(*aux_pointer == ')')
				parenthesis_flag = 0;
		}
		else
		{
			converted_num = strtof(aux_pointer, NULL);
			pushNum(num_stack, converted_num);
		}
		
		organizeStacks(num_stack, op_stack, parenthesis_flag);
		
		aux_pointer = strtok(NULL, " ");
		
		printStack(num_stack, op_stack);
	}
	
	while(op_stack -> top)
		doOperation(num_stack, op_stack);
	
	printStack(num_stack, op_stack);
	
	result_node = popNum(num_stack);
	result = result_node -> value;
	free(result_node);
	
	return result;
}

void organizeStacks(NumsStack *num_stack, OperatorsStack *op_stack, int parenthesis_flag)
{	
	if(op_stack -> top && op_stack -> top -> next)
	{
		switch(op_stack -> top -> math_operator)
		{
			case '*':
				if(parenthesis_flag == 0 && op_stack -> top -> next -> math_operator != '/' && op_stack -> top -> next -> math_operator != '*' && op_stack -> top -> next -> math_operator != '(')
				{
					switchElements(num_stack, op_stack);
					printStack(num_stack, op_stack);
				}
				doOperation(num_stack, op_stack);
				break;
			case '/':
				if(parenthesis_flag == 0 && op_stack -> top -> next -> math_operator != '*' && op_stack -> top -> next -> math_operator != '/' && op_stack -> top -> next -> math_operator != '(')
				{
					switchElements(num_stack, op_stack);
					printStack(num_stack, op_stack);
				}
				doOperation(num_stack, op_stack);
				break;
			case ')':
				parenthesisOperations(num_stack, op_stack);
				break;
			case '(':
				break;
			default:
				doOperation(num_stack, op_stack);
				break;
		}
	}
}

void switchElements(NumsStack *num_stack, OperatorsStack *op_stack)
{
	float aux_value;
	char aux_op;
	
	aux_op = op_stack -> top -> math_operator;
	op_stack -> top -> math_operator = op_stack -> top -> next -> math_operator;
	op_stack -> top -> next -> math_operator = aux_op;
	
	/*
	aux_value = num_stack -> top -> value;
	num_stack -> top -> value = num_stack -> top -> next -> value;
	num_stack -> top -> next -> value = aux_value;
	*/
}

void parenthesisOperations(NumsStack *num_stack, OperatorsStack *op_stack)
{
	NodeType2 *removed_node;
	
	removed_node = popOperator(op_stack);
	free(removed_node);
	
	while(op_stack -> top -> math_operator != '(')
		doOperation(num_stack, op_stack);
	
	removed_node = popOperator(op_stack);
	free(removed_node);
}

void doOperation(NumsStack *num_stack, OperatorsStack *op_stack)
{
	NodeType1 *num_node1, *num_node2;
	NodeType2 *removed_node;
	
	num_node1 = popNum(num_stack);
	num_node2 = popNum(num_stack);
	
	removed_node = popOperator(op_stack);
	
	switch(removed_node -> math_operator)
	{
		case '+':
			pushNum(num_stack, num_node2 -> value + num_node1 -> value);
			break;
		case '-':
			pushNum(num_stack, num_node2 -> value - num_node1 -> value);
			break;
		case '*':
			pushNum(num_stack, num_node2 -> value * num_node1 -> value);
			break;
		case '/':
			pushNum(num_stack, num_node2 -> value / num_node1 -> value);
			break;
		default:
			break;
	}
	
	free(removed_node);
	
	printStack(num_stack, op_stack);
}


void printStack(NumsStack *num_stack, OperatorsStack *op_stack)
{
	NodeType1 *aux1 = num_stack -> top;
	NodeType2 *aux2 = op_stack -> top;
	
	printf("\n");
	
	while(aux1)
	{
		printf("%.0f\n", aux1 -> value);
		aux1 = aux1 -> next;
	}
	
	printf("\n");
	
	while(aux2)
	{
		printf("%c\n", aux2 -> math_operator);
		aux2 = aux2 -> next;
	}
	
	printf("\n");
}

