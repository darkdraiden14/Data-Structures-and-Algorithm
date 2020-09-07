#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    vector<vector<int> > adj;

    public:
    Graph(int V){
        this->V=V;
        adj.resize(V);
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

    void printPath(vector<int>& path){
        int size = path.size();
        for(int i=0;i<size;i++){
            cout<<path[i]<< " ";
        }
        cout<<endl;
    }
    
    int isNotVisited(int x, vector<int>& path){
        int size=path.size();
        for(int i=0;i<size;i++){
            if(path[i]==x){
                return 0;
            }
        }
        return 1;
    }

    void findPath(){
        int src,dst;
        cout<<"Enter the Source and Destination : ";
        cin>>src>>dst;

        queue<vector<int> > q;
        vector<int>path ;
        path.push_back(src);
        q.push(path);
        while(!q.empty()){
            path = q.front();
            q.pop();
            int last = path[path.size()-1];
            if(last==dst){
                printPath(path);
            }
            for(int i=0;i<adj[last].size();i++){
                if(isNotVisited(adj[last][i],path)){
                    vector<int> newpath(path);
                    newpath.push_back(adj[last][i]);
                    q.push(newpath);
                }
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

    cout<<endl<<"Now, we have to find all the possible path between 2 vertices: ";
    g.findPath();
    return 0;
}