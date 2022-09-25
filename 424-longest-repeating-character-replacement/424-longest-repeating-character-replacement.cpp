class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        
        int i=0;
        int j=0;
        int maxCount = 0;
        int res = 0;
        
        while(j<s.size()){
            count[s[j]-'A']++;
            maxCount = max(maxCount, count[s[j]-'A']);
            if(j-i+1 - maxCount > k){
                count[s[i]-'A']--;
                i++;
            }
            
            res = max(res, j-i+1);
            j++;
        }
        
        return res;
    }
};