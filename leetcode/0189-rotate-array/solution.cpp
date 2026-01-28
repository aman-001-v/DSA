class Solution {
public:
    void reverse(vector<int>& nums, int l , int r){
        while(l < r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int r = k % n;
        reverse(nums,0, n - 1);
        reverse(nums,0, r- 1);
        reverse(nums, r , n -1);
    }
};
