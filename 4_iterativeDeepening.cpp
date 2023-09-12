#include<iostream>
#include<list>
#include<stack>
#include<unordered_set>

using namespace std;


class Graph{
    public:
        Graph(int vertices);
        void addEdge(int v, int w);
        bool iddfs(int start, int goal, int maxDepth);

    private:
        int vertices;
        list<int> *adj;
        bool dfs(int start, int goal, int depth, unordered_set<int> &visited);
};

Graph:: Graph(int vertices){
    this->vertices=vertices;
    adj=new list<int>[vertices];
}

void Graph:: addEdge(int v, int w){
    adj[v].push_back(w);
}


bool Graph::iddfs(int start, int goal, int maxDepth){
    for(int depth=0; depth<=maxDepth; ++depth){
        unordered_set<int> visited;
        if(dfs(start, goal, depth, visited)){
            return true;
        }
    }

    return false;
}


bool Graph:: dfs(int start, int goal, int depth, unordered_set<int>&visited){
    if(start==goal){
        return true;
    }

    if(depth<=0){
        return false;
    }

    visited.insert(start);

    for(const auto& neighbour: adj[start]){
        if(visited.find(neighbour)==visited.end()&& dfs(neighbour,goal,depth-1, visited)){
            return true;
        }
    }

    return false;
}


int main(){
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(4,6);


    int start=0;
    int goal=6;
    int maxDepth=3;

    if(g.iddfs(start, goal, maxDepth)){
        cout<< "Goal node "<< goal << " found within depth "<< maxDepth<< endl;
        
    }

    else{
        cout<< "Goal node "<< goal << " not found within depth "<< maxDepth<< endl;
    }


    return 0;
}