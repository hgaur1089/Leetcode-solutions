class Solution {
    bool checkPalin(string s){
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string temp = "";
        int i=0;
        while(i<s.size()){  
            if(isalnum(s[i])){
                s[i] = tolower(s[i]);
                temp += s[i];
            }
            i++;
        }
        
        return checkPalin(temp);
    }
};