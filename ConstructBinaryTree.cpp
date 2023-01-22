#include<bits/stdc++.h>
using namespace std;

//Node Class for tree node
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
    //create a new root
    cout<<"Enter Data for Node: "<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    //Recursive Call for left child node
    cout<<"Enter Data for Left Node of " << data <<endl;
    root->left = buildTree(root->left);
    //Recursive Call for right child node
    cout<<"Enter Data for Right Node of " << data <<endl;
    root->right = buildTree(root->right);

    return root;

}

int main(){
    
    Node* root = NULL;

    root = buildTree(root);

    return 0;
}