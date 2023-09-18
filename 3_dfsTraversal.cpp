#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

class Graph
{
public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void dfs(int start);
   

    private : int vertices;
    list<int> *adj;
    void dfsUtil(int v, unordered_set<int> &visited);
};

Graph ::Graph(int vertices)
{
    this->vertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::dfs(int start)
{
    unordered_set<int> visited;
    dfsUtil(start, visited);
}

void Graph::dfsUtil(int v, unordered_set<int> &visited)
{
    visited.insert(v);
    cout << v << " ";

    for (const auto &neighbour : adj[v])
    {
        if (visited.find(neighbour) == visited.end())
        {
            dfsUtil(neighbour, visited);
        }
    }
}

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS traversal starting from vertex 0:" << endl;
    g.dfs(0);

    return 0;
}
