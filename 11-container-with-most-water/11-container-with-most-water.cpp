class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
        int i = 0;
        int j = n-1;
        while(i<j){
            int h = min(height[i], height[j]);
            int b = j-i;
            
            ans = max(ans, b*h);
            
            if(height[i]<height[j]) i++;
            else j--;
        }
        return ans;
    }
};