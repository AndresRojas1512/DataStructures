#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

// Inorder will print the elements in a sorted way. 

void Inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%c ", root->data);
    Inorder(root->right);
}