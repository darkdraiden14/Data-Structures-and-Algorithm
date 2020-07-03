#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

    void DFSUtil(int v,vector<bool> &visited);

    public:
        Graph(int V);
        int findMother();
        void addEdge(int u,int v);
};

Graph::Graph(int V){
    this->V=V;
    adj =new list<int>[V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::DFSUtil(int v,vector<bool> &visited){
    visited[v] = true;

    list<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            DFSUtil(*i,visited);
        }
    }
}

int Graph::findMother(){
    
    vector<bool> visited(V,false);
    int v=0;

    for(int i=0;i<V;i++){
        DFSUtil(i,visited);
        v=i;
    }

    fill(visited.begin(),visited.end(),false);
    DFSUtil(v,visited);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            return -1;
        }
    }
    return v; 
}

int main(){
    int V;
    cout<<"Enter the number of Vertex : ";
    cin>>V;
    Graph G(V);

    cout<<"Enter The Number of Edges : ";
    int E;
    cin>>E;

    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter end Vertices of Edge "<<i<<" : ";
        cin>>u>>v;
        G.addEdge(u,v);
    }

    cout<<"\n\n A aMother Vertex is : "<<G.findMother();

    return 0;
}