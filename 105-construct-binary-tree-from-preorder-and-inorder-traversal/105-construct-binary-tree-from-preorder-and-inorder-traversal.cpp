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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder, int pS,int pE,int iS,int iE){
        
        if(iS > iE){
            return NULL;
        }
        
        int rootData = preorder[pS];
        int rootIndex = -1;
        for(int i=iS; i<=iE; i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        int inLS = iS;
        int inLE = rootIndex-1;
        int inRS = rootIndex+1;
        int inRE = iE;
        int preLS = pS+1;
        int preLE = preLS + (inLE-inLS);
        int preRS = preLE + 1;
        int preRE = pE;
        
        TreeNode* root = new TreeNode(rootData);
        
        root->left = tree(preorder, inorder, preLS, preLE, inLS, inLE);
        root->right = tree(preorder, inorder, preRS, preRE, inRS, inRE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return tree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};