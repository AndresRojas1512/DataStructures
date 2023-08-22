#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *link;
};

void Print(struct BstNode *head);
void Insert(struct BstNode **head, int data);
void ReversePrint(struct BstNode *head);

int main(void)
{
    struct BstNode *head = NULL;
    Insert(&head, 2);
    Insert(&head, 6);
    Insert(&head, 5);
    Insert(&head, 4);
    Print(head);
    return 0;
}

void Print(struct BstNode *head)
{
    if (head != NULL)
    {
        printf("%d", head->data);
        Print(head->link);
    }
}

void ReversePrint(struct BstNode *head)
{
    if (head != NULL)
    {
        Print(head->link);
        printf("%d", head->data);
    }
}

void Insert(struct BstNode **head, int data)
{
    struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
    temp->data = data;
    temp->link = NULL;
    if ((*head) == NULL)
    {
        temp->link = NULL;
        (*head) = temp;
    }
    else
    {
        struct BstNode *temp1 = (*head);
        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
            temp1->link = temp;
        }
    }
}