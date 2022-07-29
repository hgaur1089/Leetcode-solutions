class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int n=x^y;
        while(n){
            if(n&1){
                ans++;
            }
            n = n>>1;
        }
        
        return ans;
    }
};