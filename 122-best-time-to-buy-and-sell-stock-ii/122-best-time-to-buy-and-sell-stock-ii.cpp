class Solution {
    int maxProfit4(int n, vector<int>& prices){
        vector<int> ahead(2, 0);
        vector<int> curr(2, 0);

        ahead[0] = ahead[1] = 0;
        for(int index=n-1; index>=0; index--){
            for(int onGoing=0; onGoing<=1; onGoing++){
                int profit = 0;
                if(onGoing){
                    profit = max(ahead[0] - prices[index], ahead[1] - 0);
                } else {
                    profit = max(ahead[1] + prices[index], ahead[0] + 0);
                }

                curr[onGoing] = profit;
            }
            ahead = curr;
        }

        return ahead[1];
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxProfit4(prices.size(), prices);
    }
};