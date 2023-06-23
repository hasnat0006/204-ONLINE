#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> adj;
map<int, int> visited;
map<int, int> level;
map<int, int> parent;

void dfs(int start)
{
    visited[start] = 1;
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            parent[child] = start;
            level[child] = level[start] + 1;
            dfs(child);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        visited[k] = 1;
        for (auto child : adj[k])
        {
            if (!visited[child])
            {
                q.push(child);
                parent[child] = k;
                level[child] = level[k] + 1;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Number of edges: ";
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    // bfs(0);

    // debug(level);
    // debug(parent);
    for (auto it : level)
        cout << it.first << " -> " << it.second << endl;
    for (auto it : parent)
        cout << it.first << " -> " << it.second << endl;

    return 0;
}

/*
8
0 1
0 4
0 6
2 4
1 2
4 5
5 6
3 2
*/