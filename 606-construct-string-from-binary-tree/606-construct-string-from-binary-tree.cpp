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
    string paran(TreeNode* root){
        if(root==NULL){
            return "()";
        }
        if(root->left==NULL && root->right==NULL){
            string num = to_string(root->val);
            return "("+num+")";
        }
        
        string left = paran(root->left);
        string right = paran(root->right);
        
        // if(left=="()" && right=="()"){
        //     left = "";
        //     right = "";
        // } else 
        if(left!="()" && right=="()"){
            right = "";
        }
        
        string num = to_string(root->val);
        string ans = "(" + num + left + right + ")";
        return ans;
    }
public:
    string tree2str(TreeNode* root) {
        string ans = paran(root);
        ans = ans.substr(1, ans.size()-2);
        return ans;
            
    }
};