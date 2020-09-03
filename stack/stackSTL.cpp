#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> s;
    int n;
    cout<<"Enter size : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);
    }
    cout<<"Stack element : ";
    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }
    return 0;
}