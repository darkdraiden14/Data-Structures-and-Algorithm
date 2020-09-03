#include<bits/stdc++.h>

using namespace std;

#define MAX 100

class Stack{
    int top;
    public:
        int a[MAX];
        Stack(){
            top=-1;
        }
        bool push(int x){
            if(top>=(MAX-1)){
                cout<<"Overflow";
                return false;
            }
            else{
                top++;
                a[top]=x;
                return true;
            }
        }
        int pop(){
            if(top==-1){
                cout<<"UnderFlow";
                return -1;
            }
            else{
                return a[top--];
            }
        }
        bool isEmpty(){
            return (top>0);
        }
        int peek(){
            if(top==-1){
                cout<<"UnderFlow";
                return -1;
            }
            else{
                return a[top];
            }
        }
        void print(){
            int i=top;
            while(i!=-1){
                cout<<a[i]<<endl;
                i--;
            }
        }
};

int main(){
    Stack s;
    s.push(5);
    s.push(10);
    s.push(40);
    s.print();
    return 0;
}