class Solution {
    bool dfs(int src, vector<vector<int>>& graph, vector<int>& vis, 
             vector<int>& currPath, vector<int>& check){
        vis[src] = 1;
        currPath[src] = 1;
        check[src] = 0;
        
        for(int node:graph[src]){
            if(!vis[node]){
                if(dfs(node, graph, vis, currPath, check)){
                    check[src] = 0;
                    return true;
                } 
            } else if(currPath[node]){
                check[src] = 0;
                return true;
            }
        }
        
        check[src] = 1;
        currPath[src] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> currPath(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNodes;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, graph, vis, currPath, check);
            }
        }
        
        for(int i=0;i<n;i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};