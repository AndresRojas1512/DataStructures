// *
#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *next;
};

void Insert(struct BstNode **head ,int data);
void Print(struct BstNode *head);
// void Delete(int pos);

int main(void)
{
    // int n;
    struct BstNode *head;
    head = NULL;
    Insert(&head, 2);
    // Insert(&head, 4);
    // Insert(&head, 6);
    // Insert(&head, 5);
    Print(head);
    // printf("Enter N to delete: ");
    // scanf("%d", &n);
    // Delete(n);
    // Print(&head);
    return 0;
}

void Insert(struct BstNode **head, int data)
{
    struct BstNode *temp = (struct BstNode *)malloc(sizeof(struct BstNode));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL) // Insertando en la primera posicion
    {
        *head = temp;
    }
    printf("ld\n", (long int)(*head));
    // else
    // {
    //     while (*head != NULL)
    //     {
    //         *head = (*head)->next; // recorremos hasta hasta el ultimo elemento 
    //     }
    //     (*head) = temp;
    // }
}

void Print(struct BstNode *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void Delete(struct BstNode **head, int pos)
{
    struct BstNode *temp1 = (*head);
    if (pos == 1)
    {
        (*head) = temp1->next;
        free(temp1);
    }
    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct BstNode *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
    }
}
