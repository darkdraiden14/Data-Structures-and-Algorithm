#include<bits/stdc++.h>

using namespace std;

int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infiToPostfi(string s){
    string ns;
    stack<char> st;
    st.push('!');

    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            ns+=s[i];
        }
        else if(s[i]=='('){
            st.push('(');
        }
        else if(s[i]==')'){
            while(st.top()!='!' && st.top()!='('){
                char c = st.top();
                st.pop();
                ns+=c;
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else{
            while(st.top()!='!' && prec(st.top())>=prec(s[i])){
                char c=st.top();
                st.pop();
                ns+=c;
            }
            st.push(s[i]);
        }
    }
    while(st.top()!='!'){
        char c = st.top();
        st.pop();
        ns+=c;
    }
    cout<<ns;
}

int main(){
    string s;
    cin>>s;
    infiToPostfi(s);
    return 0;
}