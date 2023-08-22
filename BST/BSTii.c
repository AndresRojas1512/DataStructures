#include <stdio.h>
#include <stdlib.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

// ****************Iterative solution****************

int FindMin(struct BstNode *root) // returns the minimum of the tree
{
    if (root == NULL) // empty tree
    {
        return -100; 
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int FindMax(struct BstNode *root) // return the maximum of the tree
{
    if (root == NULL) // empty tree
    {
        return -100;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// ****************Recursive solution****************
int RecFindMin(struct BstNode *root)
{
    if (root == NULL) // empty tree
    {
        return -100;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return RecFindMin(root->left);
}

int RecFindMax(struct BstNode *root)
{
    if (root == NULL)
    {
        return -100;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return RecFindMax(root->right);
}

int main(void)
{
    return 0;
}