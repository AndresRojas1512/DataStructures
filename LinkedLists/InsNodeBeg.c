#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *next;
};

void Insert(struct BstNode **head, int x);
void Print(struct BstNode *head);

int main(void)
{
    int n, x;
    struct BstNode *head = NULL;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &x);
        Insert(&head, x);
        Print(head);
    }
    return 0;
}

void Insert(struct BstNode **head, int x)
{
    struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
    temp->data = x;
    temp->next = *head;
    *head = temp;
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
