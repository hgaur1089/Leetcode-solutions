class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int** out = new int*[m+1];
        for(int i=0; i<=m; i++){
            out[i] = new int[n+1];
        }
        
        for(int i=0; i<=m; i++){
            out[i][0] = i;
        }
        for(int j=0; j<=n; j++){
            out[0][j] = j;
        }
        
        for(int i=1; i<=m ;i++){
            for(int j=1; j<=n; j++){
                if(word1[m-i] == word2[n-j]){
                    out[i][j] = out[i-1][j-1];
                } else {
                    int x = out[i-1][j];
                    int y = out[i][j-1];
                    int z = out[i-1][j-1];
                    out[i][j] = min(x, min(y, z)) + 1;
                }
            }
        }
        
        int ans = out[m][n];
        for(int i=0; i<=m; i++){
            delete[] out[i];
        }
        delete[] out;
        
        return ans;
    }
};