class Solution {
    int maxCoins3(int n, vector<int> arr){
        arr.push_back(1);
        arr.insert(arr.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i=n; i>=1; i--){
            for(int j=1; j<=n; j++){
                if(i>j){
                    continue;
                }

                int ans = INT_MIN;
                for(int index=i; index<=j; index++){
                    int coins = (arr[i-1]*arr[index]*arr[j+1]) + dp[i][index-1] + dp[index+1][j];
                    ans = max(ans, coins);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
public:
    int maxCoins(vector<int>& nums) {
        return maxCoins3(nums.size(), nums);
    }
};