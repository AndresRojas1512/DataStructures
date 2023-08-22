#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1; // empty stack

void Push(int x)
{
    if (top == MAX_SIZE - 1)
    {
        return; // error
    }
    A[++top] = x;
}

void Pop()
{
    if (top == -1)
    {
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

void Print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(void)
{
    Push(2);
    Push(5);
    Push(10);
    Pop();
    Push(12);
    Print();
    return 0;
}