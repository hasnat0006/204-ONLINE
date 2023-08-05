#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> mp;
vector<int, int> visited;

void dfs(int start)
{
    visited[start] = 1;
    for (auto child : mp[start])
        if (!visited[child])
            dfs(child);
    visited[start] = 2;
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int k = q.front();
        visited[k] = 1;
        q.pop();
        for (auto child : mp[k])
            if (!visited[child])
                q.push(child);
        visited[k] = 2;
    }
}

map<int,vector<int>> adj;
map<int,int>visited,parent,level,color;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto child : adj[k])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                visited[child] = 1;
                level[child] = level[k] + 1;
            }
        }
    }
}

int main()
{
}