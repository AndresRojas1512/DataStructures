#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *link;
};

struct BstNode *top = NULL;

void Push(int x)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = x;
    newNode->link = top; // creamos el puente
    top = newNode;
}

void Pop()
{
    struct BstNode *temp;
    if (top == NULL)
    {
        return;
    }
    temp = top;
    top = top->link;
    free(temp);
}

int main(void)
{
    Push(2);
    return 0;
}