class NumArray {
    vector<int> memo;
public:

    NumArray(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n);
        memo[0] = nums[0];
            for(int i = 1; i< n; i++){
                memo[i] = memo[i-1] + nums[i];
            }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return memo[right];
        return memo[right]-memo[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
