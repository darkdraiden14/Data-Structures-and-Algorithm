#include<iostream>
#include<vector>

using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(vector<int>& v1, int low, int high){
    int pivot = v1[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(v1[j]<=pivot){
            i+=1;
            swap(&v1[i],&v1[j]);
        }
    }
    swap(&v1[i+1],&v1[high]);

    return i+1;
}

void quickSort(vector<int>& v1, int low, int high){
    if(low<high){
        int pi = partition(v1,low,high);
        quickSort(v1,low,pi-1);
        quickSort(v1,pi+1,high);
    }

}

int main(){
    vector<int> v1{10,20,40,55,45,25,35};

    cout<<"Before Sorting :";
    for(auto i=v1.begin();i!=v1.end();i++){
        cout<<*i<<" ";
    }

    quickSort(v1,0,v1.size()-1);

    cout<<"\nAfter Sorting : ";
    cout<<"\nAscending order : ";
    for(auto i=v1.begin();i!=v1.end();i++){
        cout<<*i<<" ";
    }

    cout<<"\nDescending Order : ";
    for(auto i=v1.rbegin();i!=v1.rend();i++){
        cout<<*i<<" ";
    }

    cout<<endl;
}