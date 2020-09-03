#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<" ";
        n=n->next;
    }
}

void listInsertAtBack(Node** head,int new_data){
    Node * new_node = new Node();

    new_node->data=new_data;
    
    Node *last=*head;

    if(*head==NULL){
        *head = new_node;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next= new_node;
    return;
}

int main(){
    Node *root=NULL;
    int c;
    cout<<"Enter the no. of elements : ";
    cin>>c;
    printList(root);
    for(int i=0;i<c;i++){
        int x;
        cin>>x;
        listInsertAtBack(&root,x);
        printList(root);
    }
    printList(root);
    return 0;
}