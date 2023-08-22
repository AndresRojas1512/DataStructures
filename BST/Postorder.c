#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

void Postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%c ", root->data);
}