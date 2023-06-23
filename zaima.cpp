
#include <bits/stdc++.h>
using namespace std;
vector<string> nodes;
vector<int> value(100, INT_MAX);
vector<bool> setmst(100, false);
int parent[100];
int selectmin(vector<int> &value, vector<bool> &setmst, int v)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < v; ++i)
    {
        if (value[i] < minimum && setmst[i] == false)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}
int main()
{
    string a, b;
    int w, v, e;
    cout << "No of vertex: ";
    cin >> v;
    cout << "No of edges: ";
    cin >> e;
    int graph[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            graph[i][j] = 0;
    }
    while (e--)
    {
        cin >> a >> b >> w;
        if (find(nodes.begin(), nodes.end(), a) == nodes.end())
        {
            nodes.push_back(a);
        }
        if (find(nodes.begin(), nodes.end(), b) == nodes.end())
        {
            nodes.push_back(b);
        }
        int x = find(nodes.begin(), nodes.end(), a) - nodes.begin();
        int y = find(nodes.begin(), nodes.end(), b) - nodes.begin();
        graph[x][y] = w;
        graph[x][y] = w;
    }
    /*for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++) cout<<graph[i][j]<<" ";
        cout<<endl;
    }*/
    string st;
    cout << "Choose one vertex to start from: ";
    cin >> st;
    // for(int i=0;i<v;i++) parent[i]=-1;
    int start = find(nodes.begin(), nodes.end(), st) - nodes.begin();
    parent[start] = start;
    value[start] = 0;
    for (int i = 1; i < v - 1 + 1; i++)
    {
        int u = selectmin(value, setmst, v + 1);
        setmst[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] != 0 && setmst[j] == false && graph[u][j] < value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (i != start)
            cout << nodes[parent[i]] << "---" << nodes[i] << "   weight: " << graph[parent[i]][i] << endl;
    }
}