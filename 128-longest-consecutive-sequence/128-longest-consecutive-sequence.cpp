class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashSet;
        for(int num:nums){
            hashSet.insert(num);
        }
        
        int longestStreak = 0;
        for(auto num:nums){
            if(hashSet.count(num-1) < 1){
                int currNum = num;
                int currStreak = 1;
                
                while(hashSet.count(currNum+1)>0){
                    currNum += 1;
                    currStreak += 1;
                }
                
                longestStreak = max(longestStreak, currStreak);
            }
        }
        
        return longestStreak;
    }
};