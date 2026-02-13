class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> memo;
        int num_max = INT_MIN;
        int index_max;
        for(int i = 0 ; i < k; i++){
            if(num_max < nums[i]){
                    num_max = nums[i];
                    index_max = i;
                }
        }
        memo.push_back(num_max);
        int l = 1;
        for(int r = l+k; r <= nums.size();r++){
            if(nums[l-1] == num_max){
                if(nums[l-1] <= nums[r - 1]) num_max = nums[r-1];
                else{
                    num_max = nums[l];
                    for(int i = l+1 ; i < r; i++){
                        if(num_max < nums[i]){
                                num_max = nums[i];
                        }
                    }
                }
            }else{
                if(num_max < nums[r - 1]) num_max = nums[r-1];
            }
            memo.push_back(num_max);
            l++;
        }
        return memo;
    }
};
