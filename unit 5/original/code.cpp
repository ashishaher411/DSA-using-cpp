
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of users: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of users.";
        return 0;
    }

    vector<vector<int>> adj(n);

    cout << "Enter number of friendship pairs: ";
    cin >> m;

    if (m < 0)
    {
        cout << "Invalid number of friendships.";
        return 0;
    }

    // Create an undirected graph
    for (int i = 0; i < m; i++)
    {
        int u, v;

        cout << "Enter friendship pair (u v): ";
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cout << "Invalid user IDs. Try again.\n";
            i--;
            continue;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display friends of every user
    cout << "\nFriend List:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "User " << i << ": ";

        if (adj[i].empty())
        {
            cout << "No friends";
        }
        else
        {
            for (int friendID : adj[i])
            {
                cout << "User " << friendID << " ";
            }
        }

        cout << endl;
    }

    // Check friends of a selected user
    int selected;
    cout << "\nEnter user ID to check friends: ";
    cin >> selected;

    if (selected < 0 || selected >= n)
    {
        cout << "Invalid user ID.";
    }
    else
    {
        cout << "Friends of User " << selected << ": ";

        if (adj[selected].empty())
        {
            cout << "No friends";
        }
        else
        {
            for (int friendID : adj[selected])
            {
                cout << "User " << friendID << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
