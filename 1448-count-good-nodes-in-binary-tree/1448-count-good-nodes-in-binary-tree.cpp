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
    int findNodes(TreeNode* root, int maxi){
        if(root == NULL){
            return 0;
        }
        
        int left = findNodes(root->left, max(root->val, maxi));
        int right = findNodes(root->right, max(root->val, maxi));
        
        int ans = left + right;
        if(root->val >= maxi){
            return ans+1;
        } 
        
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return findNodes(root, INT_MIN);
    }
};