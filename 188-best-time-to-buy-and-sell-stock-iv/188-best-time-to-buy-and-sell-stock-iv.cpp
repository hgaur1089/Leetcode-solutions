class Solution {
    int profit(int i, int buy, int k,int n, vector<int> prices, vector<vector<vector<int>>>& dp){
        if(i==n || k==0){
            return 0;
        }
        
        if(dp[i][buy][k] != -1){
            return dp[i][buy][k];
        }
        
        int ans = 0;
        if(buy){
            ans = max(profit(i+1, 0, k, n, prices, dp) - prices[i], profit(i+1, buy, k, n, prices, dp));
        } else {
            ans = max(profit(i+1, 1, k-1, n, prices, dp) + prices[i], profit(i+1, buy, k, n, prices, dp));
        }
        
        return dp[i][buy][k] = ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int txn=1; txn<=k; txn++){
                    int ans = 0;
                    if(buy){
                        ans = max(dp[i+1][0][txn] - prices[i], dp[i+1][buy][txn]);
                    } else {
                        ans = max(dp[i+1][1][txn-1] + prices[i], dp[i+1][buy][txn]);
                    }

                    dp[i][buy][txn] = ans;
                }
            }
        }
        
        return dp[0][1][k];
    }
};