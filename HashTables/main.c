#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (person *)(0xFFFFFFFFFFFFFFFFUL)

// Open  addressing

typedef struct
{
    char name[MAX_NAME];
    int age; 
} person;

// Creates an id for each person
unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = hash_value * name[i] % TABLE_SIZE;
    }
    return hash_value;
}


void HashTableInit(person **hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

void PrintTable(person **hashTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("\t%d\t---\n", i);
        }
        else
        {
            printf("\t%d\t%s\t%d\n", i, hashTable[i]->name, hashTable[i]->age);
        }
    }
}

bool HashTableInsert(person **hashTable, person *bufferStruct)
{
    if (bufferStruct == NULL)
    {
        return false;
    }
    int index = hash(bufferStruct->name); // The hash function asigns an integer to a string
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hashTable[try] == NULL)
        {
            hashTable[try] = bufferStruct;
            return true;
        }
    }
    return false;
}

// Returns a pointer to the person in the table
person *HashTableLookUp(person **hashTable, char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if ((hashTable[try] != NULL) && strncmp(hashTable[try]->name, name, TABLE_SIZE) == 0)
        {
            return hashTable[try];
        }
    }
    return NULL;
}

person *HashTableDelete(person **hashTable, char *name)
{
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if ((hashTable[try] != NULL) && strncmp(hashTable[try]->name, name, TABLE_SIZE) == 0)
        {
            person *tmp = hashTable[try];
            hashTable[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main()
{
    // Inits
    person person01 = {.name = "Pepe", .age = 1};
    person person02 = {.name = "Juan", .age = 2};
    person person03 = {.name = "Jose", .age = 3};
    person person04 = {.name = "Angel", .age = 4};
    person person05 = {.name = "Jack", .age = 5};
    person person06 = {.name = "Iker", .age = 6};
    person person07 = {.name = "Kepa", .age = 7};
    person person08 = {.name = "Carlos", .age = 8};
    person person09 = {.name = "Robert", .age = 9};
    person person10 = {.name = "Mane", .age = 10};
    person *hashTable[TABLE_SIZE]; // array of pointers

    // Initialize
    HashTableInit(hashTable);
    // Filling the table
    HashTableInsert(hashTable, &person01);
    HashTableInsert(hashTable, &person02);
    HashTableInsert(hashTable, &person03);
    HashTableInsert(hashTable, &person04);
    HashTableInsert(hashTable, &person05);
    HashTableInsert(hashTable, &person06);
    HashTableInsert(hashTable, &person07);
    HashTableInsert(hashTable, &person08);
    HashTableInsert(hashTable, &person09);
    HashTableInsert(hashTable, &person10);

    // Printing the table
    PrintTable(hashTable);
    // LookUp
    // person *tmp = HashTableLookUp(hashTable, "Pepe");
    // if (tmp == NULL)
    //     printf("Not found\n");
    // else
    //     printf("Found\n");
    // Delete
    // person *delPerson = HashTableDelete(hashTable, "Pepe");
    // if (delPerson != NULL)
    // {
    //     printf("Successful deleted\n");
    // }
    // else
    // {
    //     printf("Deleting error\n");
    // }
    // Printing
    // PrintTable(hashTable);
    return 0;
}