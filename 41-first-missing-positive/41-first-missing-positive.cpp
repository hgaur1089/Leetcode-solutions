class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 1;
        map<int, int> mp;
        for(auto num:nums){
            mp[num]++;
        }
        
        while(mp.count(ans)>0){
            ans++;
        }
        
        return ans;
    }
};