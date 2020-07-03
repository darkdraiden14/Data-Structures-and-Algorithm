#include<bits/stdc++.h>

using namespace std;

// Create Node with a root and 2 pointers (left,right)
struct Node{
    int root;
    Node *left,*right;
    Node(int x){
        root = x;
        left=right=NULL;
    }
};

// Inorder traversal 
void inorder(Node *temp){
    if (!temp){
        return;
    }

    inorder(temp->left);
    cout<<temp->root<<" ";
    inorder(temp->right);
}

//Function to delete the given deepest node in tree
void deleteDeepest(Node *root, Node *d_node){

    queue<Node *> q;
    q.push(root);

    Node* temp;
    while(!q.empty()){
        temp = q.front();

        q.pop();
        if(temp==d_node){
            temp=NULL;
            delete(d_node);
            return;
        }
        if(temp->right){
            if(temp->right == d_node){
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left == d_node){
                temp->left = NULL;
                delete(d_node);
                return;
            }
            else{
                q.push(temp->left);
            }
        }
    }
}

//Function to delete given node or for replacing given element with deepest rightmost element
Node* deletion(Node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(root->root==key){
            return NULL;
        }
        else{
            return root;
        }
    }

    queue<Node*> q;
    q.push(root);

    Node *temp;
    Node* key_node=NULL;

    //Do level order Traversal
    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->root==key){
            key_node =temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    if(key_node!=NULL){
        int x = temp->root;
        deleteDeepest(root,temp);
        key_node->root=x;
    }
    return root;
}

//Insertion in tree at Level Order Traversal
void insert(Node* temp, int key){
    queue<Node*> q;
    q.push(temp);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(!temp->left){
            temp->left = new Node(key);
            break;
        }
        else{
            q.push(temp->left);
        }

        if (!temp->right){
            temp->right = new Node(key);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
}

int main(){
    //  Crete Node of tree  as 20
    Node *root = new Node(20);
    //Create left Child 10
    root->left = new Node(10);
    //Right Node as 30
    root->right = new Node(30);

    //Sub tree for root->left
    root->left->left = new Node(5);
    root->left->right = new Node(15);

    //Sub tree for root->right
    root->right->right = new Node(35);

    //Inorder Traversal
    cout<<"The In order Traversal of Tree is : ";
    inorder(root);

    cout<<"\nSo Now we want to insert a Node in our tree, suppose we want to insert 25"<<endl;

    int key = 25;
    insert(root,key);

    cout<<"After Insertion The inorder traversal is : ";
    inorder(root);

    cout<<endl;
    cout<<"For the Deletion of a node in Tree, Replace the Node with deepest rightmost node in the Tree";
    cout<<"\nAnd then Delete the deepest rightmost Node";

    cout<<endl<<"Let's say we want to delete the key=20";
    key = 20;
    root =deletion(root, key);

    cout<<endl<<"\n After Deletion of key =20, Now the inorder of tree is : ";
    inorder(root);
}   