#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *next;
    struct BstNode *prev;
};

struct BstNode *head; // pointer to head node;

struct BstNode *GetNewNode(int x)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    struct BstNode *newNode = GetNewNode(x);
    if (head == NULL) // empty list
    {
        head = newNode; // apunta al nodo, que es el unico.
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void Print()
{
    struct BstNode* temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void ReversePrint()
{
    struct BstNode *temp = head;
    if (temp = NULL)
    {
        return; // empty list 
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Reverse: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(void)
{
    head = NULL;
    InsertAtHead(2); 
    Print();
    ReversePrint();
    InsertAtHead(4); 
    Print();
    ReversePrint();
    InsertAtHead(6); 
    Print();
    ReversePrint();
    return 0;
}