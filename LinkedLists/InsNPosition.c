#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *next;
};

void Print(struct BstNode *head);
void Insert(struct BstNode **head, int data, int pos);

int main(void)
{
    struct BstNode *head = NULL;
    Insert(&head, 2, 1);
    Insert(&head, 3, 2);
    Insert(&head, 4, 1);
    Insert(&head, 5, 2);
    Print(head);
}

void Print(struct BstNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void Insert(struct BstNode **head, int data, int pos)
{
    struct BstNode *temp1 = (struct BstNode *)malloc(sizeof(struct BstNode));
    temp1->data = data;
    temp1->next = NULL;
    if (pos == 1)
    {
        temp1->next = *head;
        *head = temp1;
    }
    else
    {
        struct BstNode *temp2 = head; // recorremos la lista hasta n - 1;
        for (int i = 0; i < pos - 2; i++)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
    }
}