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
    int sumPath(TreeNode* root, int& ans){
        if(root == NULL){
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans = max(ans, root->val);
            return root->val;
        }
        
        int leftPath = sumPath(root->left, ans);
        int rightPath = sumPath(root->right, ans);
        
        if(leftPath < 0) leftPath = 0;
        if(rightPath < 0) rightPath = 0;
        ans = max(ans, (root->val+leftPath+rightPath));
        
        return (root->val + max(leftPath, rightPath));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int temp = sumPath(root, ans);
        return ans;
    }
};