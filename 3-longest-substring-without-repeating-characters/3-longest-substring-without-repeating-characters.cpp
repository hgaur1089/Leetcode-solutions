class Solution {
public:
    int lengthOfLongestSubstring(string s) {
//         unordered_map<char, bool> mpp;
//         int len = 0;
//         int l = 0, r = 0;
        
//         while(r < s.length()){
//             if(mpp.count(s[r]) > 0){
//                 while(mpp.count(s[r]) > 0){
//                     mpp.erase(s[l]);
//                     l++;
//                 }
//             } else {
//                 len = max(len, r-l+1);
//                 mpp[s[r]] = true;
//                 r++;
//             }
//         }
        
//         return len;
        vector<int> map(256, -1);
        int left = 0, right = 0;
        int size = s.size();
        int len = 0;
        
        while(right < size){
            if(map[s[right]] != -1){
                left = max(left, map[s[right]] + 1);
            }
            
            map[s[right]] = right;
            len = max(right-left+1, len);
            right++;
        }
        
        return len;
    }
};