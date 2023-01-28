//Given 2 Arrays of Inorder and preorder traversal. The tree can contain duplicate elements. Construct a tree and print the Postorder traversal. 


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

//Approach #1 - Brute Force

class Solution{
    public:
    int findPosition(int in[], int element, int start, int end){
        for(int i = start; i <= end; i++){
            if(in[i] == element){
                return i;
            }
        }
        
        return -1;
    }
    Node* solve(int in[], int pre[], int &preIndex, int inIndexStart, int inIndexEnd, int size){
        //base case
        //when preIndex reaches end of preOrder
        //Or inorder start exceed inorder end
        if(preIndex >= size || inIndexStart > inIndexEnd){
            return NULL;
        }
        
        //pick element from preOrder and Increment preIndex 
        int element = pre[preIndex++];
        
        //create tree node of picked value
        Node* tNode = new Node(element);
        
        /* If this node has no children then return */
        if(inIndexStart == inIndexEnd){
            return tNode;
        }
        
        // Searching the index of rootElement between a specific range not in the whole in[] array
        // to avoid any error due to duplicate elements in the array
        //find the position of picked element index into inorder
        int pos = findPosition(in, element, inIndexStart, inIndexEnd);
        
        //recursive call for LST and RST
        tNode->left = solve( in, pre, preIndex, inIndexStart, pos - 1, size);
        tNode->right = solve(in, pre, preIndex, pos + 1, inIndexEnd, size);
        
        
        return tNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0; //initializing preOrder index
    
        Node* root = solve( in, pre, preIndex, 0, n - 1, n);
    
        return root;
    }
};

//Aproach #2

class Solution{
    public:
    unordered_map<int,int> createMap( unordered_map<int,int> mp, int in[], int n){
        for(int i = 0; i < n; i++){
            mp[in[i]] = i;
        }
        
        return mp;
    }
    Node* solve(int in[], int pre[], int &preIndex, int inIndexStart, int inIndexEnd, int size, unordered_map<int,int> &mp){
        //base case
        //when preIndex reaches end of preOrder
        //Or inorder start exceed inorder end
        if(preIndex >= size || inIndexStart > inIndexEnd){
            return NULL;
        }
        
        //pick element from preOrder and Increment preIndex 
        int element = pre[preIndex++];
        
        //create tree node of picked value
        Node* tNode = new Node(element);
        
        /* If this node has no children then return */
        if(inIndexStart == inIndexEnd){
            return tNode;
        }
        
        // Searching the index of rootElement between a specific range not in the whole in[] array
        // to avoid any error due to duplicate elements in the array
        //find the position of picked element index into inorder
        int pos = mp[element];
        
        //recursive call for LST and RST
        tNode->left = solve( in, pre, preIndex, inIndexStart, pos - 1, size, mp);
        tNode->right = solve(in, pre, preIndex, pos + 1, inIndexEnd, size, mp);
        
        
        return tNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0; //initializing preOrder index
        
        //creating a map to avoid searching again and again
        unordered_map<int,int> mp;
        mp = createMap(mp, in, n);
        
        Node* root = solve( in, pre, preIndex, 0, n - 1, n, mp);
    
        return root;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends