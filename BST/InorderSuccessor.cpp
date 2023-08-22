#include <iostream>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *FindMin(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
// Return the address of the successor node
struct Node *GetSuccessor(struct Node *root, int data)
{
    // Search the NOde - O(h)
    struct Node *current = Find(root, data);
    if (current == NULL)
    {
        return NULL;
    }
    // Case 1: Node has right subtree
    if (current->right != NULL)
    {
        return FindMin(current->right);
    }
    // Case 2: No right subtree
    else
    {
        struct Node *successor = NULL;
        struct Node *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
