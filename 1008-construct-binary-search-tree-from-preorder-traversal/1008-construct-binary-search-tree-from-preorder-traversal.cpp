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
    TreeNode* preorderT(vector<int>& pre, int& index, int ub){
        if(index >= pre.size() || pre[index] > ub){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[index++]);
        root->left = preorderT(pre, index, root->val);
        root->right = preorderT(pre, index, ub);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode* root = preorderT(preorder, i, INT_MAX);
        return root;
    }
};