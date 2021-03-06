#include<iostream>
#include<list>
#include<queue>
using namespace std;

//Class representing directed graph using adjacency list representation
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i]=false;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int p = q.front();
        cout << p << " ";
        q.pop();
        for(auto x:adj[p]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}
