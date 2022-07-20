class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return solveBFS(grid);
    }
    
    int solveBFS(vector<vector<char>>& grid){
        int n = grid.size(); 
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        int i = q.front().first;
                        int j= q.front().second;
                        q.pop();
                        
                        removeIsland(grid, i+1, j, q);
                        removeIsland(grid, i-1, j, q);
                        removeIsland(grid, i, j+1, q);
                        removeIsland(grid, i, j-1, q);
                        
                    }
                }
            }
        }
        
        return ans;
    }
    
    void removeIsland(vector<vector<char>>& grid, int i, int j, queue<pair<int, int>>& q){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j] == '1'){
            grid[i][j] = '0';
            q.push({i, j});
        }
    }
    
    int solveDFS(vector<vector<char>>& grid){
        int n = grid.size(); 
        int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        
    }
};