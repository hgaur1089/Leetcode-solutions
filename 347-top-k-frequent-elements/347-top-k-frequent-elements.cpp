class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(int num:nums){
            mpp[num]++;
        }
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto itr=mpp.begin(); itr!=mpp.end(); itr++){
            pq.push({itr->second, itr->first});
        }
        
        while(k--){
            pair<int, int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        
        return ans;
    }
};