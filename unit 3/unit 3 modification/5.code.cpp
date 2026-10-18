
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string movie;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void addMovie()
{
    Node* newNode = new Node;

    cout << "Enter movie name: ";
    getline(cin >> ws, newNode->movie);

    newNode->prev = NULL;
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

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Movie added successfully!\n";
}

void removeMovie()
{
    if (head == NULL)
    {
        cout << "Watchlist is empty!\n";
        return;
    }

    string name;
    cout << "Enter movie name to remove: ";
    getline(cin >> ws, name);

    Node* temp = head;

    while (temp != NULL && temp->movie != name)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Movie not found!\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Movie removed successfully!\n";
}

void displayMovies()
{
    if (head == NULL)
    {
        cout << "Watchlist is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\nMovie Watchlist:\n";

    while (temp != NULL)
    {
        cout << temp->movie << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n--- Movie Watchlist Manager (DLL) ---\n";
        cout << "1. Add Movie\n";
        cout << "2. Remove Movie\n";
        cout << "3. Display Movies\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice)
        {
            case 1:
                addMovie();
                break;
            case 2:
                removeMovie();
                break;
            case 3:
                displayMovies();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
