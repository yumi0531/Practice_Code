#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int idx;
    int u;
    int v;
    int cost;
    bool operator<(const Edge &rhs) const
    {
        return cost < rhs.cost || (cost == rhs.cost && idx < rhs.idx);
    }
};
int n;
vector<int> node[50050];
vector<Edge> edge;
int union_find[50005];
int findroo(int x)
{
    if (x == union_find[x])
    {
        return x;
    }
    else
    {
        return union_find[x] = findroo(union_find[x]);
    }
}
void kruskal()
{
    int line = 0;
    int cost = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i].u;
        int b = edge[i].v;
        a = findroo(a);
        b = findroo(b);
        if (a == b)
        {
            continue;
        }
        union_find[a] = b;
        line++;
        cost += edge[i].cost;
        cout << line << ": <" << edge[i].u << "," << edge[i].v << ">\n";
        if (line == n - 1)
        {
            break;
        }
    }
    cout << "\nThe cost of minimum spanning tree: " << cost << endl;
}
int main()
{
    int u, v, cost;
    int counter = 0;
    while (cin >> u >> v >> cost)
    {
        edge.push_back(Edge{counter, u, v, cost});
        node[u].push_back(v);
        node[v].push_back(u);
        counter++;
    }
    cout << "Adjacency list:\n";
    for (int i = 0; node[i].size(); i++)
    {
        n = i + 1;
        cout << i << ": ";
        for (int x : node[i])
        {
            cout << x << " -> ";
        }
        cout << "end\n";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        union_find[i] = i;
    }
    cout << "minimum spanning tree:\n";
    sort(edge.begin(), edge.end());
    kruskal();
    return 0;
}