class Solution {
    void conDiff(int n, int k, int num, vector<int>& ans){
        if(n==0){
            ans.push_back(num);
            return;
        }
        
        int last = num%10;
        if(last-k >=0){
            
            conDiff(n-1, k, (num*10)+(last-k), ans);
        }
        if(last+k<=9 && k!=0){
            conDiff(n-1, k, (num*10)+(last+k), ans);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1; i<=9; i++)
            conDiff(n-1, k, i, ans);
        return ans;
    }
};