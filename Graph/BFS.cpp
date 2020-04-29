#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V; //No.of Vertices

    list<int> *adj;     //Adjacency List's pointer

    public:

    Graph(int V);

    void addEdge(int v,int w);

    void BFS(int s);
};

Graph::Graph(int V){
    this->V=V;

    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    //create visited array of type boolean
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    //Queue for the BFS
    list<int> queue;

    //starting with starting vertex
    visited[s]=true;
    queue.push_back(s);
    
    //Now we will need an iterator "point" which will be used to get all adjacent 
    //vertices of vertex.
    list<int>::iterator point;

    while(!queue.empty()){
        //Dequeue a vertex from queue and print
        //also mark it visited
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        //Now Enqueue all the adjacent vertex in queue and repeat the process
        for(point = adj[s].begin();point!=adj[s].end();point++){
            if(!visited[*point]){
                visited[*point]=true;
                queue.push_back(*point);
            }
        }
    }
}

int main(){
    int V;
    cout<<"Enter the No. of Vertices : ";
    cin>>V;

    //Intializing Graph
    Graph g(V);

    int E;
    cout<<"Enter the No. of Edges : ";
    cin>>E;

    //Add edges to graph
    for(int i=0;i<E;i++){
        cout<<"Enter the Edge"<<i<<" : ";
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    //Print BFS

    cout<<"If starting Vertex is 2, then BFS is : ";
    g.BFS(2);
    return 0;
}