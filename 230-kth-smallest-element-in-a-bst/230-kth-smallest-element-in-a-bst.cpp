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
    void findK(TreeNode* root, int k, int& cnt, int& ans){
        if(root == NULL){
            return;
        }
        
        findK(root->left, k, cnt, ans);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        findK(root->right, k, cnt, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }
        int count = 0;
        int ans = -1;
        findK(root, k, count, ans);
        return ans;
    }
};