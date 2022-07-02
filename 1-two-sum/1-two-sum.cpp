class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
//         // int a, b;
//         vector<int> ans;
//         // for(int i=0; i<nums.size(); i++){
//         //     a = i;
//         //     for(int j=i+1; j<nums.size(); j++){
//         //         b = j;
//         //         if(nums[i]+nums[j] == target){
//         //              ans.push_back(a);
//         //              ans.push_back(b);
//         //              return ans;
//         //         }
//         //     }
//         // }
        
//         unordered_map<int, int> arr;
//         for(int i=0; i<nums.size(); i++){
//             int comp = target - nums[i];
//             auto x = arr.find(comp);
//             if(x != arr.end()){
//                 ans.push_back(x->second);
//                 ans.push_back(i);
//             }
            
//             arr[nums[i]] = i;
//         }
        
//         return ans;
        
        vector<int> ans;
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            if(map.count(target - nums[i]) > 0){
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                return ans;
            }
            
            map[nums[i]] = i;
        }
        
        return ans;
    }
};