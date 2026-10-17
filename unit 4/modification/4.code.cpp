#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right, *parent;
};

Node* createNode(int value, Node* p = NULL)
{
    Node* n = new Node;
    n->data = value;
    n->left = n->right = NULL;
    n->parent = p;
    return n;
}

Node* findNode(Node* root, int value)
{
    if (root == NULL)
        return NULL;

    if (root->data == value)
        return root;

    Node* n = findNode(root->left, value);

    if (n != NULL)
        return n;

    return findNode(root->right, value);
}

void insertNode(Node* root)
{
    int parentValue, value, side;

    cout << "Enter parent node: ";
    cin >> parentValue;

    Node* p = findNode(root, parentValue);

    if (p == NULL)
    {
        cout << "Parent not found!\n";
        return;
    }

    cout << "Enter new node value: ";
    cin >> value;

    if (findNode(root, value) != NULL)
    {
        cout << "Node value already exists!\n";
        return;
    }

    cout << "1. Left Child\n2. Right Child\n";
    cout << "Enter position: ";
    cin >> side;

    if (side == 1)
    {
        if (p->left != NULL)
        {
            cout << "Left position is occupied!\n";
            return;
        }

        p->left = createNode(value, p);
    }
    else if (side == 2)
    {
        if (p->right != NULL)
        {
            cout << "Right position is occupied!\n";
            return;
        }

        p->right = createNode(value, p);
    }
    else
        cout << "Invalid position!\n";
}

void display(Node* root)
{
    if (root == NULL)
        return;

    cout << "\nNode: " << root->data;

    if (root->parent != NULL)
        cout << ", Parent: " << root->parent->data;
    else
        cout << ", Parent: NULL";

    if (root->left != NULL)
        cout << ", Left: " << root->left->data;
    else
        cout << ", Left: NULL";

    if (root->right != NULL)
        cout << ", Right: " << root->right->data;
    else
        cout << ", Right: NULL";

    if (root->left == NULL && root->right == NULL)
        cout << ", Leaf: Yes";
    else
        cout << ", Leaf: No";

    display(root->left);
    display(root->right);
}

void compareArray(Node* root)
{
    if (root == NULL)
        return;

    const int SIZE = 100;
    int arr[SIZE] = {0};

    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        Node* n = q.front().first;
        int i = q.front().second;
        q.pop();

        if (i >= SIZE)
        {
            cout << "Tree is too large for this array.\n";
            return;
        }

        arr[i] = n->data;

        if (n->left != NULL)
            q.push({n->left, 2 * i + 1});

        if (n->right != NULL)
            q.push({n->right, 2 * i + 2});
    }

    cout << "\nArray Representation:\n";

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] != 0)
            cout << "Index " << i << ": " << arr[i] << endl;
    }

    cout << "\nLinked Representation uses pointers.\n";
    cout << "Array Representation uses indexes.\n";
}

int main()
{
    Node* root = createNode(1);

    root->left = createNode(2, root);
    root->right = createNode(3, root);
    root->left->left = createNode(4, root->left);
    root->left->right = createNode(5, root->left);

    int choice;

    do
    {
        cout << "\n\n--- Binary Tree Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Display Tree\n";
        cout << "3. Compare Representations\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertNode(root);
                break;

            case 2:
                display(root);
                break;

            case 3:
                compareArray(root);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
