#include<bits/stdc++.h>

using namespace std;

bool isOperator(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
    }
    return false;
}

void prefiToInfi(string s){
    string ns;
    stack<string> st;
    int l = s.length();

    for(int i=l-1;i>0;i--){
        if(isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string op3 = "(" + op1 + s[i] + op2 + ")";
            st.push(op3);
            cout<<"top string is now : "<<st.top()<<endl;
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    cout<<st.top();
}

int main(){
    string s;
    cin>>s;
    prefiToInfi(s);
    return 0;
}