#include<bits/stdc++.h>

using namespace std;

bool checkBalanced(string s){
    stack<char> st;
    int l= s.length();
    for(int i =0;i<l;i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            st.push(s[i]);
            cout<<"pushed : "<<s[i]<<endl;
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                st.pop();
                cout<<"popped : ("<<endl;
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(st.top()=='['){
                st.pop();

                cout<<"popped : ["<<endl;
            }
            else{
                return false;
            }
        }
        else if(s[i]=='}'){
            if(st.top()=='{'){
                st.pop();

                cout<<"popped : {"<<endl;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    if(checkBalanced(s)){
        cout<<s<<" is Balanced."<<endl;
    }
    else{
        cout<<s<<" is not Balanced."<<endl;
    }
    return 0;
}