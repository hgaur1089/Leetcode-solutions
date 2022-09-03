class Solution {
    int merge(vector<int>& arr, int lo, int mid, int hi){
        int k= mid+1;
        int cnt = 0;
        
        for(int i=lo; i<=mid; i++){
            while(k<=hi && arr[i]>(2LL*arr[k])){
                k++;
            }  
            cnt += (k-(mid+1));
        }
        
        vector<int> temp;
        int i=lo;
        int j=mid+1;
        while(i<=mid && j<=hi){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=mid){
            temp.push_back(arr[i++]);
        }
        while(j<=hi){
            temp.push_back(arr[j++]);
        }
        
        for(int i=lo; i<=hi; i++){
            arr[i] = temp[i-lo];
        }
        return cnt;
    }
    
    int mergeSort(vector<int>& nums, int si, int ei){
        if(si >= ei) return 0;
        
        int mid = ((si + ei)/2);
        int ans = mergeSort(nums, si, mid);
        ans += mergeSort(nums, mid+1, ei);
        ans += merge(nums, si, mid, ei);
        
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        int ans = mergeSort(nums, 0, nums.size()-1);
        return ans;
    }
};