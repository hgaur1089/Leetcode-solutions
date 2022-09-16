class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        map<char, int> hash;
        
        int l = 0;
        int r = 0;
        
        while(r < s.size()){
            if(hash.find(s[r]) != hash.end())
                l = max(l, hash[s[r]]+1);
            
            hash[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        
        return maxLen;
    }
};