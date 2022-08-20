class Solution {
    int lis2(int n, vector<int>& arr){
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int index=n-1; index>=0; index--){
            for(int prevLen=index; prevLen>=0; prevLen--){
                int prevIndex = prevLen-1;
                int len = 0 + next[prevLen]; //not take

                if(prevIndex==-1 || arr[index]>arr[prevIndex]){
                    len = max(len, 1 + next[index+1]);
                }
                curr[prevLen] = len;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lis2(n, nums);
    }
};