class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            if(nums[i]==1){
                count++;
            }
            else{
                if(max_count < count){
                    max_count = count;
                    count = 0;
                }
                else{
                    count = 0;
                }
            }
        }
        return max(max_count,count);
    }
};
