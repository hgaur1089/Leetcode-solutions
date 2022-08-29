class Solution {
    void sortIt(vector<int>& arr, int n){
        for(int i=1; i<n; i++)
            if(arr[i-1]>arr[i]){
                swap(arr[i-1], arr[i]);
            } else {
                break;
            }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        
        if(m!=0){
             for(int i=0; i<m; i++){
                if(nums1[i]>nums2[0]){
                    swap(nums1[i], nums2[0]);
                    sortIt(nums2, n);
                }
            }
        }
      
        for(int i=0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
    }
};