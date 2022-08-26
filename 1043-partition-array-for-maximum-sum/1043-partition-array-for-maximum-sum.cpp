class Solution {
    int maxSum3(int n, int k, vector<int> arr){
        vector<int> dp(n+1 ,0);
        dp[n] = 0;

        for(int index=n-1; index>=0; index--){
            int len=0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for(int j=index; j<min(n, index+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len*maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[index] = maxAns;
        }

        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        return maxSum3(arr.size(), k, arr);
    }
};