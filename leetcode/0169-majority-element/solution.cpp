class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int count = 1;
         for (int i = 1; i<nums.size() ; i++){
            if(count == 0){
                nums[0] = nums[i];
            }
            if(nums[i] == nums[0]){
                count++;
            }
            else{
                count--;
            }
         }
         return nums[0];
    }
};
