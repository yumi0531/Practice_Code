#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge //邊
{
    int u;
    int v;
    int cost; //權重
    bool operator<(const Edge &rhs) const
    {
        return cost < rhs.cost;
    }
};

int n;
vector<int> node[50000];
vector<Edge> edge;
int fa[50000];

int findroo(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    else
    {
        return fa[x] = findroo(fa[x]);
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
            continue;
        fa[a] = b;
        line++;
        cost += edge[i].cost;
        cout << line << ": <" << edge[i].u << "," << edge[i].v << ">\n";
        if (line == n - 1)
            break;
    }
    cout << "\nThe cost of minimum spanning tree: " << cost << endl;
}

int main()
{
    int u, v, cost;
    while (cin >> u >> v >> cost)
    {
        edge.push_back(Edge{u, v, cost});
        node[u].push_back(v);
        node[v].push_back(u);
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
        fa[i] = i;
    cout << "minimum spanning tree:\n";
    sort(edge.begin(), edge.end());
    kruskal();
    return 0;
}