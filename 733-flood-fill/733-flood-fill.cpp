class Solution {
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int oldColor, int color, int delRow[], int delCol[]){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;
        
        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==oldColor && ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, oldColor, color, delRow, delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        dfs(sr, sc, ans, image, oldColor, color, delRow, delCol);
        return ans;
    }
};