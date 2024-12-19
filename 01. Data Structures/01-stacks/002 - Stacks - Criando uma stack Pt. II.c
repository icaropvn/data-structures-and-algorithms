/*
002 - Stacks: criando uma Stack Pt. II

Esta é uma segunda forma de criar uma stack.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dia, mes, ano;
} Data;

typedef struct {
	char nome[50];
	Data data;
} Pessoa;

typedef struct no {
	Pessoa p;
	struct no *proximo;	
} No;

typedef struct {
	No *topo;
	int tam;
} Stack;

void createStack(Stack *s);
Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);
void push(Stack *s);
No* pop(Stack *s);
void imprimirStack(Stack *s);

int main()
{
	Stack s;
	No *remove;
	int answer;
	
	createStack(&s);
	
	while(1)
	{
		printf("\n0 - Sair\n1 - Push (empilhar)\n2 - Pop (desempilhar)\n3 - Imprimir\n");
		scanf("%i", &answer);
		getchar();
		
		switch(answer)
		{
			case 1:
				push(&s);
				break;
			case 2:
				remove = pop(&s);
				
				if(remove)
				{
					printf("\nElemento removido com sucesso!\n");
					imprimirPessoa(remove -> p);
					free(remove);
				}
				else
					printf("\nSem no a remover.\n");
				break;
			case 3:
				imprimirStack(&s);
				break;
			default:
				if(answer != 0)
					printf("\nOpcao invalida.\n");
		}
		
		if(answer == 0)
			break;
	}

	return 0;
}

void createStack(Stack *s)
{
	s -> topo = NULL;
	s -> tam = 0;
}

Pessoa lerPessoa()
{
	Pessoa p;
	
	printf("\nDigite o nome e data de nascimento (dd/mm/aaaa): ");
	scanf("%49[^\n]%i%i%i", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
	
	return p;
}

void imprimirPessoa(Pessoa p)
{
	printf("\nNome: %s\nData: %02i/%02i/%4i\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void push(Stack *s)
{
	No *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo -> p = lerPessoa();
		novo -> proximo = s -> topo;
		s -> topo = novo;
		s -> tam++;
	}
	else
		printf("\nErro ao alocar memoria.\n");
}

No* pop(Stack *s)
{
	if(s -> topo)
	{
		No *remove = s -> topo;
		s -> topo = s -> topo -> proximo;
		s -> tam--;
		return remove;
	}
	else
		printf("\nPilha vazia\n");
	
	return NULL;
}

void imprimirStack(Stack *s)
{
	No *aux = s -> topo; // é utilizado um ponteiro auxiliar para o topo
						 // para que não seja preciso a utilização da struct original durante a
						 // impressão, evitando que a pilha seja desordenada
	int there_is_element = 0;
	
	printf("\n------ STACK - Tam: %02i -------\n", s -> tam);
	
	while(aux)
	{
		if(aux)
		{
			there_is_element = 1;
			imprimirPessoa(aux -> p);
			aux = aux -> proximo;	
		}
		else
		{
			if(!there_is_element)
				printf("\n Sua pilha nao possui nenhum elemento!\n");
			break;
		}
	}
	
	printf("\n-------- FIM DA STACK --------\n");
}
