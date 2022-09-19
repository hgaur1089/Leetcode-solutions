class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hash;
        for(string str:strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            hash[temp].push_back(str);
        }
        
        for(auto itr:hash){
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};