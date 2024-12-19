#include <stdio.h>
#include <stdlib.h>

// utilizando 15 dados, temos 2 * 15 = 30, primo mais próximo: 31
#define MAX 15
#define SIZE 31

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node* beginning;
    int size;
} List;

void initList(List *list);
void insertList(List *list, int value);
int searchList(List *list, int key);

void initTable(List table[]);
int hashFunction(int key);
int isFull(List table[]);
void insert(List table[], int data);
int search(List table[], int element);
void printTable(List table[]);

int main()
{
    List table[SIZE];
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

void initList(List *list)
{
    list->beginning = NULL;
    list->size = 0;
}

void insertList(List *list, int value)
{
    Node *new_node = malloc(sizeof(Node));

    if(new_node)
    {
        new_node->value = value;
        new_node->next = list->beginning;
        list->beginning = new_node;

        list->size++;
    }
    else
        printf("\nError allocating memory for the new node.\n");
}

int searchList(List *list, int key)
{
    Node *temp = list->beginning;

    while(temp && temp->value != key)
    {
        temp = temp->next;
    }
    
    if(temp)
        return 1;
    
    return -1;
}

void printList(List *list)
{
    Node *temp = list->beginning;

    printf("| List size: %02i |", list->size);

    while(temp)
    {
        printf(" %03i ->", temp->value);

        temp = temp->next;
    }

    printf(" NULL");
}

void initTable(List table[])
{
    for(int i=0; i<SIZE; i++)
    {
        initList(&table[i]);
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

int isFull(List table[])
{
    int counter = 0;

    for(int i=0; i<SIZE; i++)
    {
        counter += table[i].size;
    }

    if(counter == MAX)
        return 1;
    else
        return 0;
}

void insert(List table[], int data)
{
    if(isFull(table) != 1)
    {
        int id = hashFunction(data);
        insertList(&table[id], data);
        printf("Value added to the Table at index %i by the Hash Function!\n", id);
    }
    else
        printf("The Hash Table is full. You can't add more values.\n");
}

int search(List table[], int key)
{
    int id = hashFunction(key);

    if(searchList(&table[id], key) == 1)
        return id;
    else
        return -1;
}

void printTable(List table[])
{
    printf("\n");

    for(int i=0; i<SIZE; i++)
    {
        printf(" [Index %02i] ", i);
        printList(&table[i]);

        printf("\n");
    }
}