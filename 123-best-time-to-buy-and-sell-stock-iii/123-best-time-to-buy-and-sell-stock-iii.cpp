class Solution {
    int maxProfit3(int txns, int n, vector<int>& prices){
        vector<vector<int>> after(2, vector<int>(txns+1, 0));
    vector<vector<int>> curr(2, vector<int>(txns+1, 0));

    for(int index=n-1; index>=0; index--){
        for(int buy=0; buy<=1; buy++){
            for(int txn=1; txn<=txns; txn++){
                int profits = 0;
                if(buy){
                    profits = max(after[0][txn] - prices[index], after[buy][txn] + 0);
                } else {
                    profits = max(after[1][txn-1] + prices[index], after[buy][txn] + 0);
                }
                curr[buy][txn] = profits;
            }
        }
        after = curr;
    }

    return after[1][txns];
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit3(2, prices.size(), prices);
    }
};