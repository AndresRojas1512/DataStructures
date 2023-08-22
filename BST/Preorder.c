#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

void Preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}