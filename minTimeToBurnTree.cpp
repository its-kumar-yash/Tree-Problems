//Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

// Amazon MicroSoft Adobe Flipkart

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    //function to create mapping as well as finding target Node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent){
        //to store target Node
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        //root node has no parent
        nodeToParent[root] = NULL;
        
        while(!q.empty()){
            
            Node* frontNode = q.front();
            q.pop();
            
            //to find target node
            if(frontNode->data == target){
                res = frontNode;
            }
            
            //check for children nodes of front 
            // and mark front as their parent in the map
            // also push children into queue
            
            if(frontNode->left != NULL){
                q.push(frontNode->left);
                nodeToParent[frontNode->left] = frontNode;
            }
            if(frontNode->right != NULL){
                q.push(frontNode->right);
                nodeToParent[frontNode->right] = frontNode;
            }
        }
        
        return res;
    }
    
    //function to calculate minimum time to burn the tree
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent){
        
        int ans = 0;
        //create a visited map and queue for level order traversal
        map<Node*, bool> visited;
        queue<Node*> q;
        
        //mark root node as visited and push it into queue
        visited[root] = 1;
        q.push(root);
        
        while(!q.empty()){
            //flag to check if insertion in queue is done or not
            int flag = 0;            
            int n = q.size();
            
            for(int i = 0; i < n; i++){
                
                Node* frontNode = q.front();
                q.pop();
                
                //now make call for all three possible paths
                if(frontNode->left && !visited[frontNode->left]){
                    flag = 1;
                    q.push(frontNode->left);
                    visited[frontNode->left] = 1;
                }
                
                if(frontNode->right && !visited[frontNode->right]){
                    flag = 1;
                    q.push(frontNode->right);
                    visited[frontNode->right] = 1;
                }
                
                if(nodeToParent[frontNode] && !visited[nodeToParent[frontNode]]){
                    flag = 1;
                    q.push(nodeToParent[frontNode]);
                    visited[nodeToParent[frontNode]] = 1;
                }
            }
            
            if(flag == 1){
                ans++;
            }
        }
        
        return ans;
    }
  
    int minTime(Node* root, int target) 
    {
        //Algo :
        // 1. create mapping nodeToParent using Level Order Traversal
        // 2. Find target Node
        // 3. Burn the tree using Level Order traversal
        
        map<Node*, Node*> nodeToParent;
        
        Node* targetNode = createParentMapping( root, target, nodeToParent);
        
        int ans = burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends