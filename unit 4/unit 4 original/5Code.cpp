#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void display(Node* root)
{
    if (root == NULL)
        return;

    cout << "Node Data: " << root->data;

    if (root->left != NULL)
        cout << ", Left Child: " << root->left->data;
    else
        cout << ", Left Child: NULL";

    if (root->right != NULL)
        cout << ", Right Child: " << root->right->data;
    else
        cout << ", Right Child: NULL";

    cout << endl;

    display(root->left);
    display(root->right);
}

int main()
{
    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Binary Tree Representation" << endl;
    cout << "--------------------------" << endl;

    display(root);

    return 0;
}