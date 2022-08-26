class Solution {
    int countSquares(vector<vector<int>>& arr, int n, int m){
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            dp[i][0] = arr[i][0];
        }
        for(int j=0; j<m; j++){
            dp[0][j] = arr[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(arr[i][j] == 1){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        return countSquares(matrix, n, m);
    }
};