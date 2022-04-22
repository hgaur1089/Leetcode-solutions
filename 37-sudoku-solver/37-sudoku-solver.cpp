class Solution {
public:
    
    bool isSafe(vector<vector<char>> board, int row, int col, int num){
        char c = num + '0';
        for(int i=0; i<9; i++){
            if(board[row][i] == c || board[i][col] == c){
                return false;
            }
        }
            
        int rowFac = row - (row%3);
        int colFac = col - (col%3);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i+rowFac][j+colFac] == c){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool findEmptyCell(vector<vector<char>> board, int& row, int& col){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool solve(vector<vector<char>>& board){
        int row, col;
        
        if(!findEmptyCell(board, row, col)){
            return true;
        }
        
        for(int i=1; i<=9; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i + '0';
                if(solve(board)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};