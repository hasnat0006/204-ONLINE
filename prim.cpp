#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<string, string>> pairUV;

// vector<pair<int, int>> adj[10005];
map<string, bool> visited;
map<string, vector<pair<string, int>>> adj;
int main()
{
    int e;
    std::cout << "Number of edges: ", std::cin >> e;
    while (e--)
    {
        string u, v;
        int wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int sum = 0, c = 0;
    vector<pairUV> ans;
    priority_queue<pairUV, vector<pairUV>, greater<pairUV>> pq;
    pq.push({0, {"Hasnat", "nai"}});
    while (!pq.empty())
    {
        pairUV k = pq.top();
        pq.pop();
        string u = k.second.first;
        string v = k.second.second;
        int wt = k.first;
        if (visited[u])
            continue;
        else
            c++;
        sum += wt;
        visited[u] = 1;
        if (v != "nai")
            ans.push_back({wt, {u, v}});
        for (auto it : adj[u])
        {
            string adjNode = it.first;
            int adjwt = it.second;
            if (!visited[adjNode])
                pq.push({adjwt, {adjNode, u}});
        }
    }
    std::cout << endl;
    std::cout << "Number of cycle is: " << c << endl;
    std::cout << "COST: " << sum << endl;
    for (auto it : ans)
        std::cout << it.second.first << " " << it.second.second << " -> " << it.first << endl;
}

/*
9
1 4 1
1 2 2
2 3 3
2 4 3
6 3 8
3 4 5
3 2 3
5 4 9
5 1 4

9
Hasnat Raisul 4
Hasnat Zaima 1
Zaima Raisul 9
Hasnat Nabiha 2
Nabiha Ifrit 3
Nabiha Zaima 3
Nabiha Pallob 7
Zaima Ifrit 5
Ifrit Pallob 8


*/