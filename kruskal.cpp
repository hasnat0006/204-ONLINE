#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;

class Graph
{
    vector<pair<int, edge>> G, T;
    vector<int> parent;
    int cost = 0;

public:
    Graph(int n)
    {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
    }
    void add_edges(int u, int v, int wt)
    {
        G.push_back({wt, {u, v}});
    }
    int find_set(int n)
    {
        if (n == parent[n])
            return n;
        else
            return find_set(parent[n]);
    }
    void union_set(int u, int v)
    {
        parent[u] = parent[v];
    }
    void kruskal()
    {
        sort(G.begin(), G.end());
        for (auto it : G)
        {
            int uRep = find_set(it.second.first);
            int vRep = find_set(it.second.second);
            if (uRep != vRep)
            {
                cost += it.first;
                T.push_back(it);
                union_set(uRep, vRep);
            }
        }
    }
    int get_cost() { return cost; }
    void print()
    {
        for (auto it : T)
            cout << it.second.first << " " << it.second.second << " -> " << it.first << endl;
    }
};

int main()
{
    Graph g(15);
    int e;
    cout << "Number of edges: ", cin >> e;
    while (e--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g.add_edges(u, v, wt);
    }
    g.kruskal();
    cout << "Total cost is: " << g.get_cost() << endl;
    g.print();
}
