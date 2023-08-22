#include <stdio.h>
#include <stdlib.h>

void Insert(int x);
void Print();

struct BstNode
{
    int data;
    struct BstNode *next;
};

struct BstNode *head;

int main(void)
{
    int n, x;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        printf("Enter the %d element: ", i);
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}

void Insert(int x)
{
    struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct BstNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}