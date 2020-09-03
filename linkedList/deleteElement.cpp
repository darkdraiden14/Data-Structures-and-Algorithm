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

void deleteElement(Node **head,int key){
    Node* temp,*prev;
    temp=*head;


    if(temp!=NULL && temp->data==key){
        *head = temp->next;
        free(temp);
        return;   
    }

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL){
        cout<<"Element not found."<<endl;
        return;
    }
    prev->next=temp->next;
    free(temp);
    return;
}

int main(){
    Node *head=NULL;
    int C,D;
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
    cout<<"Enter the element to be deleted : ";
    cin>>D;
    deleteElement(&head,D);
    cout<<"after Deletion : ";
    listPrint(head);
    return 0;
}