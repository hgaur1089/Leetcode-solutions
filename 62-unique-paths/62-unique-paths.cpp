class Solution {
    int paths(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i==(n-1)&&j==(m-1)){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = (paths(i,j+1,m,n,dp)+paths(i+1,j,m,n,dp));
    }
public:
    int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n,-1));        
        
//         return paths(0,0,m,n, dp);
        int N = n+m-2;
        int r = m-1;
        double res = 1;
        
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }
        
        return (int)res;
    }
};