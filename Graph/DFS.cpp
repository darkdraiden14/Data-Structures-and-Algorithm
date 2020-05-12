#include<iostream>
#include<list>

using namespace std;

class Graph{
    int V; //No.of Vertices

    list<int> *adj;     //Adjacency List's pointer

    public:

    Graph(int V);

    void addEdge(int v,int w);

    void DFS(int s);
};

Graph::Graph(int V){
    this->V=V;

    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::DFS(int s){
    //create visited array of type boolean
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    //stack for the BFS
    list<int> stack;

    //starting with starting vertex
    visited[s]=true;
    stack.push_back(s);
    
    //Now we will need an iterator "point" which will be used to get all adjacent 
    //vertices of vertex.
    list<int>::iterator point;

    while(!stack.empty()){
        //pop a vertex from stack and print
        //also mark it visited
        s = stack.back();
        cout<<s<<" ";
        stack.pop_back();

        //Now push all the adjacent vertex in stack and repeat the process
        for(point = adj[s].begin();point!=adj[s].end();point++){
            if(!visited[*point]){
                visited[*point]=true;
                stack.push_back(*point);
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
    int sv;
    cout<<"\n Enter the starting vertex : ";
    cin>>sv;
    cout<<"If starting Vertex is "<<sv<<", then BFS is : ";
    g.DFS(sv);
    return 0;
}