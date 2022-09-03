class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1;
        int num2 = -1;
        int cnt1 = 0, cnt2 = 0;
        
        for(int ele:nums){
            if(ele==num1) cnt1++;
            else if(ele==num2) cnt2++;
            else if(cnt1==0){
                num1 = ele;
                cnt1 = 1;
            } else if(cnt2==0){
                num2 = ele;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        cnt1 = cnt2 = 0;
        for(int ele:nums){
            if(ele==num1) cnt1++;
            else if(ele==num2) cnt2++;
        }
        cout<<num1<<" "<<num2;
        
        if(cnt1>(nums.size()/3)) ans.push_back(num1);
        if(cnt2>(nums.size()/3)) ans.push_back(num2);
        return ans;
    }
};