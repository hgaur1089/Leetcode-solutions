class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        
        int ans = 0;
        for(auto itr: mp){
            if(mp.count(itr.first+1)>0){
                ans = max(ans, itr.second + mp[itr.first+1]);
            }
        }
        
        return ans;
    }
};