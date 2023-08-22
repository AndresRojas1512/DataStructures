#include <stdio.h>
#include <stdlib.h>

void Reverse(struct BstNode *p);

struct BstNode
{
    int data;
    struct BstNode *link;
};

struct BstNode *head;

int main(void)
{
    Reverse(head);
    return 0;
}

void Reverse(struct BstNode *p)
{
    if (p->link == NULL)
    {
        head = p;
        return;
    }
    Reverse(p->link);
    struct BstNode *q = p->link;
    q->link = p;
    p->link = NULL;
}