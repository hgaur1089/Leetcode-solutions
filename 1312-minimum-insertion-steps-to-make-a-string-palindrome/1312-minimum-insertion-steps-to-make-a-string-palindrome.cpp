class Solution {
    int lcs3(int n, int m, string& s, string& t){
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int j=0; j<=m; j++){
            dp[0][j] = 0;
        }
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int ans;
                if(s[i-1] == t[j-1]){
                    ans = 1 + dp[i-1][j-1];
                } else {
                    ans = max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][m];
    }

    int minInsertion(string& s){
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        int len = lcs3(n, n, s, t);
        return n - len;
    }
public:
    int minInsertions(string s) {
        return minInsertion(s);
    }
};