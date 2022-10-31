class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1 && grid[0][0]==0){
            return 1;
        }
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0,0}});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int newR = r + i;
                    int newC = c + j;
                    
                    if(newR>=0 && newR<n && newC>=0 && newC<n && 
                        grid[newR][newC]==0 && dis+1<dist[newR][newC]){
                        dist[newR][newC] = dis+1;
                        if(newR==n-1 && newC==n-1){
                            return dis+1;
                        }
                        q.push({dis+1, {newR, newC}});
                    }
                }
            }
        }
        
        return -1;
    }
};