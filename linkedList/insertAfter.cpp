#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void insertAtBack(Node** head,int new_data){
    Node *new_node =new Node();
    new_node->data = new_data;
    Node *last = new Node();
    last = *head;

    if(*head==NULL){
        *head=new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}

void listPrint(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertAfter(Node *head,int position,int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    int count=0;

    Node *temp=head;
    while(temp!=NULL and count<position){
        temp=temp->next;
        count++;
    }
    if(count==position){
        new_node->next=temp->next;
        temp->next=new_node;
    }
    else{
        cout<<"List range exceeds"<<endl;
    }
}

int main(){
    Node *head=NULL;
    int C;
    int C1,P;
    cout<<"Enter the no. of elements : ";
    cin>>C;
    for(int i=0;i<C;i++){
        int x;
        cin>>x;
        insertAtBack(&head,x);
    }
    cout<<endl<<"The List items are : ";
    listPrint(head);
    cout<<endl;
    cout<<"Enter element to insert at specific position & position : ";
    cin>>C1>>P;
    insertAfter(head,C1,P);
    cout<<endl<<"After inserting at specific position : ";
    listPrint(head);
    return 0;
}