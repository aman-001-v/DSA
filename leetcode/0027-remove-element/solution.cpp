class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 1 && nums[0] != val){
            return 1;
        }
        int start = 0 , end =nums.size() -1 ; 
        while(start < end){
            while(start < nums.size() && nums[start] != val ){
                start++;
            }
            while(nums[end] == val && end > 0){
                end--;
            }
            if(start < end){
            swap(nums[start],nums[end]);
            }
        }
        return start;
    }
};
