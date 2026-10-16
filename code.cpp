
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string movie;
    Node* next;
};

Node* head = NULL;

// Add movie at the end
void addMovie() {
    Node* newNode = new Node;

    cout << "Enter movie name: ";
    getline(cin >> ws, newNode->movie);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Movie added successfully!\n";
}

// Remove movie by name
void removeMovie() {
    if (head == NULL) {
        cout << "Watchlist is empty!\n";
        return;
    }

    string name;
    cout << "Enter movie name to remove: ";
    getline(cin >> ws, name);

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->movie != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Movie not found!\n";
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Movie removed successfully!\n";
}

// Display all movies
void displayMovies() {
    if (head == NULL) {
        cout << "Watchlist is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\nYour Movie Watchlist:\n";

    while (temp != NULL) {
        cout << "- " << temp->movie << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Movie Watchlist Manager (SLL) ---\n";
        cout << "1. Add Movie\n";
        cout << "2. Remove Movie\n";
        cout << "3. Display Watchlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
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

    // Free allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
