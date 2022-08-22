class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1){
            return true;
        }
        if(n<=0 || n%2==1){
            return false;
        }
        bool ans = false;
        int i = 1;
        while(n){
            n = n>>1;
            i++;
            ans = ((n&1) && i%2==1 && (n>>1)==0);
            if(n&1){
                return ans;
            }
        }
        return ans;
    }
};