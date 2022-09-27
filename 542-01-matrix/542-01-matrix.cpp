class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            ans[x][y] = dis;
            for(int i=0;i<4;i++){
                int nrow = x+delRow[i];
                int ncol = y+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    q.push({{nrow, ncol}, dis+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        return ans;
    }
};