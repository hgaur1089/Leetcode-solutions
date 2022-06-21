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
    pair<int, bool> checkBalance(TreeNode* root){
        if(root == NULL){
            pair<int, bool> p;
            p.first = 0;
            p.second = true;
            return p;
        }
        
        pair<int, bool> left = checkBalance(root->left);
        pair<int, bool> right = checkBalance(root->right);
        
        int leftH = left.first;
        bool leftB = left.second;
        int rightH = right.first;
        bool rightB = right.second;
        
        int height = 1+max(leftH, rightH);
        bool balanced = (abs(leftH-rightH)<=1 && leftB && rightB);
        pair<int, bool> p;
        p.first = height;
        p.second = balanced;
        return p;
    }
    bool isBalanced(TreeNode* root) {
         
        return checkBalance(root).second;
    }
};