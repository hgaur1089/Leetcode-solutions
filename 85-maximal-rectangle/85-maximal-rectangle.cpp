class Solution {
    int largestRectangleArea(vector<int>& histo){
        stack<int> stk;
        int maxA = 0;
        int n = histo.size();
        for(int i=0; i<=n; i++){
            while(!stk.empty() && (i==n || histo[stk.top()] >= histo[i])){
                int height = histo[stk.top()];
                stk.pop();
                int width;
                if(stk.empty()){
                    width = i;
                } else {
                    width = i-stk.top()-1;
                }
                maxA = max(maxA, width*height);
            }
            stk.push(i);
        }

        return maxA;
    }

    //time -> O(n*(m+n))
    //space -> O(n)
    int maxRectangle(vector<vector<int>>& mat, int n, int m){
        int maxArea = 0;
        vector<int>height(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            int area = largestRectangleArea(height);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if(n==1 && m==1){
            return matrix[0][0] == '1';
        }
        vector<vector<int>> arr(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = matrix[i][j] - '0';
            }
        }
        
        return maxRectangle(arr, n, m);
    }
};