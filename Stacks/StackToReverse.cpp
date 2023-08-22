#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stack>

using namespace std;

// class Stack
// {
//     private:
//         char A[101];
//         int top;
//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool IsEmpty();
// };

// 1) Reverse a string

void Reverse(char *C, int n)
{
    stack<char> S;
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}
int main(void)
{
    int top;
    char C[51] = "Hello";
    Reverse(C, strlen(C));
    printf("%s\n", C);
}

