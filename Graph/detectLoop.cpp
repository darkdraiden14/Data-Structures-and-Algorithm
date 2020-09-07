#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V){
        this->V=V;
        adj= new list<int>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    bool isCyclicUnit(int v, bool visited[],bool *recStack){
        if(visited[v]==false){
            visited[v]= true;
            recStack[v]=true;

            list<int>:: iterator i;
            for(i=adj[v].begin();i!=adj[v].end();i++){
                if(!visited[*i] && isCyclicUnit(*i,visited,recStack)){
                    return true;
                }
                else if(recStack[*i]){
                    return true;
                }
            }
        }
        recStack[v]=false;
        return false;
    }

    bool isCyclic(){
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
            recStack[i]=false;
        }

        for(int i=0;i<V;i++){
            if(isCyclicUnit(i,visited,recStack)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    int V,E;
    cout<<"Ente the no. of Vertex : ";
    cin>>V;
    Graph g(V);
    cout<<"Enter No. of Edges : ";
    cin>>E;
    cout<<"Enter Edges : ";
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    cout<<"Is The graph cyclic or not :";
    if(g.isCyclic()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}