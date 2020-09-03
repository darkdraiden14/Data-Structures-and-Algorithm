#include<bits/stdc++.h>

using namespace std;

void postfiToInfi(string s){
    stack<string> st;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(s[i]>='a' &&s[i]<='z'){
            st.push(string(1,s[i]));
        }
        else{
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string op3 = '(' + op1 + s[i] + op2 + ')';
            st.push(op3);
        }
    }
    cout<<st.top();
}

int main(){
    string s;
    cin>>s;
    postfiToInfi(s);
    return 0;
}