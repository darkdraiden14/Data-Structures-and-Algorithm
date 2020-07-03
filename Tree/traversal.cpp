#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void preOrderTraversal(struct Node *head){
    if(head==NULL){
        return;
    }

    cout<<head->data<<" ";
    preOrderTraversal(head->left);
    preOrderTraversal(head->right);
}

void postOrderTraversal(struct Node *head){
    if(head==NULL){
        return;
    }
    postOrderTraversal(head->left);
    postOrderTraversal(head->right);
    cout<<head->data<<" ";
}

void inOrderTraversal(struct Node *head){
    if(head==NULL){
        return;
    }
    inOrderTraversal(head->left);
    cout<<head->data<<" ";
    inOrderTraversal(head->right);
}


int main(){
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"Preorder Traversal : ";
    preOrderTraversal(root);

    cout<<endl<<"Inorder Traversal : ";
    inOrderTraversal(root);

    cout<<endl<<"PostOrderTraversal : ";
    postOrderTraversal(root);

    return 1;
}
