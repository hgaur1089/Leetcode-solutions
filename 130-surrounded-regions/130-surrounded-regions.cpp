class Solution {
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col] = 1;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
    
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() && 
               board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i, 0, board, vis);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i, m-1, board, vis);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0, j, board, vis);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1, j, board, vis);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};