// Teste de uso do 'push' e 'pop' em stacks

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

Pessoa lerPessoa();
void imprimirPessoa(Pessoa p);
No* push(No *topo);
No* pop(No **topo);
void imprimirStack(No *topo);

int main()
{
	No *topo = NULL; // ponteiro para nó do topo da pilha
	No *remove;
	int answer;
	
	while(1)
	{
		printf("\n0 - Sair\n1 - Push (empilhar)\n2 - Pop (desempilhar)\n3 - Imprimir\n");
		scanf("%i", &answer);
		getchar();
		
		switch(answer)
		{
			case 1:
				topo = push(topo);
				break;
			case 2:
				remove = pop(&topo);
				
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
				imprimirStack(topo);
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

No* push(No *topo)
{
	No *novo = malloc(sizeof(No));
	
	if(novo)
	{
		novo -> p = lerPessoa();
		novo -> proximo = topo;
		return novo;
	}
	else
		printf("\nErro ao alocar memoria.\n");
	
	return NULL;
}

No* pop(No **topo)
{
	if(*topo)
	{
		No *remove = *topo;
		*topo = remove -> proximo;
		return remove;
	}
	else
		printf("\nPilha vazia\n");
	
	return NULL;
}

void imprimirStack(No *topo)
{
	int there_is_element = 0;
	
	printf("\n-------- STACK --------\n");
	
	while(1)
	{
		if(topo)
		{
			there_is_element = 1;
			imprimirPessoa(topo -> p);
			topo = topo -> proximo;	
		}
		else
		{
			if(!there_is_element)
				printf("\n Sua pilha nao possui nenhum elemento!\n");
			break;
		}
	}
	
	printf("\n----- FIM DA STACK -----\n");
}
