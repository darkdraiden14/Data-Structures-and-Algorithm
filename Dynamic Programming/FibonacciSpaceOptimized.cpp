#include<iostream>

using namespace std;

int fib(int n){
    int a=0,b=1,c;
    if(n==0){
        return a;
    }
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}
int main(){
    int n;
    cout<<"Enter the Number N : ";
    cin>>n;
    cout<<"The Fibonacci Numberar "<<n<<"'th position is : "<<fib(n);
}