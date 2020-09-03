#include<bits/stdc++.h>
using namespace std;

void nextGreatElement(int a[],int freq[], int n){
    stack<int> s;
    s.push(0);
    int res[n]={0};
    for(int i=1;i<n;i++){
        if(freq[a[s.top()]]>freq[a[i]]){
            s.push(i);
        }
        else{
            while(freq[a[s.top()]]<freq[a[i]] && !s.empty()){
                res[s.top()]=a[i];
                s.pop();
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        res[s.top()]=-1;
        s.pop();
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }

}

int main(){
    int n;
    cout<<"No. of Elements : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int max = INT16_MAX;
    for(int i=0;i<n;i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    int freq[max+1]={0};

    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }

    nextGreatElement(a,freq,n);
    return 0;
}