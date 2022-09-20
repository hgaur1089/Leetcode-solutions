class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pre(n), post(n);
        
        int preMax = -1;
        int postMax = -1;
        for(int i=0;i<n; i++){
            pre[i] = preMax;
            preMax = max(preMax, height[i]);
            
            post[n-1-i] = postMax;
            postMax = max(postMax, height[n-1-i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(height[i] < min(pre[i], post[i])){
                ans += min(pre[i], post[i]) - height[i];
            }
        }
        
        return ans;
    }
};