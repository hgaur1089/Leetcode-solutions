bool compare(string& a, string& b){
    return a.size() < b.size();
}
class Solution {
    bool checkStr(string& a, string& b){
        if(a.size() != b.size()+1){
            return false;
        }

        int first=0;
        int second=0;
        while(first < a.size()){
            if(a[first] == b[second]){
                first++;
                second++;
            } else {
                first++;
            }
        }

        if(first==a.size() && second==b.size()){
            return true;
        }
        return false;
    }


    //time -> O(n^2 * maxLenOfString)
    //space -> O(n)
    int longestStrChain(int n, vector<string>& arr){

        sort(arr.begin(), arr.end(), compare);
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i=0;i<n;i++){
            for(int j=0; j<i; j++){
                int possibleAns = dp[j]+1;
                if(checkStr(arr[i], arr[j]) && possibleAns>dp[i]){
                    dp[i] = possibleAns;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
            }
        }

        return ans;
    }
public:
    int longestStrChain(vector<string>& words) {
        return longestStrChain(words.size(), words);
    }
};