class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto i:mp){
            
            while(i.second-- > 0){
                for(int j=1; j<k; j++){
                    if(mp[i.first + j] > 0){
                        mp[i.first + j]--;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
};