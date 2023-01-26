
// Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

// LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

//Microsoft Amazon Google Twitter


#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Approach - 1
//Using Extra Space 
//Finding paths and checking them 
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    bool findPath(Node* root, vector<Node*> &path, int key){
        //base case
        if(root == NULL){
            return false;
        }
        
        // Store this node in path vector. The node will be
        // removed if not in path from root to k
        path.push_back(root);
        
        //if key node is same as root node
        if(root->data == key){
            return true;
        }
        
        // Check if k is found in left or right sub-tree
        if((root->left && findPath(root->left, path, key)) || root->right && findPath(root->right, path, key)){
            return true;
        }
        
        // If not present in subtree rooted with root, remove
        // root from path[] and return false
        path.pop_back();
        return false;
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {   
        // to store paths to n1 and n2 from the root    
        vector<Node*> paths1, paths2;
        
        // Find paths from root to n1 and root to n2. If either
        // n1 or n2 is not present, return -1
        if(!findPath(root, paths1, n1) || !findPath(root, paths2, n2)){
            return NULL;
        }
        
         /* Compare the paths to get the first different value */
        int  i;
        for ( i = 0; i < paths1.size() && i < paths2.size(); i++){
            if(paths1[i] != paths2[i]){
                break;
            }
        }
        
        return paths1[i - 1];
       
       
    }
};

//Approach #2 - USing Recursion

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
       if(root == NULL){
           return NULL;
       }
       //if root is anything between n1 and n2
       //then lca is root itself
       if(root->data == n1 || root->data == n2){
           return root;
       }
       
       
       //now apply four possibilities between left ans and right ans
       Node* leftAns = lca(root->left, n1, n2);
       Node* rightAns = lca(root->right, n1, n2);
       
       if(leftAns != NULL && rightAns != NULL){
           return root;
       }
       else if(leftAns != NULL && rightAns == NULL){
           return leftAns;
       }
       else if(leftAns == NULL && rightAns != NULL){
           return rightAns;
       }
       else{
           return NULL;
       }
       
    }
};

//{ Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends