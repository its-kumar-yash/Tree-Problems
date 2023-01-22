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

//Without level seperator
void levelOrder(Node* root){
    //step 1: create a queue to store child nodes of a parent node of same level
    // and push root into queue
    queue<Node*> q;

    q.push(root);

    //step 2: run while loop until queue is empty
    while(!q.empty()){
        
        //step 3: initialize temp and print temp
        Node* temp = q.front();

        cout<<temp->data<<" ";

        //step 4: push temp node children into queue
        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }

        //step 5: pop front from queue
        q.pop();
    }

}

//Level Order function showing Level - level seperator
void levelOrderModified(Node* root){
    //step 1: create a queue to store child nodes of a parent node of same level
    // and push root into queue
    // and push NULL also which works as seperator between levels
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //step 2: run while loop until queue is empty
    while(!q.empty()){
        
        //step 3: initialize temp and pop queue front node
        Node* temp = q.front();
        q.pop();

        //check if queue is empty
        // and print endl as seperator occurs
        // also if queue is not empty push NULL into queue
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        //else perform usual operation
        else{
            cout<<temp->data<<" ";

            if(temp->left != NULL){
                q.push(temp->left);
            }
            
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }

}

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans; // to store answer
    
    //step 1 - create queue and stack of Node* type
    // and push root node into queue
    queue<Node*> q;
    stack<Node*> st;
    
    q.push(root);
    
    //step 2 - run while loop untill queue is empty
    while(!q.empty()){
        //step 3 - save the q.front() and pop it
        //also push the saved node into stack
        Node* temp = q.front();
        q.pop();
        st.push(temp);
        
        //step 4 - push children of temp into queue
        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }
    
    //step 3 - run while loop untill stack is empty
    while(!st.empty()){
        int top = st.top()->data;
        st.pop();
        ans.push_back(top);
    }
    
    
    return ans;
}

int main(){
    
    Node* root = NULL;

    //1 3 7 -1 -1 4 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    levelOrder(root);
    cout<<endl;
    cout<<endl;

    levelOrderModified(root);

    return 0;
}