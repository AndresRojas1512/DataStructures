#include <iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *FindMin(Node *root) // is needed to finish the function
{
    return root;
    // finds min in the right subtree
}

Node *Delete(Node *root, int data)
{
    if (root = NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else // Case where we find the data to delete
    {
        // Case 1: No child
        if (root->left == NULL && root->right)
        {
            delete root;
            root = NULL;
        } // Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        } // Case 3: We search for minVal in right subtree or maxVal in left subtree
        else
        {
            Node *temp = FindMin(root->right); // Temp va a apuntar al Nodo con minVal en el right subtree
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root; 
}


int main(void)
{
    return 0;
}
