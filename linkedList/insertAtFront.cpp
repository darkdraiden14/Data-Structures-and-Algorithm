#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
void listInsertAtFront(Node** head,int new_data){
    Node *temp=new Node();

    temp->data=new_data;
    temp->next=(*head);
    (*head)=temp;
}

void listPrint(Node *temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node *head= NULL;
    int c;
    cout<<"Enter the no. of Elements: ";
    cin>>c;
    for(int i=0;i<c;i++){
        int x;
        cin>>x;
        listInsertAtFront(&head,x);
    }
    listPrint(head);
    return 0;
}