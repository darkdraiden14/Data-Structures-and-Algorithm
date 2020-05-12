#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> A[],int u, int v){
    A[u].push_back(v);
    A[v].push_back(u);
}

void printGraph(vector<int> A[],int V){
    for(int i=0;i<V;i++){
        cout<<"\nAdjacency List of Vertex V"<<i<<" : "<<i;
        for(auto x : A[i]){
            cout<<"-->"<<x;
        }
        cout<<endl;
    }
}

int main(){
    int V;

    cout<<"Enter the Number of Vertices : ";
    cin>>V;

    vector<int> A[5];
    int E;
    cout<<"Enter the number of Edges : ";
    cin>>E;

    for(int i=0;i<E;i++){
        int u,v;
        cout<<"Enter the Vertices for Edge E"<<i<<" : ";
        cin>>u>>v;
        addEdge(A,u,v);
    }

    printGraph(A,V);
}