#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<int>* adj;

    public:
    Graph(int V){
        this->V=V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    void printGraph(){
        for(int i=0;i<V;i++){
            cout<<"\nFor "<<i;
            for(auto x:adj[i]){
                cout<<"->"<<x;
            }
        }
    }
    
    void countPath(){
        int s, t;
        cout<<endl<<"Enter the starting and ending vertex : ";
        cin>>s>>t;
        int pathCount=0;
        countPathsUtil(s,t,pathCount);
        cout<<"\nThere are total : "<<pathCount<<" paths"; 
    }
    
    void countPathsUtil(int u,int d, int& pathCount){
        if(u==d){
            pathCount++;
        }
        else{
            list<int>::iterator i;
            for(i=adj[u].begin();i!=adj[u].end();++i){
                countPathsUtil(*i,d,pathCount);
            }
        }
    }
};

int main(){
    int N;
    cout<<"Enter the no. of Vertices : ";
    cin>>N;
    Graph g(N);
    int E;
    cout<<"Enter no. of Edges : ";
    cin>>E;
    cout<<"Enter the Edges (U-V) : ";
    for(int i=0;i<E;i++){
        int u, v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    cout<<"Graph's Adjacency list : ";
    g.printGraph();

    cout<<endl<<"Now, we have to count all the possible path between 2 vertices: ";
    g.countPath();
    return 0;
}