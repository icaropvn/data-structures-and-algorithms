#include <stdio.h>
#include <stdlib.h>

// definição de constantes
#define MAX 5 // maximo de elementos a serem inseridos
#define SIZE 7 // tamanho total da tabela

void initTable(int *table);
int hashFunction(int key);
void insertTable(int *table, int data);
int removeTable(int *table, int dataToRemove);
int searchTable(int *table, int data);
void printTable(int *table);

int main()
{
    int table[SIZE];
    int option;
    int value;

    initTable(table);

    while(1)
    {
        printf("Insert an option:\n");
        printf("[1] Insert Value\n");
        printf("[2] Remove Value\n");
        printf("[3] Search for Value\n");
        printf("[4] Print Table\n");
        printf("[5] Exit\n");
        scanf("%i", &option);

        switch(option)
        {
            case 1:
                printf("\nInsert the value: ");
                scanf("%i", &value);
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }

    return 0;
}

void initTable(int *table)
{
    for(int i=0; i<SIZE; i++)
        table[i] = -1;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insertTable(int *table, int data)
{
    int array_position = hashFunction(data);

    while(table[array_position] != -1)
    {
        array_position = hashFunction(array_position + 1);
    }

    table[array_position] = data;
}

int removeTable(int *table, int dataToRemove)
{
    int array_position = hashFunction(dataToRemove);

    while(table[array_position] != -1)
    {
        if(table[array_position] == dataToRemove)
        {
            table[array_position] = -1;
            return array_position;
        }
        else
            array_position = hashFunction(array_position + 1);
    }

    return -1;
}

int searchTable(int *table, int data)
{
    int array_position = hashFunction(data);

    while(table[array_position] != -1)
    {
        if(table[array_position] == data)
            return array_position;
        else
            array_position = hashFunction(array_position + 1);
    }

    return -1;
}

void printTable(int *table)
{
    for(int i=0; i<SIZE; i++)
    {
        if(table[i] == -1)
            printf("[Index %02i] ---", i);
        else
            printf("[Index %02i] %03i", i, table[i]);
    }
}