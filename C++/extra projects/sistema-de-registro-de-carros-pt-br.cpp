/*
 ==== Grupo do trabalho ====
 - Ícaro C. Pavan - 840790
 - Jeferson T. Querino - 769349
 - Samuel C. K. Lima - 769214
 - Samuel S. Figueiredo - 840785
 - Vítor Pinheiro - 840751
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_CARS = 100;

struct Node {
	string name, brand, model;
	Node* next;
};

struct Queue {
	Node *front, *rear;
	int size;
};

void initQueue(Queue *q);
void enqueue(Queue *q, string name, string brand, string model);
Node* dequeue(Queue *q);
void printQueue(Queue *q);

int main()
{
	Queue q;
	Node *removed_node = NULL;
	int answer;
	string name, brand, model;
	string delete_confirm;
	
	initQueue(&q);
	
	while(1)
	{
		cout << "Escolha uma opcao:" << endl;
		cout << "[1] Cadastrar Novo Carro\n[2] Deletar Carro\n[3] Listar Fila\n[4] Sair\nR: ";
		cin >> answer;
		
		switch(answer)
		{
			case 1:
			{
				if(q.size < MAX_CARS)
				{
					cout << "\nInsira o nome: ";
					cin >> name;
					cout << "Insira a marca: ";
					cin >> brand;
					cout << "Insira o modelo: ";
					cin >> model;
					
					enqueue(&q, name, brand, model);
					cout << "\nCarro adicionado com sucesso!\n" << endl;
				}
				else
					cout << "\nErro ao cadastrar. A fila esta cheia, delete um carro para adicionar um novo.\n" << endl;
				
				break;
			}
			case 2:
			{
				if(q.front)
				{
					while(1)
					{
						cout << "\nO seguinte registro sera removido: " << endl;
						cout << "Nome: " << q.front->name << endl;
						cout << "Marca: " << q.front->brand << endl;
						cout << "Modelo: " << q.front->model << endl;
	
						cout << "\nTem certeza? [s/n]\nR: ";
						cin >> delete_confirm;
						
						if(delete_confirm == "S" || delete_confirm == "s")
						{
							removed_node = dequeue(&q);
							delete removed_node;
							
							cout << "\nRegistro deletado com sucesso!\nAinda ha " << q.size << " carro(s) restante(s) na fila.\n" << endl;
							break;
						}
						else if(delete_confirm == "N" || delete_confirm == "n")
						{
							cout << "\nCerto! A operacao foi cancelada. Nenhuma mudanca foi feita na fila.\n" << endl;
							break;
						}	
						else
							cout << "\nOpcao invalida. Escolha 's' ou 'n'." << endl;
					}
				}
				else
					cout << "\nNao ha cadastros na fila para remover.\n" << endl;
				
				break;
			}
			case 3:
			{
				if(q.size > 0)
					printQueue(&q);
				else
					cout << "\nNao ha cadastros na fila para listar.\n" << endl;
				break;
			}
			case 4:
			{
				cout << "\nAte mais!\n" << endl;
				break;
			}
			default:
			{
				cout << "\nInsira uma opção valida.\n" << endl;
				break;
			}
		}
		
		if(answer == 4)
			break; 
	}
	
	return 0;
}

void initQueue(Queue *q)
{
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void enqueue(Queue *q, string name, string brand, string model)
{
	Node *new_node = new Node;
	
	if(new_node)
	{
		new_node->name = name;
		new_node->brand = brand;
		new_node->model = model;
		new_node->next = NULL;
		
		if(q->size == 0)
			q->front = new_node;
		else
			q->rear->next = new_node;
			
		q->rear = new_node;
		q->size++;
	}
	else
		cout << "\nOps! Parece que algo deu errado ao alocar o novo cadastro.\n" << endl;
}

Node* dequeue(Queue *q)
{
	Node *remove = NULL;
	
	if(q->size > 0)
	{
		remove = q->front;
		q->front = q->front->next;
		q->size--;
	}
	
	return remove;
}

void printQueue(Queue *q)
{
	Node *aux = q->front;
	int counter = 1;
	
	cout << "\n=== Frente da fila | Total de cadastros: " << setw(2) << setfill('0') << q->size << " ===" << endl;
	
	while(aux)
	{
		cout << "\n               ----- Carro " << setw(2) << setfill('0') << counter << " -----" << endl;
		cout << "                   Nome: " << aux->name << endl;
		cout << "                   Marca: " << aux->brand << endl;
		cout << "                   Modelo: " << aux->model << endl;
		cout << "               --------------------\n" << endl;
		
		counter++;
		aux = aux->next;
	}
	
	cout << "================ Final da fila ================\n" << endl;
}
