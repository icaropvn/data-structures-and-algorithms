#include <stdio.h>
#include <stdlib.h>

// utilizando 15 dados, temos 2 * 15 = 30, primo mais próximo: 31
#define MAX 15
#define SIZE 31

void initTable(int table[]);
int hashFunction(int key);
int isFull(int table[]);
void insert(int table[], int data);
int search(int table[], int element);
void printTable(int table[]);

int main()
{
    int table[SIZE];
    int option, value, found;

    initTable(table);

    while(1)
    {
        printf("\nChoose an option:\n[1] - Insert\n[2] - Search Value\n[3] - Print Table\n[4] - Exit\nR: ");
        scanf("%i", &option);

        switch(option)
        {
            case 1:
                printf("\nInsert the value to add: ");
                scanf("%i", &value);

                insert(table, value);

                if(isFull(table) == 0)
                    printf("Value added to the Table at index %i by the Hash Function!\n", hashFunction(value));

                break;
            case 2:
                printf("\nInsert the value to search: ");
                scanf("%i", &value);

                found = search(table, value);

                if(found != -1)
                    printf("\nValue found at index %02i!\n", found);
                else
                    printf("\nValue not found in the Table.\n");

                break;
            case 3:
                printTable(table);
                break;
            case 4:
                printf("\nSee you!");
                break;
            default:
                printf("\nInsert a valid option.\n");
                break;
        }

        if(option == 4)
            break;
    }

    return 0;
}

void initTable(int *table)
{
    // for que define todos os valores da tabela como -1
    for(int i=0; i<SIZE; i++)
    {
        table[i] = -1;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

int isFull(int table[])
{
    int counter = 0;

    for(int i=0; i<SIZE; i++)
    {
        if(table[i] != -1)
            counter++;
    }

    if(counter == MAX)
        return 1;
    else
        return 0;
}

void insert(int table[], int data)
{
    if(isFull(table) != 1)
    {
        int id = hashFunction(data);

        while(table[id] != -1)
        {
            id = hashFunction(id + 1);
        }

        table[id] = data;
    }
    else
        printf("\nThe Hash Table is full. You can't add more values.\n");
}

int search(int table[], int element)
{
    int id = hashFunction(element);

    while(table[id] != -1)
    {
        if(table[id] == element)
            return id;
        else
            id = hashFunction(id + 1);
    }

    return -1;
}

void printTable(int table[])
{
    printf("\n");

    for(int i=0; i<SIZE; i++)
    {
        if(table[i] == -1)
            printf(" [Index %02i] ---\n", i);
        else
            printf(" [Index %02i] %03i\n", i, table[i]);
    }
}