#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int>& B,int p){
    B[p]=1;
}

void printMatrix(vector<vector<int>> A,int V){
    cout<<"  ";
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<V;i++){
        cout<<i<<" ";
        for(int j=0;j<V;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V,E;

    //No. of Vertices
    cout<<"Enter Number of Vertices : ";
    cin>>V;
    cout<<"Enter Number of Edges : ";
    cin>>E;

    vector<vector<int> > A;
    A.reserve(V*V);

    for(int i = 0;i<V;i++){
        vector<int> temp;
        for(int j=0;j<V;j++){
            temp.push_back(0);
        }
        A.push_back(temp);
    }

    for(int i=0;i<E;i++){
        int u,v;
        cout<<"\nFor edge E"<<i<<" enter nodes : ";
        cin>>u>>v;
        addEdge(A[u],v);
        addEdge(A[v],u);
    }

    cout<<"\nTherefore, The Adjacency Matrix is : \n";
    printMatrix(A,V);
}