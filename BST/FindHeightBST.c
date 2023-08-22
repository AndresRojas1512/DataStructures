#include <stdio.h>
#include <stdlib.h>

// There is something not good with this algorithm

struct BstNode
{
    int val;
    struct BstNode *left;
    struct BstNode *right;
};

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
}

int FindHeight(struct Node *root)
{
    if (root = NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}
int main()
{
    return 0;
}