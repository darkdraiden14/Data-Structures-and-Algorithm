#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int flag;
};

void insertBack(Node** head,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->flag=0;

    Node *temp=*head;
    if(*head==NULL){
        *head=new_node;
        return;
    }

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}

bool detectLoopInList(Node *temp){
    while(temp!=NULL){
        if(temp->flag==1){
            return true;
        }
        temp->flag=1;
        temp=temp->next;
    }
    return false;
}

int main(){
    Node *head = NULL;
    int N;
    cout<<"Enter the No. of Elements : ";
    cin>>N;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        insertBack(&head,N);
    }
    cout<<"\nConnecting Last Node with 3rd Node to create a cycle.";
    cout<<"\nDetect Loop : ";
    head->next->next->next->next->next = head;
    if(detectLoopInList(head)){
        cout<<"\nLoop Detected";
    }
    else{
        cout<<"\nNo Loop";
    }
    return 0;    
}