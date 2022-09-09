bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]){
        return a[0]>b[0];
    }
    
    return a[1] < b[1];
}
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), cmp);
        
        int ans = 0;
        int maxTillNow = INT_MIN;
        for(auto it:properties){
            if(maxTillNow>it[1]){
                ans++;
            } else {
                maxTillNow = it[1];
            }
        }
        
        return ans;
    }
};