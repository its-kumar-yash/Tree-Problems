
//PREORDER
class Solution {
public:
    void solve(Node* root, vector<int> &ans){
        //edge case
        if(root == NULL){
            return;
        }
        //push the root node value into ans
        //before recursive call
        ans.push_back(root->val);
        //iterating over children of root
        for(auto child : root->children){
            //recursive call for child
            solve(child, ans);
        }

    }
    vector<int> preorder(Node* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }

        //created stack
        stack<Node*> st;
        //push root node into stack
        st.push(root);

        while(!st.empty()){
            //pop out front node from stack
            //and add it to result
            Node* top = st.top();
            st.pop();
            ans.push_back(top->val);

            for(int i = top->children.size() - 1; i >= 0; i--){
                st.push(top->children[i]);
            }
        }
        return ans;
    }
};

//POSTORDER


class Solution {
public:
    void solve(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        for(auto child : root->children){
            solve(child, ans);
        }
        ans.push_back(root->val);
    } 
    vector<int> postorder(Node* root) {
        vector<int> ans;

        solve(root, ans);

        return ans;
    }
};

class Solution {
public:
     
    vector<int> postorder(Node* root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }
        
        stack<Node*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            Node* top = st1.top();
            st1.pop();
            st2.push(top);

            for(auto child : top->children){
                st1.push(child);
            }
        }

        while(!st2.empty()){
            Node* top = st2.top();
            ans.push_back(top->val);
            st2.pop();
        }


        return ans;
    }
};

//LEVEL ORDER
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;

        if(root == NULL){
            return result;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){

            vector<int> level;
            int n = q.size();

            for(int i = 0; i < n; i++){
                Node* frontNode = q.front();
                q.pop();

                level.push_back(frontNode->val);

                for(auto child : frontNode->children){
                    q.push(child);
                }
            }

            result.push_back(level);
        }


        return result;
    }
};


