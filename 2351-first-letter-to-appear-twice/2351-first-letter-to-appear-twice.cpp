class Solution {
public:
    char repeatedCharacter(string s) {
        int arr[26] = {0};
        int ans[26] = {0};
        
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            if(arr[s[i]-'a'] == 2){
                ans[s[i]-'a'] = 1;
                break;
            }
        }
        
        char ch;
        int index = INT_MAX;
        for(int i=0; i<26; i++){
            if(ans[i] == 1){
                ch = (i+'a');
                break;
            }
        }
        return ch;
    }
};