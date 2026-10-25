
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
        cout << "Invalid number of users.\n";
        return 0;
    }

    vector<string> users;
    vector<vector<int>> adj;
    unordered_map<string, int> index;

    cout << "Enter user names:\n";

    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;

        if (index.count(name))
        {
            cout << "Duplicate user name.\n";
            return 0;
        }

        index[name] = users.size();
        users.push_back(name);
        adj.push_back({});
    }

    cout << "Enter number of friendship pairs: ";
    cin >> m;

    if (m < 0)
    {
        cout << "Invalid number of friendships.\n";
        return 0;
    }

    cout << "Enter friendship pairs:\n";

    for (int i = 0; i < m; i++)
    {
        string u, v;
        cin >> u >> v;

        if (!index.count(u) || !index.count(v) || u == v)
        {
            cout << "Invalid friendship pair.\n";
            continue;
        }

        adj[index[u]].push_back(index[v]);
        adj[index[v]].push_back(index[u]);
    }

    string newUser, friendName;

    cout << "Enter new user name: ";
    cin >> newUser;

    if (index.count(newUser))
    {
        cout << "User already exists.\n";
        return 0;
    }

    index[newUser] = users.size();
    users.push_back(newUser);
    adj.push_back({});

    cout << "Enter friend name: ";
    cin >> friendName;

    if (!index.count(friendName) || friendName == newUser)
    {
        cout << "Invalid friend name. New user added without friendship.\n";
    }
    else
    {
        int u = index[newUser];
        int v = index[friendName];

        adj[u].push_back(v);
        adj[v].push_back(u);

        cout << "User and friendship added successfully.\n";
    }

    cout << "\nUpdated Adjacency List:\n";

    for (int i = 0; i < (int)users.size(); i++)
    {
        cout << users[i] << " -> ";

        if (adj[i].empty())
            cout << "No friends";

        for (int j : adj[i])
            cout << users[j] << " ";

        cout << "\n";
    }

    return 0;
}
