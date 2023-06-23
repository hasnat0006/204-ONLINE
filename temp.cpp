#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;

class graph
{
    vector<pair<int, edge>> G, T;
    map<int, int> parent;
    int cost = 0;

public:
    graph() {}
    void set_parent(int u, int v)
    {
        parent[u] = u;
        parent[v] = v;
    }
    void add_edges(int u, int v, int wt)
    {
        set_parent(u, v);
        G.push_back({wt, {u, v}});
    }
    int find_rep(int n)
    {
        if (parent[n] == n)
            return n;
        return find_rep(parent[n]);
    }
    void uni(int u, int v)
    {
        parent[u] = parent[v];
        parent[v] = parent[u];
    }
    void kruskal()
    {
        sort(G.begin(), G.end());
        for (auto it : G)
        {
            int uRep = find_rep(it.second.first);
            int vRep = find_rep(it.second.second);
            if (uRep != vRep)
            {
                cost += it.first;
                T.push_back(it);
                uni(uRep, vRep);
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

    graph g;
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