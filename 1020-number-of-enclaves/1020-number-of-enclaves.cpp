class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                q.push({i, 0});
                vis[i][0] = 1;
            } 
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                q.push({i, m-1});
                vis[i][m-1] = 1;
            } 
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                q.push({0, j});
                vis[0][j] = 1;
            } 
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                q.push({n-1, j});
                vis[n-1][j] = 1;
            } 
        }
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};