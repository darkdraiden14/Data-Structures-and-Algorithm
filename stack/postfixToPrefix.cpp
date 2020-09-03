#include<bits/stdc++.h>

using namespace std;

string postfiToInfi(string s){
    string ns;
    stack<string> st;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(s[i]>='a' && s[i]<='z'){
            st.push(string(1,s[i]));
        }
        else{
            string op2= st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string op3 = '(' + op1 + s[i] + op2 + ')';
            st.push(op3);
        }
    }
    ns = st.top();
    st.pop();
    cout<<"Postfix to Infix : "<<ns<<endl;
    return ns;
}

int prec(char x){
    if(x=='^'){
        return 3;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='+' || x=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infiToPrefi(string ns){
    string ns1;
    stack<char> st;
    st.push('!');
    int l = ns.length();
    for(int i=l-1;i>=0;i--){
        if(ns[i]>='a' && ns[i]<='z'){
            ns1+=ns[i];
        }
        else if(ns[i]==')'){
            st.push(ns[i]);
        }
        else if(ns[i]=='('){
            while(st.top()!='!' and st.top()!=')'){
                ns1+=st.top();
                st.pop();
            }
            if(st.top()==')'){
                st.pop();
            }
        }
        else{
            while(st.top()!='!' && prec(st.top())>=prec(ns[i])){
                ns1+=st.top();
                st.pop();
            }
            st.push(ns[i]);
        }
    }
    while(st.top()!='!'){
        ns1+=st.top();
        st.pop();
    }
    reverse(ns1.begin(),ns1.end());
    cout<<"Prefix is : "<<ns1;
}

void postfiToPrefi(string s){
    string ns;
    cout<<"Input is : "<<s<<endl;
    ns = postfiToInfi(s);
    infiToPrefi(ns);
}

int main(){
    string s;
    cin>>s;
    postfiToPrefi(s);
    return 0;
}