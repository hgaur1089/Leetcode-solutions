class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = -1;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0]<newInterval[0]){
                index = i;
            }
        }
        intervals.insert(intervals.begin()+(index+1), newInterval);
        
        vector<vector<int>> ans;
        vector<int> temp;
        if(intervals.size()!=0){
            temp = intervals[0];
        } else {
            temp = newInterval;
        }
        
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1], intervals[i][1]);
            } else {
                ans.push_back(temp);
                temp = intervals[i];
            }
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        }
        ans.push_back(temp);
        
        return ans;
    }
};