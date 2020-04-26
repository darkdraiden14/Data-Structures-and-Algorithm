#include<iostream>
#include<vector>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int main(){
    vector<int> v{15,25,20,50,10,35,55,45,40,30};

    cout<<"Before Sorting :";
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }

    for(int i =0;i<v.size();i++){
        int minIndex = i;
        for(int j=i+1;j<v.size();j++){
            if(v[minIndex]>v[j]){
                minIndex=j;
            }
        }
        swap(&v[i],&v[minIndex]);
    }

    cout<<"\nAfter Sorting : ";
    cout<<"\nAscending Order : ";
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }

    for(int i =0;i<v.size();i++){
        int maxIndex = i;
        for(int j=i+1;j<v.size();j++){
            if(v[maxIndex]<v[j]){
                maxIndex=j;
            }
        }
        swap(&v[i],&v[maxIndex]);
    }


    cout<<"\nDescending Order : ";
    for(auto i=v.begin();i!=v.end();i++){
        cout<<*i<<" ";
    }

    cout<<endl;
}