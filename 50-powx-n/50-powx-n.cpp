class Solution {
public:
    double pos(double x, int n){
        if(n == 0) 
            return 1;
        
        double temp = pos(x, n/2);
        if(n%2 == 0){
            return temp*temp;
        } else {
            if(n > 0)
                return x * temp * temp;
            else 
                return (temp * temp)/x;
        }
    }
    
    double myPow(double x, int n) {
        double ans;
        ans = pos(x, n);
        return ans;
    }
};