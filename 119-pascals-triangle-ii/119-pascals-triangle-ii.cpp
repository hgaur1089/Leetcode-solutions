class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr(rowIndex+1, vector<int>(rowIndex+1, 0));
        arr[0][0] = 1;
        for(int i=1; i<=rowIndex; i++){
            for(int j=0; j<=i; j++){
                int temp = arr[i-1][j];
                if(j-1>=0){
                    temp+= arr[i-1][j-1];
                }
                arr[i][j] = temp;
            }
        }
        
        return arr[rowIndex];
    }
};