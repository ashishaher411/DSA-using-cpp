
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of users: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Number of users must be positive.\n";
        return 0;
    }

    vector<string> users(n);
    unordered_map<string, int> userIndex;

    cout << "Enter user names:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> users[i];

        if (userIndex.count(users[i]))
        {
            cout << "Duplicate user name not allowed.\n";
            return 0;
        }

        userIndex[users[i]] = i;
    }

    vector<vector<int>> adj(n);

    cout << "Enter number of friendship pairs: ";
    cin >> m;

    if (m < 0)
    {
        cout << "Number of friendships cannot be negative.\n";
        return 0;
    }

    cout << "Enter friendship pairs:\n";

    for (int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;

        if (!userIndex.count(u) || !userIndex.count(v))
        {
            cout << "Invalid user in friendship pair.\n";
            continue;
        }

        int a = userIndex[u];
        int b = userIndex[v];

        if (a == b)
        {
            cout << "Self-friendship is not allowed.\n";
            continue;
        }

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "\nAdjacency List:\n";

    for (int i = 0; i < n; i++)
    {
        cout << users[i] << " -> ";

        if (adj[i].empty())
        {
            cout << "No friends";
        }
        else
        {
            for (int friendIndex : adj[i])
            {
                cout << users[friendIndex] << " ";
            }
        }

        cout << "\n";
    }

    string selectedUser;
    cout << "\nEnter user name to check friends: ";
    cin >> selectedUser;

    if (userIndex.count(selectedUser))
    {
        int index = userIndex[selectedUser];

        cout << "Friends of " << selectedUser << ": ";

        if (adj[index].empty())
        {
            cout << "No friends";
        }
        else
        {
            for (int friendIndex : adj[index])
            {
                cout << users[friendIndex] << " ";
            }
        }

        cout << "\n";
    }
    else
    {
        cout << "User not found.\n";
    }

    return 0;
}
