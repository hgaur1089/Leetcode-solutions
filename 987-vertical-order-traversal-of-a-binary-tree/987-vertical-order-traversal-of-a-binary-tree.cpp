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
bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second < b.second;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        map<int, vector<pair<int, int>>> mp;
        
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            TreeNode* front = q.front().first;
            int level = q.front().second.first;
            int ht = q.front().second.second;
            q.pop();
            
            mp[level].push_back({front->val, ht});
            
            if(front->left){
                q.push({front->left, {level-1, ht+1}});
            }
            if(front->right){
                q.push({front->right, {level+1, ht+1}});
            }
        }
        
        for(auto itr:mp){
            vector<pair<int, int>> temp = itr.second;
            sort(temp.begin(), temp.end(), cmp);
            vector<int> arr;
            for(auto i:temp){
                arr.push_back(i.first);
            }
            ans.push_back(arr);
        }
        
        return ans;
    }
};