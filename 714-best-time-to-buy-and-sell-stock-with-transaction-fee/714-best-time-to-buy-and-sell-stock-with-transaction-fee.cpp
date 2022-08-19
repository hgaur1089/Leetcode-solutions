class Solution {
    int maxProfit3(int fees, int n, vector<int>& prices){
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;
        for(int index=n-1; index>=0; index--){    
            dp[index][1] = max(dp[index+1][0] - prices[index], dp[index+1][1] - 0);
            dp[index][0] = max(dp[index+1][1] + prices[index] - fees, dp[index+1][0] + 0);
        }

        return dp[0][1];
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return maxProfit3(fee, n, prices);
    }
};