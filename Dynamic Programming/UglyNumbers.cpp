/*Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … 
shows the first 11 ugly numbers. By convention, 1 is included.

Given a number n, the task is to find n’th Ugly number.*/
#include<iostream>
using namespace std;

unsigned uglyNumber(int n){
    unsigned ugly[n];
    unsigned i2=0,i3=0,i5=0;
    unsigned nextMultipleOf2=2,nextMultipleOf3=3,nextMultipleOf5=5, nextUglyNumber=1;

    ugly[0]=1;
    for(int i=1;i<n;i++){
        nextUglyNumber = min(nextMultipleOf2,min(nextMultipleOf3,nextMultipleOf5));

        ugly[i]=nextUglyNumber;
        if(nextUglyNumber==nextMultipleOf2){
            i2+=1;
            nextMultipleOf2=ugly[i2]*2;
        }
        if(nextUglyNumber==nextMultipleOf3){
            i3+=1;
            nextMultipleOf3=ugly[i3]*3;
        }
        if(nextUglyNumber==nextMultipleOf5){
            i5+=1;
            nextMultipleOf5=ugly[i5]*5;
        }
    }
    return nextUglyNumber;
}

int main(){
    int n;
    cin>>n;
    cout<<"The "<<n<<"'th Ugly Number is : "<<uglyNumber(n);
}