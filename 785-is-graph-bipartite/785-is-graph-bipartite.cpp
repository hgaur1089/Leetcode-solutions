class Solution {
    bool bipartite(int src, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int adjacentNode:graph[node]){
                if(color[adjacentNode]==-1){
                    color[adjacentNode] = color[node] ? 0 : 1;
                    q.push(adjacentNode);
                } else if(color[adjacentNode] == color[node]){
                    return false;
                }
            }
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bipartite(i, graph, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};