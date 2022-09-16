class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(int num:nums){
            if(hash.find(num)!=hash.end()){
                return true;
            }
            
            hash[num]++;
        }
        
        return false;
    }
};