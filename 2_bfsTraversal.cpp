#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> adj;

    public:
        Graph(int vertices): V(vertices){
            adj.resize(V);
        }


    void addEdge(int v, int w){
        adj[v].push_back(w);
    }


    void BFS(int source){

        vector<bool> visited (V,false);

        queue<int> q;

        q.push(source);

        while(!q.empty()){
            int currentVertex=q.front();
            cout<< currentVertex<< " ";

            q.pop();


            for(int neighbour: adj[currentVertex]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
    }
};

int main(){

    Graph g(6);


    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(1,4);

    cout<< "BFS traversal starting from vertex 0: ";
    g.BFS(0);


    return 0;


}