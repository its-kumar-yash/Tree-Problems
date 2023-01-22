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

void preOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    // Create an empty stack and push root to it
    stack<Node*> st;
    st.push(root);

    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while(!st.empty()){
        
        Node* temp = st.top();
        cout<<temp->data<<" ";
        st.pop();

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
}

void inOrder(Node* root){

}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    //create two stack 
    //push root node in stack 1
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);

    //loop while st1 is not empty 
    while(!st1.empty()){
        //pop element from stack 1
        Node* temp = st1.top();
        // and push into stack 2
        st1.pop();
        st2.push(temp);

        //push left and right children of temp into stack 1
        if(temp->left){
            st1.push(temp->left);
        }
        if(temp->right){
            st1.push(temp->right);
        }
    }

    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    } 
}




int main(){
    
    Node* root = NULL;

    //1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    preOrder(root);
    cout<<endl;
    // inOrder(root);
    cout<<endl;
    postOrder(root);

    return 0;
}