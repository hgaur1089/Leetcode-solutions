class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        if(nums.size() == 2){
            if(nums[0] == nums[1]){
                return 1;
            } else {
                return 2;
            }
        }
        
        int len = 1;
        int slope = 0;
        
        int i=0;
        for(; i<nums.size()-1; i++){
            if(nums[i] < nums[i+1]){
                slope = 0;
                len++;
                break;
            } else if(nums[i] > nums[i+1]){
                slope = 1;
                len++;
                break;
            }
        }
        
        // int i = 0;
        while(i<nums.size()-1){
            if(nums[i] < nums[i+1] && slope == 1){
                slope = 0;
                len++;
            } else if(nums[i] > nums[i+1] && slope == 0) {
                slope = 1;
                len++;
            } 
            
            i++;
        }
        
        return len;
    }
};