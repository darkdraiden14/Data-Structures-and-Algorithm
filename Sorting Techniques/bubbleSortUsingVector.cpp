#include<iostream>
#include<vector>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(){
    vector<int> v1{10,20,40,55,45,25,35};

    cout<<"Before Sorting :";
    for(auto i=v1.begin();i!=v1.end();i++){
        cout<<*i<<" ";
    }

    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v1.size()-1;j++){
            if(v1[j]>v1[j+1]){
                swap(&v1[j],&v1[j+1]);
            }
        }
    }

    cout<<"\nAfter Sorting : ";
    cout<<"\nAscending order : ";
    for(auto i=v1.begin();i!=v1.end();i++){
        cout<<*i<<" ";
    }

    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v1.size()-1;j++){
            if(v1[j]<v1[j+1]){
                swap(&v1[j],&v1[j+1]);
            }
        }
    }

    cout<<"\nDescending Order : ";
    for(auto i=v1.begin();i!=v1.end();i++){
        cout<<*i<<" ";
    }

    cout<<endl;
}