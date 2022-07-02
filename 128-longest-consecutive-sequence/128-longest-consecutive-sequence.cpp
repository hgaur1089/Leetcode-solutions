class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            if(map.find(temp - 1) != map.end()){
                continue;
            } else {
                int count = 0;
                while(map.find(temp) != map.end()){
                    temp++;
                    count++;
                }
                
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
};