#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *link;
};

void Reverse(struct BstNode **head);

int main(void)
{
    struct BstNode *head;
    return 0;
}

void Reverse(struct BstNode **head)
{
    struct BstNode *current, *prev, *next;
    current = (*head);
    prev = NULL;
    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}