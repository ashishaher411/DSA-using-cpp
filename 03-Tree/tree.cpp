#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void display(Node* root) {
    if (root == NULL)
        return;

    cout << "Data: " << root->data;

    cout << ", Left Child: ";
    if (root->left != NULL)
        cout << root->left->data;
    else
        cout << "NULL";

    cout << ", Right Child: ";
    if (root->right != NULL)
        cout << root->right->data;
    else
        cout << "NULL";

    cout << endl;

    display(root->left);
    display(root->right);
}

int main() {
    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Binary Tree Representation:" << endl;
    display(root);

    return 0;
}