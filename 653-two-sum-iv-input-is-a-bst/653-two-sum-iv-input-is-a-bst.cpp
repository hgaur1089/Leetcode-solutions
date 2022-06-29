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
class BSTIterator {
    stack<TreeNode* > stk;
    bool reverse = true;
    
    void pushAll(TreeNode* node){
        while(node){
            stk.push(node);
            if(reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root);
    }
    
    int next() {
        TreeNode* top = stk.top();
        stk.pop();
        if(reverse)
            pushAll(top->left);
        else
            pushAll(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return stk.size() != 0;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j){
            if(i + j == k){
                return true;
            } else if(i + j > k){
                j = r.next();
            } else {
                i = l.next();
            }
        }
        
        return false;
    }
};