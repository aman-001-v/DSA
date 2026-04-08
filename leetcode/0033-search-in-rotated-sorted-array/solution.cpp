class Solution {
public:
    int bsearch(vector<int> nums , int target , int l , int r){
        while(l <= r){
            int m = l + ((r-l)/2);
            if(target == nums[m]) return m;
            else if(target < nums[m]) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        if(nums[l] <= nums[r]) return bsearch(nums, target , l , r);
        int m;
        while(l < r){
            m = l + ((r - l)/2);
            if(nums[m]>= nums[r]) l = m + 1;
            else r = m;
        }
        if(target > nums[nums.size() - 1]){
            return bsearch(nums , target , 0 , l -1);
        }else{
            return bsearch(nums , target , l , nums.size() - 1);
        }
    }
};
