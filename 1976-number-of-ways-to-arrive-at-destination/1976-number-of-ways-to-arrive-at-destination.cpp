class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        int mod = (1e9 + 7);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                long long adjNode = it.first;
                long long adjWt = it.second;
                
                if(dis+adjWt < dist[adjNode]){
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis + adjWt, adjNode});
                    ways[adjNode] = ways[node];
                } else if(dis + adjWt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};