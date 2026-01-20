class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n ; i++){
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i = 0; i< n ; i++){
            if(abs(nums[i]) - 1 >=0 && abs(nums[i]) - 1 < n){
                if(nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
                else if(nums[abs(nums[i]) - 1] == 0) nums[abs(nums[i]) - 1] = -(n+1);
            }
        }
        int smallest = 0;
        while(smallest < n && nums[smallest] < 0){
            smallest ++;
        }
        return smallest +1;
    }
};
