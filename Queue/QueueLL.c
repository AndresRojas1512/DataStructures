#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *next;
};

struct BstNode* front = NULL;
struct BstNode* rear = NULL;

void Enqueue(int x)
{
    struct BstNode *temp = (struct BstNode*)malloc(sizeof(struct BstNode));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    struct BstNode* temp = front;
    if (front == NULL)
    {
        return; // empty queue
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

int main(void)
{
    return 0;
}