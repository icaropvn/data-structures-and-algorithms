#include <stdio.h>
#include <stdlib.h>

// utilizando 15 dados, temos 2 * 15 = 30, primo mais próximo: 31
#define MAX 15
#define SIZE 31

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char street[50], block[50], city[50], country[50];
    int num, zip;
} Adress;

typedef struct {
    int code;
    Date dateSignature;
    char position[50];
    float income;
} Contract;

typedef struct {
    int id;
    char name[50];
    Date birthDate;
    Adress personAdress;
    Contract personContract;
} Person;

void printDate(Date date);
void printAdress(Adress adress);
void printContract(Contract contract);
void printPerson(Person person);
Date getDate();
Adress getAdress();
Contract getContract();
Person getPerson();

void initTable(Person table[]);
int hashFunction(int key);
int isFull(Person table[]);
void insert(Person table[], Person data);
Person* search(Person table[], int element);
void printTable(Person table[]);

int main()
{
    Person table[SIZE];
    Person personToInsert, *personFound;
    int option, id;

    initTable(table);

    while(1)
    {
        printf("\nChoose an option:\n[1] - Insert\n[2] - Search Value\n[3] - Print Table\n[4] - Exit\nR: ");
        scanf("%i", &option);
        getchar(); // limpa o buffer do teclado

        switch(option)
        {
            case 1:
                personToInsert = getPerson();

                insert(table, personToInsert);

                if(isFull(table) == 0)
                    printf("Person added to the Table at index %i by the Hash Function!\n", hashFunction(personToInsert.id));

                break;
            case 2:
                printf("\nInsert the person ID to search: ");
                scanf("%i", &id);

                personFound = search(table, id);

                if(personFound)
                {
                    printf("\nThe person was found at index %02i!\n", hashFunction(personFound->id));
                    printf("Here's the information about the data searched:\n");
                    printPerson(*personFound);
                }
                else
                    printf("\nPerson doesn't exist in the Table.\n");

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

// structs prints functions

void printDate(Date date)
{
    printf("%02i/%02i/%4i\n", date.day, date.month, date.year);
}

void printAdress(Adress adress)
{
    printf("\nAdress ===\n");
    printf("  Street: %s", adress.street);
    printf("  Block: %s", adress.block);
    printf("  City: %s", adress.city);
    printf("  Country: %s", adress.city);
    printf("  Number: %i\n", adress.num);
    printf("  ZIP: %i\n", adress.zip);
}

void printContract(Contract contract)
{
    printf("\nContract %i ===\n", contract.code);
    printf("  Position: %s", contract.position);
    printf("  Income: R$%.2f\n", contract.income);
    printf("  Date of admission: ");
    printDate(contract.dateSignature);
}

void printPerson(Person person)
{
    printf("\nPerson ID: %i\n", person.id);
    printf("\nPersonal Information ===\n");
    printf("  Name: %s", person.name);
    printf("  Birth Date: ");
    printDate(person.birthDate);
    printAdress(person.personAdress);
    printContract(person.personContract);
}

// structs reading functions

Date getDate()
{
    Date date;

    printf("\nInsert the day: ");
    scanf("%i", &date.day);

    printf("\nInsert the month: ");
    scanf("%i", &date.month);

    printf("\nInsert the year: ");
    scanf("%i", &date.year);

    getchar();

    return date;
}

Adress getAdress()
{
    Adress adress;

    printf("\nInsert the street: ");
    fgets(adress.street, 49, stdin);

    printf("\nInsert the block: ");
    fgets(adress.block, 49, stdin);

    printf("\nInsert the city: ");
    fgets(adress.city, 49, stdin);

    printf("\nInsert the country: ");
    fgets(adress.country, 49, stdin);

    printf("\nInsert the number: ");
    scanf("%i", &adress.num);

    printf("\nInsert the ZIP: ");
    scanf("%i", &adress.zip);

    getchar();

    return adress;
}

Contract getContract()
{
    Contract contract;

    printf("\nInsert the contract code: ");
    scanf("%i", &contract.code);

    printf("\nInsert the signature date: ");
    contract.dateSignature = getDate();

    printf("\nInsert the position: ");
    fgets(contract.position, 49, stdin);

    printf("\nInsert the income: ");
    scanf("%f", &contract.income);

    getchar();

    return contract;
}

Person getPerson()
{
    Person person;

    printf("\nInsert the person's ID: ");
    scanf("%i", &person.id);

    getchar();

    printf("\nInsert the name: ");
    fgets(person.name, 49, stdin);

    printf("\nInsert the birth date: ");
    person.birthDate = getDate();

    person.personAdress = getAdress();

    person.personContract = getContract();

    return person;
}

// Hash Table functions

void initTable(Person table[])
{
    // for que define todos os valores da tabela como -1
    for(int i=0; i<SIZE; i++)
    {
        table[i].id = -1;
    }
}

int hashFunction(int key)
{
    return key % SIZE;
}

int isFull(Person table[])
{
    int counter = 0;

    for(int i=0; i<SIZE; i++)
    {
        if(table[i].id != -1)
            counter++;
    }

    if(counter == MAX)
        return 1;
    else
        return 0;
}

void insert(Person table[], Person data)
{
    if(isFull(table) != 1)
    {
        int arrayPosition = hashFunction(data.id);

        while(table[arrayPosition].id != -1)
        {
            arrayPosition = hashFunction(arrayPosition + 1);
        }

        table[arrayPosition] = data;
    }
    else
        printf("\nThe Hash Table is full. You can't add more values.\n");
}

Person* search(Person table[], int id)
{
    int arrayPosition = hashFunction(id);

    while(table[arrayPosition].id != -1)
    {
        if(table[arrayPosition].id == id)
            return &table[arrayPosition];
        else
            arrayPosition = hashFunction(arrayPosition + 1);
    }

    return NULL;
}

void printTable(Person table[])
{
    printf("\n");

    for(int i=0; i<SIZE; i++)
    {
        if(table[i].id == -1)
            printf(" [Index %02i] ---\n", i);
        else
        {
            printf(" [Index %02i]\n", i);
            printPerson(table[i]);
        }    
        
        printf("\n------------------------------\n");
    }
}