class Solution {
    int findLen(int si, int ei, string& s, vector<vector<int>>& dp){
    if(si>ei){
        return 0;
    }
    if(dp[si][ei] != -1){
        return dp[si][ei];
    }
    if(si==ei){
        return dp[si][ei] = 1;
    }

    if(s[si] == s[ei]){
        return dp[si][ei] = 2 + findLen(si+1, ei-1, s, dp);
    }

    return dp[si][ei] = max(findLen(si+1, ei, s, dp), findLen(si, ei-1, s, dp));
}
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
    
        return findLen(0, s.size()-1, s, dp);
    }
};