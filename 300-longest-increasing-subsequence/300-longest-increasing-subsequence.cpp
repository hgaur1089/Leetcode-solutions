class Solution {
    int lis4(int n, vector<int>& input)
    {
        vector<int> output(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (input[j] >= input[i])
                {
                    continue;
                }
                int possibleAns = output[j] + 1;
                if (possibleAns > output[i])
                {
                    output[i] = possibleAns;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans < output[i])
            {
                ans = output[i];
            }
        }
        return ans;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lis4(n, nums);
    }
};