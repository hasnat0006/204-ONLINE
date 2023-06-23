#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> edge;

class Graph
{
    vector<pair<int, edge>> G, T;
    map<string, string> parent;
    int cost = 0, c = 0;

public:
    Graph(int n)
    {
    }
    void add_edges(string u, string v, int wt)
    {
        G.push_back({wt, {u, v}});
    }
    void set_parent(string u, string v)
    {
        parent[u] = u;
        parent[v] = v;
    }
    string find_set(string n)
    {
        if (n == parent[n])
            return n;
        else
            return find_set(parent[n]);
    }
    void union_set(string u, string v)
    {
        parent[u] = parent[v];
    }
    void kruskal()
    {
        sort(G.begin(), G.end());
        for (auto it : G)
        {
            string uRep = find_set(it.second.first);
            string vRep = find_set(it.second.second);
            if (uRep != vRep)
            {
                cost += it.first;
                T.push_back(it);
                union_set(uRep, vRep);
            }
            else
                c++;
        }
    }
    int get_cycle() { return c; }
    int get_cost() { return cost; }
    void print()
    {
        for (auto it : T)
            std::cout << it.second.first << " " << it.second.second << " -> " << it.first << endl;
    }
};

int main()
{
    Graph g(15);
    int e;
    std::cout << "Number of edges: ", cin >> e;
    while (e--)
    {
        string u, v;
        int wt;
        cin >> u >> v >> wt;
        g.set_parent(u, v);
        g.add_edges(u, v, wt);
    }
    g.kruskal();
    std::cout << endl;
    std::cout << "Number of cycle is: " << g.get_cycle() << endl;
    std::cout << "Total cost is: " << g.get_cost() << endl;
    g.print();
}
/*
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
