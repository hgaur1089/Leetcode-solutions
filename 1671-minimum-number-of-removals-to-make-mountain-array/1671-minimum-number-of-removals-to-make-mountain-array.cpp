class Solution {
    int bitonicLen(int n, vector<int>& arr){

        vector<int> dp(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                int possibleAns = 1 + dp[prev];
                if(arr[i]>arr[prev] && possibleAns>dp[i]){
                    dp[i] = possibleAns;
                }
            }
        }

        vector<int> dp2(n, 1);
        for(int i=n-1; i>=0; i--){
            for(int prev=n-1; prev>i; prev--){
                int possibleAns = 1 + dp2[prev];
                if(arr[i]>arr[prev] && possibleAns>dp2[i]){
                    dp2[i] = possibleAns;
                }
            }
        }

        int ans = 0;
        for(int i=1;i<n-1;i++){
            int num = dp[i]+dp2[i]-1;
            int prev = dp[i-1]+dp2[i-1]-1;
            int next = dp[i+1]+dp2[i+1]-1;
            if(prev<=num && num>next)
                ans = max(ans, dp[i]+dp2[i]-1);
            cout<<dp[i]+dp2[i]-1<<" ";
        }
        // cout<<endl;
        // for(int i=0; i<n;i++){
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0; i<n;i++){
        //     cout<<dp2[i]<<" ";
        // }
        // cout<<endl;

        return n-ans;
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        return bitonicLen(nums.size(), nums);
    }
};