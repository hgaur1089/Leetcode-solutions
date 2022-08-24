class Solution {
    int minCost3(int n, vector<int> cuts){
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

        for(int i=c; i>=1; i--){
            for(int j=1; j<=c; j++){
                if(i>j){
                    continue;
                }

                int miniCost = INT_MAX;
                for(int index=i; index<=j; index++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    miniCost = min(miniCost, cost);
                }
                dp[i][j] = miniCost;
            }
        }

        return dp[1][c];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        return minCost3(n, cuts);
    }
};