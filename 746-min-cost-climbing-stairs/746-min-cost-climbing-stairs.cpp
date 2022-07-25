class Solution {
    
    int minCost(vector<int>& cost, int n, int* output){
        if(n < 0){
            return 0;
        }
        if(n == 0 || n == 1){
            return cost[n];
        }
        
        if(output[n] != -1){
            return output[n];
        }
        
        int a = minCost(cost, n-1, output);
        int b = minCost(cost, n-2, output);
        int ans = cost[n] + min(a, b);
        output[n] = ans;
        
        return ans;
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int* output = new int[n+1];
        for(int i=0; i<=n; i++){
            output[i] = -1;
        }
        int a = minCost(cost, n-1, output);
        int b = minCost(cost, n-2, output);
        int ans = min(a, b);
        return ans;
    }
};