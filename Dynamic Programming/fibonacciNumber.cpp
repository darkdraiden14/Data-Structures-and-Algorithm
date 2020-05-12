#include<iostream>
#include<time.h>
using namespace std;

#define NIL -1
#define MAX 100

int lookup[MAX];

//Suing Recursion
int fibonacciRecursion(int n){
    if(n<=1){
        return n;
    }
    return (fibonacciRecursion(n-1)+fibonacciRecursion(n-2));
}

//Using Memoization (TOP DOWN)
void _initializeLookup(){
    for(int i=0;i<MAX;i++){
        lookup[i]=NIL;    
    }
}

int fibonacciMemo(int n){
    if(lookup[n]==NIL){
        if(n<=1){
            lookup[n] = n;
        }
        else{
            lookup[n]=fibonacciMemo(n-1)+fibonacciMemo(n-2);
        }
    }
    return lookup[n];
}

//Using Tabulation Method (BOTTOM UP)
int fibonacciTabu(int n){
    int f[n+1]; 
    int i; 
    f[0] = 0;   f[1] = 1;  
    for (i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    } 
    return f[n]; 
}

int main(){
    clock_t start, end;
    _initializeLookup();
    cout<<"1. Using Recurssion : \n";
    start = clock();
    cout<<"\n\tFibonacci Number at n=40 is : "<<fibonacciRecursion(40);
    cout<<"\n\tFibonacci Number at n=20 is : "<<fibonacciRecursion(20);

    end = clock();
    double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\n\n\tTime Taken is "<<fixed<<time_taken<<"sec";

    cout<<"\n2.Using Memoization : \n";
    start=clock();
    cout<<"\n\tFibonacci Number at n=40 is : "<<fibonacciMemo(40);
    cout<<"\n\tFibonacci Number at n=20 is : "<<fibonacciMemo(20);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\n\n\tTime Taken is "<<fixed<<time_taken<<"sec";

    cout<<"\n3.Using Tabulation : \n";
    start=clock();
    cout<<"\n\tFibonacci Number at n=40 is : "<<fibonacciTabu(40);
    cout<<"\n\tFibonacci Number at n=20 is : "<<fibonacciTabu(20);
    end = clock();
    time_taken = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"\n\n\tTime Taken is "<<fixed<<time_taken<<"sec"<<endl;

    cout<<"\n\nConclusion : Memoization stores value in demand, while Tabulation stores Values from 0 to N"<<endl;
}