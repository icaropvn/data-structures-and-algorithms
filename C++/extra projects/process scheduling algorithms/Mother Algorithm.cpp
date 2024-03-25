#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
//#include "algoritmos_escalonamento.h"
using namespace std;

struct Processo {
	int id;
	int tempo_execucao;
};

void FirstComeFirstServed(Processo processos[], int max);
void ShortestJobFirst(Processo processos[], int max);
int escolhaDoAlgoritmo();
int escolhaProcessos();
void gerarProcessos(Processo *processos, int tipoProcessos, int quantidadeProcessos);
void executarAlgoritmo(int algoritmo, int quantidadeProcessos, Processo *processos);

int main()
{	
	srand(time(NULL));
	
	int quantidadeProcessos, tipoProcessos = 0;
	int algoritmo = escolhaDoAlgoritmo();
	
	if(algoritmo != 4)
	{
		tipoProcessos = escolhaProcessos();
		
		cout << "\nInsira a quantidade de processos a serem executados: ";
		cin >> quantidadeProcessos;
		cout << endl;
		
		Processo processos[quantidadeProcessos];
		
		gerarProcessos(processos, tipoProcessos, quantidadeProcessos);
		
		executarAlgoritmo(algoritmo, quantidadeProcessos, processos);
	}
	
	return 0;
}

void FirstComeFirstServed(Processo processos[], int max)
{
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0;
	
	// loop que simula a execu��o dos processos em geral
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		cout << "Executando processo " << processos[contador].id << "..." << endl;
		
		// loop interno que simula a execu��o de cada processo individualmente
		for(int i = processos[contador].tempo_execucao; i > 0; i--)
		{
			processos[contador].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		// condi��o usada quando um processo � terminado
		if(processos[contador].tempo_execucao == 0)
			cout << "Processo " << processos[contador].id << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		contador++;
	}
	
	cout << "Tempo de execução total: " << tempo_total << " unidades de tempo." << endl;
}

void ShortestJobFirst(Processo processos[], int max)
{
	Processo temp;
	int i, j;
	
	int tempo_total = 0, tempo_por_processo = 0;
	int contador = 0;
	
	// implementa��o do algoritmo insertion sort para ordenar os processos
	for(i=1; i<max; i++)
	{
		temp = processos[i];
		
		for(j=i-1; j>=0 && processos[j].tempo_execucao > temp.tempo_execucao; j--)
		{
			processos[j+1].id = processos[j].id;
			processos[j+1].tempo_execucao = processos[j].tempo_execucao;
		}
		
		processos[j+1].id = temp.id;
		processos[j+1].tempo_execucao = temp.tempo_execucao;
	}
	
	// loop que simula a execu��o dos processos em geral
	while(contador < max)
	{
		tempo_por_processo = 0;
		
		cout << "Executando processo " << processos[contador].id << "..." << endl;
		
		// loop interno que simula a execu��o de cada processo individualmente
		for(int i = processos[contador].tempo_execucao; i > 0; i--)
		{
			processos[contador].tempo_execucao--;
			tempo_por_processo++;
			tempo_total++;
		}
		
		// condi��o usada quando um processo � terminado
		if(processos[contador].tempo_execucao == 0)
			cout << "Processo " << processos[contador].id << " executado por " << tempo_por_processo << " unidades de tempo\n" << endl;
		
		contador++;
	}
	
	cout << "Tempo de execucao total: " << tempo_total << " unidades de tempo." << endl;
}

int escolhaDoAlgoritmo()
{
	int resposta;
	
	while(resposta > 4 || resposta < 1)
	{
		cout << "Escolha um algoritmo para testar:" << endl;
		cout << "[1] First Come, First Served\n[2] Shortest Job First\n[3] Round-Robin\n[4] Sair" << endl;
		cout << "R: ";
		cin >> resposta;
	}
	
	return resposta;
}

int escolhaProcessos()
{
	int tipoProcessos = 0;
	
	while(tipoProcessos < 1 || tipoProcessos > 3)
	{
		cout << "\nQual teste deseja fazer?" << endl;
		cout << "[1] Processos Curtos\n[2] Processos Medios\n[3] Processos Longos\nR: ";
		cin >> tipoProcessos;
	}
	
	return tipoProcessos;
}

void gerarProcessos(Processo *processos, int tipoProcessos, int quantidadeProcessos)
{
	int min_rand, max_rand, counter = 1;
	
	switch(tipoProcessos)
	{
		case 1: {
			min_rand = 1;
			max_rand = 20;
			break;
		}
		case 2: {
			min_rand = 40;
			max_rand = 70;
			break;
		}
		case 3: {
			min_rand = 80;
			max_rand = 120;
			break;
		}
	}
	
	for(int i=0; i<quantidadeProcessos; i++)
	{
		processos[i].id = counter;
		processos[i].tempo_execucao = min_rand + (rand() % (max_rand - min_rand + 1));
		
		counter++;
	}
}

void executarAlgoritmo(int algoritmo, int quantidadeProcessos, Processo *processos)
{
	auto inicio = chrono::high_resolution_clock::now();
	
	switch(algoritmo)
	{
		case 1:
			FirstComeFirstServed(processos, quantidadeProcessos);
			break;
		case 2:
			ShortestJobFirst(processos, quantidadeProcessos);
			break;
		case 3:
			cout << "\nO algoritmo RR esta atualmente indisponivel :(" << endl;
			break;
	}
	
	auto fim = chrono::high_resolution_clock::now();
	auto duracao = chrono::duration_cast<std::chrono::microseconds>(fim - inicio);
	
	cout << "\nTempo de duracao real do algoritmo: " << duracao.count() << " microssegundos\n" << endl;
}
