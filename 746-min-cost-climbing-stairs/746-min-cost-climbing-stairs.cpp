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
        
        // // memoization
        // for(int i=0; i<n; i++){
        //     output[i] = -1;
        // }
        // int a = minCost(cost, n-1, output);
        // int b = minCost(cost, n-2, output);
        // int ans = min(a, b);
        
        output[0] = cost[0];
        output[1] = cost[1];
        for(int i=2; i<n; i++){
            int a = output[i-1];
            int b = output[i-2];
            
            output[i] = cost[i] + min(a, b);
        }
        
        int ans = min(output[n-1], output[n-2]);
        return ans;
    }
};