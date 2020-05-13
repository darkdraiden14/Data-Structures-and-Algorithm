#include<iostream>
#include<cmath>
using namespace std;

int fib(int n){
    double f = (1+sqrt(5))/2;
    return round(pow(f,n)/sqrt(5));
}

int main(){
    int n;
    cout<<"Enter N : ";
    cin>>n;
    cout<<"The Fibonacci Number at "<<n<<"'th position is : "<<fib(n);
    
    return 0;
}