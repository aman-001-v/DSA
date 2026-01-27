class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector <int> memo;
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(nums1[i] >= nums2[j]){
                memo.push_back(nums2[j++]);
            }
            else{
                memo.push_back(nums1[i++]);
            }

        }
        while(i < m){
            memo.push_back(nums1[i++]);
        }
        while(j < n){
            memo.push_back(nums2[j++]);
        }
        nums1 = memo;

    }
};
