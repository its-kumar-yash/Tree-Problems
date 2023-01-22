#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data for node :"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);
}


void inOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    //Left -> Node -> Right
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    //Node -> Left -> Right
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }

    //Left -> Right -> Node
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}



int main(){
    
    Node* root = NULL;

    //1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);

    return 0;
}