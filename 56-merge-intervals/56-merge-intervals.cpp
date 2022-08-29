class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            return ans;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempIntervals = intervals[0];
        
        for(auto it:intervals){
            if(tempIntervals[1] >= it[0]){
                tempIntervals[1] = max(tempIntervals[1], it[1]);
            } else {
                ans.push_back(tempIntervals);
                tempIntervals = it;
            }
        }
        ans.push_back(tempIntervals);
        
        return ans;
    }
};