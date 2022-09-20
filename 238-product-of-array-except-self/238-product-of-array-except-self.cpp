class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n =nums.size();
        
        int pre = 1;
        for(int i=0;i<n;i++){
            ans[i] = pre;
            pre = pre*nums[i];
        }
        
        int post = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i]*post;
            post = post*nums[i];
        }
        return ans;
    }
};