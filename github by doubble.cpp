#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string movie;
    Node*prev;
    Node* next;
    
};

// Add movie
void addMovie(Node*& head, string name)
{
    Node* newNode = new Node;
    newNode->movie = name;
    newNode->next = NULL;
    

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newNode->prev=temp;
        temp->next = newNode;
        
    }

    cout << "Movie added successfully.\n";
}

// Remove movie
void removeMovie(Node*& head, string name)
{
    if (head == NULL)
    {
        cout << "Watchlist is empty.\n";
        return;
    }

    if (head->movie == name)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Movie removed successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->movie != name)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Movie not found.\n";
    }
    else
    {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Movie removed successfully.\n";
    }
}

// Display movies
void displayMovies(Node* head)
{
    if (head == NULL)
    {
        cout << "Watchlist is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nMovie Watchlist:\n";

    while (temp != NULL)
    {
        cout << temp->movie << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    Node* head = NULL;
    int choice;
    string name;

    do
    {
        cout << "\n--- Movie Watchlist Manager ---\n";
        cout << "1. Add Movie\n";
        cout << "2. Remove Movie\n";
        cout << "3. Display Movies\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter movie name: ";
                cin.ignore();
                getline(cin, name);
                addMovie(head, name);
                break;

            case 2:
                cout << "Enter movie name to remove: ";
                cin.ignore();
                getline(cin, name);
                removeMovie(head, name);
                break;

            case 3:
                displayMovies(head);
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
