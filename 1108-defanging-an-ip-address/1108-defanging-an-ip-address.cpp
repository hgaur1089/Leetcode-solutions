class Solution {
public:
    void defang(string str, string& ans){
        if(str.length() == 0){
            return;
        }
        
        if(str[0] == '.'){
            ans += "[.]";
        } else {
            ans += str[0];   
        }
        
        defang(str.substr(1), ans);
    }
    string defangIPaddr(string address) {
        string ans = "";
        defang(address, ans);
        return ans;
    }
};