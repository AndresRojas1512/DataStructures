#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Checks if all the elements in a given tree all lesser than argument value
bool IsSubtreeLesser(Node *root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->data <= value) && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsSubtreeGreater(Node *root, int value)
{
    if (root == NULL)
    {
        return true;
    }
    if ((root->data > value) && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node *root)
{
    if (root = NULL)
    {
        return true;
    }
    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// We can get rid of IsSubtreeGreater and IsSubtreeLesser using the Math Intervals ind this function
bool IsBstUtil(Node *root, int minValue, int maxValue)
{
    if (root = NULL)
    {
        return true;
    }
    if (root->data > minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsBST(Node *root)
{
    return IsBstUtil(root, INT8_MAX, INT8_MIN);
}