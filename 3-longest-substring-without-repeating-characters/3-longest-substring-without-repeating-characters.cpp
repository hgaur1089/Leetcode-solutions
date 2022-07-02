class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> mpp;
        int len = 0;
        int l = 0, r = 0;
        
        while(r < s.length()){
            if(mpp.count(s[r]) > 0){
                while(mpp.count(s[r]) > 0){
                    mpp.erase(s[l]);
                    l++;
                }
            } else {
                len = max(len, r-l+1);
                mpp[s[r]] = true;
                r++;
            }
        }
        
        return len;
    }
};