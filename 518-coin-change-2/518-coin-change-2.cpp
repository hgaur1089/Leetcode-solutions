class Solution {
    int minCoins(int index, int tar, vector<int>& coins, vector<vector<int>>& dp){
        if(index == 0){
            if(tar%coins[0] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[index][tar]!=-1){
            return dp[index][tar];
        }
        
        int notTake = minCoins(index-1, tar, coins, dp);
        int take = 0;
        if(coins[index]<=tar){
            take = minCoins(index, tar-coins[index], coins, dp);
        }
        return dp[index][tar] = (take+notTake);
    }
    
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        
        for(int i=0;i<=amount;i++){
            prev[i] = (i%coins[0]==0);
        }
        
        for(int index=1; index<n; index++){
            for(int tar=0; tar<=amount; tar++){
                int notTake = prev[tar];
                int take = 0;
                if(coins[index]<=tar){
                    take = prev[tar-coins[index]];
                }
                prev[tar] = (take+notTake);
            }
        }
        
        return prev[amount];
    }
};