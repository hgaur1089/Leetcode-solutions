/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ref(TreeNode* root, TreeNode* tar){
        if(root==NULL || root->val==tar->val){
            return root;
        }
        
        TreeNode* leftAns = ref(root->left, tar);
        TreeNode* rightAns = ref(root->right, tar);
        
        if(leftAns){
            return leftAns;
        } else if(rightAns){
            return rightAns;
        }
        
        return NULL;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return ref(cloned, target);
    }
};