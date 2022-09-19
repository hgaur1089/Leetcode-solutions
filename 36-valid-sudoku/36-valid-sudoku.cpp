class Solution {
    bool checkRowCol(int x, int y, char c, vector<vector<char>>& board){
        int cnt = 0;
        for(int i=0;i<9;i++){
            if(board[i][y] == c){
                if(cnt)
                    return false;
                cnt++;
            }
        }
        cnt = 0;
        for(int j=0;j<9;j++){
            if(board[x][j] == c){
                if(cnt)
                    return false;
                cnt++;
            }
        }
        return true;
    }
    
    bool checkGrid(int x, int y, char c, vector<vector<char>>& board){
        int row = (x/3) *3;
        int col = (y/3) *3;
        int cnt = 0;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j]==c){
                    if(cnt)
                        return false;
                    cnt++;
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9; i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.')
                if(!checkRowCol(i,j, board[i][j], board) || !checkGrid(i,j, board[i][j], board)){
                    return false;
                }
            }
        }
        
        return true;
    }
};