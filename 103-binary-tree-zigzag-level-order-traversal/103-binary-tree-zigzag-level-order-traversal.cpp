/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  ans;
        if(root == NULL){
            return ans;
        }
        
        stack<TreeNode*> s1, s2;
        s1.push(root);
        int flag = 1;
        vector<int> temp;
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            
            temp.push_back(curr->val);
            
            if(flag){
                if(curr->left)  s2.push(curr->left);
                if(curr->right)   s2.push(curr->right);
            } else {
                if(curr->right)   s2.push(curr->right);
                if(curr->left)  s2.push(curr->left);
            }
            
            if(s1.empty()){
                ans.push_back(temp);
                temp.clear();
                
                stack<TreeNode*> stk = s1;
                s1 = s2;
                s2 = stk;
                
                flag = !flag;
            }
        }
        
        return ans;
    }
};