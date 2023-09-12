#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


class Graph{
    private:
        unordered_map<int, vector<int>>adjacencyList;


    public:
        Graph(){}


    void addEdge(int u, int v){
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);

    }


    void printGraph(){
        for(const auto&pair: adjacencyList){
            int vertex=pair.first;
            const vector<int> &neighbours=pair.second;


            cout<< "Vertex: "<< vertex<< " is connected to: ";
            for(int neighbour: neighbours){
                cout<< neighbour<< " ";
            }

            cout<< endl;
        }
    }

};

int main(){

    Graph myGraph;

    myGraph.addEdge(1,2);
    myGraph.addEdge(1,4);
    myGraph.addEdge(1,3);
    myGraph.addEdge(3,2);
    myGraph.addEdge(3,4);

    myGraph.printGraph();



    return 0;


}