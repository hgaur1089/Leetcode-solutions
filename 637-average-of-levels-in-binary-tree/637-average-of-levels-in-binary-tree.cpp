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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int cnt = 0;
        double avg = 0;
        while(q.size() != 0){
            TreeNode* front = q.front();
            q.pop();
            
            if(front == NULL){
                avg = avg/(double)cnt;
                ans.push_back(avg);
                avg = 0;
                cnt = 0;
                
                if(q.size() == 0){
                    break;
                }
                q.push(NULL);
                continue;
            } 
            
            cnt++;
            avg += (double)(front->val)*1.0;
            
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            
        }
        
        return ans;
    }
};