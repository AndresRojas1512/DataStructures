#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

// Prints the data of the nodes
void LevelOrder(struct Node *root)
{
    if (root == NULL) // empty tree
    {
        return;
    }
    queue<Node*> Q; // Queue of type "pointer to Node"
    Q.push(root);
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}