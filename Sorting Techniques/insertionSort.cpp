#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v{15,25,20,50,10,35,55,45,40,30};

    cout<<"Before Sorting :";
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }

    for(int i =1;i<v.size();i++){
        int key = v[i];
        int j = i-1;
        while(j>=0 && key<v[j]){
            v[j+1]=v[j];
            j=j-1;
        }
        v[j+1] = key;

        cout<<"\nAfter Step "<<i<<" : ";
        for(auto i=v.begin();i!=v.end();i++){
            cout<<*i<<" ";
        }
    }

    cout<<"\nAfter Sorting : ";
    cout<<"\nAscending Order : ";
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }


    cout<<"\nDescending Order : ";
    for(auto i=v.rbegin();i!=v.rend();i++){
        cout<<*i<<" ";
    }

    cout<<endl;
}