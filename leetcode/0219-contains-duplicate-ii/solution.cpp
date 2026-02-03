class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> memo;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if( i > k ) memo.erase(nums[i-k-1]);
            if(memo.count(nums[i])) return true;
            memo.insert(nums[i]);
        }
        return false;
    }
};
