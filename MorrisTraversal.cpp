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

/* Function to traverse the binary tree without recursion
   and without stack */

void MorrisTraversal(Node* root){

    Node* curr = root;
    Node* pre = NULL;

    while(curr != NULL){

        if(curr->left == NULL){
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else{
            /* Find the inorder predecessor of current */
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            /* Make current as the right child of its
               inorder predecessor */
            if(pre->right == NULL){
                pre->right = curr;
                curr = curr->left;
            }
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else{
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }

        }
    }
}

int main(){
    
    
    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    MorrisTraversal(root);


    return 0;
}